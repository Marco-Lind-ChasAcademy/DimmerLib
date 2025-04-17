#include <DimmerLib.h>


// Stress test with 100 dimmer threads to demonstrate the capabilities
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
DimmerLib::LightSensingDimmer dimmer_14(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_15(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_16(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_17(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_18(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_19(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_20(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_21(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_22(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_23(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_24(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_25(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_26(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_27(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_28(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_29(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_30(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_31(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_32(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_33(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_34(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_35(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_36(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_37(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_38(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_39(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_40(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_41(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_42(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_43(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_44(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_45(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_46(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_47(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_48(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_49(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_50(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_51(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_52(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_53(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_54(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_55(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_56(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_57(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_58(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_59(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_60(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_61(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_62(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_63(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_64(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_65(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_66(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_67(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_68(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_69(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_70(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_71(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_72(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_73(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_74(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_75(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_76(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_77(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_78(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_79(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_80(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_81(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_82(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_83(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_84(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_85(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_86(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_87(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_88(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_89(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_90(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_91(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_92(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_93(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_94(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_95(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_96(A4, 21, 20, 10, A0, 3);
DimmerLib::LightSensingDimmer dimmer_97(A4, 8, 9, 10, A2, 1);
DimmerLib::LightSensingDimmer dimmer_98(A4, 21, 20, 10, A1, 2);
DimmerLib::LightSensingDimmer dimmer_99(A4, 21, 20, 10, A0, 3);


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
MAKE_MODE_SWITCH_ISR(dimmer_14_mode_ISR, dimmer_14)
MAKE_MODE_SWITCH_ISR(dimmer_15_mode_ISR, dimmer_15)
MAKE_MODE_SWITCH_ISR(dimmer_16_mode_ISR, dimmer_16)
MAKE_MODE_SWITCH_ISR(dimmer_17_mode_ISR, dimmer_17)
MAKE_MODE_SWITCH_ISR(dimmer_18_mode_ISR, dimmer_18)
MAKE_MODE_SWITCH_ISR(dimmer_19_mode_ISR, dimmer_19)
MAKE_MODE_SWITCH_ISR(dimmer_20_mode_ISR, dimmer_20)
MAKE_MODE_SWITCH_ISR(dimmer_21_mode_ISR, dimmer_21)
MAKE_MODE_SWITCH_ISR(dimmer_22_mode_ISR, dimmer_22)
MAKE_MODE_SWITCH_ISR(dimmer_23_mode_ISR, dimmer_23)
MAKE_MODE_SWITCH_ISR(dimmer_24_mode_ISR, dimmer_24)
MAKE_MODE_SWITCH_ISR(dimmer_25_mode_ISR, dimmer_25)
MAKE_MODE_SWITCH_ISR(dimmer_26_mode_ISR, dimmer_26)
MAKE_MODE_SWITCH_ISR(dimmer_27_mode_ISR, dimmer_27)
MAKE_MODE_SWITCH_ISR(dimmer_28_mode_ISR, dimmer_28)
MAKE_MODE_SWITCH_ISR(dimmer_29_mode_ISR, dimmer_29)
MAKE_MODE_SWITCH_ISR(dimmer_30_mode_ISR, dimmer_30)
MAKE_MODE_SWITCH_ISR(dimmer_31_mode_ISR, dimmer_31)
MAKE_MODE_SWITCH_ISR(dimmer_32_mode_ISR, dimmer_32)
MAKE_MODE_SWITCH_ISR(dimmer_33_mode_ISR, dimmer_33)
MAKE_MODE_SWITCH_ISR(dimmer_34_mode_ISR, dimmer_34)
MAKE_MODE_SWITCH_ISR(dimmer_35_mode_ISR, dimmer_35)
MAKE_MODE_SWITCH_ISR(dimmer_36_mode_ISR, dimmer_36)
MAKE_MODE_SWITCH_ISR(dimmer_37_mode_ISR, dimmer_37)
MAKE_MODE_SWITCH_ISR(dimmer_38_mode_ISR, dimmer_38)
MAKE_MODE_SWITCH_ISR(dimmer_39_mode_ISR, dimmer_39)
MAKE_MODE_SWITCH_ISR(dimmer_40_mode_ISR, dimmer_40)
MAKE_MODE_SWITCH_ISR(dimmer_41_mode_ISR, dimmer_41)
MAKE_MODE_SWITCH_ISR(dimmer_42_mode_ISR, dimmer_42)
MAKE_MODE_SWITCH_ISR(dimmer_43_mode_ISR, dimmer_43)
MAKE_MODE_SWITCH_ISR(dimmer_44_mode_ISR, dimmer_44)
MAKE_MODE_SWITCH_ISR(dimmer_45_mode_ISR, dimmer_45)
MAKE_MODE_SWITCH_ISR(dimmer_46_mode_ISR, dimmer_46)
MAKE_MODE_SWITCH_ISR(dimmer_47_mode_ISR, dimmer_47)
MAKE_MODE_SWITCH_ISR(dimmer_48_mode_ISR, dimmer_48)
MAKE_MODE_SWITCH_ISR(dimmer_49_mode_ISR, dimmer_49)
MAKE_MODE_SWITCH_ISR(dimmer_50_mode_ISR, dimmer_50)
MAKE_MODE_SWITCH_ISR(dimmer_51_mode_ISR, dimmer_51)
MAKE_MODE_SWITCH_ISR(dimmer_52_mode_ISR, dimmer_52)
MAKE_MODE_SWITCH_ISR(dimmer_53_mode_ISR, dimmer_53)
MAKE_MODE_SWITCH_ISR(dimmer_54_mode_ISR, dimmer_54)
MAKE_MODE_SWITCH_ISR(dimmer_55_mode_ISR, dimmer_55)
MAKE_MODE_SWITCH_ISR(dimmer_56_mode_ISR, dimmer_56)
MAKE_MODE_SWITCH_ISR(dimmer_57_mode_ISR, dimmer_57)
MAKE_MODE_SWITCH_ISR(dimmer_58_mode_ISR, dimmer_58)
MAKE_MODE_SWITCH_ISR(dimmer_59_mode_ISR, dimmer_59)
MAKE_MODE_SWITCH_ISR(dimmer_60_mode_ISR, dimmer_60)
MAKE_MODE_SWITCH_ISR(dimmer_61_mode_ISR, dimmer_61)
MAKE_MODE_SWITCH_ISR(dimmer_62_mode_ISR, dimmer_62)
MAKE_MODE_SWITCH_ISR(dimmer_63_mode_ISR, dimmer_63)
MAKE_MODE_SWITCH_ISR(dimmer_64_mode_ISR, dimmer_64)
MAKE_MODE_SWITCH_ISR(dimmer_65_mode_ISR, dimmer_65)
MAKE_MODE_SWITCH_ISR(dimmer_66_mode_ISR, dimmer_66)
MAKE_MODE_SWITCH_ISR(dimmer_67_mode_ISR, dimmer_67)
MAKE_MODE_SWITCH_ISR(dimmer_68_mode_ISR, dimmer_68)
MAKE_MODE_SWITCH_ISR(dimmer_69_mode_ISR, dimmer_69)
MAKE_MODE_SWITCH_ISR(dimmer_70_mode_ISR, dimmer_70)
MAKE_MODE_SWITCH_ISR(dimmer_71_mode_ISR, dimmer_71)
MAKE_MODE_SWITCH_ISR(dimmer_72_mode_ISR, dimmer_72)
MAKE_MODE_SWITCH_ISR(dimmer_73_mode_ISR, dimmer_73)
MAKE_MODE_SWITCH_ISR(dimmer_74_mode_ISR, dimmer_74)
MAKE_MODE_SWITCH_ISR(dimmer_75_mode_ISR, dimmer_75)
MAKE_MODE_SWITCH_ISR(dimmer_76_mode_ISR, dimmer_76)
MAKE_MODE_SWITCH_ISR(dimmer_77_mode_ISR, dimmer_77)
MAKE_MODE_SWITCH_ISR(dimmer_78_mode_ISR, dimmer_78)
MAKE_MODE_SWITCH_ISR(dimmer_79_mode_ISR, dimmer_79)
MAKE_MODE_SWITCH_ISR(dimmer_80_mode_ISR, dimmer_80)
MAKE_MODE_SWITCH_ISR(dimmer_81_mode_ISR, dimmer_81)
MAKE_MODE_SWITCH_ISR(dimmer_82_mode_ISR, dimmer_82)
MAKE_MODE_SWITCH_ISR(dimmer_83_mode_ISR, dimmer_83)
MAKE_MODE_SWITCH_ISR(dimmer_84_mode_ISR, dimmer_84)
MAKE_MODE_SWITCH_ISR(dimmer_85_mode_ISR, dimmer_85)
MAKE_MODE_SWITCH_ISR(dimmer_86_mode_ISR, dimmer_86)
MAKE_MODE_SWITCH_ISR(dimmer_87_mode_ISR, dimmer_87)
MAKE_MODE_SWITCH_ISR(dimmer_88_mode_ISR, dimmer_88)
MAKE_MODE_SWITCH_ISR(dimmer_89_mode_ISR, dimmer_89)
MAKE_MODE_SWITCH_ISR(dimmer_90_mode_ISR, dimmer_90)
MAKE_MODE_SWITCH_ISR(dimmer_91_mode_ISR, dimmer_91)
MAKE_MODE_SWITCH_ISR(dimmer_92_mode_ISR, dimmer_92)
MAKE_MODE_SWITCH_ISR(dimmer_93_mode_ISR, dimmer_93)
MAKE_MODE_SWITCH_ISR(dimmer_94_mode_ISR, dimmer_94)
MAKE_MODE_SWITCH_ISR(dimmer_95_mode_ISR, dimmer_95)
MAKE_MODE_SWITCH_ISR(dimmer_96_mode_ISR, dimmer_96)
MAKE_MODE_SWITCH_ISR(dimmer_97_mode_ISR, dimmer_97)
MAKE_MODE_SWITCH_ISR(dimmer_98_mode_ISR, dimmer_98)
MAKE_MODE_SWITCH_ISR(dimmer_99_mode_ISR, dimmer_99)


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
MAKE_DEBUG_SWITCH_ISR(dimmer_14_debug_ISR, dimmer_14)
MAKE_DEBUG_SWITCH_ISR(dimmer_15_debug_ISR, dimmer_15)
MAKE_DEBUG_SWITCH_ISR(dimmer_16_debug_ISR, dimmer_16)
MAKE_DEBUG_SWITCH_ISR(dimmer_17_debug_ISR, dimmer_17)
MAKE_DEBUG_SWITCH_ISR(dimmer_18_debug_ISR, dimmer_18)
MAKE_DEBUG_SWITCH_ISR(dimmer_19_debug_ISR, dimmer_19)
MAKE_DEBUG_SWITCH_ISR(dimmer_20_debug_ISR, dimmer_20)
MAKE_DEBUG_SWITCH_ISR(dimmer_21_debug_ISR, dimmer_21)
MAKE_DEBUG_SWITCH_ISR(dimmer_22_debug_ISR, dimmer_22)
MAKE_DEBUG_SWITCH_ISR(dimmer_23_debug_ISR, dimmer_23)
MAKE_DEBUG_SWITCH_ISR(dimmer_24_debug_ISR, dimmer_24)
MAKE_DEBUG_SWITCH_ISR(dimmer_25_debug_ISR, dimmer_25)
MAKE_DEBUG_SWITCH_ISR(dimmer_26_debug_ISR, dimmer_26)
MAKE_DEBUG_SWITCH_ISR(dimmer_27_debug_ISR, dimmer_27)
MAKE_DEBUG_SWITCH_ISR(dimmer_28_debug_ISR, dimmer_28)
MAKE_DEBUG_SWITCH_ISR(dimmer_29_debug_ISR, dimmer_29)
MAKE_DEBUG_SWITCH_ISR(dimmer_30_debug_ISR, dimmer_30)
MAKE_DEBUG_SWITCH_ISR(dimmer_31_debug_ISR, dimmer_31)
MAKE_DEBUG_SWITCH_ISR(dimmer_32_debug_ISR, dimmer_32)
MAKE_DEBUG_SWITCH_ISR(dimmer_33_debug_ISR, dimmer_33)
MAKE_DEBUG_SWITCH_ISR(dimmer_34_debug_ISR, dimmer_34)
MAKE_DEBUG_SWITCH_ISR(dimmer_35_debug_ISR, dimmer_35)
MAKE_DEBUG_SWITCH_ISR(dimmer_36_debug_ISR, dimmer_36)
MAKE_DEBUG_SWITCH_ISR(dimmer_37_debug_ISR, dimmer_37)
MAKE_DEBUG_SWITCH_ISR(dimmer_38_debug_ISR, dimmer_38)
MAKE_DEBUG_SWITCH_ISR(dimmer_39_debug_ISR, dimmer_39)
MAKE_DEBUG_SWITCH_ISR(dimmer_40_debug_ISR, dimmer_40)
MAKE_DEBUG_SWITCH_ISR(dimmer_41_debug_ISR, dimmer_41)
MAKE_DEBUG_SWITCH_ISR(dimmer_42_debug_ISR, dimmer_42)
MAKE_DEBUG_SWITCH_ISR(dimmer_43_debug_ISR, dimmer_43)
MAKE_DEBUG_SWITCH_ISR(dimmer_44_debug_ISR, dimmer_44)
MAKE_DEBUG_SWITCH_ISR(dimmer_45_debug_ISR, dimmer_45)
MAKE_DEBUG_SWITCH_ISR(dimmer_46_debug_ISR, dimmer_46)
MAKE_DEBUG_SWITCH_ISR(dimmer_47_debug_ISR, dimmer_47)
MAKE_DEBUG_SWITCH_ISR(dimmer_48_debug_ISR, dimmer_48)
MAKE_DEBUG_SWITCH_ISR(dimmer_49_debug_ISR, dimmer_49)
MAKE_DEBUG_SWITCH_ISR(dimmer_50_debug_ISR, dimmer_50)
MAKE_DEBUG_SWITCH_ISR(dimmer_51_debug_ISR, dimmer_51)
MAKE_DEBUG_SWITCH_ISR(dimmer_52_debug_ISR, dimmer_52)
MAKE_DEBUG_SWITCH_ISR(dimmer_53_debug_ISR, dimmer_53)
MAKE_DEBUG_SWITCH_ISR(dimmer_54_debug_ISR, dimmer_54)
MAKE_DEBUG_SWITCH_ISR(dimmer_55_debug_ISR, dimmer_55)
MAKE_DEBUG_SWITCH_ISR(dimmer_56_debug_ISR, dimmer_56)
MAKE_DEBUG_SWITCH_ISR(dimmer_57_debug_ISR, dimmer_57)
MAKE_DEBUG_SWITCH_ISR(dimmer_58_debug_ISR, dimmer_58)
MAKE_DEBUG_SWITCH_ISR(dimmer_59_debug_ISR, dimmer_59)
MAKE_DEBUG_SWITCH_ISR(dimmer_60_debug_ISR, dimmer_60)
MAKE_DEBUG_SWITCH_ISR(dimmer_61_debug_ISR, dimmer_61)
MAKE_DEBUG_SWITCH_ISR(dimmer_62_debug_ISR, dimmer_62)
MAKE_DEBUG_SWITCH_ISR(dimmer_63_debug_ISR, dimmer_63)
MAKE_DEBUG_SWITCH_ISR(dimmer_64_debug_ISR, dimmer_64)
MAKE_DEBUG_SWITCH_ISR(dimmer_65_debug_ISR, dimmer_65)
MAKE_DEBUG_SWITCH_ISR(dimmer_66_debug_ISR, dimmer_66)
MAKE_DEBUG_SWITCH_ISR(dimmer_67_debug_ISR, dimmer_67)
MAKE_DEBUG_SWITCH_ISR(dimmer_68_debug_ISR, dimmer_68)
MAKE_DEBUG_SWITCH_ISR(dimmer_69_debug_ISR, dimmer_69)
MAKE_DEBUG_SWITCH_ISR(dimmer_70_debug_ISR, dimmer_70)
MAKE_DEBUG_SWITCH_ISR(dimmer_71_debug_ISR, dimmer_71)
MAKE_DEBUG_SWITCH_ISR(dimmer_72_debug_ISR, dimmer_72)
MAKE_DEBUG_SWITCH_ISR(dimmer_73_debug_ISR, dimmer_73)
MAKE_DEBUG_SWITCH_ISR(dimmer_74_debug_ISR, dimmer_74)
MAKE_DEBUG_SWITCH_ISR(dimmer_75_debug_ISR, dimmer_75)
MAKE_DEBUG_SWITCH_ISR(dimmer_76_debug_ISR, dimmer_76)
MAKE_DEBUG_SWITCH_ISR(dimmer_77_debug_ISR, dimmer_77)
MAKE_DEBUG_SWITCH_ISR(dimmer_78_debug_ISR, dimmer_78)
MAKE_DEBUG_SWITCH_ISR(dimmer_79_debug_ISR, dimmer_79)
MAKE_DEBUG_SWITCH_ISR(dimmer_80_debug_ISR, dimmer_80)
MAKE_DEBUG_SWITCH_ISR(dimmer_81_debug_ISR, dimmer_81)
MAKE_DEBUG_SWITCH_ISR(dimmer_82_debug_ISR, dimmer_82)
MAKE_DEBUG_SWITCH_ISR(dimmer_83_debug_ISR, dimmer_83)
MAKE_DEBUG_SWITCH_ISR(dimmer_84_debug_ISR, dimmer_84)
MAKE_DEBUG_SWITCH_ISR(dimmer_85_debug_ISR, dimmer_85)
MAKE_DEBUG_SWITCH_ISR(dimmer_86_debug_ISR, dimmer_86)
MAKE_DEBUG_SWITCH_ISR(dimmer_87_debug_ISR, dimmer_87)
MAKE_DEBUG_SWITCH_ISR(dimmer_88_debug_ISR, dimmer_88)
MAKE_DEBUG_SWITCH_ISR(dimmer_89_debug_ISR, dimmer_89)
MAKE_DEBUG_SWITCH_ISR(dimmer_90_debug_ISR, dimmer_90)
MAKE_DEBUG_SWITCH_ISR(dimmer_91_debug_ISR, dimmer_91)
MAKE_DEBUG_SWITCH_ISR(dimmer_92_debug_ISR, dimmer_92)
MAKE_DEBUG_SWITCH_ISR(dimmer_93_debug_ISR, dimmer_93)
MAKE_DEBUG_SWITCH_ISR(dimmer_94_debug_ISR, dimmer_94)
MAKE_DEBUG_SWITCH_ISR(dimmer_95_debug_ISR, dimmer_95)
MAKE_DEBUG_SWITCH_ISR(dimmer_96_debug_ISR, dimmer_96)
MAKE_DEBUG_SWITCH_ISR(dimmer_97_debug_ISR, dimmer_97)
MAKE_DEBUG_SWITCH_ISR(dimmer_98_debug_ISR, dimmer_98)
MAKE_DEBUG_SWITCH_ISR(dimmer_99_debug_ISR, dimmer_99)



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
  attachInterrupt(digitalPinToInterrupt(dimmer_14.MODE_BUTTON_PIN), dimmer_14_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_15.MODE_BUTTON_PIN), dimmer_15_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_16.MODE_BUTTON_PIN), dimmer_16_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_17.MODE_BUTTON_PIN), dimmer_17_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_18.MODE_BUTTON_PIN), dimmer_18_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_19.MODE_BUTTON_PIN), dimmer_19_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_20.MODE_BUTTON_PIN), dimmer_20_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_21.MODE_BUTTON_PIN), dimmer_21_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_22.MODE_BUTTON_PIN), dimmer_22_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_23.MODE_BUTTON_PIN), dimmer_23_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_24.MODE_BUTTON_PIN), dimmer_24_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_25.MODE_BUTTON_PIN), dimmer_25_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_26.MODE_BUTTON_PIN), dimmer_26_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_27.MODE_BUTTON_PIN), dimmer_27_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_28.MODE_BUTTON_PIN), dimmer_28_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_29.MODE_BUTTON_PIN), dimmer_29_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_30.MODE_BUTTON_PIN), dimmer_30_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_31.MODE_BUTTON_PIN), dimmer_31_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_32.MODE_BUTTON_PIN), dimmer_32_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_33.MODE_BUTTON_PIN), dimmer_33_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_34.MODE_BUTTON_PIN), dimmer_34_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_35.MODE_BUTTON_PIN), dimmer_35_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_36.MODE_BUTTON_PIN), dimmer_36_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_37.MODE_BUTTON_PIN), dimmer_37_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_38.MODE_BUTTON_PIN), dimmer_38_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_39.MODE_BUTTON_PIN), dimmer_39_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_40.MODE_BUTTON_PIN), dimmer_40_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_41.MODE_BUTTON_PIN), dimmer_41_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_42.MODE_BUTTON_PIN), dimmer_42_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_43.MODE_BUTTON_PIN), dimmer_43_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_44.MODE_BUTTON_PIN), dimmer_44_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_45.MODE_BUTTON_PIN), dimmer_45_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_46.MODE_BUTTON_PIN), dimmer_46_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_47.MODE_BUTTON_PIN), dimmer_47_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_48.MODE_BUTTON_PIN), dimmer_48_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_49.MODE_BUTTON_PIN), dimmer_49_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_50.MODE_BUTTON_PIN), dimmer_50_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_51.MODE_BUTTON_PIN), dimmer_51_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_52.MODE_BUTTON_PIN), dimmer_52_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_53.MODE_BUTTON_PIN), dimmer_53_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_54.MODE_BUTTON_PIN), dimmer_54_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_55.MODE_BUTTON_PIN), dimmer_55_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_56.MODE_BUTTON_PIN), dimmer_56_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_57.MODE_BUTTON_PIN), dimmer_57_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_58.MODE_BUTTON_PIN), dimmer_58_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_59.MODE_BUTTON_PIN), dimmer_59_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_60.MODE_BUTTON_PIN), dimmer_60_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_61.MODE_BUTTON_PIN), dimmer_61_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_62.MODE_BUTTON_PIN), dimmer_62_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_63.MODE_BUTTON_PIN), dimmer_63_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_64.MODE_BUTTON_PIN), dimmer_64_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_65.MODE_BUTTON_PIN), dimmer_65_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_66.MODE_BUTTON_PIN), dimmer_66_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_67.MODE_BUTTON_PIN), dimmer_67_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_68.MODE_BUTTON_PIN), dimmer_68_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_69.MODE_BUTTON_PIN), dimmer_69_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_70.MODE_BUTTON_PIN), dimmer_70_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_71.MODE_BUTTON_PIN), dimmer_71_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_72.MODE_BUTTON_PIN), dimmer_72_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_73.MODE_BUTTON_PIN), dimmer_73_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_74.MODE_BUTTON_PIN), dimmer_74_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_75.MODE_BUTTON_PIN), dimmer_75_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_76.MODE_BUTTON_PIN), dimmer_76_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_77.MODE_BUTTON_PIN), dimmer_77_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_78.MODE_BUTTON_PIN), dimmer_78_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_79.MODE_BUTTON_PIN), dimmer_79_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_80.MODE_BUTTON_PIN), dimmer_80_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_81.MODE_BUTTON_PIN), dimmer_81_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_82.MODE_BUTTON_PIN), dimmer_82_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_83.MODE_BUTTON_PIN), dimmer_83_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_84.MODE_BUTTON_PIN), dimmer_84_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_85.MODE_BUTTON_PIN), dimmer_85_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_86.MODE_BUTTON_PIN), dimmer_86_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_87.MODE_BUTTON_PIN), dimmer_87_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_88.MODE_BUTTON_PIN), dimmer_88_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_89.MODE_BUTTON_PIN), dimmer_89_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_90.MODE_BUTTON_PIN), dimmer_90_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_91.MODE_BUTTON_PIN), dimmer_91_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_92.MODE_BUTTON_PIN), dimmer_92_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_93.MODE_BUTTON_PIN), dimmer_93_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_94.MODE_BUTTON_PIN), dimmer_94_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_95.MODE_BUTTON_PIN), dimmer_95_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_96.MODE_BUTTON_PIN), dimmer_96_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_97.MODE_BUTTON_PIN), dimmer_97_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_98.MODE_BUTTON_PIN), dimmer_98_mode_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_99.MODE_BUTTON_PIN), dimmer_99_mode_ISR, RISING);

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
  attachInterrupt(digitalPinToInterrupt(dimmer_14.DEBUG_BUTTON_PIN), dimmer_14_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_15.DEBUG_BUTTON_PIN), dimmer_15_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_16.DEBUG_BUTTON_PIN), dimmer_16_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_17.DEBUG_BUTTON_PIN), dimmer_17_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_18.DEBUG_BUTTON_PIN), dimmer_18_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_19.DEBUG_BUTTON_PIN), dimmer_19_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_20.DEBUG_BUTTON_PIN), dimmer_20_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_21.DEBUG_BUTTON_PIN), dimmer_21_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_22.DEBUG_BUTTON_PIN), dimmer_22_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_23.DEBUG_BUTTON_PIN), dimmer_23_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_24.DEBUG_BUTTON_PIN), dimmer_24_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_25.DEBUG_BUTTON_PIN), dimmer_25_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_26.DEBUG_BUTTON_PIN), dimmer_26_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_27.DEBUG_BUTTON_PIN), dimmer_27_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_28.DEBUG_BUTTON_PIN), dimmer_28_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_29.DEBUG_BUTTON_PIN), dimmer_29_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_30.DEBUG_BUTTON_PIN), dimmer_30_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_31.DEBUG_BUTTON_PIN), dimmer_31_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_32.DEBUG_BUTTON_PIN), dimmer_32_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_33.DEBUG_BUTTON_PIN), dimmer_33_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_34.DEBUG_BUTTON_PIN), dimmer_34_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_35.DEBUG_BUTTON_PIN), dimmer_35_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_36.DEBUG_BUTTON_PIN), dimmer_36_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_37.DEBUG_BUTTON_PIN), dimmer_37_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_38.DEBUG_BUTTON_PIN), dimmer_38_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_39.DEBUG_BUTTON_PIN), dimmer_39_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_40.DEBUG_BUTTON_PIN), dimmer_40_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_41.DEBUG_BUTTON_PIN), dimmer_41_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_42.DEBUG_BUTTON_PIN), dimmer_42_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_43.DEBUG_BUTTON_PIN), dimmer_43_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_44.DEBUG_BUTTON_PIN), dimmer_44_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_45.DEBUG_BUTTON_PIN), dimmer_45_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_46.DEBUG_BUTTON_PIN), dimmer_46_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_47.DEBUG_BUTTON_PIN), dimmer_47_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_48.DEBUG_BUTTON_PIN), dimmer_48_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_49.DEBUG_BUTTON_PIN), dimmer_49_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_50.DEBUG_BUTTON_PIN), dimmer_40_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_51.DEBUG_BUTTON_PIN), dimmer_41_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_52.DEBUG_BUTTON_PIN), dimmer_42_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_53.DEBUG_BUTTON_PIN), dimmer_43_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_54.DEBUG_BUTTON_PIN), dimmer_44_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_55.DEBUG_BUTTON_PIN), dimmer_45_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_56.DEBUG_BUTTON_PIN), dimmer_46_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_57.DEBUG_BUTTON_PIN), dimmer_47_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_58.DEBUG_BUTTON_PIN), dimmer_48_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_59.DEBUG_BUTTON_PIN), dimmer_49_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_60.DEBUG_BUTTON_PIN), dimmer_60_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_61.DEBUG_BUTTON_PIN), dimmer_61_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_62.DEBUG_BUTTON_PIN), dimmer_62_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_63.DEBUG_BUTTON_PIN), dimmer_63_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_64.DEBUG_BUTTON_PIN), dimmer_64_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_65.DEBUG_BUTTON_PIN), dimmer_65_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_66.DEBUG_BUTTON_PIN), dimmer_66_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_67.DEBUG_BUTTON_PIN), dimmer_67_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_68.DEBUG_BUTTON_PIN), dimmer_68_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_69.DEBUG_BUTTON_PIN), dimmer_69_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_70.DEBUG_BUTTON_PIN), dimmer_70_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_71.DEBUG_BUTTON_PIN), dimmer_71_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_72.DEBUG_BUTTON_PIN), dimmer_72_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_73.DEBUG_BUTTON_PIN), dimmer_73_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_74.DEBUG_BUTTON_PIN), dimmer_74_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_75.DEBUG_BUTTON_PIN), dimmer_75_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_76.DEBUG_BUTTON_PIN), dimmer_76_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_77.DEBUG_BUTTON_PIN), dimmer_77_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_78.DEBUG_BUTTON_PIN), dimmer_78_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_79.DEBUG_BUTTON_PIN), dimmer_79_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_80.DEBUG_BUTTON_PIN), dimmer_80_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_81.DEBUG_BUTTON_PIN), dimmer_81_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_82.DEBUG_BUTTON_PIN), dimmer_82_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_83.DEBUG_BUTTON_PIN), dimmer_83_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_84.DEBUG_BUTTON_PIN), dimmer_84_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_85.DEBUG_BUTTON_PIN), dimmer_85_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_86.DEBUG_BUTTON_PIN), dimmer_86_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_87.DEBUG_BUTTON_PIN), dimmer_87_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_88.DEBUG_BUTTON_PIN), dimmer_88_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_89.DEBUG_BUTTON_PIN), dimmer_89_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_90.DEBUG_BUTTON_PIN), dimmer_90_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_91.DEBUG_BUTTON_PIN), dimmer_91_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_92.DEBUG_BUTTON_PIN), dimmer_92_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_93.DEBUG_BUTTON_PIN), dimmer_93_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_94.DEBUG_BUTTON_PIN), dimmer_94_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_95.DEBUG_BUTTON_PIN), dimmer_95_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_96.DEBUG_BUTTON_PIN), dimmer_96_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_97.DEBUG_BUTTON_PIN), dimmer_97_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_98.DEBUG_BUTTON_PIN), dimmer_98_debug_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(dimmer_99.DEBUG_BUTTON_PIN), dimmer_99_debug_ISR, RISING);

  // Example with initiation macros for all the dimmers
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
  INITIATE_DIMMER_TASK(dimmer_14, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_15, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_16, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_17, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_18, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_19, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_20, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_21, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_22, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_23, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_24, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_25, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_26, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_27, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_28, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_29, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_30, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_31, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_32, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_33, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_34, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_35, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_36, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_37, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_38, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_39, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_40, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_41, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_42, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_43, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_44, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_45, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_46, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_47, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_48, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_49, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_50, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_51, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_52, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_53, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_54, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_55, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_56, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_57, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_58, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_59, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_60, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_61, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_62, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_63, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_64, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_65, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_66, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_67, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_68, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_69, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_70, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_71, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_72, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_73, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_74, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_75, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_76, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_77, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_78, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_79, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_80, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_81, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_82, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_83, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_84, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_85, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_86, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_87, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_88, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_89, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_90, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_91, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_92, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_93, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_94, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_95, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_96, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_97, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_98, configMAX_PRIORITIES - 1);
  INITIATE_DIMMER_TASK(dimmer_99, configMAX_PRIORITIES - 1);
}

void loop()
{
}