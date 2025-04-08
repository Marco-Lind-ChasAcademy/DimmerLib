#include <Arduino.h>
#include <Light_sensing_dimmer.h>


enum modes
{
  MANUAL,
  AUTO
};


const uint8_t MODE_BUTTON_PIN = 2;
volatile uint8_t mode = AUTO;



void switch_mode();



Light_sensing_dimmer dimmer_1(A4, 3, 100, 20, 2500, 2);



void setup()
{
  ledcSetup(0, 490, 8);
  ledcAttachPin(dimmer_1.LED_PIN, 0);
  pinMode(dimmer_1.SENSOR_PIN, INPUT);

  Serial.begin(115200);

  pinMode(MODE_BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(MODE_BUTTON_PIN), switch_mode, RISING);
}

void loop()
{
  switch (mode)
  {
  case MANUAL:
    ledcWrite(0, 255);
    delay(dimmer_1.POLLING_RATE);
    break;
  
  default:
    measureLight(
      dimmer_1.sensor_value_sum,
      dimmer_1.AVERAGES,
      dimmer_1.SENSOR_PIN,
      dimmer_1.PART_DELAY);
    averageLight(
      dimmer_1.sensor_value_average,
      dimmer_1.sensor_value_sum,
      dimmer_1.AVERAGES);

    mapLed(
      dimmer_1.led_value,
      dimmer_1.sensor_value_average,
      dimmer_1.K);
    writeLed(dimmer_1.led_value);

    writeSerial(
      dimmer_1.led_value,
      dimmer_1.sensor_value_average);

    delay(dimmer_1.DELAY_TIME);
    break;
  }
}



void switch_mode()
{
  switch (mode)
  {
  case MANUAL:
    mode = AUTO;
    break;
  
  default:
    mode = MANUAL;
    break;
  }

}