#include <Arduino.h>
#include <Light_sensing_dimmer.h>



Light_sensing_dimmer dimmer_1(4, 3, 100, 10, 5, 2);



void setup()
{
  ledcSetup(0, 490, 8);
  ledcAttachPin(dimmer_1.LED_PIN, 0);
  pinMode(dimmer_1.SENSOR_PIN, INPUT);
  Serial.begin(115200);
}

void loop()
{
  measureLight(dimmer_1.sensor_value_sum, dimmer_1.AVERAGES, dimmer_1.SENSOR_PIN, dimmer_1.PART_DELAY);
  averageLight(dimmer_1.sensor_value_average, dimmer_1.sensor_value_sum, dimmer_1.AVERAGES);

  mapLed(dimmer_1.led_value, dimmer_1.sensor_value_average, dimmer_1.k);
  writeLed(dimmer_1.led_value);

  writeSerial(dimmer_1.led_value, dimmer_1.sensor_value_average);
  
  delay(dimmer_1.DELAY_TIME);
}