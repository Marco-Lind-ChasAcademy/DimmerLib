#include <DimmerLib.h>


// Example with four dimmmers connected to the same light sensor, but with individual pots for manual dimming
DimmerLib::LightSensingDimmer dimmer_0(A4, 6, 5, 7, A3, 0);
DimmerLib::LightSensingDimmer dimmer_1(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_2(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_3(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_4(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_5(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_6(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_7(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_8(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_9(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_10(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_11(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_12(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_13(A4, 21, 20, 10, A0, 3);


// Example with mode switch ISR:s for all the dimmers
MAKE_MODE_SWITCH_ISR(dimmer_0_mode_ISR, dimmer_0)
MAKE_MODE_SWITCH_ISR(dimmer_1_mode_ISR, dimmer_1)
MAKE_MODE_SWITCH_ISR(dimmer_2_mode_ISR, dimmer_2)
MAKE_MODE_SWITCH_ISR(dimmer_3_mode_ISR, dimmer_3)
MAKE_MODE_SWITCH_ISR(dimmer_4_mode_ISR, dimmer_4)
MAKE_MODE_SWITCH_ISR(dimmer_5_mode_ISR, dimmer_5)
MAKE_MODE_SWITCH_ISR(dimmer_6_mode_ISR, dimmer_6)
MAKE_MODE_SWITCH_ISR(dimmer_7_mode_ISR, dimmer_7)
MAKE_MODE_SWITCH_ISR(dimmer_8_mode_ISR, dimmer_8)
MAKE_MODE_SWITCH_ISR(dimmer_9_mode_ISR, dimmer_9)
MAKE_MODE_SWITCH_ISR(dimmer_10_mode_ISR, dimmer_10)
MAKE_MODE_SWITCH_ISR(dimmer_11_mode_ISR, dimmer_11)
MAKE_MODE_SWITCH_ISR(dimmer_12_mode_ISR, dimmer_12)
MAKE_MODE_SWITCH_ISR(dimmer_13_mode_ISR, dimmer_13)


// Example with debug ISR:s for all the dimmers
MAKE_DEBUG_SWITCH_ISR(dimmer_0_debug_ISR, dimmer_0)
MAKE_DEBUG_SWITCH_ISR(dimmer_1_debug_ISR, dimmer_1)
MAKE_DEBUG_SWITCH_ISR(dimmer_2_debug_ISR, dimmer_2)
MAKE_DEBUG_SWITCH_ISR(dimmer_3_debug_ISR, dimmer_3)
MAKE_DEBUG_SWITCH_ISR(dimmer_4_debug_ISR, dimmer_4)
MAKE_DEBUG_SWITCH_ISR(dimmer_5_debug_ISR, dimmer_5)
MAKE_DEBUG_SWITCH_ISR(dimmer_6_debug_ISR, dimmer_6)
MAKE_DEBUG_SWITCH_ISR(dimmer_7_debug_ISR, dimmer_7)
MAKE_DEBUG_SWITCH_ISR(dimmer_8_debug_ISR, dimmer_8)
MAKE_DEBUG_SWITCH_ISR(dimmer_9_debug_ISR, dimmer_9)
MAKE_DEBUG_SWITCH_ISR(dimmer_10_debug_ISR, dimmer_10)
MAKE_DEBUG_SWITCH_ISR(dimmer_11_debug_ISR, dimmer_11)
MAKE_DEBUG_SWITCH_ISR(dimmer_12_debug_ISR, dimmer_12)
MAKE_DEBUG_SWITCH_ISR(dimmer_13_debug_ISR, dimmer_13)



void setup()
{
  Serial.begin(115200);

  DimmerLib::semInit(); // Initializing the serial semaphore

  attachInterrupt(digitalPinToInterrupt(dimmer_0.MODE_BUTTON_PIN), dimmer_0_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_1.MODE_BUTTON_PIN), dimmer_1_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_2.MODE_BUTTON_PIN), dimmer_2_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_3.MODE_BUTTON_PIN), dimmer_3_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_4.MODE_BUTTON_PIN), dimmer_4_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_5.MODE_BUTTON_PIN), dimmer_5_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_6.MODE_BUTTON_PIN), dimmer_6_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_7.MODE_BUTTON_PIN), dimmer_7_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_8.MODE_BUTTON_PIN), dimmer_8_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_9.MODE_BUTTON_PIN), dimmer_9_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_10.MODE_BUTTON_PIN), dimmer_10_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_11.MODE_BUTTON_PIN), dimmer_11_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_12.MODE_BUTTON_PIN), dimmer_12_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_13.MODE_BUTTON_PIN), dimmer_13_mode_ISR, RISING);

  attachInterrupt(digitalPinToInterrupt(dimmer_0.DEBUG_BUTTON_PIN), dimmer_0_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_1.DEBUG_BUTTON_PIN), dimmer_1_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_2.DEBUG_BUTTON_PIN), dimmer_2_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_3.DEBUG_BUTTON_PIN), dimmer_3_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_4.DEBUG_BUTTON_PIN), dimmer_4_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_5.DEBUG_BUTTON_PIN), dimmer_5_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_6.DEBUG_BUTTON_PIN), dimmer_6_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_7.DEBUG_BUTTON_PIN), dimmer_7_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_8.DEBUG_BUTTON_PIN), dimmer_8_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_9.DEBUG_BUTTON_PIN), dimmer_9_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_10.DEBUG_BUTTON_PIN), dimmer_10_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_11.DEBUG_BUTTON_PIN), dimmer_11_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_12.DEBUG_BUTTON_PIN), dimmer_12_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_13.DEBUG_BUTTON_PIN), dimmer_13_debug_ISR, RISING);

  INITIATE_DIMMER_TASK(dimmer_0, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_1, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_2, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_3, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_4, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_5, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_6, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_7, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_8, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_9, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_10, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_11, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_12, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_13, configMAX_PRIORITIES - 1);
}

void loop()
{
}