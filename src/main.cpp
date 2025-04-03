#include <Arduino.h>

const uint8_t SENSOR = A4;
const uint8_t LED = 3;
const uint8_t DELAY_TIME = 100;
const uint8_t AVERAGES = 5;
const uint8_t PART_DELAY = DELAY_TIME / AVERAGES;

uint32_t sensor_value_sum;
uint16_t sensor_value_average;
uint8_t led_value;

void setup()
{
  pinMode(SENSOR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  sensor_value_sum = 0;

  for (int i = 0; i < AVERAGES; i++)
  {
    sensor_value_sum += analogRead(SENSOR);
    delay(PART_DELAY);
  }
  

  sensor_value_average = sensor_value_sum / AVERAGES;
  
  led_value = map(sensor_value_average, 0, 16383, 0, 255);
  analogWrite(LED, led_value);
}