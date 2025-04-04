#ifndef LIGHT_SENSING_DIMMER_H
#define LIGHT_SENSING_DIMMER_H


#include <Arduino.h>


inline void measureLight(
    uint32_t sensor_value_sum,
    const uint8_t AVERAGES,
    const uint8_t SENSOR_PIN,
    const uint8_t PART_DELAY);
inline void averageLight(
    uint16_t sensor_value_average,
    uint32_t sensor_value_sum,
    const uint8_t AVERAGES);
inline void mapLed(uint8_t led_value, uint16_t sensor_value_average, float k);
inline void writeLed(uint8_t led_value);
inline void writeSerial(uint8_t led_value, uint16_t sensor_value_average);


class Light_sensing_dimmer
{
public:
    const uint8_t SENSOR_PIN;
    const uint8_t LED_PIN;
    const uint8_t POLLING_RATE;
    const uint8_t AVERAGES;
    const uint8_t PART_DELAY;
    const uint8_t DELAY_TIME;

    uint32_t sensor_value_sum;
    uint16_t sensor_value_average;
    uint8_t led_value;
    float k = 2;  // You can adjust this value to make the transition sharper or smoother
    
    Light_sensing_dimmer(const uint8_t SENSOR_PIN_,
                         const uint8_t LED_PIN_,
                         const uint8_t POLLING_RATE_,
                         const uint8_t AVERAGES_,
                         const uint8_t PART_DELAY_,
                         float k);
    ~Light_sensing_dimmer();
};


#endif