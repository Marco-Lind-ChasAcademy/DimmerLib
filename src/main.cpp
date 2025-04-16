#include <DimmerLib.h>


// Example with four dimmmers connected to the same light sensor, but with individual pots for manual dimming
DimmerLib::LightSensingDimmer dimmer_0(A4, 6, 5, 7, A3, 0);
DimmerLib::LightSensingDimmer dimmer_1(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_2(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_3(A4, 21, 20, 10, A0, 3);


// Example with an ISR:s for all the dimmers
MAKE_MODE_SWITCH_ISR(dimmer_0_mode_ISR, dimmer_0)
MAKE_MODE_SWITCH_ISR(dimmer_1_mode_ISR, dimmer_1)
MAKE_MODE_SWITCH_ISR(dimmer_2_mode_ISR, dimmer_2)
MAKE_MODE_SWITCH_ISR(dimmer_3_mode_ISR, dimmer_3)



MAKE_DEBUG_SWITCH_ISR(dimmer_0_debug_ISR, dimmer_0)
MAKE_DEBUG_SWITCH_ISR(dimmer_1_debug_ISR, dimmer_1)
MAKE_DEBUG_SWITCH_ISR(dimmer_2_debug_ISR, dimmer_2)
MAKE_DEBUG_SWITCH_ISR(dimmer_3_debug_ISR, dimmer_3)



void setup()
{
  Serial.begin(115200);

  DimmerLib::semInit(); // Initializing the serial semaphore

  attachInterrupt(digitalPinToInterrupt(dimmer_0.MODE_BUTTON_PIN), dimmer_0_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_1.MODE_BUTTON_PIN), dimmer_1_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_2.MODE_BUTTON_PIN), dimmer_2_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_3.MODE_BUTTON_PIN), dimmer_3_mode_ISR, RISING);

  attachInterrupt(digitalPinToInterrupt(dimmer_0.DEBUG_BUTTON_PIN), dimmer_0_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_1.DEBUG_BUTTON_PIN), dimmer_1_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_2.DEBUG_BUTTON_PIN), dimmer_2_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_3.DEBUG_BUTTON_PIN), dimmer_3_debug_ISR, RISING);

  xTaskCreate(DimmerLib::runDimmerTask, "Dimmer 0", 4096, &dimmer_0, configMAX_PRIORITIES - 1, NULL);
  vTaskDelay(2);
  xTaskCreate(DimmerLib::runDimmerTask, "Dimmer 1", 4096, &dimmer_1, configMAX_PRIORITIES - 1, NULL);
  vTaskDelay(2);
  xTaskCreate(DimmerLib::runDimmerTask, "Dimmer 2", 4096, &dimmer_2, configMAX_PRIORITIES - 1, NULL);
  vTaskDelay(2);
  xTaskCreate(DimmerLib::runDimmerTask, "Dimmer 3", 4096, &dimmer_3, configMAX_PRIORITIES - 1, NULL);
}

void loop()
{
}