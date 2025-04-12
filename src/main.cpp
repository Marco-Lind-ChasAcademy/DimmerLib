#include <DimmerLib.h>


// Example with one dimmer. Uses default initializers to operate at 100 ms polling rate and anti-flicker at 50-60 Hz
//DimmerLib::LightSensingDimmer dimmer(A4, 6, 5, A3, 0);



// Example with four dimmers. Accuracy of anti-flickering is slightly lowered to have a ~100 ms total loop() and ~50 % duty cycle
DimmerLib::LightSensingDimmer dimmer_1(A4, 6, 5, A3, 0, DimmerLib::AUTO, 2, 12, 20, 625);
DimmerLib::LightSensingDimmer dimmer_2(A4, 8, 7, A2, 1, DimmerLib::AUTO, 2, 12, 20, 625);
DimmerLib::LightSensingDimmer dimmer_3(A4, 10, 9, A1, 2, DimmerLib::AUTO, 2, 12, 20, 625);
DimmerLib::LightSensingDimmer dimmer_4(A4, 21, 20, A0, 3, DimmerLib::AUTO, 2, 12, 20, 625);



// Example simplified ISR macro for a single dimmer
//MAKE_MODE_SWITCH_ISR(dimmer_ISR, dimmer)



// Example custom ISR to control 4 dimmers with the same mode button
void dimmer_ISR()
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

  attachInterrupt(digitalPinToInterrupt(dimmer_1.MODE_BUTTON_PIN), dimmer_ISR, RISING);
}

void loop()
{
  DimmerLib::runDimmer(dimmer_1);
  DimmerLib::runDimmer(dimmer_2);
  DimmerLib::runDimmer(dimmer_3);
  DimmerLib::runDimmer(dimmer_4);
  delay(50); // For power efficiency
}