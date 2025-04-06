#ifndef LIGHT_SENSING_DIMMER_H
#define LIGHT_SENSING_DIMMER_H


#include <Arduino.h>



inline void measureLight(
    uint32_t &sensor_value_sum,
    const uint8_t AVERAGES,
    const uint8_t SENSOR_PIN,
    const uint16_t PART_DELAY);
inline void averageLight(uint16_t &sensor_value_average, uint32_t sensor_value_sum, const uint8_t AVERAGES);
inline void mapLed(uint8_t &led_value, uint16_t sensor_value_average, const float K);
inline void writeLed(uint8_t led_value);
inline void writeSerial(uint8_t led_value, uint16_t sensor_value_average);



/**
 * @brief Light sensing dimmer object. Initialize with member values
 * 
 * @param SENSOR_PIN_ Analog pin to read the light level from
 * @param LED_PIN_ Digital pin for the dimmable LED
 * @param POLLING_RATE_ Rate in ms at which the LED updates the light level
 * @param AVERAGES_ Number of measuring points
 * @param PART_DELAY_ Delay in microseconds between each measuring point
 * @param K_ Constant for the rate of change in the LED brightness
 */
class Light_sensing_dimmer
{
public:
    const uint8_t SENSOR_PIN;
    const uint8_t LED_PIN;
    const uint8_t POLLING_RATE;
    const uint8_t AVERAGES;
    const uint16_t PART_DELAY;
    const uint8_t DELAY_TIME;

    uint32_t sensor_value_sum;
    uint16_t sensor_value_average;
    uint8_t led_value;
    const float K = 2;  // You can adjust this value to make the transition sharper or smoother
    
    /**
     * @param SENSOR_PIN_ Analog pin to read the light level from
     * @param LED_PIN_ Digital pin for the dimmable LED
     * @param POLLING_RATE_ Rate in ms at which the LED updates the light level
     * @param AVERAGES_ Number of measuring points
     * @param PART_DELAY_ Delay in microseconds between each measuring point
     * @param K_ Constant for the rate of change in the LED brightness
     */
    Light_sensing_dimmer(
        const uint8_t SENSOR_PIN_,
        const uint8_t LED_PIN_,
        const uint8_t POLLING_RATE_,
        const uint8_t AVERAGES_,
        const uint16_t PART_DELAY_,
        const float K);
    ~Light_sensing_dimmer();
};




Light_sensing_dimmer::Light_sensing_dimmer
(
    const uint8_t SENSOR_PIN_,
    const uint8_t LED_PIN_,
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
    K(K_)
    {}

Light_sensing_dimmer::~Light_sensing_dimmer()
{
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
inline void writeLed(uint8_t led_value)
{
    ledcWrite(0, led_value);
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




#endif