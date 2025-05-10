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

  DimmerLib::runDimmerCoro(dimmer_0);
  DimmerLib::runDimmerCoro(dimmer_1);
  DimmerLib::runDimmerCoro(dimmer_2);
  DimmerLib::runDimmerCoro(dimmer_3);
  DimmerLib::runDimmerCoro(dimmer_4);
  DimmerLib::runDimmerCoro(dimmer_5);
  DimmerLib::runDimmerCoro(dimmer_6);
  DimmerLib::runDimmerCoro(dimmer_7);
  DimmerLib::runDimmerCoro(dimmer_8);
  DimmerLib::runDimmerCoro(dimmer_9);
  DimmerLib::runDimmerCoro(dimmer_10);
  DimmerLib::runDimmerCoro(dimmer_11);
  DimmerLib::runDimmerCoro(dimmer_12);
  DimmerLib::runDimmerCoro(dimmer_13);
  DimmerLib::runDimmerCoro(dimmer_14);
  DimmerLib::runDimmerCoro(dimmer_15);
  DimmerLib::runDimmerCoro(dimmer_16);
  DimmerLib::runDimmerCoro(dimmer_17);
  DimmerLib::runDimmerCoro(dimmer_18);
  DimmerLib::runDimmerCoro(dimmer_19);
  DimmerLib::runDimmerCoro(dimmer_20);
  DimmerLib::runDimmerCoro(dimmer_21);
  DimmerLib::runDimmerCoro(dimmer_22);
  DimmerLib::runDimmerCoro(dimmer_23);
  DimmerLib::runDimmerCoro(dimmer_24);
  DimmerLib::runDimmerCoro(dimmer_25);
  DimmerLib::runDimmerCoro(dimmer_26);
  DimmerLib::runDimmerCoro(dimmer_27);
  DimmerLib::runDimmerCoro(dimmer_28);
  DimmerLib::runDimmerCoro(dimmer_29);
  DimmerLib::runDimmerCoro(dimmer_30);
  DimmerLib::runDimmerCoro(dimmer_31);
  DimmerLib::runDimmerCoro(dimmer_32);
  DimmerLib::runDimmerCoro(dimmer_33);
  DimmerLib::runDimmerCoro(dimmer_34);
  DimmerLib::runDimmerCoro(dimmer_35);
  DimmerLib::runDimmerCoro(dimmer_36);
  DimmerLib::runDimmerCoro(dimmer_37);
  DimmerLib::runDimmerCoro(dimmer_38);
  DimmerLib::runDimmerCoro(dimmer_39);

  DimmerLib::current_micros = micros();
  DimmerLib::interval_micros = DimmerLib::current_micros - DimmerLib::last_micros;

  /* Serial.print("Time taken: ");
  Serial.print(DimmerLib::interval_micros);
  Serial.println("us"); */

  DimmerLib::delays(dimmer_0, DimmerLib::interval_micros);
}