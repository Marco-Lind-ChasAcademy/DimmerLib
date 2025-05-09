#include <DimmerLib.h>


DimmerLib::LightSensingDimmer dimmer_0(A4, 6, 5, 7, A3, 0);
DimmerLib::LightSensingDimmer dimmer_1(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_2(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_3(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_4(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_5(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_6(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_7(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_8(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_9(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_10(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_11(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_12(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_13(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_14(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_15(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_16(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_17(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_18(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_19(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_20(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_21(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_22(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_23(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_24(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_25(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_26(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_27(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_28(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_29(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_30(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_31(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_32(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_33(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_34(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_35(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_36(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_37(A4, 8, 9, 7, A2, 1);
DimmerLib::LightSensingDimmer dimmer_38(A4, 21, 20, 7, A1, 2);
DimmerLib::LightSensingDimmer dimmer_39(A4, 21, 20, 7, A1, 2);


// Example with mode switch ISR:s for all the dimmer objects
MAKE_MODE_SWITCH_ISR(dimmer_0_mode_ISR, dimmer_0)


// Example with debug ISR. Only one is needed since all dimmer objects here use the same debug pin
MAKE_DEBUG_SWITCH_ISR(dimmer_0_debug_ISR, dimmer_0)



void setup()
{
  Serial.begin(115200);

  DimmerLib::semInit(); // Initializing the serial semaphore

  attachInterrupt(digitalPinToInterrupt(dimmer_0.MODE_BUTTON_PIN), dimmer_0_mode_ISR, RISING);

  attachInterrupt(digitalPinToInterrupt(dimmer_0.DEBUG_BUTTON_PIN), dimmer_0_debug_ISR, RISING);
}

void loop()
{
  DimmerLib::last_micros = micros();

  DimmerLib::runDimmer(dimmer_0);
  DimmerLib::runDimmer(dimmer_1);
  DimmerLib::runDimmer(dimmer_2);
  DimmerLib::runDimmer(dimmer_3);
  DimmerLib::runDimmer(dimmer_4);
  DimmerLib::runDimmer(dimmer_5);
  DimmerLib::runDimmer(dimmer_6);
  DimmerLib::runDimmer(dimmer_7);
  DimmerLib::runDimmer(dimmer_8);
  DimmerLib::runDimmer(dimmer_9);
  DimmerLib::runDimmer(dimmer_10);
  DimmerLib::runDimmer(dimmer_11);
  DimmerLib::runDimmer(dimmer_12);
  DimmerLib::runDimmer(dimmer_13);
  DimmerLib::runDimmer(dimmer_14);
  DimmerLib::runDimmer(dimmer_15);
  DimmerLib::runDimmer(dimmer_16);
  DimmerLib::runDimmer(dimmer_17);
  DimmerLib::runDimmer(dimmer_18);
  DimmerLib::runDimmer(dimmer_19);
  DimmerLib::runDimmer(dimmer_20);
  DimmerLib::runDimmer(dimmer_21);
  DimmerLib::runDimmer(dimmer_22);
  DimmerLib::runDimmer(dimmer_23);
  DimmerLib::runDimmer(dimmer_24);
  DimmerLib::runDimmer(dimmer_25);
  DimmerLib::runDimmer(dimmer_26);
  DimmerLib::runDimmer(dimmer_27);
  DimmerLib::runDimmer(dimmer_28);
  DimmerLib::runDimmer(dimmer_29);
  DimmerLib::runDimmer(dimmer_30);
  DimmerLib::runDimmer(dimmer_31);
  DimmerLib::runDimmer(dimmer_32);
  DimmerLib::runDimmer(dimmer_33);
  DimmerLib::runDimmer(dimmer_34);
  DimmerLib::runDimmer(dimmer_35);
  DimmerLib::runDimmer(dimmer_36);
  DimmerLib::runDimmer(dimmer_37);
  DimmerLib::runDimmer(dimmer_38);
  DimmerLib::runDimmer(dimmer_39);

  DimmerLib::current_micros = micros();
  DimmerLib::interval_micros = DimmerLib::current_micros - DimmerLib::last_micros;



  Serial.println(DimmerLib::interval_micros);



  switch (dimmer_0.mode)
  {
  case DimmerLib::MANUAL:
    delay((dimmer_0.POLLING_RATE * 1000 - DimmerLib::interval_micros) / 1000);

    break;
  
  case DimmerLib::AUTO:
    switch (dimmer_0.state)
    {
    case 0:
      while (dimmer_0.PART_DELAY - DimmerLib::interval_micros >= 1000)
      {
        delay(1);
        DimmerLib::current_micros = micros();
        DimmerLib::interval_micros = DimmerLib::current_micros - DimmerLib::last_micros;
      }
      delayMicroseconds(dimmer_0.PART_DELAY - DimmerLib::interval_micros);

      break;
    
    case 1:
      delay((dimmer_0.DELAY_TIME * 1000 - DimmerLib::interval_micros) / 1000);

      break;

    default:
      Serial.println("Invalid state.");

      break;
    }

      break;

  default:
    Serial.println("Invalid mode.");













    break;
  }

}