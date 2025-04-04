#ifndef LIGHT_SENSING_DIMMER_H
#define LIGHT_SENSING_DIMMER_H


#include <Arduino.h>



inline void measureLight(
    uint32_t &sensor_value_sum,
    const uint8_t AVERAGES,
    const uint8_t SENSOR_PIN,
    const uint8_t PART_DELAY);
inline void averageLight(
    uint16_t &sensor_value_average,
    uint32_t sensor_value_sum,
    const uint8_t AVERAGES);
inline void mapLed(uint8_t &led_value, uint16_t sensor_value_average, float k);
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
    
    Light_sensing_dimmer(
        const uint8_t SENSOR_PIN_,
        const uint8_t LED_PIN_,
        const uint8_t POLLING_RATE_,
        const uint8_t AVERAGES_,
        const uint8_t PART_DELAY_,
        float k);
    ~Light_sensing_dimmer();
};




Light_sensing_dimmer::Light_sensing_dimmer
(
    const uint8_t SENSOR_PIN_,
    const uint8_t LED_PIN_,
    const uint8_t POLLING_RATE_,
    const uint8_t AVERAGES_,
    const uint8_t PART_DELAY_,
    float k_
) :
    SENSOR_PIN(SENSOR_PIN_),
    LED_PIN(LED_PIN_),
    POLLING_RATE(POLLING_RATE_),
    AVERAGES(AVERAGES_),
    PART_DELAY(PART_DELAY_),
    DELAY_TIME(POLLING_RATE_ - AVERAGES_ * PART_DELAY_),
    k(k_)
    {}

Light_sensing_dimmer::~Light_sensing_dimmer()
{
}




inline void measureLight(
    uint32_t &sensor_value_sum,
    const uint8_t AVERAGES,
    const uint8_t SENSOR_PIN,
    const uint8_t PART_DELAY)
{
  sensor_value_sum = 0;

  for (int i = 0; i < AVERAGES; i++)
  {
    sensor_value_sum += analogRead(SENSOR_PIN);
    delay(PART_DELAY);
  }
}

inline void averageLight(
    uint16_t &sensor_value_average,
    uint32_t sensor_value_sum,
    const uint8_t AVERAGES)
{
  sensor_value_average = sensor_value_sum / AVERAGES;
}

inline void mapLed(uint8_t &led_value, uint16_t sensor_value_average, float k)
{
  led_value = 255 * pow((float)(sensor_value_average) / 4096, k);
}

inline void writeLed(uint8_t led_value)
{
  ledcWrite(0, led_value);
}

inline void writeSerial(uint8_t led_value, uint16_t sensor_value_average)
{
  Serial.print(led_value);
  Serial.print(" ");
  Serial.print(sensor_value_average);
  Serial.println();
}




#endif