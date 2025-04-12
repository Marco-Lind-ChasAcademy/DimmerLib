#ifndef LIGHT_SENSING_DIMMER_H
#define LIGHT_SENSING_DIMMER_H


#include <Arduino.h>


/**
 * @brief Generates a mode switch ISR function with a custom name
 * @param ISR_NAME Desired name for the ISR
 * @param DIMMER_OBJECT Dimmer object to operate on
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
    enum modes
    {
      MANUAL,
      AUTO
    };




    /**
     * @brief Light sensing dimmer object. Initialize with member values
     * 
     * @param SENSOR_PIN_ Analog pin to read the light level from
     * @param LED_PIN_ Digital pin for the dimmable LED
     * @param MODE_BUTTON_PIN_ Digital pin for mode-switching button
     * @param POT_PIN_ Analog pin for the dimming potentiometer
     * @param CHANNEL_ PWM channel for the ESP32 (0-15)
     * @param mode_ Optional: Mode to start the dimmer in (MAN/AUTO)
     * @param POLLING_RATE_ Optional: Rate in ms at which the LED updates the light level
     * @param AVERAGES_ Optional: Number of measuring points
     * @param PART_DELAY_ Optional: Delay in microseconds between each measuring point
     * @param K_ Optional: Constant for the rate of change in the LED brightness
     */
    class Light_sensing_dimmer
    {
    public:
        const uint8_t SENSOR_PIN;
        const uint8_t LED_PIN;
        const uint16_t POLLING_RATE;
        const uint8_t AVERAGES;
        const uint16_t PART_DELAY;
        const uint16_t DELAY_TIME;
        const float K;  // You can adjust this value to make the transition sharper or smoother
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
         * @param SENSOR_PIN_ Analog pin to read the light level from
         * @param LED_PIN_ Digital pin for the dimmable LED
         * @param MODE_BUTTON_PIN_ Digital pin for mode-switching button
         * @param POT_PIN_ Analog pin for the dimming potentiometer
         * @param CHANNEL_ PWM channel for the ESP32 (0-15)
         * @param mode_ Optional: Mode to start the dimmer in (MAN/AUTO)
         * @param POLLING_RATE_ Optional: Rate in ms at which the LED updates the light level
         * @param AVERAGES_ Optional: Number of measuring points
         * @param PART_DELAY_ Optional: Delay in microseconds between each measuring point
         * @param K_ Optional: Constant for the rate of change in the LED brightness
         */
        Light_sensing_dimmer(
            const uint8_t SENSOR_PIN_,
            const uint8_t LED_PIN_,
            const uint8_t MODE_BUTTON_PIN_,
            const uint8_t POT_PIN_,
            const uint8_t CHANNEL_,
            volatile uint8_t mode_ = AUTO,
            const uint8_t POLLING_RATE_ = 100,
            const uint8_t AVERAGES_ = 20,
            const uint16_t PART_DELAY_ = 2500,
            const float K_ = 2);
        ~Light_sensing_dimmer();
    };
    
    
    
    
    Light_sensing_dimmer::Light_sensing_dimmer
    (
        const uint8_t SENSOR_PIN_,
        const uint8_t LED_PIN_,
        const uint8_t MODE_BUTTON_PIN_,
        const uint8_t POT_PIN_,
        const uint8_t CHANNEL_,
        volatile uint8_t mode_,
        const uint8_t POLLING_RATE_,
        const uint8_t AVERAGES_,
        const uint16_t PART_DELAY_,
        const float K_
    ) :
        SENSOR_PIN(SENSOR_PIN_),
        LED_PIN(LED_PIN_),
        POLLING_RATE(POLLING_RATE_),
        AVERAGES(AVERAGES_),
        PART_DELAY(PART_DELAY_),
        DELAY_TIME(POLLING_RATE_ - (AVERAGES_ * PART_DELAY_) / 1000),
        K(K_),
        MODE_BUTTON_PIN(MODE_BUTTON_PIN_),
        POT_PIN(POT_PIN_),
        mode(mode_),
        last_millis(0),
        CHANNEL(CHANNEL_)
    {
        ledcSetup(CHANNEL, 490, 8);
        ledcAttachPin(LED_PIN, CHANNEL);
        pinMode(SENSOR_PIN, INPUT);
        pinMode(MODE_BUTTON_PIN, INPUT_PULLUP);
    }
    
    Light_sensing_dimmer::~Light_sensing_dimmer()
    {
    }



    inline void measureLight(
        uint32_t &sensor_value_sum,
        const uint8_t AVERAGES,
        const uint8_t SENSOR_PIN,
        const uint16_t PART_DELAY);
    inline void averageLight(uint16_t &sensor_value_average, uint32_t sensor_value_sum, const uint8_t AVERAGES);
    inline void mapLed(uint8_t &led_value, uint16_t sensor_value_average, const float K);
    inline void writeLed(Light_sensing_dimmer &dimmer);
    inline void writeSerial(uint8_t led_value, uint16_t sensor_value_average);
    void runDimmer(Light_sensing_dimmer& dimmer);

    
    /**
     * @brief Runs dimmer. Put into main()
     * 
     * @param dimmer Dimmer object
     */
    void runDimmer(Light_sensing_dimmer& dimmer)
    {
        dimmer.current_millis = millis();


        switch (dimmer.mode)
        {
        case MANUAL:
            if (dimmer.current_millis - dimmer.last_millis >= dimmer.POLLING_RATE)
            {
                dimmer.last_millis = dimmer.current_millis;
                
                dimmer.pot_value = analogRead(dimmer.POT_PIN);
                mapLed(dimmer.led_value, dimmer.pot_value, dimmer.K);
                ledcWrite(dimmer.CHANNEL, dimmer.led_value);
                //delay(dimmer.POLLING_RATE);
            }
            
            break;
        
        default:
            if (dimmer.current_millis - dimmer.last_millis >= dimmer.DELAY_TIME)
            {
                dimmer.last_millis = dimmer.current_millis;

                measureLight(
                  dimmer.sensor_value_sum,
                  dimmer.AVERAGES,
                  dimmer.SENSOR_PIN,
                  dimmer.PART_DELAY);
                averageLight(
                  dimmer.sensor_value_average,
                  dimmer.sensor_value_sum,
                  dimmer.AVERAGES);
                
                mapLed(
                  dimmer.led_value,
                  dimmer.sensor_value_average,
                  dimmer.K);
                writeLed(dimmer);
                
                writeSerial(
                  dimmer.led_value,
                  dimmer.sensor_value_average);
                //delay(dimmer.DELAY_TIME);
            }
            
            break;
        }
        
        delay(1);
    }

    /**
     * @brief Measure average light level
     * 
     * @param sensor_value_sum Sum of the measured values
     * @param AVERAGES Number of measuring points
     * @param SENSOR_PIN Analog pin to read the light level from
     * @param PART_DELAY Delay in microseconds between each measuring point
     */
    inline void measureLight(
        uint32_t &sensor_value_sum,
        const uint8_t AVERAGES,
        const uint8_t SENSOR_PIN,
        const uint16_t PART_DELAY)
    {
        sensor_value_sum = 0;
        
        for (int i = 0; i < AVERAGES; i++)
        {
            sensor_value_sum += analogRead(SENSOR_PIN);
            delayMicroseconds(PART_DELAY);
        }

    }
    
    /**
     * @brief Calculates average light level over time
     * 
     * @param sensor_value_average Averaged light level over time
     * @param sensor_value_sum Sum of the measured values
     * @param AVERAGES Number of measuring points
     */
    inline void averageLight(
        uint16_t &sensor_value_average,
        uint32_t sensor_value_sum,
        const uint8_t AVERAGES)
    {
        sensor_value_average = sensor_value_sum / AVERAGES;
    }
    
    /**
     * @brief Maps averaged sensor value exponentially to 8-bit resolution
     * 
     * @param led_value LED brightness level
     * @param sensor_value_average Averaged light level over time
     * @param K Constant for the rate of change in the LED brightness
     */
    inline void mapLed(uint8_t &led_value, uint16_t sensor_value_average, const float K)
    {
        led_value = 255 * pow((float)(sensor_value_average) / 4096, K);
    }
    
    /**
     * @brief Writes to the LED pin
     * 
     * @param led_value LED brightness level
     */
    inline void writeLed(Light_sensing_dimmer &dimmer)
    {
        ledcWrite(dimmer.CHANNEL, dimmer.led_value);
    }
    
    /**
     * @brief Writes values to the serial monitor
     * 
     * @param led_value LED brightness level
     * @param sensor_value_average Averaged light level over time
     */
    inline void writeSerial(uint8_t led_value, uint16_t sensor_value_average)
    {
        Serial.print(led_value);
        Serial.print(" ");
        Serial.print(sensor_value_average);
        Serial.println();
    }

}




#endif