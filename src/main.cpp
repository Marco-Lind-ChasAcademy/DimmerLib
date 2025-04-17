#include <DimmerLib.h>


// Example with three LED:s controlled by the same light sensor, but with individual pots for manual dimming
DimmerLib::LightSensingDimmer dimmer_0(A4, 6, 5, 7, A3, 0);
DimmerLib::LightSensingDimmer dimmer_1(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_2(A4, 21, 20, 7, A1, 2);


// Example with mode switch ISR:s for all the dimmer objects
MAKE_MODE_SWITCH_ISR(dimmer_0_mode_ISR, dimmer_0)
MAKE_MODE_SWITCH_ISR(dimmer_1_mode_ISR, dimmer_1)
MAKE_MODE_SWITCH_ISR(dimmer_2_mode_ISR, dimmer_2)


// Example with debug ISR. Only one is needed since all dimmer objects here use the same debug pin
MAKE_DEBUG_SWITCH_ISR(dimmer_0_debug_ISR, dimmer_0)



void setup()
{
  Serial.begin(115200);

  DimmerLib::semInit(); // Initializing the serial semaphore

  attachInterrupt(digitalPinToInterrupt(dimmer_0.MODE_BUTTON_PIN), dimmer_0_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_1.MODE_BUTTON_PIN), dimmer_1_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_2.MODE_BUTTON_PIN), dimmer_2_mode_ISR, RISING);

  attachInterrupt(digitalPinToInterrupt(dimmer_0.DEBUG_BUTTON_PIN), dimmer_0_debug_ISR, RISING);

  // Macros for simplified dimmer initialization
  INITIATE_DIMMER_TASK(dimmer_0, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_1, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_2, configMAX_PRIORITIES - 1);
}

void loop()
{
}