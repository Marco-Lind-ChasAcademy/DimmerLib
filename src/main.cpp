#include <Arduino.h>
#include <Light_sensing_dimmer.h>



void switch_mode();



DimmerLib::Light_sensing_dimmer dimmer_1(A4, 3, 100, 20, 2500, 2, 2, A1);



volatile uint8_t mode = DimmerLib::AUTO;



void setup()
{
  Serial.begin(115200);

  DimmerLib::setupDimmer(dimmer_1, 0);

  attachInterrupt(digitalPinToInterrupt(dimmer_1.MODE_BUTTON_PIN), switch_mode, RISING);
}

void loop()
{
  DimmerLib::runDimmer(dimmer_1, mode);
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