#include <DimmerLib.h>


// Example with four dimmmers connected to the same light sensor, but with individual pots for manual dimming
DimmerLib::LightSensingDimmer dimmer_1(A4, 6, 5, A3, 0);
DimmerLib::LightSensingDimmer dimmer_2(A4, 8, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_3(A4, 10, 9, A1, 2);
DimmerLib::LightSensingDimmer dimmer_4(A4, 21, 20, A0, 3);


// Example with an ISR for dimmer_1
MAKE_MODE_SWITCH_ISR(dimmer_1_ISR, dimmer_1)



void setup()
{
  Serial.begin(115200);

  DimmerLib::semInit(); // Initializing the pin semaphores

  attachInterrupt(digitalPinToInterrupt(dimmer_1.MODE_BUTTON_PIN), dimmer_1_ISR, RISING);

  xTaskCreate(DimmerLib::runDimmerTask, "Dimmer 1", 1024, &dimmer_1, configMAX_PRIORITIES - 1, NULL);
  xTaskCreate(DimmerLib::runDimmerTask, "Dimmer 2", 1024, &dimmer_2, configMAX_PRIORITIES - 1, NULL);
  xTaskCreate(DimmerLib::runDimmerTask, "Dimmer 3", 1024, &dimmer_3, configMAX_PRIORITIES - 1, NULL);
  xTaskCreate(DimmerLib::runDimmerTask, "Dimmer 4", 1024, &dimmer_4, configMAX_PRIORITIES - 1, NULL);
}

void loop()
{
}