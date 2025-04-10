#include <Arduino.h>
#include <Light_sensing_dimmer.h>


//enum modes
//{
//  MANUAL,
//  AUTO
//};


//const uint8_t MODE_BUTTON_PIN = 2;
//const uint8_t POT_PIN = A1;
//
//volatile uint8_t mode = AUTO;
//uint16_t pot_value;



void switch_mode();



Light_sensing_dimmer dimmer_1(A4, 3, 100, 20, 2500, 2, 2, A1);

volatile uint8_t mode = DimmerLib::AUTO;



void setup()
{
  Serial.begin(115200);


  ledcSetup(0, 490, 8);
  ledcAttachPin(dimmer_1.LED_PIN, 0);
  pinMode(dimmer_1.SENSOR_PIN, INPUT);
  pinMode(dimmer_1.MODE_BUTTON_PIN, INPUT_PULLUP);


  attachInterrupt(digitalPinToInterrupt(dimmer_1.MODE_BUTTON_PIN), switch_mode, RISING);
}

void loop()
{
  switch (mode)
  {
  case DimmerLib::MANUAL:
    dimmer_1.pot_value = analogRead(dimmer_1.POT_PIN);
    DimmerLib::mapLed(dimmer_1.led_value, dimmer_1.pot_value, dimmer_1.K);
    ledcWrite(0, dimmer_1.led_value);
    delay(dimmer_1.POLLING_RATE);
    break;
  
  default:
    DimmerLib::measureLight(
      dimmer_1.sensor_value_sum,
      dimmer_1.AVERAGES,
      dimmer_1.SENSOR_PIN,
      dimmer_1.PART_DELAY);
    DimmerLib::averageLight(
      dimmer_1.sensor_value_average,
      dimmer_1.sensor_value_sum,
      dimmer_1.AVERAGES);

    DimmerLib::mapLed(
      dimmer_1.led_value,
      dimmer_1.sensor_value_average,
      dimmer_1.K);
    DimmerLib::writeLed(dimmer_1.led_value);

    DimmerLib::writeSerial(
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
  case DimmerLib::MANUAL:
    mode = DimmerLib::AUTO;
    break;
  
  default:
    mode = DimmerLib::MANUAL;
    break;
  }

}