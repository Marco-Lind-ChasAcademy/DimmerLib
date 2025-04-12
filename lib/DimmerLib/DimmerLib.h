#ifndef DIMMERLIB_H
#define DIMMERLIB_H


#include <Arduino.h>

/**
 * @brief Macro to create a mode-switching ISR that toggles between AUTO and MANUAL modes.
 * 
 * @param ISR_NAME Desired name for the ISR function.
 * @param DIMMER_OBJECT Instance of LightSensingDimmer to operate on.
 */
#define MAKE_MODE_SWITCH_ISR(ISR_NAME, DIMMER_OBJECT) \
    void ISR_NAME() \
    { \
        switch (DIMMER_OBJECT.mode) \
        { \
        case DimmerLib::MANUAL: \
            DIMMER_OBJECT.mode = DimmerLib::AUTO; \
            break; \
         \
        default: \
            DIMMER_OBJECT.mode = DimmerLib::MANUAL; \
            break; \
        } \
       \
    }



namespace DimmerLib
{
    enum modes { MANUAL, AUTO };;

    /**
     * @brief Light-sensing dimmer class.
     * 
     * This class manages automatic and manual LED brightness control
     * based on ambient light or a potentiometer.
     */
    class LightSensingDimmer
    {
    public:
        const uint8_t SENSOR_PIN;
        const uint8_t LED_PIN;
        const uint16_t POLLING_RATE;
        const uint8_t AVERAGES;
        const uint16_t PART_DELAY;
        const uint16_t DELAY_TIME;
        const float K;
        const uint8_t MODE_BUTTON_PIN;
        const uint8_t POT_PIN;
        const uint8_t CHANNEL;
        
        volatile uint8_t mode;
        uint16_t pot_value;
        uint32_t sensor_value_sum;
        uint16_t sensor_value_average;
        uint8_t led_value;
        uint32_t last_millis;
        uint32_t current_millis;

        /**
         * @brief Constructor to initialize a LightSensingDimmer object.
         * 
         * Sets up pins, PWM output, and initial configuration.
         * 
         * @param SENSOR_PIN_ Analog pin to read light levels.
         * @param LED_PIN_ PWM-capable pin connected to the LED.
         * @param MODE_BUTTON_PIN_ Pin connected to mode toggle button (INPUT_PULLUP).
         * @param POT_PIN_ Analog pin connected to potentiometer for manual dimming.
         * @param CHANNEL_ PWM channel (0–15 on ESP32).
         * @param mode_ Optional: Starting mode (AUTO or MANUAL).
         * @param K_ Optional: Exponential scaling factor for brightness mapping.
         * @param POLLING_RATE_ Optional: Update rate in ms.
         * @param AVERAGES_ Optional: Number of light samples to average.
         * @param PART_DELAY_ Optional: Microsecond delay between samples.
         */
        LightSensingDimmer(
            const uint8_t SENSOR_PIN_,
            const uint8_t LED_PIN_,
            const uint8_t MODE_BUTTON_PIN_,
            const uint8_t POT_PIN_,
            const uint8_t CHANNEL_,
            volatile uint8_t mode_ = AUTO,
            const float K_ = 2,
            const uint8_t POLLING_RATE_ = 100,
            const uint8_t AVERAGES_ = 20,
            const uint16_t PART_DELAY_ = 2500);
        ~LightSensingDimmer();
    };
    
    
    
    
    LightSensingDimmer::LightSensingDimmer
    (
        const uint8_t SENSOR_PIN_,
        const uint8_t LED_PIN_,
        const uint8_t MODE_BUTTON_PIN_,
        const uint8_t POT_PIN_,
        const uint8_t CHANNEL_,
        volatile uint8_t mode_,
        const float K_,
        const uint8_t POLLING_RATE_,
        const uint8_t AVERAGES_,
        const uint16_t PART_DELAY_
    ) :
        SENSOR_PIN(SENSOR_PIN_), LED_PIN(LED_PIN_),
        POLLING_RATE(POLLING_RATE_), AVERAGES(AVERAGES_),
        PART_DELAY(PART_DELAY_), POT_PIN(POT_PIN_),
        DELAY_TIME(POLLING_RATE_ - (AVERAGES_ * PART_DELAY_) / 1000),
        K(K_), MODE_BUTTON_PIN(MODE_BUTTON_PIN_),
        mode(mode_), last_millis(0), CHANNEL(CHANNEL_)
    {
        ledcSetup(CHANNEL, 490, 8);
        ledcAttachPin(LED_PIN, CHANNEL);
        pinMode(SENSOR_PIN, INPUT);
        pinMode(MODE_BUTTON_PIN, INPUT_PULLUP);
    }
    
    LightSensingDimmer::~LightSensingDimmer()
    {
    }

    /**
     * @brief Measures ambient light by summing analog readings over multiple samples.
     * 
     * @param sensor_value_sum Reference to store the total light measurement.
     * @param AVERAGES Number of samples to take.
     * @param SENSOR_PIN Analog pin used to read the light sensor.
     * @param PART_DELAY Delay (in microseconds) between each sample.
     */
    inline void measureLight(uint32_t &sensor_value_sum, const uint8_t AVERAGES, const uint8_t SENSOR_PIN, const uint16_t PART_DELAY);

    /**
     * @brief Calculates the average sensor value over the total sum of readings.
     * 
     * @param sensor_value_average Reference to store the averaged result.
     * @param sensor_value_sum Accumulated sum of sensor readings.
     * @param AVERAGES Number of samples used in the sum.
     */
    inline void averageLight(uint16_t &sensor_value_average, uint32_t sensor_value_sum, const uint8_t AVERAGES);

    /**
     * @brief Applies an exponential mapping to the averaged sensor value to determine LED brightness.
     * 
     * @param led_value Reference to store the calculated brightness (0–255).
     * @param sensor_value_average Averaged sensor value.
     * @param K Curve sharpness constant (higher values make the curve steeper).
     */
    inline void mapLed(uint8_t &led_value, uint16_t sensor_value_average, const float K);

    /**
     * @brief Writes the calculated brightness level to the LED using PWM.
     * 
     * @param dimmer Reference to the LightSensingDimmer instance to control.
     */
    inline void writeLed(LightSensingDimmer &dimmer);

    /**
     * @brief Outputs the current LED brightness and light level average to the serial monitor.
     * 
     * @param led_value Current brightness level.
     * @param sensor_value_average Current averaged light level.
     */
    inline void writeSerial(uint8_t led_value, uint16_t sensor_value_average);

    /**
     * @brief Main control loop for the dimmer. Should be called repeatedly in loop().
     * 
     * - AUTO mode: Measures ambient light and adjusts LED brightness.
     * - MANUAL mode: Uses potentiometer value to set LED brightness.
     * 
     * @param dimmer Reference to a LightSensingDimmer object.
     */
    void runDimmer(LightSensingDimmer& dimmer);


    
    void runDimmer(LightSensingDimmer& dimmer)
    {
        switch (dimmer.mode)
        {
        case MANUAL:
            dimmer.pot_value = analogRead(dimmer.POT_PIN); // Needs thread sync!
            mapLed(dimmer.led_value, dimmer.pot_value, dimmer.K);
            ledcWrite(dimmer.CHANNEL, dimmer.led_value); // Needs thread sync!
            delay(dimmer.POLLING_RATE);
            
            break;
        
        default:
            measureLight(
                dimmer.sensor_value_sum,
                dimmer.AVERAGES,
                dimmer.SENSOR_PIN,
                dimmer.PART_DELAY); // Needs thread sync!
            averageLight(
                dimmer.sensor_value_average,
                dimmer.sensor_value_sum,
                dimmer.AVERAGES);
            mapLed(
                dimmer.led_value,
                dimmer.sensor_value_average,
                dimmer.K);
            writeLed(dimmer); // Needs thread sync!
            
            writeSerial(
                dimmer.led_value,
                dimmer.sensor_value_average); // Maybe needs thread sync...
            delay(dimmer.DELAY_TIME);
            
            break;
        }
    }
    
    inline void measureLight(uint32_t &sensor_value_sum, const uint8_t AVERAGES, const uint8_t SENSOR_PIN, const uint16_t PART_DELAY)
    {
        sensor_value_sum = 0;
        
        for (int i = 0; i < AVERAGES; i++)
        {
            sensor_value_sum += analogRead(SENSOR_PIN);
            delayMicroseconds(PART_DELAY);
        }

    }
    
    inline void averageLight(uint16_t &sensor_value_average, uint32_t sensor_value_sum, const uint8_t AVERAGES)
    {
        sensor_value_average = sensor_value_sum / AVERAGES;
    }
    
    inline void mapLed(uint8_t &led_value, uint16_t sensor_value_average, const float K)
    {
        led_value = 255 * pow((float)(sensor_value_average) / 4096, K);
    }
    
    inline void writeLed(LightSensingDimmer &dimmer)
    {
        ledcWrite(dimmer.CHANNEL, dimmer.led_value);
    }
    
    inline void writeSerial(uint8_t led_value, uint16_t sensor_value_average)
    {
        Serial.print(led_value);
        Serial.print(" ");
        Serial.print(sensor_value_average);
        Serial.println();
    }

}




#endif