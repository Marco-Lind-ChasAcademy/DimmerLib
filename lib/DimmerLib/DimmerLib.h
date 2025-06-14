#ifndef DIMMERLIB_H
#define DIMMERLIB_H

#define pdUS_TO_TICKS(xTimeInUs) ( ( TickType_t ) ( ( ( TickType_t ) ( xTimeInUs ) * ( TickType_t ) configTICK_RATE_HZ ) / ( TickType_t ) 1000000U ) )


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
    DimmerLib::current_time_ms = millis(); \
    \
    if (DimmerLib::current_time_ms - DimmerLib::last_mode_button_press_ms > 200) \
    { \
        DimmerLib::last_mode_button_press_ms = DimmerLib::current_time_ms; \
         \
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
    } \
   \
}

/**
 * @brief Macro to create a debug ISR that toggles switches serial prints on or off.
 * 
 * @param ISR_NAME Desired name for the ISR function.
 * @param DIMMER_OBJECT Instance of LightSensingDimmer to operate on.
 */
#define MAKE_DEBUG_SWITCH_ISR(ISR_NAME, DIMMER_OBJECT) \
void ISR_NAME() \
{ \
    DimmerLib::current_time_ms = millis(); \
    \
    if (DimmerLib::current_time_ms - DimmerLib::last_debug_button_press_ms > 200) \
    { \
        DimmerLib::last_debug_button_press_ms = DimmerLib::current_time_ms; \
         \
        switch (DimmerLib::debug_mode) \
        { \
        case 1: \
            DimmerLib::debug_mode = 0; \
            break; \
         \
        default: \
            DimmerLib::debug_mode = 1; \
            break; \
        } \
    } \
   \
}

/**
 * @brief Macro to dimmer task.
 * 
 * @param DIMMER_OBJECT Instance of LightSensingDimmer to operate on.
 */
#define INITIATE_DIMMER_TASK(DIMMER_OBJECT, PRIORITY) \
xTaskCreate(DimmerLib::runDimmerTask, #DIMMER_OBJECT, 1024, &DIMMER_OBJECT, PRIORITY, NULL);



namespace DimmerLib
{
    uint64_t last_micros;
    uint64_t current_micros;
    uint64_t interval_micros;
    
    SemaphoreHandle_t semaphore_serial = xSemaphoreCreateBinary();
    uint32_t last_mode_button_press_ms = 0;
    uint32_t last_debug_button_press_ms = 0;
    uint32_t current_time_ms;
    
    volatile uint8_t debug_mode = 0;
    uint8_t dimmer_id = 0;
    enum modes : uint8_t { MANUAL, AUTO };;

    /**
     * @brief Light-sensing dimmer class.
     * 
     * This class manages automatic and manual LED brightness control
     * based on ambient light or a potentiometer.
     */
    class LightSensingDimmer
    {
    public:
        uint32_t sensor_value_sum;
        const float K;

        const uint16_t POLLING_RATE;
        const uint16_t PART_DELAY;
        const uint16_t DELAY_TIME;
        uint16_t pot_value;
        uint16_t sensor_value_average;

        const uint8_t SENSOR_PIN;
        const uint8_t LED_PIN;
        const uint8_t AVERAGES;
        const uint8_t MODE_BUTTON_PIN;
        const uint8_t DEBUG_BUTTON_PIN;
        const uint8_t POT_PIN;
        const uint8_t CHANNEL;
        volatile uint8_t mode;
        uint8_t led_value;
        const uint8_t ID;
        uint8_t state;
        uint8_t counter;

        /**
         * @brief Constructor to initialize a LightSensingDimmer object.
         * 
         * Sets up pins, PWM output, and initial configuration.
         * 
         * @param SENSOR_PIN_ Analog pin to read light levels.
         * @param LED_PIN_ PWM-capable pin connected to the LED.
         * @param MODE_BUTTON_PIN_ Digital pin connected to mode toggle button (INPUT_PULLUP).
         * @param DEBUG_BUTTON_PIN_ Digital pin connected to debug toggle button (INPUT_PULLUP).
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
            const uint8_t DEBUG_BUTTON_PIN_,
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
        const uint8_t DEBUG_BUTTON_PIN_,
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
        mode(mode_), CHANNEL(CHANNEL_), ID(dimmer_id++),
        DEBUG_BUTTON_PIN(DEBUG_BUTTON_PIN_), sensor_value_sum(0)
    {
        ledcSetup(CHANNEL, 490, 8);
        ledcAttachPin(LED_PIN, CHANNEL);
        pinMode(SENSOR_PIN, INPUT);
        pinMode(MODE_BUTTON_PIN, INPUT_PULLUP);
        pinMode(DEBUG_BUTTON_PIN, INPUT_PULLUP);
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
    inline void averageLight(uint16_t &sensor_value_average, uint32_t &sensor_value_sum, const uint8_t AVERAGES);

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
    inline void writeSerial(LightSensingDimmer &dimmer);

    /**
     * @brief Main control loop for the dimmer. Should be called repeatedly in loop().
     * 
     * - AUTO mode: Measures ambient light and adjusts LED brightness.
     * - MANUAL mode: Uses potentiometer value to set LED brightness.
     * 
     * @param dimmer Reference to a LightSensingDimmer object.
     */
    void runDimmer(LightSensingDimmer& dimmer);

    /**
     * @brief FreeRTOS task for runDimmer()
     * 
     * @param pvParameter pvParameter for xTaskCreate()
     */
    void runDimmerTask(void *pvParameter);

    /**
     * @brief Writes serial output in thread-safe manner
     * 
     * @param led_value Dimmer object LED output value
     * @param sensor_value_average Dimmer object average sensor value
     */
    void writeSerialSafe(LightSensingDimmer &dimmer);

    /**
     * @brief Initializes semaphores
     * 
     */
    void semInit();
    
    void runDimmerCoro(LightSensingDimmer& dimmer);

    void delays(LightSensingDimmer& dimmer, uint64_t time_taken);



    void delays(LightSensingDimmer& dimmer, uint64_t time_taken)
    {
        switch (dimmer.mode)
        {
        case MANUAL:
            delay((dimmer.POLLING_RATE * 1000 - time_taken) / 1000);
            
            /* Serial.print("Manual dimming done. Slept for ");
            Serial.print((dimmer.POLLING_RATE * 1000 - time_taken) / 1000);
            Serial.println("ms..."); */
            
            
            break;
            
        case AUTO:
            switch (dimmer.state)
            {
            case 0:
                while (dimmer.PART_DELAY - time_taken >= 1000)
                {
                    delay(1);
                    current_micros = micros();
                    time_taken = current_micros - last_micros;
                }
                delayMicroseconds(dimmer.PART_DELAY - time_taken);
              
                /* Serial.print("Measurements done. Slept for ");
                Serial.print(dimmer.PART_DELAY - time_taken);
                Serial.println("us..."); */
              
                break;
              
            case 1:
                delay((dimmer.DELAY_TIME * 1000 - time_taken) / 1000);
                
                /* Serial.print("Dimming done. Slept for ");
                Serial.print((dimmer.DELAY_TIME * 1000 - time_taken) / 1000);
                Serial.println("ms..."); */
                
                break;

            case 2:
                //Serial.println("Everything done. Now restarting...\n");

                break;
            
            default:
                Serial.println("Invalid state");
                
                break;
            }
          
            break;
          
        default:
            Serial.println("Invalid mode.");
            
            break;
        }
    }

    void semInit()
    {
        xSemaphoreGive(semaphore_serial);
    }

    void writeSerialSafe(LightSensingDimmer &dimmer)
    {
        if (xSemaphoreTake(semaphore_serial, portMAX_DELAY) == pdTRUE)
        {
            writeSerial(dimmer);

            xSemaphoreGive(semaphore_serial);
        }
    }

    void runDimmerTask(void *pvParameter)
    {
        DimmerLib::LightSensingDimmer *dimmer = (DimmerLib::LightSensingDimmer *)pvParameter;

        vTaskDelay(pdUS_TO_TICKS((dimmer->POLLING_RATE * 1000) / (DimmerLib::dimmer_id + 1)) * dimmer->ID);
        
        while (1)
        {
            DimmerLib::runDimmer(*dimmer);
        }
      
    }

    void runDimmer(LightSensingDimmer& dimmer)
    {
        switch (dimmer.mode)
        {
        case MANUAL:
            dimmer.pot_value = analogRead(dimmer.POT_PIN);
            mapLed(dimmer.led_value, dimmer.pot_value, dimmer.K);
            ledcWrite(dimmer.CHANNEL, dimmer.led_value);
            delay(dimmer.POLLING_RATE);
            
            break;
        
        default:
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
            ledcWrite(dimmer.CHANNEL, dimmer.led_value);

            if (debug_mode)
            {
                writeSerialSafe(dimmer);
            }
            
            delay(dimmer.DELAY_TIME);
            
            break;
        }
    }

    void runDimmerCoro(LightSensingDimmer& dimmer)
    {
        switch (dimmer.mode)
        {
        case MANUAL:
            dimmer.pot_value = analogRead(dimmer.POT_PIN);
            mapLed(dimmer.led_value, dimmer.pot_value, dimmer.K);
            ledcWrite(dimmer.CHANNEL, dimmer.led_value);
            
            break;
        
        default:
            switch (dimmer.state)
            {
            case 0:
                restart:
                if (dimmer.counter < dimmer.AVERAGES)
                {
                    measureLight
                    (
                        dimmer.sensor_value_sum,
                        dimmer.AVERAGES,
                        dimmer.SENSOR_PIN,
                        dimmer.PART_DELAY
                    );

                    /* Serial.print("Dimmer ");
                    Serial.print(dimmer.ID);
                    Serial.print(": Measurement ");
                    Serial.print(dimmer.counter);
                    Serial.print(" is DONE, sensor_value_sum: ");
                    Serial.println(dimmer.sensor_value_sum); */

                    dimmer.counter += 1;
                    
                    return;
                }

                dimmer.counter = 0;
                dimmer.state = 1;

                /* Serial.print("Dimmer ");
                Serial.print(dimmer.ID);
                Serial.println(": Case 0 is DONE"); */
                
            case 1:
                if (dimmer.counter < 1)
                {
                    averageLight(
                        dimmer.sensor_value_average,
                        dimmer.sensor_value_sum,
                        dimmer.AVERAGES);
                    mapLed(
                        dimmer.led_value,
                        dimmer.sensor_value_average,
                        dimmer.K);
                    ledcWrite(dimmer.CHANNEL, dimmer.led_value);
    
                    if (debug_mode)
                    {
                        writeSerial(dimmer);
                    }

                    dimmer.counter += 1;

                    /* Serial.print("Dimmer ");
                    Serial.print(dimmer.ID);
                    Serial.println(": Case 1 subtasks are DONE"); */

                    return;
                }

                dimmer.counter = 0;
                
                /* Serial.print("Dimmer ");
                Serial.print(dimmer.ID);
                Serial.println(": Case 1 is DONE"); */

                dimmer.state = 2;

                break;

            case 2:
                /* Serial.print("Dimmer ");
                Serial.print(dimmer.ID);
                Serial.println(": Case 2 is DONE"); */

                dimmer.state = 0;

                goto restart;

                break;

            default:
                /* Serial.print("Invalid state, dimmer: ");
                Serial.println(dimmer.ID); */

                break;
            }
            
            break;
        }
    }
    
    inline void measureLight(uint32_t &sensor_value_sum, const uint8_t AVERAGES, const uint8_t SENSOR_PIN, const uint16_t PART_DELAY)
    {
        sensor_value_sum += analogRead(SENSOR_PIN);
    }
    
    inline void averageLight(uint16_t &sensor_value_average, uint32_t &sensor_value_sum, const uint8_t AVERAGES)
    {
        sensor_value_average = sensor_value_sum / AVERAGES;
        /* Serial.print("sensor_value_average = ");
        Serial.println(sensor_value_average); */
        sensor_value_sum = 0;
    }
    
    inline void mapLed(uint8_t &led_value, uint16_t sensor_value_average, const float K)
    {
        led_value = 255 * pow((float)(sensor_value_average) / 4096, K);
    }
    
    inline void writeLed(LightSensingDimmer &dimmer)
    {
        ledcWrite(dimmer.CHANNEL, dimmer.led_value);
    }
    
    inline void writeSerial(LightSensingDimmer &dimmer)
    {
        Serial.print("Dimmer ID: ");
        Serial.print(dimmer.ID);
        Serial.print(":    LED value: ");
        Serial.print(dimmer.led_value);
        Serial.print("    Sensor value: ");
        Serial.print(dimmer.sensor_value_average);
        Serial.println();
    }

}

#endif