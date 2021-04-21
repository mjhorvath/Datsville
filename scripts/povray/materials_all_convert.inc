// POV-Ray scripts for LDraw models and scenes
// Copyright (C) 2019  Michael Horvath
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LDX = LDView
// L3 = L3P.exe
// ld = LDCAD
// lg = LGEO
// lc = LeoCAD

// row 1 - Black
#declare LDXColor0 = MJHMat0;
#declare LDXColor0_slope = MJHMat0Slope;
#declare L3Texture0 = MJHTex0;
#declare L3Texture0_slope = MJHTex0Slope;
#declare L3Color0 = MJHMat0;
#declare L3Color0_slope = MJHMat0Slope;
#declare ldMat0 = MJHMat0;
#declare ldTex0 = MJHTex0;
#declare lg_black = MJHTex0;
#declare lc_Black = MJHTex0;

// row 2 - Blue
#declare LDXColor1 = MJHMat1;
#declare LDXColor1_slope = MJHMat1Slope;
#declare L3Texture1 = MJHTex1;
#declare L3Texture1_slope = MJHTex1Slope;
#declare L3Color1 = MJHMat1;
#declare L3Color1_slope = MJHMat1Slope;
#declare ldMat1 = MJHMat1;
#declare ldTex1 = MJHTex1;
#declare lg_blue = MJHTex1;
#declare lc_Blue = MJHTex1;

// row 3 - Green
#declare LDXColor2 = MJHMat2;
#declare LDXColor2_slope = MJHMat2Slope;
#declare L3Texture2 = MJHTex2;
#declare L3Texture2_slope = MJHTex2Slope;
#declare L3Color2 = MJHMat2;
#declare L3Color2_slope = MJHMat2Slope;
#declare ldMat2 = MJHMat2;
#declare ldTex2 = MJHTex2;
#declare lg_green = MJHTex2;
#declare lc_Green = MJHTex2;

// row 4 - Dark_Turquoise
#declare LDXColor3 = MJHMat3;
#declare LDXColor3_slope = MJHMat3Slope;
#declare L3Texture3 = MJHTex3;
#declare L3Texture3_slope = MJHTex3Slope;
#declare L3Color3 = MJHMat3;
#declare L3Color3_slope = MJHMat3Slope;
#declare ldMat3 = MJHMat3;
#declare ldTex3 = MJHTex3;
#declare lg_cyan = MJHTex3;
#declare lc_Dark_Turquoise = MJHTex3;

// row 5 - Red
#declare LDXColor4 = MJHMat4;
#declare LDXColor4_slope = MJHMat4Slope;
#declare L3Texture4 = MJHTex4;
#declare L3Texture4_slope = MJHTex4Slope;
#declare L3Color4 = MJHMat4;
#declare L3Color4_slope = MJHMat4Slope;
#declare ldMat4 = MJHMat4;
#declare ldTex4 = MJHTex4;
#declare lg_red = MJHTex4;
#declare lc_Red = MJHTex4;

// row 6 - Dark_Pink
#declare LDXColor5 = MJHMat5;
#declare LDXColor5_slope = MJHMat5Slope;
#declare L3Texture5 = MJHTex5;
#declare L3Texture5_slope = MJHTex5Slope;
#declare L3Color5 = MJHMat5;
#declare L3Color5_slope = MJHMat5Slope;
#declare ldMat5 = MJHMat5;
#declare ldTex5 = MJHTex5;
#declare lg_dark_pink = MJHTex5;
#declare lc_Dark_Pink = MJHTex5;

// row 7 - Brown
#declare LDXColor6 = MJHMat6;
#declare LDXColor6_slope = MJHMat6Slope;
#declare L3Texture6 = MJHTex6;
#declare L3Texture6_slope = MJHTex6Slope;
#declare L3Color6 = MJHMat6;
#declare L3Color6_slope = MJHMat6Slope;
#declare ldMat6 = MJHMat6;
#declare ldTex6 = MJHTex6;
#declare lg_brown = MJHTex6;
#declare lc_Brown = MJHTex6;

// row 8 - Light_Grey
#declare LDXColor7 = MJHMat7;
#declare LDXColor7_slope = MJHMat7Slope;
#declare L3Texture7 = MJHTex7;
#declare L3Texture7_slope = MJHTex7Slope;
#declare L3Color7 = MJHMat7;
#declare L3Color7_slope = MJHMat7Slope;
#declare ldMat7 = MJHMat7;
#declare ldTex7 = MJHTex7;
#declare lg_grey = MJHTex7;
#declare lc_Light_Grey = MJHTex7;

// row 9 - Dark_Grey
#declare LDXColor8 = MJHMat8;
#declare LDXColor8_slope = MJHMat8Slope;
#declare L3Texture8 = MJHTex8;
#declare L3Texture8_slope = MJHTex8Slope;
#declare L3Color8 = MJHMat8;
#declare L3Color8_slope = MJHMat8Slope;
#declare ldMat8 = MJHMat8;
#declare ldTex8 = MJHTex8;
#declare lg_dark_grey = MJHTex8;
#declare lc_Dark_Grey = MJHTex8;

// row 10 - Light_Blue
#declare LDXColor9 = MJHMat9;
#declare LDXColor9_slope = MJHMat9Slope;
#declare L3Texture9 = MJHTex9;
#declare L3Texture9_slope = MJHTex9Slope;
#declare L3Color9 = MJHMat9;
#declare L3Color9_slope = MJHMat9Slope;
#declare ldMat9 = MJHMat9;
#declare ldTex9 = MJHTex9;
#declare lg_light_blue = MJHTex9;
#declare lc_Light_Blue = MJHTex9;

// row 11 - Bright_Green
#declare LDXColor10 = MJHMat10;
#declare LDXColor10_slope = MJHMat10Slope;
#declare L3Texture10 = MJHTex10;
#declare L3Texture10_slope = MJHTex10Slope;
#declare L3Color10 = MJHMat10;
#declare L3Color10_slope = MJHMat10Slope;
#declare ldMat10 = MJHMat10;
#declare ldTex10 = MJHTex10;
#declare lg_bright_green = MJHTex10;
#declare lc_Bright_Green = MJHTex10;

// row 12 - Light_Turquoise
#declare LDXColor11 = MJHMat11;
#declare LDXColor11_slope = MJHMat11Slope;
#declare L3Texture11 = MJHTex11;
#declare L3Texture11_slope = MJHTex11Slope;
#declare L3Color11 = MJHMat11;
#declare L3Color11_slope = MJHMat11Slope;
#declare ldMat11 = MJHMat11;
#declare ldTex11 = MJHTex11;
#declare lg_turquoise = MJHTex11;
#declare lc_Light_Turquoise = MJHTex11;

// row 13 - Salmon
#declare LDXColor12 = MJHMat12;
#declare LDXColor12_slope = MJHMat12Slope;
#declare L3Texture12 = MJHTex12;
#declare L3Texture12_slope = MJHTex12Slope;
#declare L3Color12 = MJHMat12;
#declare L3Color12_slope = MJHMat12Slope;
#declare ldMat12 = MJHMat12;
#declare ldTex12 = MJHTex12;
#declare lg_salmon = MJHTex12;
#declare lc_Salmon = MJHTex12;

// row 14 - Pink
#declare LDXColor13 = MJHMat13;
#declare LDXColor13_slope = MJHMat13Slope;
#declare L3Texture13 = MJHTex13;
#declare L3Texture13_slope = MJHTex13Slope;
#declare L3Color13 = MJHMat13;
#declare L3Color13_slope = MJHMat13Slope;
#declare ldMat13 = MJHMat13;
#declare ldTex13 = MJHTex13;
#declare lg_pink = MJHTex13;
#declare lc_Pink = MJHTex13;

// row 15 - Yellow
#declare LDXColor14 = MJHMat14;
#declare LDXColor14_slope = MJHMat14Slope;
#declare L3Texture14 = MJHTex14;
#declare L3Texture14_slope = MJHTex14Slope;
#declare L3Color14 = MJHMat14;
#declare L3Color14_slope = MJHMat14Slope;
#declare ldMat14 = MJHMat14;
#declare ldTex14 = MJHTex14;
#declare lg_yellow = MJHTex14;
#declare lc_Yellow = MJHTex14;

// row 16 - White
#declare LDXColor15 = MJHMat15;
#declare LDXColor15_slope = MJHMat15Slope;
#declare L3Texture15 = MJHTex15;
#declare L3Texture15_slope = MJHTex15Slope;
#declare L3Color15 = MJHMat15;
#declare L3Color15_slope = MJHMat15Slope;
#declare ldMat15 = MJHMat15;
#declare ldTex15 = MJHTex15;
#declare lg_white = MJHTex15;
#declare lc_White = MJHTex15;

// row 17 - Main_Colour
#declare LDXColor16 = MJHMat16;
#declare LDXColor16_slope = MJHMat16Slope;
#declare L3Texture16 = MJHTex16;
#declare L3Texture16_slope = MJHTex16Slope;
#declare L3Color16 = MJHMat16;
#declare L3Color16_slope = MJHMat16Slope;
#declare ldMat16 = MJHMat16;
#declare ldTex16 = MJHTex16;
#declare lg_undefined = MJHTex16;
#declare lc_Main_Colour = MJHTex16;

// row 18 - Light_Green
#declare LDXColor17 = MJHMat17;
#declare LDXColor17_slope = MJHMat17Slope;
#declare L3Texture17 = MJHTex17;
#declare L3Texture17_slope = MJHTex17Slope;
#declare L3Color17 = MJHMat17;
#declare L3Color17_slope = MJHMat17Slope;
#declare ldMat17 = MJHMat17;
#declare ldTex17 = MJHTex17;
#declare lg_light_green = MJHTex17;
#declare lc_Light_Green = MJHTex17;

// row 19 - Light_Yellow
#declare LDXColor18 = MJHMat18;
#declare LDXColor18_slope = MJHMat18Slope;
#declare L3Texture18 = MJHTex18;
#declare L3Texture18_slope = MJHTex18Slope;
#declare L3Color18 = MJHMat18;
#declare L3Color18_slope = MJHMat18Slope;
#declare ldMat18 = MJHMat18;
#declare ldTex18 = MJHTex18;
#declare lg_light_yellow = MJHTex18;
#declare lc_Light_Yellow = MJHTex18;

// row 20 - Tan
#declare LDXColor19 = MJHMat19;
#declare LDXColor19_slope = MJHMat19Slope;
#declare L3Texture19 = MJHTex19;
#declare L3Texture19_slope = MJHTex19Slope;
#declare L3Color19 = MJHMat19;
#declare L3Color19_slope = MJHMat19Slope;
#declare ldMat19 = MJHMat19;
#declare ldTex19 = MJHTex19;
#declare lg_tan = MJHTex19;
#declare lc_Tan = MJHTex19;

// row 21 - Light_Violet
#declare LDXColor20 = MJHMat20;
#declare LDXColor20_slope = MJHMat20Slope;
#declare L3Texture20 = MJHTex20;
#declare L3Texture20_slope = MJHTex20Slope;
#declare L3Color20 = MJHMat20;
#declare L3Color20_slope = MJHMat20Slope;
#declare ldMat20 = MJHMat20;
#declare ldTex20 = MJHTex20;
#declare lg_light_violet = MJHTex20;
#declare lc_Light_Violet = MJHTex20;

// row 22 - Glow_In_Dark_Opaque
#declare LDXColor21 = MJHMat21;
#declare LDXColor21_slope = MJHMat21Slope;
#declare L3Texture21 = MJHTex21;
#declare L3Texture21_slope = MJHTex21Slope;
#declare L3Color21 = MJHMat21;
#declare L3Color21_slope = MJHMat21Slope;
#declare ldMat21 = MJHMat21;
#declare ldTex21 = MJHTex21;
#declare lg_glow_in_dark_opaque = MJHTex21;
#declare lc_Glow_In_Dark_Opaque = MJHTex21;

// row 23 - Purple
#declare LDXColor22 = MJHMat22;
#declare LDXColor22_slope = MJHMat22Slope;
#declare L3Texture22 = MJHTex22;
#declare L3Texture22_slope = MJHTex22Slope;
#declare L3Color22 = MJHMat22;
#declare L3Color22_slope = MJHMat22Slope;
#declare ldMat22 = MJHMat22;
#declare ldTex22 = MJHTex22;
#declare lg_purple = MJHTex22;
#declare lc_Purple = MJHTex22;

// row 24 - Dark_Blue_Violet
#declare LDXColor23 = MJHMat23;
#declare LDXColor23_slope = MJHMat23Slope;
#declare L3Texture23 = MJHTex23;
#declare L3Texture23_slope = MJHTex23Slope;
#declare L3Color23 = MJHMat23;
#declare L3Color23_slope = MJHMat23Slope;
#declare ldMat23 = MJHMat23;
#declare ldTex23 = MJHTex23;
#declare lg_violet_blue = MJHTex23;
#declare lc_Dark_Blue_Violet = MJHTex23;

// row 25 - Edge_Colour
#declare LDXColor24 = MJHMat24;
#declare LDXColor24_slope = MJHMat24Slope;
#declare L3Texture24 = MJHTex24;
#declare L3Texture24_slope = MJHTex24Slope;
#declare L3Color24 = MJHMat24;
#declare L3Color24_slope = MJHMat24Slope;
#declare ldMat24 = MJHMat24;
#declare ldTex24 = MJHTex24;
#declare lg_undefined = MJHTex24;
#declare lc_Edge_Colour = MJHTex24;

// row 26 - Orange
#declare LDXColor25 = MJHMat25;
#declare LDXColor25_slope = MJHMat25Slope;
#declare L3Texture25 = MJHTex25;
#declare L3Texture25_slope = MJHTex25Slope;
#declare L3Color25 = MJHMat25;
#declare L3Color25_slope = MJHMat25Slope;
#declare ldMat25 = MJHMat25;
#declare ldTex25 = MJHTex25;
#declare lg_orange = MJHTex25;
#declare lc_Orange = MJHTex25;

// row 27 - Magenta
#declare LDXColor26 = MJHMat26;
#declare LDXColor26_slope = MJHMat26Slope;
#declare L3Texture26 = MJHTex26;
#declare L3Texture26_slope = MJHTex26Slope;
#declare L3Color26 = MJHMat26;
#declare L3Color26_slope = MJHMat26Slope;
#declare ldMat26 = MJHMat26;
#declare ldTex26 = MJHTex26;
#declare lg_magenta = MJHTex26;
#declare lc_Magenta = MJHTex26;

// row 28 - Lime
#declare LDXColor27 = MJHMat27;
#declare LDXColor27_slope = MJHMat27Slope;
#declare L3Texture27 = MJHTex27;
#declare L3Texture27_slope = MJHTex27Slope;
#declare L3Color27 = MJHMat27;
#declare L3Color27_slope = MJHMat27Slope;
#declare ldMat27 = MJHMat27;
#declare ldTex27 = MJHTex27;
#declare lg_lime = MJHTex27;
#declare lc_Lime = MJHTex27;

// row 29 - Dark_Tan
#declare LDXColor28 = MJHMat28;
#declare LDXColor28_slope = MJHMat28Slope;
#declare L3Texture28 = MJHTex28;
#declare L3Texture28_slope = MJHTex28Slope;
#declare L3Color28 = MJHMat28;
#declare L3Color28_slope = MJHMat28Slope;
#declare ldMat28 = MJHMat28;
#declare ldTex28 = MJHTex28;
#declare lg_dark_tan = MJHTex28;
#declare lc_Dark_Tan = MJHTex28;

// row 30 - Bright_Pink
#declare LDXColor29 = MJHMat29;
#declare LDXColor29_slope = MJHMat29Slope;
#declare L3Texture29 = MJHTex29;
#declare L3Texture29_slope = MJHTex29Slope;
#declare L3Color29 = MJHMat29;
#declare L3Color29_slope = MJHMat29Slope;
#declare ldMat29 = MJHMat29;
#declare ldTex29 = MJHTex29;
#declare lg_light_purple = MJHTex29;
#declare lc_Bright_Pink = MJHTex29;

// row 31 - Medium_Lavender
#declare LDXColor30 = MJHMat30;
#declare LDXColor30_slope = MJHMat30Slope;
#declare L3Texture30 = MJHTex30;
#declare L3Texture30_slope = MJHTex30Slope;
#declare L3Color30 = MJHMat30;
#declare L3Color30_slope = MJHMat30Slope;
#declare ldMat30 = MJHMat30;
#declare ldTex30 = MJHTex30;
#declare lg_medium_lavender = MJHTex30;
#declare lc_Medium_Lavender = MJHTex30;

// row 32 - Lavender
#declare LDXColor31 = MJHMat31;
#declare LDXColor31_slope = MJHMat31Slope;
#declare L3Texture31 = MJHTex31;
#declare L3Texture31_slope = MJHTex31Slope;
#declare L3Color31 = MJHMat31;
#declare L3Color31_slope = MJHMat31Slope;
#declare ldMat31 = MJHMat31;
#declare ldTex31 = MJHTex31;
#declare lg_lavender = MJHTex31;
#declare lc_Lavender = MJHTex31;

// row 33 - Trans_Black_IR_Lens
#declare LDXColor32 = MJHMat32;
#declare LDXColor32_slope = MJHMat32Slope;
#declare L3Texture32 = MJHTex32;
#declare L3Texture32_slope = MJHTex32Slope;
#declare L3Color32 = MJHMat32;
#declare L3Color32_slope = MJHMat32Slope;
#declare ldMat32 = MJHMat32;
#declare ldTex32 = MJHTex32;
#declare lg_black_ir = MJHTex32;
#declare lc_Trans_Black_IR_Lens = MJHTex32;

// row 34 - Trans_Dark_Blue
#declare LDXColor33 = MJHMat33;
#declare LDXColor33_slope = MJHMat33Slope;
#declare L3Texture33 = MJHTex33;
#declare L3Texture33_slope = MJHTex33Slope;
#declare L3Color33 = MJHMat33;
#declare L3Color33_slope = MJHMat33Slope;
#declare ldMat33 = MJHMat33;
#declare ldTex33 = MJHTex33;
#declare lg_clear_blue = MJHTex33;
#declare lc_Trans_Dark_Blue = MJHTex33;

// row 35 - Trans_Green
#declare LDXColor34 = MJHMat34;
#declare LDXColor34_slope = MJHMat34Slope;
#declare L3Texture34 = MJHTex34;
#declare L3Texture34_slope = MJHTex34Slope;
#declare L3Color34 = MJHMat34;
#declare L3Color34_slope = MJHMat34Slope;
#declare ldMat34 = MJHMat34;
#declare ldTex34 = MJHTex34;
#declare lg_clear_green = MJHTex34;
#declare lc_Trans_Green = MJHTex34;

// row 36 - Trans_Bright_Green
#declare LDXColor35 = MJHMat35;
#declare LDXColor35_slope = MJHMat35Slope;
#declare L3Texture35 = MJHTex35;
#declare L3Texture35_slope = MJHTex35Slope;
#declare L3Color35 = MJHMat35;
#declare L3Color35_slope = MJHMat35Slope;
#declare ldMat35 = MJHMat35;
#declare ldTex35 = MJHTex35;
#declare lg_clear_bright_green = MJHTex35;
#declare lc_Trans_Bright_Green = MJHTex35;

// row 37 - Trans_Red
#declare LDXColor36 = MJHMat36;
#declare LDXColor36_slope = MJHMat36Slope;
#declare L3Texture36 = MJHTex36;
#declare L3Texture36_slope = MJHTex36Slope;
#declare L3Color36 = MJHMat36;
#declare L3Color36_slope = MJHMat36Slope;
#declare ldMat36 = MJHMat36;
#declare ldTex36 = MJHTex36;
#declare lg_clear_red = MJHTex36;
#declare lc_Trans_Red = MJHTex36;

// row 38 - Trans_Dark_Pink
#declare LDXColor37 = MJHMat37;
#declare LDXColor37_slope = MJHMat37Slope;
#declare L3Texture37 = MJHTex37;
#declare L3Texture37_slope = MJHTex37Slope;
#declare L3Color37 = MJHMat37;
#declare L3Color37_slope = MJHMat37Slope;
#declare ldMat37 = MJHMat37;
#declare ldTex37 = MJHTex37;
#declare lg_clear_violet = MJHTex37;
#declare lc_Trans_Dark_Pink = MJHTex37;

// row 39 - Trans_Neon_Orange
#declare LDXColor38 = MJHMat38;
#declare LDXColor38_slope = MJHMat38Slope;
#declare L3Texture38 = MJHTex38;
#declare L3Texture38_slope = MJHTex38Slope;
#declare L3Color38 = MJHMat38;
#declare L3Color38_slope = MJHMat38Slope;
#declare ldMat38 = MJHMat38;
#declare ldTex38 = MJHTex38;
#declare lg_clear_neon_orange = MJHTex38;
#declare lc_Trans_Neon_Orange = MJHTex38;

// row 40 - Trans_Very_Light_Blue
#declare LDXColor39 = MJHMat39;
#declare LDXColor39_slope = MJHMat39Slope;
#declare L3Texture39 = MJHTex39;
#declare L3Texture39_slope = MJHTex39Slope;
#declare L3Color39 = MJHMat39;
#declare L3Color39_slope = MJHMat39Slope;
#declare ldMat39 = MJHMat39;
#declare ldTex39 = MJHTex39;
#declare lg_clear_brown = MJHTex39;
#declare lc_Trans_Very_Light_Blue = MJHTex39;

// row 41 - Trans_Black
#declare LDXColor40 = MJHMat40;
#declare LDXColor40_slope = MJHMat40Slope;
#declare L3Texture40 = MJHTex40;
#declare L3Texture40_slope = MJHTex40Slope;
#declare L3Color40 = MJHMat40;
#declare L3Color40_slope = MJHMat40Slope;
#declare ldMat40 = MJHMat40;
#declare ldTex40 = MJHTex40;
#declare lg_clear_brown = MJHTex40;
#declare lc_Trans_Black = MJHTex40;

// row 42 - Trans_Medium_Blue
#declare LDXColor41 = MJHMat41;
#declare LDXColor41_slope = MJHMat41Slope;
#declare L3Texture41 = MJHTex41;
#declare L3Texture41_slope = MJHTex41Slope;
#declare L3Color41 = MJHMat41;
#declare L3Color41_slope = MJHMat41Slope;
#declare ldMat41 = MJHMat41;
#declare ldTex41 = MJHTex41;
#declare lg_clear_cyan = MJHTex41;
#declare lc_Trans_Medium_Blue = MJHTex41;

// row 43 - Trans_Neon_Green
#declare LDXColor42 = MJHMat42;
#declare LDXColor42_slope = MJHMat42Slope;
#declare L3Texture42 = MJHTex42;
#declare L3Texture42_slope = MJHTex42Slope;
#declare L3Color42 = MJHMat42;
#declare L3Color42_slope = MJHMat42Slope;
#declare ldMat42 = MJHMat42;
#declare ldTex42 = MJHTex42;
#declare lg_clear_neon_yellow = MJHTex42;
#declare lc_Trans_Neon_Green = MJHTex42;

// row 44 - Trans_Light_Blue
#declare LDXColor43 = MJHMat43;
#declare LDXColor43_slope = MJHMat43Slope;
#declare L3Texture43 = MJHTex43;
#declare L3Texture43_slope = MJHTex43Slope;
#declare L3Color43 = MJHMat43;
#declare L3Color43_slope = MJHMat43Slope;
#declare ldMat43 = MJHMat43;
#declare ldTex43 = MJHTex43;
#declare lg_clear_light_blue = MJHTex43;
#declare lc_Trans_Light_Blue = MJHTex43;

// row 45 - Trans_Bright_Reddish_Lilac
#declare LDXColor44 = MJHMat44;
#declare LDXColor44_slope = MJHMat44Slope;
#declare L3Texture44 = MJHTex44;
#declare L3Texture44_slope = MJHTex44Slope;
#declare L3Color44 = MJHMat44;
#declare L3Color44_slope = MJHMat44Slope;
#declare ldMat44 = MJHMat44;
#declare ldTex44 = MJHTex44;
#declare lg_clear_light_purple = MJHTex44;
#declare lc_Trans_Bright_Reddish_Lilac = MJHTex44;

// row 46 - Trans_Pink
#declare LDXColor45 = MJHMat45;
#declare LDXColor45_slope = MJHMat45Slope;
#declare L3Texture45 = MJHTex45;
#declare L3Texture45_slope = MJHTex45Slope;
#declare L3Color45 = MJHMat45;
#declare L3Color45_slope = MJHMat45Slope;
#declare ldMat45 = MJHMat45;
#declare ldTex45 = MJHTex45;
#declare lg_clear_pink = MJHTex45;
#declare lc_Trans_Pink = MJHTex45;

// row 47 - Trans_Yellow
#declare LDXColor46 = MJHMat46;
#declare LDXColor46_slope = MJHMat46Slope;
#declare L3Texture46 = MJHTex46;
#declare L3Texture46_slope = MJHTex46Slope;
#declare L3Color46 = MJHMat46;
#declare L3Color46_slope = MJHMat46Slope;
#declare ldMat46 = MJHMat46;
#declare ldTex46 = MJHTex46;
#declare lg_clear_yellow = MJHTex46;
#declare lc_Trans_Yellow = MJHTex46;

// row 48 - Trans_Clear
#declare LDXColor47 = MJHMat47;
#declare LDXColor47_slope = MJHMat47Slope;
#declare L3Texture47 = MJHTex47;
#declare L3Texture47_slope = MJHTex47Slope;
#declare L3Color47 = MJHMat47;
#declare L3Color47_slope = MJHMat47Slope;
#declare ldMat47 = MJHMat47;
#declare ldTex47 = MJHTex47;
#declare lg_clear = MJHTex47;
#declare lc_Trans_Clear = MJHTex47;

// row 49 - Trans_Purple
#declare LDXColor52 = MJHMat52;
#declare LDXColor52_slope = MJHMat52Slope;
#declare L3Texture52 = MJHTex52;
#declare L3Texture52_slope = MJHTex52Slope;
#declare L3Color52 = MJHMat52;
#declare L3Color52_slope = MJHMat52Slope;
#declare ldMat52 = MJHMat52;
#declare ldTex52 = MJHTex52;
#declare lg_clear_violet = MJHTex52;
#declare lc_Trans_Purple = MJHTex52;

// row 50 - Trans_Neon_Yellow
#declare LDXColor54 = MJHMat54;
#declare LDXColor54_slope = MJHMat54Slope;
#declare L3Texture54 = MJHTex54;
#declare L3Texture54_slope = MJHTex54Slope;
#declare L3Color54 = MJHMat54;
#declare L3Color54_slope = MJHMat54Slope;
#declare ldMat54 = MJHMat54;
#declare ldTex54 = MJHTex54;
#declare lg_clear_neon_yellow = MJHTex54;
#declare lc_Trans_Neon_Yellow = MJHTex54;

// row 51 - Trans_Orange
#declare LDXColor57 = MJHMat57;
#declare LDXColor57_slope = MJHMat57Slope;
#declare L3Texture57 = MJHTex57;
#declare L3Texture57_slope = MJHTex57Slope;
#declare L3Color57 = MJHMat57;
#declare L3Color57_slope = MJHMat57Slope;
#declare ldMat57 = MJHMat57;
#declare ldTex57 = MJHTex57;
#declare lg_clear_neon_orange = MJHTex57;
#declare lc_Trans_Orange = MJHTex57;

// row 52 - Chrome_Antique_Brass
#declare LDXColor60 = MJHMat60;
#declare LDXColor60_slope = MJHMat60Slope;
#declare L3Texture60 = MJHTex60;
#declare L3Texture60_slope = MJHTex60Slope;
#declare L3Color60 = MJHMat60;
#declare L3Color60_slope = MJHMat60Slope;
#declare ldMat60 = MJHMat60;
#declare ldTex60 = MJHTex60;
#declare lg_undefined = MJHTex60;
#declare lc_Chrome_Antique_Brass = MJHTex60;

// row 53 - Chrome_Blue
#declare LDXColor61 = MJHMat61;
#declare LDXColor61_slope = MJHMat61Slope;
#declare L3Texture61 = MJHTex61;
#declare L3Texture61_slope = MJHTex61Slope;
#declare L3Color61 = MJHMat61;
#declare L3Color61_slope = MJHMat61Slope;
#declare ldMat61 = MJHMat61;
#declare ldTex61 = MJHTex61;
#declare lg_undefined = MJHTex61;
#declare lc_Chrome_Blue = MJHTex61;

// row 54 - Chrome_Green
#declare LDXColor62 = MJHMat62;
#declare LDXColor62_slope = MJHMat62Slope;
#declare L3Texture62 = MJHTex62;
#declare L3Texture62_slope = MJHTex62Slope;
#declare L3Color62 = MJHMat62;
#declare L3Color62_slope = MJHMat62Slope;
#declare ldMat62 = MJHMat62;
#declare ldTex62 = MJHTex62;
#declare lg_undefined = MJHTex62;
#declare lc_Chrome_Green = MJHTex62;

// row 55 - Chrome_Pink
#declare LDXColor63 = MJHMat63;
#declare LDXColor63_slope = MJHMat63Slope;
#declare L3Texture63 = MJHTex63;
#declare L3Texture63_slope = MJHTex63Slope;
#declare L3Color63 = MJHMat63;
#declare L3Color63_slope = MJHMat63Slope;
#declare ldMat63 = MJHMat63;
#declare ldTex63 = MJHTex63;
#declare lg_undefined = MJHTex63;
#declare lc_Chrome_Pink = MJHTex63;

// row 56 - Chrome_Black
#declare LDXColor64 = MJHMat64;
#declare LDXColor64_slope = MJHMat64Slope;
#declare L3Texture64 = MJHTex64;
#declare L3Texture64_slope = MJHTex64Slope;
#declare L3Color64 = MJHMat64;
#declare L3Color64_slope = MJHMat64Slope;
#declare ldMat64 = MJHMat64;
#declare ldTex64 = MJHTex64;
#declare lg_undefined = MJHTex64;
#declare lc_Chrome_Black = MJHTex64;

// row 57 - Rubber_Yellow
#declare LDXColor65 = MJHMat65;
#declare LDXColor65_slope = MJHMat65Slope;
#declare L3Texture65 = MJHTex65;
#declare L3Texture65_slope = MJHTex65Slope;
#declare L3Color65 = MJHMat65;
#declare L3Color65_slope = MJHMat65Slope;
#declare ldMat65 = MJHMat65;
#declare ldTex65 = MJHTex65;
#declare lg_rubber_yellow = MJHTex65;
#declare lc_Rubber_Yellow = MJHTex65;

// row 58 - Rubber_Trans_Yellow
#declare LDXColor66 = MJHMat66;
#declare LDXColor66_slope = MJHMat66Slope;
#declare L3Texture66 = MJHTex66;
#declare L3Texture66_slope = MJHTex66Slope;
#declare L3Color66 = MJHMat66;
#declare L3Color66_slope = MJHMat66Slope;
#declare ldMat66 = MJHMat66;
#declare ldTex66 = MJHTex66;
#declare lg_rubber_clear_yellow = MJHTex66;
#declare lc_Rubber_Trans_Yellow = MJHTex66;

// row 59 - Rubber_Trans_Clear
#declare LDXColor67 = MJHMat67;
#declare LDXColor67_slope = MJHMat67Slope;
#declare L3Texture67 = MJHTex67;
#declare L3Texture67_slope = MJHTex67Slope;
#declare L3Color67 = MJHMat67;
#declare L3Color67_slope = MJHMat67Slope;
#declare ldMat67 = MJHMat67;
#declare ldTex67 = MJHTex67;
#declare lg_rubber_clear = MJHTex67;
#declare lc_Rubber_Trans_Clear = MJHTex67;

// row 60 - Very_Light_Orange
#declare LDXColor68 = MJHMat68;
#declare LDXColor68_slope = MJHMat68Slope;
#declare L3Texture68 = MJHTex68;
#declare L3Texture68_slope = MJHTex68Slope;
#declare L3Color68 = MJHMat68;
#declare L3Color68_slope = MJHMat68Slope;
#declare ldMat68 = MJHMat68;
#declare ldTex68 = MJHTex68;
#declare lg_very_light_orange = MJHTex68;
#declare lc_Very_Light_Orange = MJHTex68;

// row 61 - Bright_Reddish_Lilac
#declare LDXColor69 = MJHMat69;
#declare LDXColor69_slope = MJHMat69Slope;
#declare L3Texture69 = MJHTex69;
#declare L3Texture69_slope = MJHTex69Slope;
#declare L3Color69 = MJHMat69;
#declare L3Color69_slope = MJHMat69Slope;
#declare ldMat69 = MJHMat69;
#declare ldTex69 = MJHTex69;
#declare lg_bright_purple = MJHTex69;
#declare lc_Bright_Reddish_Lilac = MJHTex69;

// row 62 - Reddish_Brown
#declare LDXColor70 = MJHMat70;
#declare LDXColor70_slope = MJHMat70Slope;
#declare L3Texture70 = MJHTex70;
#declare L3Texture70_slope = MJHTex70Slope;
#declare L3Color70 = MJHMat70;
#declare L3Color70_slope = MJHMat70Slope;
#declare ldMat70 = MJHMat70;
#declare ldTex70 = MJHTex70;
#declare lg_reddish_brown = MJHTex70;
#declare lc_Reddish_Brown = MJHTex70;

// row 63 - Light_Bluish_Grey
#declare LDXColor71 = MJHMat71;
#declare LDXColor71_slope = MJHMat71Slope;
#declare L3Texture71 = MJHTex71;
#declare L3Texture71_slope = MJHTex71Slope;
#declare L3Color71 = MJHMat71;
#declare L3Color71_slope = MJHMat71Slope;
#declare ldMat71 = MJHMat71;
#declare ldTex71 = MJHTex71;
#declare lg_bluish_grey = MJHTex71;
#declare lc_Light_Bluish_Grey = MJHTex71;

// row 64 - Dark_Bluish_Grey
#declare LDXColor72 = MJHMat72;
#declare LDXColor72_slope = MJHMat72Slope;
#declare L3Texture72 = MJHTex72;
#declare L3Texture72_slope = MJHTex72Slope;
#declare L3Color72 = MJHMat72;
#declare L3Color72_slope = MJHMat72Slope;
#declare ldMat72 = MJHMat72;
#declare ldTex72 = MJHTex72;
#declare lg_dark_bluish_grey = MJHTex72;
#declare lc_Dark_Bluish_Grey = MJHTex72;

// row 65 - Medium_Blue
#declare LDXColor73 = MJHMat73;
#declare LDXColor73_slope = MJHMat73Slope;
#declare L3Texture73 = MJHTex73;
#declare L3Texture73_slope = MJHTex73Slope;
#declare L3Color73 = MJHMat73;
#declare L3Color73_slope = MJHMat73Slope;
#declare ldMat73 = MJHMat73;
#declare ldTex73 = MJHTex73;
#declare lg_medium_blue = MJHTex73;
#declare lc_Medium_Blue = MJHTex73;

// row 66 - Medium_Green
#declare LDXColor74 = MJHMat74;
#declare LDXColor74_slope = MJHMat74Slope;
#declare L3Texture74 = MJHTex74;
#declare L3Texture74_slope = MJHTex74Slope;
#declare L3Color74 = MJHMat74;
#declare L3Color74_slope = MJHMat74Slope;
#declare ldMat74 = MJHMat74;
#declare ldTex74 = MJHTex74;
#declare lg_medium_green = MJHTex74;
#declare lc_Medium_Green = MJHTex74;

// row 67 - Speckle_Black_Copper
#declare LDXColor75 = MJHMat75;
#declare LDXColor75_slope = MJHMat75Slope;
#declare L3Texture75 = MJHTex75;
#declare L3Texture75_slope = MJHTex75Slope;
#declare L3Color75 = MJHMat75;
#declare L3Color75_slope = MJHMat75Slope;
#declare ldMat75 = MJHMat75;
#declare ldTex75 = MJHTex75;
#declare lg_undefined = MJHTex75;
#declare lc_Speckle_Black_Copper = MJHTex75;

// row 68 - Speckle_Dark_Bluish_Grey_Silver
#declare LDXColor76 = MJHMat76;
#declare LDXColor76_slope = MJHMat76Slope;
#declare L3Texture76 = MJHTex76;
#declare L3Texture76_slope = MJHTex76Slope;
#declare L3Color76 = MJHMat76;
#declare L3Color76_slope = MJHMat76Slope;
#declare ldMat76 = MJHMat76;
#declare ldTex76 = MJHTex76;
#declare lg_undefined = MJHTex76;
#declare lc_Speckle_Dark_Bluish_Grey_Silver = MJHTex76;

// row 69 - Light_Pink
#declare LDXColor77 = MJHMat77;
#declare LDXColor77_slope = MJHMat77Slope;
#declare L3Texture77 = MJHTex77;
#declare L3Texture77_slope = MJHTex77Slope;
#declare L3Color77 = MJHMat77;
#declare L3Color77_slope = MJHMat77Slope;
#declare ldMat77 = MJHMat77;
#declare ldTex77 = MJHTex77;
#declare lg_paradisa_pink = MJHTex77;
#declare lc_Light_Pink = MJHTex77;

// row 70 - Light_Flesh
#declare LDXColor78 = MJHMat78;
#declare LDXColor78_slope = MJHMat78Slope;
#declare L3Texture78 = MJHTex78;
#declare L3Texture78_slope = MJHTex78Slope;
#declare L3Color78 = MJHMat78;
#declare L3Color78_slope = MJHMat78Slope;
#declare ldMat78 = MJHMat78;
#declare ldTex78 = MJHTex78;
#declare lg_light_flesh = MJHTex78;
#declare lc_Light_Flesh = MJHTex78;

// row 71 - Milky_White
#declare LDXColor79 = MJHMat79;
#declare LDXColor79_slope = MJHMat79Slope;
#declare L3Texture79 = MJHTex79;
#declare L3Texture79_slope = MJHTex79Slope;
#declare L3Color79 = MJHMat79;
#declare L3Color79_slope = MJHMat79Slope;
#declare ldMat79 = MJHMat79;
#declare ldTex79 = MJHTex79;
#declare lg_milky_white = MJHTex79;
#declare lc_Milky_White = MJHTex79;

// row 72 - Metallic_Silver
#declare LDXColor80 = MJHMat80;
#declare LDXColor80_slope = MJHMat80Slope;
#declare L3Texture80 = MJHTex80;
#declare L3Texture80_slope = MJHTex80Slope;
#declare L3Color80 = MJHMat80;
#declare L3Color80_slope = MJHMat80Slope;
#declare ldMat80 = MJHMat80;
#declare ldTex80 = MJHTex80;
#declare lg_metallic_silver = MJHTex80;
#declare lc_Metallic_Silver = MJHTex80;

// row 73 - Metallic_Green
#declare LDXColor81 = MJHMat81;
#declare LDXColor81_slope = MJHMat81Slope;
#declare L3Texture81 = MJHTex81;
#declare L3Texture81_slope = MJHTex81Slope;
#declare L3Color81 = MJHMat81;
#declare L3Color81_slope = MJHMat81Slope;
#declare ldMat81 = MJHMat81;
#declare ldTex81 = MJHTex81;
#declare lg_undefined = MJHTex81;
#declare lc_Metallic_Green = MJHTex81;

// row 74 - Metallic_Gold
#declare LDXColor82 = MJHMat82;
#declare LDXColor82_slope = MJHMat82Slope;
#declare L3Texture82 = MJHTex82;
#declare L3Texture82_slope = MJHTex82Slope;
#declare L3Color82 = MJHMat82;
#declare L3Color82_slope = MJHMat82Slope;
#declare ldMat82 = MJHMat82;
#declare ldTex82 = MJHTex82;
#declare lg_metallic_gold = MJHTex82;
#declare lc_Metallic_Gold = MJHTex82;

// row 75 - Metallic_Black
#declare LDXColor83 = MJHMat83;
#declare LDXColor83_slope = MJHMat83Slope;
#declare L3Texture83 = MJHTex83;
#declare L3Texture83_slope = MJHTex83Slope;
#declare L3Color83 = MJHMat83;
#declare L3Color83_slope = MJHMat83Slope;
#declare ldMat83 = MJHMat83;
#declare ldTex83 = MJHTex83;
#declare lg_undefined = MJHTex83;
#declare lc_Metallic_Black = MJHTex83;

// row 76 - Medium_Dark_Flesh
#declare LDXColor84 = MJHMat84;
#declare LDXColor84_slope = MJHMat84Slope;
#declare L3Texture84 = MJHTex84;
#declare L3Texture84_slope = MJHTex84Slope;
#declare L3Color84 = MJHMat84;
#declare L3Color84_slope = MJHMat84Slope;
#declare ldMat84 = MJHMat84;
#declare ldTex84 = MJHTex84;
#declare lg_medium_dark_flesh = MJHTex84;
#declare lc_Medium_Dark_Flesh = MJHTex84;

// row 77 - Medium_Lilac
#declare LDXColor85 = MJHMat85;
#declare LDXColor85_slope = MJHMat85Slope;
#declare L3Texture85 = MJHTex85;
#declare L3Texture85_slope = MJHTex85Slope;
#declare L3Color85 = MJHMat85;
#declare L3Color85_slope = MJHMat85Slope;
#declare ldMat85 = MJHMat85;
#declare ldTex85 = MJHTex85;
#declare lg_medium_violet = MJHTex85;
#declare lc_Medium_Lilac = MJHTex85;

// row 78 - Dark_Flesh
#declare LDXColor86 = MJHMat86;
#declare LDXColor86_slope = MJHMat86Slope;
#declare L3Texture86 = MJHTex86;
#declare L3Texture86_slope = MJHTex86Slope;
#declare L3Color86 = MJHMat86;
#declare L3Color86_slope = MJHMat86Slope;
#declare ldMat86 = MJHMat86;
#declare ldTex86 = MJHTex86;
#declare lg_dark_flesh = MJHTex86;
#declare lc_Dark_Flesh = MJHTex86;

// row 79 - Metallic_Dark_Grey
#declare LDXColor87 = MJHMat87;
#declare LDXColor87_slope = MJHMat87Slope;
#declare L3Texture87 = MJHTex87;
#declare L3Texture87_slope = MJHTex87Slope;
#declare L3Color87 = MJHMat87;
#declare L3Color87_slope = MJHMat87Slope;
#declare ldMat87 = MJHMat87;
#declare ldTex87 = MJHTex87;
#declare lg_undefined = MJHTex87;
#declare lc_Metallic_Dark_Grey = MJHTex87;

// row 80 - Blue_Violet
#declare LDXColor89 = MJHMat89;
#declare LDXColor89_slope = MJHMat89Slope;
#declare L3Texture89 = MJHTex89;
#declare L3Texture89_slope = MJHTex89Slope;
#declare L3Color89 = MJHMat89;
#declare L3Color89_slope = MJHMat89Slope;
#declare ldMat89 = MJHMat89;
#declare ldTex89 = MJHTex89;
#declare lg_royal_blue = MJHTex89;
#declare lc_Blue_Violet = MJHTex89;

// row 81 - Flesh
#declare LDXColor92 = MJHMat92;
#declare LDXColor92_slope = MJHMat92Slope;
#declare L3Texture92 = MJHTex92;
#declare L3Texture92_slope = MJHTex92Slope;
#declare L3Color92 = MJHMat92;
#declare L3Color92_slope = MJHMat92Slope;
#declare ldMat92 = MJHMat92;
#declare ldTex92 = MJHTex92;
#declare lg_flesh = MJHTex92;
#declare lc_Flesh = MJHTex92;

// row 82 - Light_Salmon
#declare LDXColor100 = MJHMat100;
#declare LDXColor100_slope = MJHMat100Slope;
#declare L3Texture100 = MJHTex100;
#declare L3Texture100_slope = MJHTex100Slope;
#declare L3Color100 = MJHMat100;
#declare L3Color100_slope = MJHMat100Slope;
#declare ldMat100 = MJHMat100;
#declare ldTex100 = MJHTex100;
#declare lg_light_salmon = MJHTex100;
#declare lc_Light_Salmon = MJHTex100;

// row 83 - Violet
#declare LDXColor110 = MJHMat110;
#declare LDXColor110_slope = MJHMat110Slope;
#declare L3Texture110 = MJHTex110;
#declare L3Texture110_slope = MJHTex110Slope;
#declare L3Color110 = MJHMat110;
#declare L3Color110_slope = MJHMat110Slope;
#declare ldMat110 = MJHMat110;
#declare ldTex110 = MJHTex110;
#declare lg_undefined = MJHTex110;
#declare lc_Violet = MJHTex110;

// row 84 - Medium_Violet
#declare LDXColor112 = MJHMat112;
#declare LDXColor112_slope = MJHMat112Slope;
#declare L3Texture112 = MJHTex112;
#declare L3Texture112_slope = MJHTex112Slope;
#declare L3Color112 = MJHMat112;
#declare L3Color112_slope = MJHMat112Slope;
#declare ldMat112 = MJHMat112;
#declare ldTex112 = MJHTex112;
#declare lg_undefined = MJHTex112;
#declare lc_Medium_Violet = MJHTex112;

// row 85 - Glitter_Trans_Dark_Pink
#declare LDXColor114 = MJHMat114;
#declare LDXColor114_slope = MJHMat114Slope;
#declare L3Texture114 = MJHTex114;
#declare L3Texture114_slope = MJHTex114Slope;
#declare L3Color114 = MJHMat114;
#declare L3Color114_slope = MJHMat114Slope;
#declare ldMat114 = MJHMat114;
#declare ldTex114 = MJHTex114;
#declare lg_undefined = MJHTex114;
#declare lc_Glitter_Trans_Dark_Pink = MJHTex114;

// row 86 - Medium_Lime
#declare LDXColor115 = MJHMat115;
#declare LDXColor115_slope = MJHMat115Slope;
#declare L3Texture115 = MJHTex115;
#declare L3Texture115_slope = MJHTex115Slope;
#declare L3Color115 = MJHMat115;
#declare L3Color115_slope = MJHMat115Slope;
#declare ldMat115 = MJHMat115;
#declare ldTex115 = MJHTex115;
#declare lg_medium_lime = MJHTex115;
#declare lc_Medium_Lime = MJHTex115;

// row 87 - Glitter_Trans_Clear
#declare LDXColor117 = MJHMat117;
#declare LDXColor117_slope = MJHMat117Slope;
#declare L3Texture117 = MJHTex117;
#declare L3Texture117_slope = MJHTex117Slope;
#declare L3Color117 = MJHMat117;
#declare L3Color117_slope = MJHMat117Slope;
#declare ldMat117 = MJHMat117;
#declare ldTex117 = MJHTex117;
#declare lg_undefined = MJHTex117;
#declare lc_Glitter_Trans_Clear = MJHTex117;

// row 88 - Aqua
#declare LDXColor118 = MJHMat118;
#declare LDXColor118_slope = MJHMat118Slope;
#declare L3Texture118 = MJHTex118;
#declare L3Texture118_slope = MJHTex118Slope;
#declare L3Color118 = MJHMat118;
#declare L3Color118_slope = MJHMat118Slope;
#declare ldMat118 = MJHMat118;
#declare ldTex118 = MJHTex118;
#declare lg_undefined = MJHTex118;
#declare lc_Aqua = MJHTex118;

// row 89 - Light_Lime
#declare LDXColor120 = MJHMat120;
#declare LDXColor120_slope = MJHMat120Slope;
#declare L3Texture120 = MJHTex120;
#declare L3Texture120_slope = MJHTex120Slope;
#declare L3Color120 = MJHMat120;
#declare L3Color120_slope = MJHMat120Slope;
#declare ldMat120 = MJHMat120;
#declare ldTex120 = MJHTex120;
#declare lg_undefined = MJHTex120;
#declare lc_Light_Lime = MJHTex120;

// row 90 - Light_Orange
#declare LDXColor125 = MJHMat125;
#declare LDXColor125_slope = MJHMat125Slope;
#declare L3Texture125 = MJHTex125;
#declare L3Texture125_slope = MJHTex125Slope;
#declare L3Color125 = MJHMat125;
#declare L3Color125_slope = MJHMat125Slope;
#declare ldMat125 = MJHMat125;
#declare ldTex125 = MJHTex125;
#declare lg_undefined = MJHTex125;
#declare lc_Light_Orange = MJHTex125;

// row 91 - Dark_Nougat
#declare LDXColor128 = MJHMat128;
#declare LDXColor128_slope = MJHMat128Slope;
#declare L3Texture128 = MJHTex128;
#declare L3Texture128_slope = MJHTex128Slope;
#declare L3Color128 = MJHMat128;
#declare L3Color128_slope = MJHMat128Slope;
#declare ldMat128 = MJHMat128;
#declare ldTex128 = MJHTex128;
#declare lg_undefined = MJHTex128;
#declare lc_Dark_Nougat = MJHTex128;

// row 92 - Glitter_Trans_Purple
#declare LDXColor129 = MJHMat129;
#declare LDXColor129_slope = MJHMat129Slope;
#declare L3Texture129 = MJHTex129;
#declare L3Texture129_slope = MJHTex129Slope;
#declare L3Color129 = MJHMat129;
#declare L3Color129_slope = MJHMat129Slope;
#declare ldMat129 = MJHMat129;
#declare ldTex129 = MJHTex129;
#declare lg_undefined = MJHTex129;
#declare lc_Glitter_Trans_Purple = MJHTex129;

// row 93 - Speckle_Black_Silver
#declare LDXColor132 = MJHMat132;
#declare LDXColor132_slope = MJHMat132Slope;
#declare L3Texture132 = MJHTex132;
#declare L3Texture132_slope = MJHTex132Slope;
#declare L3Color132 = MJHMat132;
#declare L3Color132_slope = MJHMat132Slope;
#declare ldMat132 = MJHMat132;
#declare ldTex132 = MJHTex132;
#declare lg_undefined = MJHTex132;
#declare lc_Speckle_Black_Silver = MJHTex132;

// row 94 - Speckle_Black_Gold
#declare LDXColor133 = MJHMat133;
#declare LDXColor133_slope = MJHMat133Slope;
#declare L3Texture133 = MJHTex133;
#declare L3Texture133_slope = MJHTex133Slope;
#declare L3Color133 = MJHMat133;
#declare L3Color133_slope = MJHMat133Slope;
#declare ldMat133 = MJHMat133;
#declare ldTex133 = MJHTex133;
#declare lg_undefined = MJHTex133;
#declare lc_Speckle_Black_Gold = MJHTex133;

// row 95 - Copper
#declare LDXColor134 = MJHMat134;
#declare LDXColor134_slope = MJHMat134Slope;
#declare L3Texture134 = MJHTex134;
#declare L3Texture134_slope = MJHTex134Slope;
#declare L3Color134 = MJHMat134;
#declare L3Color134_slope = MJHMat134Slope;
#declare ldMat134 = MJHMat134;
#declare ldTex134 = MJHTex134;
#declare lg_pearl_copper = MJHTex134;
#declare lc_Copper = MJHTex134;

// row 96 - Pearl_Light_Grey
#declare LDXColor135 = MJHMat135;
#declare LDXColor135_slope = MJHMat135Slope;
#declare L3Texture135 = MJHTex135;
#declare L3Texture135_slope = MJHTex135Slope;
#declare L3Color135 = MJHMat135;
#declare L3Color135_slope = MJHMat135Slope;
#declare ldMat135 = MJHMat135;
#declare ldTex135 = MJHTex135;
#declare lg_pearl_grey = MJHTex135;
#declare lc_Pearl_Light_Grey = MJHTex135;

// row 97 - Metal_Blue
#declare LDXColor137 = MJHMat137;
#declare LDXColor137_slope = MJHMat137Slope;
#declare L3Texture137 = MJHTex137;
#declare L3Texture137_slope = MJHTex137Slope;
#declare L3Color137 = MJHMat137;
#declare L3Color137_slope = MJHMat137Slope;
#declare ldMat137 = MJHMat137;
#declare ldTex137 = MJHTex137;
#declare lg_pearl_blue = MJHTex137;
#declare lc_Metal_Blue = MJHTex137;

// row 98 - Pearl_Light_Gold
#declare LDXColor142 = MJHMat142;
#declare LDXColor142_slope = MJHMat142Slope;
#declare L3Texture142 = MJHTex142;
#declare L3Texture142_slope = MJHTex142Slope;
#declare L3Color142 = MJHMat142;
#declare L3Color142_slope = MJHMat142Slope;
#declare ldMat142 = MJHMat142;
#declare ldTex142 = MJHTex142;
#declare lg_pearl_gold = MJHTex142;
#declare lc_Pearl_Light_Gold = MJHTex142;

// row 99 - Pearl_Dark_Grey
#declare LDXColor148 = MJHMat148;
#declare LDXColor148_slope = MJHMat148Slope;
#declare L3Texture148 = MJHTex148;
#declare L3Texture148_slope = MJHTex148Slope;
#declare L3Color148 = MJHMat148;
#declare L3Color148_slope = MJHMat148Slope;
#declare ldMat148 = MJHMat148;
#declare ldTex148 = MJHTex148;
#declare lg_pearl_dark_grey = MJHTex148;
#declare lc_Pearl_Dark_Grey = MJHTex148;

// row 100 - Pearl_Very_Light_Grey
#declare LDXColor150 = MJHMat150;
#declare LDXColor150_slope = MJHMat150Slope;
#declare L3Texture150 = MJHTex150;
#declare L3Texture150_slope = MJHTex150Slope;
#declare L3Color150 = MJHMat150;
#declare L3Color150_slope = MJHMat150Slope;
#declare ldMat150 = MJHMat150;
#declare ldTex150 = MJHTex150;
#declare lg_undefined = MJHTex150;
#declare lc_Pearl_Very_Light_Grey = MJHTex150;

// row 101 - Very_Light_Bluish_Grey
#declare LDXColor151 = MJHMat151;
#declare LDXColor151_slope = MJHMat151Slope;
#declare L3Texture151 = MJHTex151;
#declare L3Texture151_slope = MJHTex151Slope;
#declare L3Color151 = MJHMat151;
#declare L3Color151_slope = MJHMat151Slope;
#declare ldMat151 = MJHMat151;
#declare ldTex151 = MJHTex151;
#declare lg_very_light_bluish_grey = MJHTex151;
#declare lc_Very_Light_Bluish_Grey = MJHTex151;

// row 102 - Flat_Dark_Gold
#declare LDXColor178 = MJHMat178;
#declare LDXColor178_slope = MJHMat178Slope;
#declare L3Texture178 = MJHTex178;
#declare L3Texture178_slope = MJHTex178Slope;
#declare L3Color178 = MJHMat178;
#declare L3Color178_slope = MJHMat178Slope;
#declare ldMat178 = MJHMat178;
#declare ldTex178 = MJHTex178;
#declare lg_undefined = MJHTex178;
#declare lc_Flat_Dark_Gold = MJHTex178;

// row 103 - Flat_Silver
#declare LDXColor179 = MJHMat179;
#declare LDXColor179_slope = MJHMat179Slope;
#declare L3Texture179 = MJHTex179;
#declare L3Texture179_slope = MJHTex179Slope;
#declare L3Color179 = MJHMat179;
#declare L3Color179_slope = MJHMat179Slope;
#declare ldMat179 = MJHMat179;
#declare ldTex179 = MJHTex179;
#declare lg_flat_silver = MJHTex179;
#declare lc_Flat_Silver = MJHTex179;

// row 104 - Pearl_White
#declare LDXColor183 = MJHMat183;
#declare LDXColor183_slope = MJHMat183Slope;
#declare L3Texture183 = MJHTex183;
#declare L3Texture183_slope = MJHTex183Slope;
#declare L3Color183 = MJHMat183;
#declare L3Color183_slope = MJHMat183Slope;
#declare ldMat183 = MJHMat183;
#declare ldTex183 = MJHTex183;
#declare lg_pearl_white = MJHTex183;
#declare lc_Pearl_White = MJHTex183;

// row 105 - Metallic_Bright_Red
#declare LDXColor184 = MJHMat184;
#declare LDXColor184_slope = MJHMat184Slope;
#declare L3Texture184 = MJHTex184;
#declare L3Texture184_slope = MJHTex184Slope;
#declare L3Color184 = MJHMat184;
#declare L3Color184_slope = MJHMat184Slope;
#declare ldMat184 = MJHMat184;
#declare ldTex184 = MJHTex184;
#declare lg_undefined = MJHTex184;
#declare lc_Metallic_Bright_Red = MJHTex184;

// row 106 - Metallic_Dark_Green
#declare LDXColor186 = MJHMat186;
#declare LDXColor186_slope = MJHMat186Slope;
#declare L3Texture186 = MJHTex186;
#declare L3Texture186_slope = MJHTex186Slope;
#declare L3Color186 = MJHMat186;
#declare L3Color186_slope = MJHMat186Slope;
#declare ldMat186 = MJHMat186;
#declare ldTex186 = MJHTex186;
#declare lg_undefined = MJHTex186;
#declare lc_Metallic_Dark_Green = MJHTex186;

// row 107 - Reddish_Gold
#declare LDXColor189 = MJHMat189;
#declare LDXColor189_slope = MJHMat189Slope;
#declare L3Texture189 = MJHTex189;
#declare L3Texture189_slope = MJHTex189Slope;
#declare L3Color189 = MJHMat189;
#declare L3Color189_slope = MJHMat189Slope;
#declare ldMat189 = MJHMat189;
#declare ldTex189 = MJHTex189;
#declare lg_undefined = MJHTex189;
#declare lc_Reddish_Gold = MJHTex189;

// row 108 - Bright_Light_Orange
#declare LDXColor191 = MJHMat191;
#declare LDXColor191_slope = MJHMat191Slope;
#declare L3Texture191 = MJHTex191;
#declare L3Texture191_slope = MJHTex191Slope;
#declare L3Color191 = MJHMat191;
#declare L3Color191_slope = MJHMat191Slope;
#declare ldMat191 = MJHMat191;
#declare ldTex191 = MJHTex191;
#declare lg_bright_light_orange = MJHTex191;
#declare lc_Bright_Light_Orange = MJHTex191;

// row 109 - Bright_Light_Blue
#declare LDXColor212 = MJHMat212;
#declare LDXColor212_slope = MJHMat212Slope;
#declare L3Texture212 = MJHTex212;
#declare L3Texture212_slope = MJHTex212Slope;
#declare L3Color212 = MJHMat212;
#declare L3Color212_slope = MJHMat212Slope;
#declare ldMat212 = MJHMat212;
#declare ldTex212 = MJHTex212;
#declare lg_bright_light_blue = MJHTex212;
#declare lc_Bright_Light_Blue = MJHTex212;

// row 110 - Rust
#declare LDXColor216 = MJHMat216;
#declare LDXColor216_slope = MJHMat216Slope;
#declare L3Texture216 = MJHTex216;
#declare L3Texture216_slope = MJHTex216Slope;
#declare L3Color216 = MJHMat216;
#declare L3Color216_slope = MJHMat216Slope;
#declare ldMat216 = MJHMat216;
#declare ldTex216 = MJHTex216;
#declare lg_rust = MJHTex216;
#declare lc_Rust = MJHTex216;

// row 111 - Reddish_Lilac
#declare LDXColor218 = MJHMat218;
#declare LDXColor218_slope = MJHMat218Slope;
#declare L3Texture218 = MJHTex218;
#declare L3Texture218_slope = MJHTex218Slope;
#declare L3Color218 = MJHMat218;
#declare L3Color218_slope = MJHMat218Slope;
#declare ldMat218 = MJHMat218;
#declare ldTex218 = MJHTex218;
#declare lg_undefined = MJHTex218;
#declare lc_Reddish_Lilac = MJHTex218;

// row 112 - Lilac
#declare LDXColor219 = MJHMat219;
#declare LDXColor219_slope = MJHMat219Slope;
#declare L3Texture219 = MJHTex219;
#declare L3Texture219_slope = MJHTex219Slope;
#declare L3Color219 = MJHMat219;
#declare L3Color219_slope = MJHMat219Slope;
#declare ldMat219 = MJHMat219;
#declare ldTex219 = MJHTex219;
#declare lg_undefined = MJHTex219;
#declare lc_Lilac = MJHTex219;

// row 113 - Bright_Light_Yellow
#declare LDXColor226 = MJHMat226;
#declare LDXColor226_slope = MJHMat226Slope;
#declare L3Texture226 = MJHTex226;
#declare L3Texture226_slope = MJHTex226Slope;
#declare L3Color226 = MJHMat226;
#declare L3Color226_slope = MJHMat226Slope;
#declare ldMat226 = MJHMat226;
#declare ldTex226 = MJHTex226;
#declare lg_bright_light_yellow = MJHTex226;
#declare lc_Bright_Light_Yellow = MJHTex226;

// row 114 - Trans_Bright_Light_Orange
#declare LDXColor231 = MJHMat231;
#declare LDXColor231_slope = MJHMat231Slope;
#declare L3Texture231 = MJHTex231;
#declare L3Texture231_slope = MJHTex231Slope;
#declare L3Color231 = MJHMat231;
#declare L3Color231_slope = MJHMat231Slope;
#declare ldMat231 = MJHMat231;
#declare ldTex231 = MJHTex231;
#declare lg_undefined = MJHTex231;
#declare lc_Trans_Bright_Light_Orange = MJHTex231;

// row 115 - Sky_Blue
#declare LDXColor232 = MJHMat232;
#declare LDXColor232_slope = MJHMat232Slope;
#declare L3Texture232 = MJHTex232;
#declare L3Texture232_slope = MJHTex232Slope;
#declare L3Color232 = MJHMat232;
#declare L3Color232_slope = MJHMat232Slope;
#declare ldMat232 = MJHMat232;
#declare ldTex232 = MJHTex232;
#declare lg_sky_blue = MJHTex232;
#declare lc_Sky_Blue = MJHTex232;

// row 116 - Trans_Fire_Yellow
#declare LDXColor234 = MJHMat234;
#declare LDXColor234_slope = MJHMat234Slope;
#declare L3Texture234 = MJHTex234;
#declare L3Texture234_slope = MJHTex234Slope;
#declare L3Color234 = MJHMat234;
#declare L3Color234_slope = MJHMat234Slope;
#declare ldMat234 = MJHMat234;
#declare ldTex234 = MJHTex234;
#declare lg_undefined = MJHTex234;
#declare lc_Trans_Fire_Yellow = MJHTex234;

// row 117 - Rubber_Black
#declare LDXColor256 = MJHMat256;
#declare LDXColor256_slope = MJHMat256Slope;
#declare L3Texture256 = MJHTex256;
#declare L3Texture256_slope = MJHTex256Slope;
#declare L3Color256 = MJHMat256;
#declare L3Color256_slope = MJHMat256Slope;
#declare ldMat256 = MJHMat256;
#declare ldTex256 = MJHTex256;
#declare lg_rubber_black = MJHTex256;
#declare lc_Rubber_Black = MJHTex256;

// row 118 - Dark_Blue
#declare LDXColor272 = MJHMat272;
#declare LDXColor272_slope = MJHMat272Slope;
#declare L3Texture272 = MJHTex272;
#declare L3Texture272_slope = MJHTex272Slope;
#declare L3Color272 = MJHMat272;
#declare L3Color272_slope = MJHMat272Slope;
#declare ldMat272 = MJHMat272;
#declare ldTex272 = MJHTex272;
#declare lg_dark_blue = MJHTex272;
#declare lc_Dark_Blue = MJHTex272;

// row 119 - Rubber_Blue
#declare LDXColor273 = MJHMat273;
#declare LDXColor273_slope = MJHMat273Slope;
#declare L3Texture273 = MJHTex273;
#declare L3Texture273_slope = MJHTex273Slope;
#declare L3Color273 = MJHMat273;
#declare L3Color273_slope = MJHMat273Slope;
#declare ldMat273 = MJHMat273;
#declare ldTex273 = MJHTex273;
#declare lg_rubber_blue = MJHTex273;
#declare lc_Rubber_Blue = MJHTex273;

// row 120 - Trans_Reddish_Lilac
#declare LDXColor284 = MJHMat284;
#declare LDXColor284_slope = MJHMat284Slope;
#declare L3Texture284 = MJHTex284;
#declare L3Texture284_slope = MJHTex284Slope;
#declare L3Color284 = MJHMat284;
#declare L3Color284_slope = MJHMat284Slope;
#declare ldMat284 = MJHMat284;
#declare ldTex284 = MJHTex284;
#declare lg_undefined = MJHTex284;
#declare lc_Trans_Reddish_Lilac = MJHTex284;

// row 121 - Trans_Light_Green
#declare LDXColor285 = MJHMat285;
#declare LDXColor285_slope = MJHMat285Slope;
#declare L3Texture285 = MJHTex285;
#declare L3Texture285_slope = MJHTex285Slope;
#declare L3Color285 = MJHMat285;
#declare L3Color285_slope = MJHMat285Slope;
#declare ldMat285 = MJHMat285;
#declare ldTex285 = MJHTex285;
#declare lg_undefined = MJHTex285;
#declare lc_Trans_Light_Green = MJHTex285;

// row 122 - Dark_Green
#declare LDXColor288 = MJHMat288;
#declare LDXColor288_slope = MJHMat288Slope;
#declare L3Texture288 = MJHTex288;
#declare L3Texture288_slope = MJHTex288Slope;
#declare L3Color288 = MJHMat288;
#declare L3Color288_slope = MJHMat288Slope;
#declare ldMat288 = MJHMat288;
#declare ldTex288 = MJHTex288;
#declare lg_dark_green = MJHTex288;
#declare lc_Dark_Green = MJHTex288;

// row 123 - Trans_Light_Blue_Violet
#declare LDXColor293 = MJHMat293;
#declare LDXColor293_slope = MJHMat293Slope;
#declare L3Texture293 = MJHTex293;
#declare L3Texture293_slope = MJHTex293Slope;
#declare L3Color293 = MJHMat293;
#declare L3Color293_slope = MJHMat293Slope;
#declare ldMat293 = MJHMat293;
#declare ldTex293 = MJHTex293;
#declare lg_undefined = MJHTex293;
#declare lc_Trans_Light_Blue_Violet = MJHTex293;

// row 124 - Glow_In_Dark_Trans
#declare LDXColor294 = MJHMat294;
#declare LDXColor294_slope = MJHMat294Slope;
#declare L3Texture294 = MJHTex294;
#declare L3Texture294_slope = MJHTex294Slope;
#declare L3Color294 = MJHMat294;
#declare L3Color294_slope = MJHMat294Slope;
#declare ldMat294 = MJHMat294;
#declare ldTex294 = MJHTex294;
#declare lg_glow_in_dark_clear = MJHTex294;
#declare lc_Glow_In_Dark_Trans = MJHTex294;

// row 125 - Flamingo_Pink
#declare LDXColor295 = MJHMat295;
#declare LDXColor295_slope = MJHMat295Slope;
#declare L3Texture295 = MJHTex295;
#declare L3Texture295_slope = MJHTex295Slope;
#declare L3Color295 = MJHMat295;
#declare L3Color295_slope = MJHMat295Slope;
#declare ldMat295 = MJHMat295;
#declare ldTex295 = MJHTex295;
#declare lg_undefined = MJHTex295;
#declare lc_Flamingo_Pink = MJHTex295;

// row 126 - Pearl_Gold
#declare LDXColor297 = MJHMat297;
#declare LDXColor297_slope = MJHMat297Slope;
#declare L3Texture297 = MJHTex297;
#declare L3Texture297_slope = MJHTex297Slope;
#declare L3Color297 = MJHMat297;
#declare L3Color297_slope = MJHMat297Slope;
#declare ldMat297 = MJHMat297;
#declare ldTex297 = MJHTex297;
#declare lg_pearl_gold = MJHTex297;
#declare lc_Pearl_Gold = MJHTex297;

// row 127 - Metallic_Copper
#declare LDXColor300 = MJHMat300;
#declare LDXColor300_slope = MJHMat300Slope;
#declare L3Texture300 = MJHTex300;
#declare L3Texture300_slope = MJHTex300Slope;
#declare L3Color300 = MJHMat300;
#declare L3Color300_slope = MJHMat300Slope;
#declare ldMat300 = MJHMat300;
#declare ldTex300 = MJHTex300;
#declare lg_undefined = MJHTex300;
#declare lc_Metallic_Copper = MJHTex300;

// row 128 - Glitter_Trans_Light_Blue
#declare LDXColor302 = MJHMat302;
#declare LDXColor302_slope = MJHMat302Slope;
#declare L3Texture302 = MJHTex302;
#declare L3Texture302_slope = MJHTex302Slope;
#declare L3Color302 = MJHMat302;
#declare L3Color302_slope = MJHMat302Slope;
#declare ldMat302 = MJHMat302;
#declare ldTex302 = MJHTex302;
#declare lg_undefined = MJHTex302;
#declare lc_Glitter_Trans_Light_Blue = MJHTex302;

// row 129 - Dark_Brown
#declare LDXColor308 = MJHMat308;
#declare LDXColor308_slope = MJHMat308Slope;
#declare L3Texture308 = MJHTex308;
#declare L3Texture308_slope = MJHTex308Slope;
#declare L3Color308 = MJHMat308;
#declare L3Color308_slope = MJHMat308Slope;
#declare ldMat308 = MJHMat308;
#declare ldTex308 = MJHTex308;
#declare lg_dark_brown = MJHTex308;
#declare lc_Dark_Brown = MJHTex308;

// row 130 - Maersk_Blue
#declare LDXColor313 = MJHMat313;
#declare LDXColor313_slope = MJHMat313Slope;
#declare L3Texture313 = MJHTex313;
#declare L3Texture313_slope = MJHTex313Slope;
#declare L3Color313 = MJHMat313;
#declare L3Color313_slope = MJHMat313Slope;
#declare ldMat313 = MJHMat313;
#declare ldTex313 = MJHTex313;
#declare lg_maersk_blue = MJHTex313;
#declare lc_Maersk_Blue = MJHTex313;

// row 131 - Dark_Red
#declare LDXColor320 = MJHMat320;
#declare LDXColor320_slope = MJHMat320Slope;
#declare L3Texture320 = MJHTex320;
#declare L3Texture320_slope = MJHTex320Slope;
#declare L3Color320 = MJHMat320;
#declare L3Color320_slope = MJHMat320Slope;
#declare ldMat320 = MJHMat320;
#declare ldTex320 = MJHTex320;
#declare lg_dark_red = MJHTex320;
#declare lc_Dark_Red = MJHTex320;

// row 132 - Dark_Azure
#declare LDXColor321 = MJHMat321;
#declare LDXColor321_slope = MJHMat321Slope;
#declare L3Texture321 = MJHTex321;
#declare L3Texture321_slope = MJHTex321Slope;
#declare L3Color321 = MJHMat321;
#declare L3Color321_slope = MJHMat321Slope;
#declare ldMat321 = MJHMat321;
#declare ldTex321 = MJHTex321;
#declare lg_dark_azur = MJHTex321;
#declare lc_Dark_Azure = MJHTex321;

// row 133 - Medium_Azure
#declare LDXColor322 = MJHMat322;
#declare LDXColor322_slope = MJHMat322Slope;
#declare L3Texture322 = MJHTex322;
#declare L3Texture322_slope = MJHTex322Slope;
#declare L3Color322 = MJHMat322;
#declare L3Color322_slope = MJHMat322Slope;
#declare ldMat322 = MJHMat322;
#declare ldTex322 = MJHTex322;
#declare lg_medium_azur = MJHTex322;
#declare lc_Medium_Azure = MJHTex322;

// row 134 - Light_Aqua
#declare LDXColor323 = MJHMat323;
#declare LDXColor323_slope = MJHMat323Slope;
#declare L3Texture323 = MJHTex323;
#declare L3Texture323_slope = MJHTex323Slope;
#declare L3Color323 = MJHMat323;
#declare L3Color323_slope = MJHMat323Slope;
#declare ldMat323 = MJHMat323;
#declare ldTex323 = MJHTex323;
#declare lg_light_aqua = MJHTex323;
#declare lc_Light_Aqua = MJHTex323;

// row 135 - Rubber_Red
#declare LDXColor324 = MJHMat324;
#declare LDXColor324_slope = MJHMat324Slope;
#declare L3Texture324 = MJHTex324;
#declare L3Texture324_slope = MJHTex324Slope;
#declare L3Color324 = MJHMat324;
#declare L3Color324_slope = MJHMat324Slope;
#declare ldMat324 = MJHMat324;
#declare ldTex324 = MJHTex324;
#declare lg_rubber_red = MJHTex324;
#declare lc_Rubber_Red = MJHTex324;

// row 136 - Yellowish_Green
#declare LDXColor326 = MJHMat326;
#declare LDXColor326_slope = MJHMat326Slope;
#declare L3Texture326 = MJHTex326;
#declare L3Texture326_slope = MJHTex326Slope;
#declare L3Color326 = MJHMat326;
#declare L3Color326_slope = MJHMat326Slope;
#declare ldMat326 = MJHMat326;
#declare ldTex326 = MJHTex326;
#declare lg_spring_yellowish_green = MJHTex326;
#declare lc_Yellowish_Green = MJHTex326;

// row 137 - Glow_In_Dark_White
#declare LDXColor329 = MJHMat329;
#declare LDXColor329_slope = MJHMat329Slope;
#declare L3Texture329 = MJHTex329;
#declare L3Texture329_slope = MJHTex329Slope;
#declare L3Color329 = MJHMat329;
#declare L3Color329_slope = MJHMat329Slope;
#declare ldMat329 = MJHMat329;
#declare ldTex329 = MJHTex329;
#declare lg_undefined = MJHTex329;
#declare lc_Glow_In_Dark_White = MJHTex329;

// row 138 - Olive_Green
#declare LDXColor330 = MJHMat330;
#declare LDXColor330_slope = MJHMat330Slope;
#declare L3Texture330 = MJHTex330;
#declare L3Texture330_slope = MJHTex330Slope;
#declare L3Color330 = MJHMat330;
#declare L3Color330_slope = MJHMat330Slope;
#declare ldMat330 = MJHMat330;
#declare ldTex330 = MJHTex330;
#declare lg_olive_green = MJHTex330;
#declare lc_Olive_Green = MJHTex330;

// row 139 - Chrome_Gold
#declare LDXColor334 = MJHMat334;
#declare LDXColor334_slope = MJHMat334Slope;
#declare L3Texture334 = MJHTex334;
#declare L3Texture334_slope = MJHTex334Slope;
#declare L3Color334 = MJHMat334;
#declare L3Color334_slope = MJHMat334Slope;
#declare ldMat334 = MJHMat334;
#declare ldTex334 = MJHTex334;
#declare lg_chrome_gold = MJHTex334;
#declare lc_Chrome_Gold = MJHTex334;

// row 140 - Sand_Red
#declare LDXColor335 = MJHMat335;
#declare LDXColor335_slope = MJHMat335Slope;
#declare L3Texture335 = MJHTex335;
#declare L3Texture335_slope = MJHTex335Slope;
#declare L3Color335 = MJHMat335;
#declare L3Color335_slope = MJHMat335Slope;
#declare ldMat335 = MJHMat335;
#declare ldTex335 = MJHTex335;
#declare lg_sand_red = MJHTex335;
#declare lc_Sand_Red = MJHTex335;

// row 141 - Glitter_Trans_Neon_Green
#declare LDXColor339 = MJHMat339;
#declare LDXColor339_slope = MJHMat339Slope;
#declare L3Texture339 = MJHTex339;
#declare L3Texture339_slope = MJHTex339Slope;
#declare L3Color339 = MJHMat339;
#declare L3Color339_slope = MJHMat339Slope;
#declare ldMat339 = MJHMat339;
#declare ldTex339 = MJHTex339;
#declare lg_undefined = MJHTex339;
#declare lc_Glitter_Trans_Neon_Green = MJHTex339;

// row 142 - Rubber_Orange
#declare LDXColor350 = MJHMat350;
#declare LDXColor350_slope = MJHMat350Slope;
#declare L3Texture350 = MJHTex350;
#declare L3Texture350_slope = MJHTex350Slope;
#declare L3Color350 = MJHMat350;
#declare L3Color350_slope = MJHMat350Slope;
#declare ldMat350 = MJHMat350;
#declare ldTex350 = MJHTex350;
#declare lg_undefined = MJHTex350;
#declare lc_Rubber_Orange = MJHTex350;

// row 143 - Medium_Dark_Pink
#declare LDXColor351 = MJHMat351;
#declare LDXColor351_slope = MJHMat351Slope;
#declare L3Texture351 = MJHTex351;
#declare L3Texture351_slope = MJHTex351Slope;
#declare L3Color351 = MJHMat351;
#declare L3Color351_slope = MJHMat351Slope;
#declare ldMat351 = MJHMat351;
#declare ldTex351 = MJHTex351;
#declare lg_undefined = MJHTex351;
#declare lc_Medium_Dark_Pink = MJHTex351;

// row 145 - Earth_Orange
#declare LDXColor366 = MJHMat366;
#declare LDXColor366_slope = MJHMat366Slope;
#declare L3Texture366 = MJHTex366;
#declare L3Texture366_slope = MJHTex366Slope;
#declare L3Color366 = MJHMat366;
#declare L3Color366_slope = MJHMat366Slope;
#declare ldMat366 = MJHMat366;
#declare ldTex366 = MJHTex366;
#declare lg_earth_orange = MJHTex366;
#declare lc_Earth_Orange = MJHTex366;

// row 146 - Sand_Purple
#declare LDXColor373 = MJHMat373;
#declare LDXColor373_slope = MJHMat373Slope;
#declare L3Texture373 = MJHTex373;
#declare L3Texture373_slope = MJHTex373Slope;
#declare L3Color373 = MJHMat373;
#declare L3Color373_slope = MJHMat373Slope;
#declare ldMat373 = MJHMat373;
#declare ldTex373 = MJHTex373;
#declare lg_sand_purple = MJHTex373;
#declare lc_Sand_Purple = MJHTex373;

// row 147 - Rubber_Light_Grey
#declare LDXColor375 = MJHMat375;
#declare LDXColor375_slope = MJHMat375Slope;
#declare L3Texture375 = MJHTex375;
#declare L3Texture375_slope = MJHTex375Slope;
#declare L3Color375 = MJHMat375;
#declare L3Color375_slope = MJHMat375Slope;
#declare ldMat375 = MJHMat375;
#declare ldTex375 = MJHTex375;
#declare lg_rubber_light_gray = MJHTex375;
#declare lc_Rubber_Light_Grey = MJHTex375;

// row 148 - Sand_Green
#declare LDXColor378 = MJHMat378;
#declare LDXColor378_slope = MJHMat378Slope;
#declare L3Texture378 = MJHTex378;
#declare L3Texture378_slope = MJHTex378Slope;
#declare L3Color378 = MJHMat378;
#declare L3Color378_slope = MJHMat378Slope;
#declare ldMat378 = MJHMat378;
#declare ldTex378 = MJHTex378;
#declare lg_sand_green = MJHTex378;
#declare lc_Sand_Green = MJHTex378;

// row 149 - Sand_Blue
#declare LDXColor379 = MJHMat379;
#declare LDXColor379_slope = MJHMat379Slope;
#declare L3Texture379 = MJHTex379;
#declare L3Texture379_slope = MJHTex379Slope;
#declare L3Color379 = MJHMat379;
#declare L3Color379_slope = MJHMat379Slope;
#declare ldMat379 = MJHMat379;
#declare ldTex379 = MJHTex379;
#declare lg_sand_blue = MJHTex379;
#declare lc_Sand_Blue = MJHTex379;

// row 150 - Chrome_Silver
#declare LDXColor383 = MJHMat383;
#declare LDXColor383_slope = MJHMat383Slope;
#declare L3Texture383 = MJHTex383;
#declare L3Texture383_slope = MJHTex383Slope;
#declare L3Color383 = MJHMat383;
#declare L3Color383_slope = MJHMat383Slope;
#declare ldMat383 = MJHMat383;
#declare ldTex383 = MJHTex383;
#declare lg_chrome = MJHTex383;
#declare lc_Chrome_Silver = MJHTex383;

// row 151 - Rubber_Dark_Blue
#declare LDXColor406 = MJHMat406;
#declare LDXColor406_slope = MJHMat406Slope;
#declare L3Texture406 = MJHTex406;
#declare L3Texture406_slope = MJHTex406Slope;
#declare L3Color406 = MJHMat406;
#declare L3Color406_slope = MJHMat406Slope;
#declare ldMat406 = MJHMat406;
#declare ldTex406 = MJHTex406;
#declare lg_rubber_dark_blue = MJHTex406;
#declare lc_Rubber_Dark_Blue = MJHTex406;

// row 152 - Rubber_Purple
#declare LDXColor449 = MJHMat449;
#declare LDXColor449_slope = MJHMat449Slope;
#declare L3Texture449 = MJHTex449;
#declare L3Texture449_slope = MJHTex449Slope;
#declare L3Color449 = MJHMat449;
#declare L3Color449_slope = MJHMat449Slope;
#declare ldMat449 = MJHMat449;
#declare ldTex449 = MJHTex449;
#declare lg_rubber_purple = MJHTex449;
#declare lc_Rubber_Purple = MJHTex449;

// row 153 - Fabuland_Brown
#declare LDXColor450 = MJHMat450;
#declare LDXColor450_slope = MJHMat450Slope;
#declare L3Texture450 = MJHTex450;
#declare L3Texture450_slope = MJHTex450Slope;
#declare L3Color450 = MJHMat450;
#declare L3Color450_slope = MJHMat450Slope;
#declare ldMat450 = MJHMat450;
#declare ldTex450 = MJHTex450;
#declare lg_fabuland_brown = MJHTex450;
#declare lc_Fabuland_Brown = MJHTex450;

// row 154 - Medium_Orange
#declare LDXColor462 = MJHMat462;
#declare LDXColor462_slope = MJHMat462Slope;
#declare L3Texture462 = MJHTex462;
#declare L3Texture462_slope = MJHTex462Slope;
#declare L3Color462 = MJHMat462;
#declare L3Color462_slope = MJHMat462Slope;
#declare ldMat462 = MJHMat462;
#declare ldTex462 = MJHTex462;
#declare lg_light_orange = MJHTex462;
#declare lc_Medium_Orange = MJHTex462;

// row 155 - Dark_Orange
#declare LDXColor484 = MJHMat484;
#declare LDXColor484_slope = MJHMat484Slope;
#declare L3Texture484 = MJHTex484;
#declare L3Texture484_slope = MJHTex484Slope;
#declare L3Color484 = MJHMat484;
#declare L3Color484_slope = MJHMat484Slope;
#declare ldMat484 = MJHMat484;
#declare ldTex484 = MJHTex484;
#declare lg_dark_orange = MJHTex484;
#declare lc_Dark_Orange = MJHTex484;

// row 156 - Rubber_Lime
#declare LDXColor490 = MJHMat490;
#declare LDXColor490_slope = MJHMat490Slope;
#declare L3Texture490 = MJHTex490;
#declare L3Texture490_slope = MJHTex490Slope;
#declare L3Color490 = MJHMat490;
#declare L3Color490_slope = MJHMat490Slope;
#declare ldMat490 = MJHMat490;
#declare ldTex490 = MJHTex490;
#declare lg_rubber_lime = MJHTex490;
#declare lc_Rubber_Lime = MJHTex490;

// row 157 - Magnet
#declare LDXColor493 = MJHMat493;
#declare LDXColor493_slope = MJHMat493Slope;
#declare L3Texture493 = MJHTex493;
#declare L3Texture493_slope = MJHTex493Slope;
#declare L3Color493 = MJHMat493;
#declare L3Color493_slope = MJHMat493Slope;
#declare ldMat493 = MJHMat493;
#declare ldTex493 = MJHTex493;
#declare lg_magnet = MJHTex493;
#declare lc_Magnet = MJHTex493;

// row 158 - Electric_Contact_Alloy
#declare LDXColor494 = MJHMat494;
#declare LDXColor494_slope = MJHMat494Slope;
#declare L3Texture494 = MJHTex494;
#declare L3Texture494_slope = MJHTex494Slope;
#declare L3Color494 = MJHMat494;
#declare L3Color494_slope = MJHMat494Slope;
#declare ldMat494 = MJHMat494;
#declare ldTex494 = MJHTex494;
#declare lg_electric_contact_alloy = MJHTex494;
#declare lc_Electric_Contact_Alloy = MJHTex494;

// row 159 - Electric_Contact_Copper
#declare LDXColor495 = MJHMat495;
#declare LDXColor495_slope = MJHMat495Slope;
#declare L3Texture495 = MJHTex495;
#declare L3Texture495_slope = MJHTex495Slope;
#declare L3Color495 = MJHMat495;
#declare L3Color495_slope = MJHMat495Slope;
#declare ldMat495 = MJHMat495;
#declare ldTex495 = MJHTex495;
#declare lg_undefined = MJHTex495;
#declare lc_Electric_Contact_Copper = MJHTex495;

// row 160 - Rubber_Light_Bluish_Grey
#declare LDXColor496 = MJHMat496;
#declare LDXColor496_slope = MJHMat496Slope;
#declare L3Texture496 = MJHTex496;
#declare L3Texture496_slope = MJHTex496Slope;
#declare L3Color496 = MJHMat496;
#declare L3Color496_slope = MJHMat496Slope;
#declare ldMat496 = MJHMat496;
#declare ldTex496 = MJHTex496;
#declare lg_rubber_light_bluish_gray = MJHTex496;
#declare lc_Rubber_Light_Bluish_Grey = MJHTex496;

// row 161 - Very_Light_Grey
#declare LDXColor503 = MJHMat503;
#declare LDXColor503_slope = MJHMat503Slope;
#declare L3Texture503 = MJHTex503;
#declare L3Texture503_slope = MJHTex503Slope;
#declare L3Color503 = MJHMat503;
#declare L3Color503_slope = MJHMat503Slope;
#declare ldMat503 = MJHMat503;
#declare ldTex503 = MJHTex503;
#declare lg_very_light_grey = MJHTex503;
#declare lc_Very_Light_Grey = MJHTex503;

// row 162 - Rubber_Flat_Silver
#declare LDXColor504 = MJHMat504;
#declare LDXColor504_slope = MJHMat504Slope;
#declare L3Texture504 = MJHTex504;
#declare L3Texture504_slope = MJHTex504Slope;
#declare L3Color504 = MJHMat504;
#declare L3Color504_slope = MJHMat504Slope;
#declare ldMat504 = MJHMat504;
#declare ldTex504 = MJHTex504;
#declare lg_rubber_flat_silver = MJHTex504;
#declare lc_Rubber_Flat_Silver = MJHTex504;

// row 166 - Rubber_White
#declare LDXColor511 = MJHMat511;
#declare LDXColor511_slope = MJHMat511Slope;
#declare L3Texture511 = MJHTex511;
#declare L3Texture511_slope = MJHTex511Slope;
#declare L3Color511 = MJHMat511;
#declare L3Color511_slope = MJHMat511Slope;
#declare ldMat511 = MJHMat511;
#declare ldTex511 = MJHTex511;
#declare lg_rubber_white = MJHTex511;
#declare lc_Rubber_White = MJHTex511;
