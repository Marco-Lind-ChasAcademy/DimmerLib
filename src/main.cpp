#include <Arduino.h>

const uint8_t SENSOR = A4;
const uint8_t LED = 3;
const uint8_t POLLING_RATE = 100;
const uint8_t AVERAGES = 10;
const uint8_t PART_DELAY = 5;
const uint8_t DELAY_TIME = POLLING_RATE - AVERAGES * PART_DELAY;

uint32_t sensor_value_sum;
uint16_t sensor_value_average;
uint8_t led_value;
float k = 2;  // You can adjust this value to make the transition sharper or smoother

void setup()
{
  ledcSetup(0, 490, 8);
  ledcAttachPin(LED, 0);
  pinMode(SENSOR, INPUT);
  Serial.begin(115200);
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
  
  
  led_value = 255 * pow((float)(sensor_value_average) / 4096, k);

  Serial.print(led_value);
  Serial.print(" ");
  Serial.print(sensor_value_average);
  Serial.println();
  ledcWrite(0, led_value);


  delay(DELAY_TIME);
}