#include <Arduino.h>
#include <Light_sensing_dimmer.h>



DimmerLib::Light_sensing_dimmer dimmer_1(A4, 6, 5, A3, 0);
DimmerLib::Light_sensing_dimmer dimmer_2(A4, 8, 7, A2, 1);
DimmerLib::Light_sensing_dimmer dimmer_3(A4, 10, 9, A1, 2);
DimmerLib::Light_sensing_dimmer dimmer_4(A4, 21, 20, A1, 3);



void dimmer_1_ISR()
{
  switch (dimmer_1.mode)
  {
    case DimmerLib::MANUAL:
      dimmer_1.mode = DimmerLib::AUTO;
      dimmer_2.mode = DimmerLib::AUTO;
      dimmer_3.mode = DimmerLib::AUTO;
      dimmer_4.mode = DimmerLib::AUTO;
      break;
    default:
      dimmer_1.mode = DimmerLib::MANUAL;
      dimmer_2.mode = DimmerLib::MANUAL;
      dimmer_3.mode = DimmerLib::MANUAL;
      dimmer_4.mode = DimmerLib::MANUAL;
      break;
  }

}




void setup()
{
  Serial.begin(115200);

  DimmerLib::setupDimmer(dimmer_1);
  DimmerLib::setupDimmer(dimmer_2);
  DimmerLib::setupDimmer(dimmer_3);
  DimmerLib::setupDimmer(dimmer_4);

  attachInterrupt(digitalPinToInterrupt(dimmer_1.MODE_BUTTON_PIN), dimmer_1_ISR, RISING);
}

void loop()
{
  DimmerLib::runDimmer(dimmer_1);
  DimmerLib::runDimmer(dimmer_2);
  DimmerLib::runDimmer(dimmer_3);
  DimmerLib::runDimmer(dimmer_4);
}