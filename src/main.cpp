#include <Arduino.h>
#include <Light_sensing_dimmer.h>



DimmerLib::Light_sensing_dimmer dimmer_1(A4, 3, 100, 20, 2500, 2, 2, A1);



MAKE_MODE_SWITCH_ISR(dimmer_1_ISR, dimmer_1)



void setup()
{
  Serial.begin(115200);

  DimmerLib::setupDimmer(dimmer_1, 0);

  attachInterrupt(digitalPinToInterrupt(dimmer_1.MODE_BUTTON_PIN), dimmer_1_ISR, RISING);
}

void loop()
{
  DimmerLib::runDimmer(dimmer_1);
}