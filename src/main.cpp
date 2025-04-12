#include <DimmerLib.h>


DimmerLib::LightSensingDimmer dimmer_1(A4, 6, 5, A3, 0);
DimmerLib::LightSensingDimmer dimmer_2(A4, 8, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_3(A4, 10, 9, A1, 2);
DimmerLib::LightSensingDimmer dimmer_4(A4, 21, 20, A0, 3);



MAKE_MODE_SWITCH_ISR(dimmer_1_ISR, dimmer_1)



void runDimmerTask(void *pvParameter);



void setup()
{
  Serial.begin(115200);

  //while (!Serial) delay(10);

  attachInterrupt(digitalPinToInterrupt(dimmer_1.MODE_BUTTON_PIN), dimmer_1_ISR, RISING);

  xTaskCreate(runDimmerTask, "Dimmer 1", 1024, &dimmer_1, configMAX_PRIORITIES - 1, NULL);
  xTaskCreate(runDimmerTask, "Dimmer 2", 1024, &dimmer_2, configMAX_PRIORITIES - 1, NULL);
  xTaskCreate(runDimmerTask, "Dimmer 3", 1024, &dimmer_3, configMAX_PRIORITIES - 1, NULL);
  xTaskCreate(runDimmerTask, "Dimmer 4", 1024, &dimmer_4, configMAX_PRIORITIES - 1, NULL);
}

void loop()
{
}



void runDimmerTask(void *pvParameter)
{
  DimmerLib::LightSensingDimmer *dimmer_1 = (DimmerLib::LightSensingDimmer *)pvParameter;

  while (1)
  {
    DimmerLib::runDimmer(*dimmer_1);
  }
  
}