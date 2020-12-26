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
// This file is not ready for use yet.

// These values are copied from the LGEO settings.
#declare lc_ior_block = interior {ior lc_ior}
#declare lc_slope_bumps = 0.3;
#declare lc_slope_scale = 0.5;
#declare lc_slope_normal = normal { bumps lc_slope_bumps scale lc_slope_scale }

// row 1 - Black
#ifdef (lc_Black) #ifndef (MJHTex0) #declare MJHTex0 = texture {lc_Black} #end #end
#ifdef (lc_Black) #ifndef (MJHTex0Slope) #declare MJHTex0Slope = texture {lc_Black  normal {lc_slope_normal}} #end #end
#ifdef (lc_Black) #ifndef (MJHMat0) #declare MJHMat0 = material {texture {MJHTex0} interior {lc_ior_block}} #end #end
#ifdef (lc_Black) #ifndef (MJHMat0Slope) #declare MJHMat0Slope = material { texture {MJHTex0Slope} interior {lc_ior_block}} #end #end

// row 2 - Blue
#ifdef (lc_Blue) #ifndef (MJHTex1) #declare MJHTex1 = texture {lc_Blue} #end #end
#ifdef (lc_Blue) #ifndef (MJHTex1Slope) #declare MJHTex1Slope = texture {lc_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Blue) #ifndef (MJHMat1) #declare MJHMat1 = material {texture {MJHTex1} interior {lc_ior_block}} #end #end
#ifdef (lc_Blue) #ifndef (MJHMat1Slope) #declare MJHMat1Slope = material { texture {MJHTex1Slope} interior {lc_ior_block}} #end #end

// row 3 - Green
#ifdef (lc_Green) #ifndef (MJHTex2) #declare MJHTex2 = texture {lc_Green} #end #end
#ifdef (lc_Green) #ifndef (MJHTex2Slope) #declare MJHTex2Slope = texture {lc_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Green) #ifndef (MJHMat2) #declare MJHMat2 = material {texture {MJHTex2} interior {lc_ior_block}} #end #end
#ifdef (lc_Green) #ifndef (MJHMat2Slope) #declare MJHMat2Slope = material { texture {MJHTex2Slope} interior {lc_ior_block}} #end #end

// row 4 - Dark_Turquoise
#ifdef (lc_Dark_Turquoise) #ifndef (MJHTex3) #declare MJHTex3 = texture {lc_Dark_Turquoise} #end #end
#ifdef (lc_Dark_Turquoise) #ifndef (MJHTex3Slope) #declare MJHTex3Slope = texture {lc_Dark_Turquoise  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Turquoise) #ifndef (MJHMat3) #declare MJHMat3 = material {texture {MJHTex3} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Turquoise) #ifndef (MJHMat3Slope) #declare MJHMat3Slope = material { texture {MJHTex3Slope} interior {lc_ior_block}} #end #end

// row 5 - Red
#ifdef (lc_Red) #ifndef (MJHTex4) #declare MJHTex4 = texture {lc_Red} #end #end
#ifdef (lc_Red) #ifndef (MJHTex4Slope) #declare MJHTex4Slope = texture {lc_Red  normal {lc_slope_normal}} #end #end
#ifdef (lc_Red) #ifndef (MJHMat4) #declare MJHMat4 = material {texture {MJHTex4} interior {lc_ior_block}} #end #end
#ifdef (lc_Red) #ifndef (MJHMat4Slope) #declare MJHMat4Slope = material { texture {MJHTex4Slope} interior {lc_ior_block}} #end #end

// row 6 - Dark_Pink
#ifdef (lc_Dark_Pink) #ifndef (MJHTex5) #declare MJHTex5 = texture {lc_Dark_Pink} #end #end
#ifdef (lc_Dark_Pink) #ifndef (MJHTex5Slope) #declare MJHTex5Slope = texture {lc_Dark_Pink  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Pink) #ifndef (MJHMat5) #declare MJHMat5 = material {texture {MJHTex5} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Pink) #ifndef (MJHMat5Slope) #declare MJHMat5Slope = material { texture {MJHTex5Slope} interior {lc_ior_block}} #end #end

// row 7 - Brown
#ifdef (lc_Brown) #ifndef (MJHTex6) #declare MJHTex6 = texture {lc_Brown} #end #end
#ifdef (lc_Brown) #ifndef (MJHTex6Slope) #declare MJHTex6Slope = texture {lc_Brown  normal {lc_slope_normal}} #end #end
#ifdef (lc_Brown) #ifndef (MJHMat6) #declare MJHMat6 = material {texture {MJHTex6} interior {lc_ior_block}} #end #end
#ifdef (lc_Brown) #ifndef (MJHMat6Slope) #declare MJHMat6Slope = material { texture {MJHTex6Slope} interior {lc_ior_block}} #end #end

// row 8 - Light_Grey
#ifdef (lc_Light_Grey) #ifndef (MJHTex7) #declare MJHTex7 = texture {lc_Light_Grey} #end #end
#ifdef (lc_Light_Grey) #ifndef (MJHTex7Slope) #declare MJHTex7Slope = texture {lc_Light_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Grey) #ifndef (MJHMat7) #declare MJHMat7 = material {texture {MJHTex7} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Grey) #ifndef (MJHMat7Slope) #declare MJHMat7Slope = material { texture {MJHTex7Slope} interior {lc_ior_block}} #end #end

// row 9 - Dark_Grey
#ifdef (lc_Dark_Grey) #ifndef (MJHTex8) #declare MJHTex8 = texture {lc_Dark_Grey} #end #end
#ifdef (lc_Dark_Grey) #ifndef (MJHTex8Slope) #declare MJHTex8Slope = texture {lc_Dark_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Grey) #ifndef (MJHMat8) #declare MJHMat8 = material {texture {MJHTex8} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Grey) #ifndef (MJHMat8Slope) #declare MJHMat8Slope = material { texture {MJHTex8Slope} interior {lc_ior_block}} #end #end

// row 10 - Light_Blue
#ifdef (lc_Light_Blue) #ifndef (MJHTex9) #declare MJHTex9 = texture {lc_Light_Blue} #end #end
#ifdef (lc_Light_Blue) #ifndef (MJHTex9Slope) #declare MJHTex9Slope = texture {lc_Light_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Blue) #ifndef (MJHMat9) #declare MJHMat9 = material {texture {MJHTex9} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Blue) #ifndef (MJHMat9Slope) #declare MJHMat9Slope = material { texture {MJHTex9Slope} interior {lc_ior_block}} #end #end

// row 11 - Bright_Green
#ifdef (lc_Bright_Green) #ifndef (MJHTex10) #declare MJHTex10 = texture {lc_Bright_Green} #end #end
#ifdef (lc_Bright_Green) #ifndef (MJHTex10Slope) #declare MJHTex10Slope = texture {lc_Bright_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Bright_Green) #ifndef (MJHMat10) #declare MJHMat10 = material {texture {MJHTex10} interior {lc_ior_block}} #end #end
#ifdef (lc_Bright_Green) #ifndef (MJHMat10Slope) #declare MJHMat10Slope = material { texture {MJHTex10Slope} interior {lc_ior_block}} #end #end

// row 12 - Light_Turquoise
#ifdef (lc_Light_Turquoise) #ifndef (MJHTex11) #declare MJHTex11 = texture {lc_Light_Turquoise} #end #end
#ifdef (lc_Light_Turquoise) #ifndef (MJHTex11Slope) #declare MJHTex11Slope = texture {lc_Light_Turquoise  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Turquoise) #ifndef (MJHMat11) #declare MJHMat11 = material {texture {MJHTex11} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Turquoise) #ifndef (MJHMat11Slope) #declare MJHMat11Slope = material { texture {MJHTex11Slope} interior {lc_ior_block}} #end #end

// row 13 - Salmon
#ifdef (lc_Salmon) #ifndef (MJHTex12) #declare MJHTex12 = texture {lc_Salmon} #end #end
#ifdef (lc_Salmon) #ifndef (MJHTex12Slope) #declare MJHTex12Slope = texture {lc_Salmon  normal {lc_slope_normal}} #end #end
#ifdef (lc_Salmon) #ifndef (MJHMat12) #declare MJHMat12 = material {texture {MJHTex12} interior {lc_ior_block}} #end #end
#ifdef (lc_Salmon) #ifndef (MJHMat12Slope) #declare MJHMat12Slope = material { texture {MJHTex12Slope} interior {lc_ior_block}} #end #end

// row 14 - Pink
#ifdef (lc_Pink) #ifndef (MJHTex13) #declare MJHTex13 = texture {lc_Pink} #end #end
#ifdef (lc_Pink) #ifndef (MJHTex13Slope) #declare MJHTex13Slope = texture {lc_Pink  normal {lc_slope_normal}} #end #end
#ifdef (lc_Pink) #ifndef (MJHMat13) #declare MJHMat13 = material {texture {MJHTex13} interior {lc_ior_block}} #end #end
#ifdef (lc_Pink) #ifndef (MJHMat13Slope) #declare MJHMat13Slope = material { texture {MJHTex13Slope} interior {lc_ior_block}} #end #end

// row 15 - Yellow
#ifdef (lc_Yellow) #ifndef (MJHTex14) #declare MJHTex14 = texture {lc_Yellow} #end #end
#ifdef (lc_Yellow) #ifndef (MJHTex14Slope) #declare MJHTex14Slope = texture {lc_Yellow  normal {lc_slope_normal}} #end #end
#ifdef (lc_Yellow) #ifndef (MJHMat14) #declare MJHMat14 = material {texture {MJHTex14} interior {lc_ior_block}} #end #end
#ifdef (lc_Yellow) #ifndef (MJHMat14Slope) #declare MJHMat14Slope = material { texture {MJHTex14Slope} interior {lc_ior_block}} #end #end

// row 16 - White
#ifdef (lc_White) #ifndef (MJHTex15) #declare MJHTex15 = texture {lc_White} #end #end
#ifdef (lc_White) #ifndef (MJHTex15Slope) #declare MJHTex15Slope = texture {lc_White  normal {lc_slope_normal}} #end #end
#ifdef (lc_White) #ifndef (MJHMat15) #declare MJHMat15 = material {texture {MJHTex15} interior {lc_ior_block}} #end #end
#ifdef (lc_White) #ifndef (MJHMat15Slope) #declare MJHMat15Slope = material { texture {MJHTex15Slope} interior {lc_ior_block}} #end #end

// row 17 - Main_Colour
#ifdef (lc_Main_Colour) #ifndef (MJHTex16) #declare MJHTex16 = texture {lc_Main_Colour} #end #end
#ifdef (lc_Main_Colour) #ifndef (MJHTex16Slope) #declare MJHTex16Slope = texture {lc_Main_Colour  normal {lc_slope_normal}} #end #end
#ifdef (lc_Main_Colour) #ifndef (MJHMat16) #declare MJHMat16 = material {texture {MJHTex16} interior {lc_ior_block}} #end #end
#ifdef (lc_Main_Colour) #ifndef (MJHMat16Slope) #declare MJHMat16Slope = material { texture {MJHTex16Slope} interior {lc_ior_block}} #end #end

// row 18 - Light_Green
#ifdef (lc_Light_Green) #ifndef (MJHTex17) #declare MJHTex17 = texture {lc_Light_Green} #end #end
#ifdef (lc_Light_Green) #ifndef (MJHTex17Slope) #declare MJHTex17Slope = texture {lc_Light_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Green) #ifndef (MJHMat17) #declare MJHMat17 = material {texture {MJHTex17} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Green) #ifndef (MJHMat17Slope) #declare MJHMat17Slope = material { texture {MJHTex17Slope} interior {lc_ior_block}} #end #end

// row 19 - Light_Yellow
#ifdef (lc_Light_Yellow) #ifndef (MJHTex18) #declare MJHTex18 = texture {lc_Light_Yellow} #end #end
#ifdef (lc_Light_Yellow) #ifndef (MJHTex18Slope) #declare MJHTex18Slope = texture {lc_Light_Yellow  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Yellow) #ifndef (MJHMat18) #declare MJHMat18 = material {texture {MJHTex18} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Yellow) #ifndef (MJHMat18Slope) #declare MJHMat18Slope = material { texture {MJHTex18Slope} interior {lc_ior_block}} #end #end

// row 20 - Tan
#ifdef (lc_Tan) #ifndef (MJHTex19) #declare MJHTex19 = texture {lc_Tan} #end #end
#ifdef (lc_Tan) #ifndef (MJHTex19Slope) #declare MJHTex19Slope = texture {lc_Tan  normal {lc_slope_normal}} #end #end
#ifdef (lc_Tan) #ifndef (MJHMat19) #declare MJHMat19 = material {texture {MJHTex19} interior {lc_ior_block}} #end #end
#ifdef (lc_Tan) #ifndef (MJHMat19Slope) #declare MJHMat19Slope = material { texture {MJHTex19Slope} interior {lc_ior_block}} #end #end

// row 21 - Light_Violet
#ifdef (lc_Light_Violet) #ifndef (MJHTex20) #declare MJHTex20 = texture {lc_Light_Violet} #end #end
#ifdef (lc_Light_Violet) #ifndef (MJHTex20Slope) #declare MJHTex20Slope = texture {lc_Light_Violet  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Violet) #ifndef (MJHMat20) #declare MJHMat20 = material {texture {MJHTex20} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Violet) #ifndef (MJHMat20Slope) #declare MJHMat20Slope = material { texture {MJHTex20Slope} interior {lc_ior_block}} #end #end

// row 22 - Glow_In_Dark_Opaque
#ifdef (lc_Glow_In_Dark_Opaque) #ifndef (MJHTex21) #declare MJHTex21 = texture {lc_Glow_In_Dark_Opaque} #end #end
#ifdef (lc_Glow_In_Dark_Opaque) #ifndef (MJHTex21Slope) #declare MJHTex21Slope = texture {lc_Glow_In_Dark_Opaque  normal {lc_slope_normal}} #end #end
#ifdef (lc_Glow_In_Dark_Opaque) #ifndef (MJHMat21) #declare MJHMat21 = material {texture {MJHTex21} interior {lc_ior_block}} #end #end
#ifdef (lc_Glow_In_Dark_Opaque) #ifndef (MJHMat21Slope) #declare MJHMat21Slope = material { texture {MJHTex21Slope} interior {lc_ior_block}} #end #end

// row 23 - Purple
#ifdef (lc_Purple) #ifndef (MJHTex22) #declare MJHTex22 = texture {lc_Purple} #end #end
#ifdef (lc_Purple) #ifndef (MJHTex22Slope) #declare MJHTex22Slope = texture {lc_Purple  normal {lc_slope_normal}} #end #end
#ifdef (lc_Purple) #ifndef (MJHMat22) #declare MJHMat22 = material {texture {MJHTex22} interior {lc_ior_block}} #end #end
#ifdef (lc_Purple) #ifndef (MJHMat22Slope) #declare MJHMat22Slope = material { texture {MJHTex22Slope} interior {lc_ior_block}} #end #end

// row 24 - Dark_Blue_Violet
#ifdef (lc_Dark_Blue_Violet) #ifndef (MJHTex23) #declare MJHTex23 = texture {lc_Dark_Blue_Violet} #end #end
#ifdef (lc_Dark_Blue_Violet) #ifndef (MJHTex23Slope) #declare MJHTex23Slope = texture {lc_Dark_Blue_Violet  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Blue_Violet) #ifndef (MJHMat23) #declare MJHMat23 = material {texture {MJHTex23} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Blue_Violet) #ifndef (MJHMat23Slope) #declare MJHMat23Slope = material { texture {MJHTex23Slope} interior {lc_ior_block}} #end #end

// row 25 - Edge_Colour
#ifdef (lc_Edge_Colour) #ifndef (MJHTex24) #declare MJHTex24 = texture {lc_Edge_Colour} #end #end
#ifdef (lc_Edge_Colour) #ifndef (MJHTex24Slope) #declare MJHTex24Slope = texture {lc_Edge_Colour  normal {lc_slope_normal}} #end #end
#ifdef (lc_Edge_Colour) #ifndef (MJHMat24) #declare MJHMat24 = material {texture {MJHTex24} interior {lc_ior_block}} #end #end
#ifdef (lc_Edge_Colour) #ifndef (MJHMat24Slope) #declare MJHMat24Slope = material { texture {MJHTex24Slope} interior {lc_ior_block}} #end #end

// row 26 - Orange
#ifdef (lc_Orange) #ifndef (MJHTex25) #declare MJHTex25 = texture {lc_Orange} #end #end
#ifdef (lc_Orange) #ifndef (MJHTex25Slope) #declare MJHTex25Slope = texture {lc_Orange  normal {lc_slope_normal}} #end #end
#ifdef (lc_Orange) #ifndef (MJHMat25) #declare MJHMat25 = material {texture {MJHTex25} interior {lc_ior_block}} #end #end
#ifdef (lc_Orange) #ifndef (MJHMat25Slope) #declare MJHMat25Slope = material { texture {MJHTex25Slope} interior {lc_ior_block}} #end #end

// row 27 - Magenta
#ifdef (lc_Magenta) #ifndef (MJHTex26) #declare MJHTex26 = texture {lc_Magenta} #end #end
#ifdef (lc_Magenta) #ifndef (MJHTex26Slope) #declare MJHTex26Slope = texture {lc_Magenta  normal {lc_slope_normal}} #end #end
#ifdef (lc_Magenta) #ifndef (MJHMat26) #declare MJHMat26 = material {texture {MJHTex26} interior {lc_ior_block}} #end #end
#ifdef (lc_Magenta) #ifndef (MJHMat26Slope) #declare MJHMat26Slope = material { texture {MJHTex26Slope} interior {lc_ior_block}} #end #end

// row 28 - Lime
#ifdef (lc_Lime) #ifndef (MJHTex27) #declare MJHTex27 = texture {lc_Lime} #end #end
#ifdef (lc_Lime) #ifndef (MJHTex27Slope) #declare MJHTex27Slope = texture {lc_Lime  normal {lc_slope_normal}} #end #end
#ifdef (lc_Lime) #ifndef (MJHMat27) #declare MJHMat27 = material {texture {MJHTex27} interior {lc_ior_block}} #end #end
#ifdef (lc_Lime) #ifndef (MJHMat27Slope) #declare MJHMat27Slope = material { texture {MJHTex27Slope} interior {lc_ior_block}} #end #end

// row 29 - Dark_Tan
#ifdef (lc_Dark_Tan) #ifndef (MJHTex28) #declare MJHTex28 = texture {lc_Dark_Tan} #end #end
#ifdef (lc_Dark_Tan) #ifndef (MJHTex28Slope) #declare MJHTex28Slope = texture {lc_Dark_Tan  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Tan) #ifndef (MJHMat28) #declare MJHMat28 = material {texture {MJHTex28} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Tan) #ifndef (MJHMat28Slope) #declare MJHMat28Slope = material { texture {MJHTex28Slope} interior {lc_ior_block}} #end #end

// row 30 - Bright_Pink
#ifdef (lc_Bright_Pink) #ifndef (MJHTex29) #declare MJHTex29 = texture {lc_Bright_Pink} #end #end
#ifdef (lc_Bright_Pink) #ifndef (MJHTex29Slope) #declare MJHTex29Slope = texture {lc_Bright_Pink  normal {lc_slope_normal}} #end #end
#ifdef (lc_Bright_Pink) #ifndef (MJHMat29) #declare MJHMat29 = material {texture {MJHTex29} interior {lc_ior_block}} #end #end
#ifdef (lc_Bright_Pink) #ifndef (MJHMat29Slope) #declare MJHMat29Slope = material { texture {MJHTex29Slope} interior {lc_ior_block}} #end #end

// row 31 - Medium_Lavender
#ifdef (lc_Medium_Lavender) #ifndef (MJHTex30) #declare MJHTex30 = texture {lc_Medium_Lavender} #end #end
#ifdef (lc_Medium_Lavender) #ifndef (MJHTex30Slope) #declare MJHTex30Slope = texture {lc_Medium_Lavender  normal {lc_slope_normal}} #end #end
#ifdef (lc_Medium_Lavender) #ifndef (MJHMat30) #declare MJHMat30 = material {texture {MJHTex30} interior {lc_ior_block}} #end #end
#ifdef (lc_Medium_Lavender) #ifndef (MJHMat30Slope) #declare MJHMat30Slope = material { texture {MJHTex30Slope} interior {lc_ior_block}} #end #end

// row 32 - Lavender
#ifdef (lc_Lavender) #ifndef (MJHTex31) #declare MJHTex31 = texture {lc_Lavender} #end #end
#ifdef (lc_Lavender) #ifndef (MJHTex31Slope) #declare MJHTex31Slope = texture {lc_Lavender  normal {lc_slope_normal}} #end #end
#ifdef (lc_Lavender) #ifndef (MJHMat31) #declare MJHMat31 = material {texture {MJHTex31} interior {lc_ior_block}} #end #end
#ifdef (lc_Lavender) #ifndef (MJHMat31Slope) #declare MJHMat31Slope = material { texture {MJHTex31Slope} interior {lc_ior_block}} #end #end

// row 33 - Trans_Black_IR_Lens
#ifdef (lc_Trans_Black_IR_Lens) #ifndef (MJHTex32) #declare MJHTex32 = texture {lc_Trans_Black_IR_Lens} #end #end
#ifdef (lc_Trans_Black_IR_Lens) #ifndef (MJHTex32Slope) #declare MJHTex32Slope = texture {lc_Trans_Black_IR_Lens  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Black_IR_Lens) #ifndef (MJHMat32) #declare MJHMat32 = material {texture {MJHTex32} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Black_IR_Lens) #ifndef (MJHMat32Slope) #declare MJHMat32Slope = material { texture {MJHTex32Slope} interior {lc_ior_block}} #end #end

// row 34 - Trans_Dark_Blue
#ifdef (lc_Trans_Dark_Blue) #ifndef (MJHTex33) #declare MJHTex33 = texture {lc_Trans_Dark_Blue} #end #end
#ifdef (lc_Trans_Dark_Blue) #ifndef (MJHTex33Slope) #declare MJHTex33Slope = texture {lc_Trans_Dark_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Dark_Blue) #ifndef (MJHMat33) #declare MJHMat33 = material {texture {MJHTex33} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Dark_Blue) #ifndef (MJHMat33Slope) #declare MJHMat33Slope = material { texture {MJHTex33Slope} interior {lc_ior_block}} #end #end

// row 35 - Trans_Green
#ifdef (lc_Trans_Green) #ifndef (MJHTex34) #declare MJHTex34 = texture {lc_Trans_Green} #end #end
#ifdef (lc_Trans_Green) #ifndef (MJHTex34Slope) #declare MJHTex34Slope = texture {lc_Trans_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Green) #ifndef (MJHMat34) #declare MJHMat34 = material {texture {MJHTex34} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Green) #ifndef (MJHMat34Slope) #declare MJHMat34Slope = material { texture {MJHTex34Slope} interior {lc_ior_block}} #end #end

// row 36 - Trans_Bright_Green
#ifdef (lc_Trans_Bright_Green) #ifndef (MJHTex35) #declare MJHTex35 = texture {lc_Trans_Bright_Green} #end #end
#ifdef (lc_Trans_Bright_Green) #ifndef (MJHTex35Slope) #declare MJHTex35Slope = texture {lc_Trans_Bright_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Bright_Green) #ifndef (MJHMat35) #declare MJHMat35 = material {texture {MJHTex35} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Bright_Green) #ifndef (MJHMat35Slope) #declare MJHMat35Slope = material { texture {MJHTex35Slope} interior {lc_ior_block}} #end #end

// row 37 - Trans_Red
#ifdef (lc_Trans_Red) #ifndef (MJHTex36) #declare MJHTex36 = texture {lc_Trans_Red} #end #end
#ifdef (lc_Trans_Red) #ifndef (MJHTex36Slope) #declare MJHTex36Slope = texture {lc_Trans_Red  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Red) #ifndef (MJHMat36) #declare MJHMat36 = material {texture {MJHTex36} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Red) #ifndef (MJHMat36Slope) #declare MJHMat36Slope = material { texture {MJHTex36Slope} interior {lc_ior_block}} #end #end

// row 38 - Trans_Dark_Pink
#ifdef (lc_Trans_Dark_Pink) #ifndef (MJHTex37) #declare MJHTex37 = texture {lc_Trans_Dark_Pink} #end #end
#ifdef (lc_Trans_Dark_Pink) #ifndef (MJHTex37Slope) #declare MJHTex37Slope = texture {lc_Trans_Dark_Pink  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Dark_Pink) #ifndef (MJHMat37) #declare MJHMat37 = material {texture {MJHTex37} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Dark_Pink) #ifndef (MJHMat37Slope) #declare MJHMat37Slope = material { texture {MJHTex37Slope} interior {lc_ior_block}} #end #end

// row 39 - Trans_Neon_Orange
#ifdef (lc_Trans_Neon_Orange) #ifndef (MJHTex38) #declare MJHTex38 = texture {lc_Trans_Neon_Orange} #end #end
#ifdef (lc_Trans_Neon_Orange) #ifndef (MJHTex38Slope) #declare MJHTex38Slope = texture {lc_Trans_Neon_Orange  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Neon_Orange) #ifndef (MJHMat38) #declare MJHMat38 = material {texture {MJHTex38} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Neon_Orange) #ifndef (MJHMat38Slope) #declare MJHMat38Slope = material { texture {MJHTex38Slope} interior {lc_ior_block}} #end #end

// row 40 - Trans_Very_Light_Blue
#ifdef (lc_Trans_Very_Light_Blue) #ifndef (MJHTex39) #declare MJHTex39 = texture {lc_Trans_Very_Light_Blue} #end #end
#ifdef (lc_Trans_Very_Light_Blue) #ifndef (MJHTex39Slope) #declare MJHTex39Slope = texture {lc_Trans_Very_Light_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Very_Light_Blue) #ifndef (MJHMat39) #declare MJHMat39 = material {texture {MJHTex39} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Very_Light_Blue) #ifndef (MJHMat39Slope) #declare MJHMat39Slope = material { texture {MJHTex39Slope} interior {lc_ior_block}} #end #end

// row 41 - Trans_Black
#ifdef (lc_Trans_Black) #ifndef (MJHTex40) #declare MJHTex40 = texture {lc_Trans_Black} #end #end
#ifdef (lc_Trans_Black) #ifndef (MJHTex40Slope) #declare MJHTex40Slope = texture {lc_Trans_Black  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Black) #ifndef (MJHMat40) #declare MJHMat40 = material {texture {MJHTex40} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Black) #ifndef (MJHMat40Slope) #declare MJHMat40Slope = material { texture {MJHTex40Slope} interior {lc_ior_block}} #end #end

// row 42 - Trans_Medium_Blue
#ifdef (lc_Trans_Medium_Blue) #ifndef (MJHTex41) #declare MJHTex41 = texture {lc_Trans_Medium_Blue} #end #end
#ifdef (lc_Trans_Medium_Blue) #ifndef (MJHTex41Slope) #declare MJHTex41Slope = texture {lc_Trans_Medium_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Medium_Blue) #ifndef (MJHMat41) #declare MJHMat41 = material {texture {MJHTex41} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Medium_Blue) #ifndef (MJHMat41Slope) #declare MJHMat41Slope = material { texture {MJHTex41Slope} interior {lc_ior_block}} #end #end

// row 43 - Trans_Neon_Green
#ifdef (lc_Trans_Neon_Green) #ifndef (MJHTex42) #declare MJHTex42 = texture {lc_Trans_Neon_Green} #end #end
#ifdef (lc_Trans_Neon_Green) #ifndef (MJHTex42Slope) #declare MJHTex42Slope = texture {lc_Trans_Neon_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Neon_Green) #ifndef (MJHMat42) #declare MJHMat42 = material {texture {MJHTex42} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Neon_Green) #ifndef (MJHMat42Slope) #declare MJHMat42Slope = material { texture {MJHTex42Slope} interior {lc_ior_block}} #end #end

// row 44 - Trans_Light_Blue
#ifdef (lc_Trans_Light_Blue) #ifndef (MJHTex43) #declare MJHTex43 = texture {lc_Trans_Light_Blue} #end #end
#ifdef (lc_Trans_Light_Blue) #ifndef (MJHTex43Slope) #declare MJHTex43Slope = texture {lc_Trans_Light_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Light_Blue) #ifndef (MJHMat43) #declare MJHMat43 = material {texture {MJHTex43} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Light_Blue) #ifndef (MJHMat43Slope) #declare MJHMat43Slope = material { texture {MJHTex43Slope} interior {lc_ior_block}} #end #end

// row 45 - Trans_Bright_Reddish_Lilac
#ifdef (lc_Trans_Bright_Reddish_Lilac) #ifndef (MJHTex44) #declare MJHTex44 = texture {lc_Trans_Bright_Reddish_Lilac} #end #end
#ifdef (lc_Trans_Bright_Reddish_Lilac) #ifndef (MJHTex44Slope) #declare MJHTex44Slope = texture {lc_Trans_Bright_Reddish_Lilac  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Bright_Reddish_Lilac) #ifndef (MJHMat44) #declare MJHMat44 = material {texture {MJHTex44} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Bright_Reddish_Lilac) #ifndef (MJHMat44Slope) #declare MJHMat44Slope = material { texture {MJHTex44Slope} interior {lc_ior_block}} #end #end

// row 46 - Trans_Pink
#ifdef (lc_Trans_Pink) #ifndef (MJHTex45) #declare MJHTex45 = texture {lc_Trans_Pink} #end #end
#ifdef (lc_Trans_Pink) #ifndef (MJHTex45Slope) #declare MJHTex45Slope = texture {lc_Trans_Pink  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Pink) #ifndef (MJHMat45) #declare MJHMat45 = material {texture {MJHTex45} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Pink) #ifndef (MJHMat45Slope) #declare MJHMat45Slope = material { texture {MJHTex45Slope} interior {lc_ior_block}} #end #end

// row 47 - Trans_Yellow
#ifdef (lc_Trans_Yellow) #ifndef (MJHTex46) #declare MJHTex46 = texture {lc_Trans_Yellow} #end #end
#ifdef (lc_Trans_Yellow) #ifndef (MJHTex46Slope) #declare MJHTex46Slope = texture {lc_Trans_Yellow  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Yellow) #ifndef (MJHMat46) #declare MJHMat46 = material {texture {MJHTex46} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Yellow) #ifndef (MJHMat46Slope) #declare MJHMat46Slope = material { texture {MJHTex46Slope} interior {lc_ior_block}} #end #end

// row 48 - Trans_Clear
#ifdef (lc_Trans_Clear) #ifndef (MJHTex47) #declare MJHTex47 = texture {lc_Trans_Clear} #end #end
#ifdef (lc_Trans_Clear) #ifndef (MJHTex47Slope) #declare MJHTex47Slope = texture {lc_Trans_Clear  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Clear) #ifndef (MJHMat47) #declare MJHMat47 = material {texture {MJHTex47} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Clear) #ifndef (MJHMat47Slope) #declare MJHMat47Slope = material { texture {MJHTex47Slope} interior {lc_ior_block}} #end #end

// row 49 - Trans_Purple
#ifdef (lc_Trans_Purple) #ifndef (MJHTex52) #declare MJHTex52 = texture {lc_Trans_Purple} #end #end
#ifdef (lc_Trans_Purple) #ifndef (MJHTex52Slope) #declare MJHTex52Slope = texture {lc_Trans_Purple  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Purple) #ifndef (MJHMat52) #declare MJHMat52 = material {texture {MJHTex52} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Purple) #ifndef (MJHMat52Slope) #declare MJHMat52Slope = material { texture {MJHTex52Slope} interior {lc_ior_block}} #end #end

// row 50 - Trans_Neon_Yellow
#ifdef (lc_Trans_Neon_Yellow) #ifndef (MJHTex54) #declare MJHTex54 = texture {lc_Trans_Neon_Yellow} #end #end
#ifdef (lc_Trans_Neon_Yellow) #ifndef (MJHTex54Slope) #declare MJHTex54Slope = texture {lc_Trans_Neon_Yellow  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Neon_Yellow) #ifndef (MJHMat54) #declare MJHMat54 = material {texture {MJHTex54} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Neon_Yellow) #ifndef (MJHMat54Slope) #declare MJHMat54Slope = material { texture {MJHTex54Slope} interior {lc_ior_block}} #end #end

// row 51 - Trans_Orange
#ifdef (lc_Trans_Orange) #ifndef (MJHTex57) #declare MJHTex57 = texture {lc_Trans_Orange} #end #end
#ifdef (lc_Trans_Orange) #ifndef (MJHTex57Slope) #declare MJHTex57Slope = texture {lc_Trans_Orange  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Orange) #ifndef (MJHMat57) #declare MJHMat57 = material {texture {MJHTex57} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Orange) #ifndef (MJHMat57Slope) #declare MJHMat57Slope = material { texture {MJHTex57Slope} interior {lc_ior_block}} #end #end

// row 52 - Chrome_Antique_Brass
#ifdef (lc_Chrome_Antique_Brass) #ifndef (MJHTex60) #declare MJHTex60 = texture {lc_Chrome_Antique_Brass} #end #end
#ifdef (lc_Chrome_Antique_Brass) #ifndef (MJHTex60Slope) #declare MJHTex60Slope = texture {lc_Chrome_Antique_Brass  normal {lc_slope_normal}} #end #end
#ifdef (lc_Chrome_Antique_Brass) #ifndef (MJHMat60) #declare MJHMat60 = material {texture {MJHTex60} interior {lc_ior_block}} #end #end
#ifdef (lc_Chrome_Antique_Brass) #ifndef (MJHMat60Slope) #declare MJHMat60Slope = material { texture {MJHTex60Slope} interior {lc_ior_block}} #end #end

// row 53 - Chrome_Blue
#ifdef (lc_Chrome_Blue) #ifndef (MJHTex61) #declare MJHTex61 = texture {lc_Chrome_Blue} #end #end
#ifdef (lc_Chrome_Blue) #ifndef (MJHTex61Slope) #declare MJHTex61Slope = texture {lc_Chrome_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Chrome_Blue) #ifndef (MJHMat61) #declare MJHMat61 = material {texture {MJHTex61} interior {lc_ior_block}} #end #end
#ifdef (lc_Chrome_Blue) #ifndef (MJHMat61Slope) #declare MJHMat61Slope = material { texture {MJHTex61Slope} interior {lc_ior_block}} #end #end

// row 54 - Chrome_Green
#ifdef (lc_Chrome_Green) #ifndef (MJHTex62) #declare MJHTex62 = texture {lc_Chrome_Green} #end #end
#ifdef (lc_Chrome_Green) #ifndef (MJHTex62Slope) #declare MJHTex62Slope = texture {lc_Chrome_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Chrome_Green) #ifndef (MJHMat62) #declare MJHMat62 = material {texture {MJHTex62} interior {lc_ior_block}} #end #end
#ifdef (lc_Chrome_Green) #ifndef (MJHMat62Slope) #declare MJHMat62Slope = material { texture {MJHTex62Slope} interior {lc_ior_block}} #end #end

// row 55 - Chrome_Pink
#ifdef (lc_Chrome_Pink) #ifndef (MJHTex63) #declare MJHTex63 = texture {lc_Chrome_Pink} #end #end
#ifdef (lc_Chrome_Pink) #ifndef (MJHTex63Slope) #declare MJHTex63Slope = texture {lc_Chrome_Pink  normal {lc_slope_normal}} #end #end
#ifdef (lc_Chrome_Pink) #ifndef (MJHMat63) #declare MJHMat63 = material {texture {MJHTex63} interior {lc_ior_block}} #end #end
#ifdef (lc_Chrome_Pink) #ifndef (MJHMat63Slope) #declare MJHMat63Slope = material { texture {MJHTex63Slope} interior {lc_ior_block}} #end #end

// row 56 - Chrome_Black
#ifdef (lc_Chrome_Black) #ifndef (MJHTex64) #declare MJHTex64 = texture {lc_Chrome_Black} #end #end
#ifdef (lc_Chrome_Black) #ifndef (MJHTex64Slope) #declare MJHTex64Slope = texture {lc_Chrome_Black  normal {lc_slope_normal}} #end #end
#ifdef (lc_Chrome_Black) #ifndef (MJHMat64) #declare MJHMat64 = material {texture {MJHTex64} interior {lc_ior_block}} #end #end
#ifdef (lc_Chrome_Black) #ifndef (MJHMat64Slope) #declare MJHMat64Slope = material { texture {MJHTex64Slope} interior {lc_ior_block}} #end #end

// row 57 - Rubber_Yellow
#ifdef (lc_Rubber_Yellow) #ifndef (MJHTex65) #declare MJHTex65 = texture {lc_Rubber_Yellow} #end #end
#ifdef (lc_Rubber_Yellow) #ifndef (MJHTex65Slope) #declare MJHTex65Slope = texture {lc_Rubber_Yellow  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Yellow) #ifndef (MJHMat65) #declare MJHMat65 = material {texture {MJHTex65} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Yellow) #ifndef (MJHMat65Slope) #declare MJHMat65Slope = material { texture {MJHTex65Slope} interior {lc_ior_block}} #end #end

// row 58 - Rubber_Trans_Yellow
#ifdef (lc_Rubber_Trans_Yellow) #ifndef (MJHTex66) #declare MJHTex66 = texture {lc_Rubber_Trans_Yellow} #end #end
#ifdef (lc_Rubber_Trans_Yellow) #ifndef (MJHTex66Slope) #declare MJHTex66Slope = texture {lc_Rubber_Trans_Yellow  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Trans_Yellow) #ifndef (MJHMat66) #declare MJHMat66 = material {texture {MJHTex66} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Trans_Yellow) #ifndef (MJHMat66Slope) #declare MJHMat66Slope = material { texture {MJHTex66Slope} interior {lc_ior_block}} #end #end

// row 59 - Rubber_Trans_Clear
#ifdef (lc_Rubber_Trans_Clear) #ifndef (MJHTex67) #declare MJHTex67 = texture {lc_Rubber_Trans_Clear} #end #end
#ifdef (lc_Rubber_Trans_Clear) #ifndef (MJHTex67Slope) #declare MJHTex67Slope = texture {lc_Rubber_Trans_Clear  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Trans_Clear) #ifndef (MJHMat67) #declare MJHMat67 = material {texture {MJHTex67} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Trans_Clear) #ifndef (MJHMat67Slope) #declare MJHMat67Slope = material { texture {MJHTex67Slope} interior {lc_ior_block}} #end #end

// row 60 - Very_Light_Orange
#ifdef (lc_Very_Light_Orange) #ifndef (MJHTex68) #declare MJHTex68 = texture {lc_Very_Light_Orange} #end #end
#ifdef (lc_Very_Light_Orange) #ifndef (MJHTex68Slope) #declare MJHTex68Slope = texture {lc_Very_Light_Orange  normal {lc_slope_normal}} #end #end
#ifdef (lc_Very_Light_Orange) #ifndef (MJHMat68) #declare MJHMat68 = material {texture {MJHTex68} interior {lc_ior_block}} #end #end
#ifdef (lc_Very_Light_Orange) #ifndef (MJHMat68Slope) #declare MJHMat68Slope = material { texture {MJHTex68Slope} interior {lc_ior_block}} #end #end

// row 61 - Bright_Reddish_Lilac
#ifdef (lc_Bright_Reddish_Lilac) #ifndef (MJHTex69) #declare MJHTex69 = texture {lc_Bright_Reddish_Lilac} #end #end
#ifdef (lc_Bright_Reddish_Lilac) #ifndef (MJHTex69Slope) #declare MJHTex69Slope = texture {lc_Bright_Reddish_Lilac  normal {lc_slope_normal}} #end #end
#ifdef (lc_Bright_Reddish_Lilac) #ifndef (MJHMat69) #declare MJHMat69 = material {texture {MJHTex69} interior {lc_ior_block}} #end #end
#ifdef (lc_Bright_Reddish_Lilac) #ifndef (MJHMat69Slope) #declare MJHMat69Slope = material { texture {MJHTex69Slope} interior {lc_ior_block}} #end #end

// row 62 - Reddish_Brown
#ifdef (lc_Reddish_Brown) #ifndef (MJHTex70) #declare MJHTex70 = texture {lc_Reddish_Brown} #end #end
#ifdef (lc_Reddish_Brown) #ifndef (MJHTex70Slope) #declare MJHTex70Slope = texture {lc_Reddish_Brown  normal {lc_slope_normal}} #end #end
#ifdef (lc_Reddish_Brown) #ifndef (MJHMat70) #declare MJHMat70 = material {texture {MJHTex70} interior {lc_ior_block}} #end #end
#ifdef (lc_Reddish_Brown) #ifndef (MJHMat70Slope) #declare MJHMat70Slope = material { texture {MJHTex70Slope} interior {lc_ior_block}} #end #end

// row 63 - Light_Bluish_Grey
#ifdef (lc_Light_Bluish_Grey) #ifndef (MJHTex71) #declare MJHTex71 = texture {lc_Light_Bluish_Grey} #end #end
#ifdef (lc_Light_Bluish_Grey) #ifndef (MJHTex71Slope) #declare MJHTex71Slope = texture {lc_Light_Bluish_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Bluish_Grey) #ifndef (MJHMat71) #declare MJHMat71 = material {texture {MJHTex71} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Bluish_Grey) #ifndef (MJHMat71Slope) #declare MJHMat71Slope = material { texture {MJHTex71Slope} interior {lc_ior_block}} #end #end

// row 64 - Dark_Bluish_Grey
#ifdef (lc_Dark_Bluish_Grey) #ifndef (MJHTex72) #declare MJHTex72 = texture {lc_Dark_Bluish_Grey} #end #end
#ifdef (lc_Dark_Bluish_Grey) #ifndef (MJHTex72Slope) #declare MJHTex72Slope = texture {lc_Dark_Bluish_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Bluish_Grey) #ifndef (MJHMat72) #declare MJHMat72 = material {texture {MJHTex72} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Bluish_Grey) #ifndef (MJHMat72Slope) #declare MJHMat72Slope = material { texture {MJHTex72Slope} interior {lc_ior_block}} #end #end

// row 65 - Medium_Blue
#ifdef (lc_Medium_Blue) #ifndef (MJHTex73) #declare MJHTex73 = texture {lc_Medium_Blue} #end #end
#ifdef (lc_Medium_Blue) #ifndef (MJHTex73Slope) #declare MJHTex73Slope = texture {lc_Medium_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Medium_Blue) #ifndef (MJHMat73) #declare MJHMat73 = material {texture {MJHTex73} interior {lc_ior_block}} #end #end
#ifdef (lc_Medium_Blue) #ifndef (MJHMat73Slope) #declare MJHMat73Slope = material { texture {MJHTex73Slope} interior {lc_ior_block}} #end #end

// row 66 - Medium_Green
#ifdef (lc_Medium_Green) #ifndef (MJHTex74) #declare MJHTex74 = texture {lc_Medium_Green} #end #end
#ifdef (lc_Medium_Green) #ifndef (MJHTex74Slope) #declare MJHTex74Slope = texture {lc_Medium_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Medium_Green) #ifndef (MJHMat74) #declare MJHMat74 = material {texture {MJHTex74} interior {lc_ior_block}} #end #end
#ifdef (lc_Medium_Green) #ifndef (MJHMat74Slope) #declare MJHMat74Slope = material { texture {MJHTex74Slope} interior {lc_ior_block}} #end #end

// row 67 - Speckle_Black_Copper
#ifdef (lc_Speckle_Black_Copper) #ifndef (MJHTex75) #declare MJHTex75 = texture {lc_Speckle_Black_Copper} #end #end
#ifdef (lc_Speckle_Black_Copper) #ifndef (MJHTex75Slope) #declare MJHTex75Slope = texture {lc_Speckle_Black_Copper  normal {lc_slope_normal}} #end #end
#ifdef (lc_Speckle_Black_Copper) #ifndef (MJHMat75) #declare MJHMat75 = material {texture {MJHTex75} interior {lc_ior_block}} #end #end
#ifdef (lc_Speckle_Black_Copper) #ifndef (MJHMat75Slope) #declare MJHMat75Slope = material { texture {MJHTex75Slope} interior {lc_ior_block}} #end #end

// row 68 - Speckle_Dark_Bluish_Grey_Silver
#ifdef (lc_Speckle_Dark_Bluish_Grey_Silver) #ifndef (MJHTex76) #declare MJHTex76 = texture {lc_Speckle_Dark_Bluish_Grey_Silver} #end #end
#ifdef (lc_Speckle_Dark_Bluish_Grey_Silver) #ifndef (MJHTex76Slope) #declare MJHTex76Slope = texture {lc_Speckle_Dark_Bluish_Grey_Silver  normal {lc_slope_normal}} #end #end
#ifdef (lc_Speckle_Dark_Bluish_Grey_Silver) #ifndef (MJHMat76) #declare MJHMat76 = material {texture {MJHTex76} interior {lc_ior_block}} #end #end
#ifdef (lc_Speckle_Dark_Bluish_Grey_Silver) #ifndef (MJHMat76Slope) #declare MJHMat76Slope = material { texture {MJHTex76Slope} interior {lc_ior_block}} #end #end

// row 69 - Light_Pink
#ifdef (lc_Light_Pink) #ifndef (MJHTex77) #declare MJHTex77 = texture {lc_Light_Pink} #end #end
#ifdef (lc_Light_Pink) #ifndef (MJHTex77Slope) #declare MJHTex77Slope = texture {lc_Light_Pink  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Pink) #ifndef (MJHMat77) #declare MJHMat77 = material {texture {MJHTex77} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Pink) #ifndef (MJHMat77Slope) #declare MJHMat77Slope = material { texture {MJHTex77Slope} interior {lc_ior_block}} #end #end

// row 70 - Light_Flesh
#ifdef (lc_Light_Flesh) #ifndef (MJHTex78) #declare MJHTex78 = texture {lc_Light_Flesh} #end #end
#ifdef (lc_Light_Flesh) #ifndef (MJHTex78Slope) #declare MJHTex78Slope = texture {lc_Light_Flesh  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Flesh) #ifndef (MJHMat78) #declare MJHMat78 = material {texture {MJHTex78} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Flesh) #ifndef (MJHMat78Slope) #declare MJHMat78Slope = material { texture {MJHTex78Slope} interior {lc_ior_block}} #end #end

// row 71 - Milky_White
#ifdef (lc_Milky_White) #ifndef (MJHTex79) #declare MJHTex79 = texture {lc_Milky_White} #end #end
#ifdef (lc_Milky_White) #ifndef (MJHTex79Slope) #declare MJHTex79Slope = texture {lc_Milky_White  normal {lc_slope_normal}} #end #end
#ifdef (lc_Milky_White) #ifndef (MJHMat79) #declare MJHMat79 = material {texture {MJHTex79} interior {lc_ior_block}} #end #end
#ifdef (lc_Milky_White) #ifndef (MJHMat79Slope) #declare MJHMat79Slope = material { texture {MJHTex79Slope} interior {lc_ior_block}} #end #end

// row 72 - Metallic_Silver
#ifdef (lc_Metallic_Silver) #ifndef (MJHTex80) #declare MJHTex80 = texture {lc_Metallic_Silver} #end #end
#ifdef (lc_Metallic_Silver) #ifndef (MJHTex80Slope) #declare MJHTex80Slope = texture {lc_Metallic_Silver  normal {lc_slope_normal}} #end #end
#ifdef (lc_Metallic_Silver) #ifndef (MJHMat80) #declare MJHMat80 = material {texture {MJHTex80} interior {lc_ior_block}} #end #end
#ifdef (lc_Metallic_Silver) #ifndef (MJHMat80Slope) #declare MJHMat80Slope = material { texture {MJHTex80Slope} interior {lc_ior_block}} #end #end

// row 73 - Metallic_Green
#ifdef (lc_Metallic_Green) #ifndef (MJHTex81) #declare MJHTex81 = texture {lc_Metallic_Green} #end #end
#ifdef (lc_Metallic_Green) #ifndef (MJHTex81Slope) #declare MJHTex81Slope = texture {lc_Metallic_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Metallic_Green) #ifndef (MJHMat81) #declare MJHMat81 = material {texture {MJHTex81} interior {lc_ior_block}} #end #end
#ifdef (lc_Metallic_Green) #ifndef (MJHMat81Slope) #declare MJHMat81Slope = material { texture {MJHTex81Slope} interior {lc_ior_block}} #end #end

// row 74 - Metallic_Gold
#ifdef (lc_Metallic_Gold) #ifndef (MJHTex82) #declare MJHTex82 = texture {lc_Metallic_Gold} #end #end
#ifdef (lc_Metallic_Gold) #ifndef (MJHTex82Slope) #declare MJHTex82Slope = texture {lc_Metallic_Gold  normal {lc_slope_normal}} #end #end
#ifdef (lc_Metallic_Gold) #ifndef (MJHMat82) #declare MJHMat82 = material {texture {MJHTex82} interior {lc_ior_block}} #end #end
#ifdef (lc_Metallic_Gold) #ifndef (MJHMat82Slope) #declare MJHMat82Slope = material { texture {MJHTex82Slope} interior {lc_ior_block}} #end #end

// row 75 - Metallic_Black
#ifdef (lc_Metallic_Black) #ifndef (MJHTex83) #declare MJHTex83 = texture {lc_Metallic_Black} #end #end
#ifdef (lc_Metallic_Black) #ifndef (MJHTex83Slope) #declare MJHTex83Slope = texture {lc_Metallic_Black  normal {lc_slope_normal}} #end #end
#ifdef (lc_Metallic_Black) #ifndef (MJHMat83) #declare MJHMat83 = material {texture {MJHTex83} interior {lc_ior_block}} #end #end
#ifdef (lc_Metallic_Black) #ifndef (MJHMat83Slope) #declare MJHMat83Slope = material { texture {MJHTex83Slope} interior {lc_ior_block}} #end #end

// row 76 - Medium_Dark_Flesh
#ifdef (lc_Medium_Dark_Flesh) #ifndef (MJHTex84) #declare MJHTex84 = texture {lc_Medium_Dark_Flesh} #end #end
#ifdef (lc_Medium_Dark_Flesh) #ifndef (MJHTex84Slope) #declare MJHTex84Slope = texture {lc_Medium_Dark_Flesh  normal {lc_slope_normal}} #end #end
#ifdef (lc_Medium_Dark_Flesh) #ifndef (MJHMat84) #declare MJHMat84 = material {texture {MJHTex84} interior {lc_ior_block}} #end #end
#ifdef (lc_Medium_Dark_Flesh) #ifndef (MJHMat84Slope) #declare MJHMat84Slope = material { texture {MJHTex84Slope} interior {lc_ior_block}} #end #end

// row 77 - Medium_Lilac
#ifdef (lc_Medium_Lilac) #ifndef (MJHTex85) #declare MJHTex85 = texture {lc_Medium_Lilac} #end #end
#ifdef (lc_Medium_Lilac) #ifndef (MJHTex85Slope) #declare MJHTex85Slope = texture {lc_Medium_Lilac  normal {lc_slope_normal}} #end #end
#ifdef (lc_Medium_Lilac) #ifndef (MJHMat85) #declare MJHMat85 = material {texture {MJHTex85} interior {lc_ior_block}} #end #end
#ifdef (lc_Medium_Lilac) #ifndef (MJHMat85Slope) #declare MJHMat85Slope = material { texture {MJHTex85Slope} interior {lc_ior_block}} #end #end

// row 78 - Dark_Flesh
#ifdef (lc_Dark_Flesh) #ifndef (MJHTex86) #declare MJHTex86 = texture {lc_Dark_Flesh} #end #end
#ifdef (lc_Dark_Flesh) #ifndef (MJHTex86Slope) #declare MJHTex86Slope = texture {lc_Dark_Flesh  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Flesh) #ifndef (MJHMat86) #declare MJHMat86 = material {texture {MJHTex86} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Flesh) #ifndef (MJHMat86Slope) #declare MJHMat86Slope = material { texture {MJHTex86Slope} interior {lc_ior_block}} #end #end

// row 79 - Metallic_Dark_Grey
#ifdef (lc_Metallic_Dark_Grey) #ifndef (MJHTex87) #declare MJHTex87 = texture {lc_Metallic_Dark_Grey} #end #end
#ifdef (lc_Metallic_Dark_Grey) #ifndef (MJHTex87Slope) #declare MJHTex87Slope = texture {lc_Metallic_Dark_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Metallic_Dark_Grey) #ifndef (MJHMat87) #declare MJHMat87 = material {texture {MJHTex87} interior {lc_ior_block}} #end #end
#ifdef (lc_Metallic_Dark_Grey) #ifndef (MJHMat87Slope) #declare MJHMat87Slope = material { texture {MJHTex87Slope} interior {lc_ior_block}} #end #end

// row 80 - Blue_Violet
#ifdef (lc_Blue_Violet) #ifndef (MJHTex89) #declare MJHTex89 = texture {lc_Blue_Violet} #end #end
#ifdef (lc_Blue_Violet) #ifndef (MJHTex89Slope) #declare MJHTex89Slope = texture {lc_Blue_Violet  normal {lc_slope_normal}} #end #end
#ifdef (lc_Blue_Violet) #ifndef (MJHMat89) #declare MJHMat89 = material {texture {MJHTex89} interior {lc_ior_block}} #end #end
#ifdef (lc_Blue_Violet) #ifndef (MJHMat89Slope) #declare MJHMat89Slope = material { texture {MJHTex89Slope} interior {lc_ior_block}} #end #end

// row 81 - Flesh
#ifdef (lc_Flesh) #ifndef (MJHTex92) #declare MJHTex92 = texture {lc_Flesh} #end #end
#ifdef (lc_Flesh) #ifndef (MJHTex92Slope) #declare MJHTex92Slope = texture {lc_Flesh  normal {lc_slope_normal}} #end #end
#ifdef (lc_Flesh) #ifndef (MJHMat92) #declare MJHMat92 = material {texture {MJHTex92} interior {lc_ior_block}} #end #end
#ifdef (lc_Flesh) #ifndef (MJHMat92Slope) #declare MJHMat92Slope = material { texture {MJHTex92Slope} interior {lc_ior_block}} #end #end

// row 82 - Light_Salmon
#ifdef (lc_Light_Salmon) #ifndef (MJHTex100) #declare MJHTex100 = texture {lc_Light_Salmon} #end #end
#ifdef (lc_Light_Salmon) #ifndef (MJHTex100Slope) #declare MJHTex100Slope = texture {lc_Light_Salmon  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Salmon) #ifndef (MJHMat100) #declare MJHMat100 = material {texture {MJHTex100} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Salmon) #ifndef (MJHMat100Slope) #declare MJHMat100Slope = material { texture {MJHTex100Slope} interior {lc_ior_block}} #end #end

// row 83 - Violet
#ifdef (lc_Violet) #ifndef (MJHTex110) #declare MJHTex110 = texture {lc_Violet} #end #end
#ifdef (lc_Violet) #ifndef (MJHTex110Slope) #declare MJHTex110Slope = texture {lc_Violet  normal {lc_slope_normal}} #end #end
#ifdef (lc_Violet) #ifndef (MJHMat110) #declare MJHMat110 = material {texture {MJHTex110} interior {lc_ior_block}} #end #end
#ifdef (lc_Violet) #ifndef (MJHMat110Slope) #declare MJHMat110Slope = material { texture {MJHTex110Slope} interior {lc_ior_block}} #end #end

// row 84 - Medium_Violet
#ifdef (lc_Medium_Violet) #ifndef (MJHTex112) #declare MJHTex112 = texture {lc_Medium_Violet} #end #end
#ifdef (lc_Medium_Violet) #ifndef (MJHTex112Slope) #declare MJHTex112Slope = texture {lc_Medium_Violet  normal {lc_slope_normal}} #end #end
#ifdef (lc_Medium_Violet) #ifndef (MJHMat112) #declare MJHMat112 = material {texture {MJHTex112} interior {lc_ior_block}} #end #end
#ifdef (lc_Medium_Violet) #ifndef (MJHMat112Slope) #declare MJHMat112Slope = material { texture {MJHTex112Slope} interior {lc_ior_block}} #end #end

// row 85 - Glitter_Trans_Dark_Pink
#ifdef (lc_Glitter_Trans_Dark_Pink) #ifndef (MJHTex114) #declare MJHTex114 = texture {lc_Glitter_Trans_Dark_Pink} #end #end
#ifdef (lc_Glitter_Trans_Dark_Pink) #ifndef (MJHTex114Slope) #declare MJHTex114Slope = texture {lc_Glitter_Trans_Dark_Pink  normal {lc_slope_normal}} #end #end
#ifdef (lc_Glitter_Trans_Dark_Pink) #ifndef (MJHMat114) #declare MJHMat114 = material {texture {MJHTex114} interior {lc_ior_block}} #end #end
#ifdef (lc_Glitter_Trans_Dark_Pink) #ifndef (MJHMat114Slope) #declare MJHMat114Slope = material { texture {MJHTex114Slope} interior {lc_ior_block}} #end #end

// row 86 - Medium_Lime
#ifdef (lc_Medium_Lime) #ifndef (MJHTex115) #declare MJHTex115 = texture {lc_Medium_Lime} #end #end
#ifdef (lc_Medium_Lime) #ifndef (MJHTex115Slope) #declare MJHTex115Slope = texture {lc_Medium_Lime  normal {lc_slope_normal}} #end #end
#ifdef (lc_Medium_Lime) #ifndef (MJHMat115) #declare MJHMat115 = material {texture {MJHTex115} interior {lc_ior_block}} #end #end
#ifdef (lc_Medium_Lime) #ifndef (MJHMat115Slope) #declare MJHMat115Slope = material { texture {MJHTex115Slope} interior {lc_ior_block}} #end #end

// row 87 - Glitter_Trans_Clear
#ifdef (lc_Glitter_Trans_Clear) #ifndef (MJHTex117) #declare MJHTex117 = texture {lc_Glitter_Trans_Clear} #end #end
#ifdef (lc_Glitter_Trans_Clear) #ifndef (MJHTex117Slope) #declare MJHTex117Slope = texture {lc_Glitter_Trans_Clear  normal {lc_slope_normal}} #end #end
#ifdef (lc_Glitter_Trans_Clear) #ifndef (MJHMat117) #declare MJHMat117 = material {texture {MJHTex117} interior {lc_ior_block}} #end #end
#ifdef (lc_Glitter_Trans_Clear) #ifndef (MJHMat117Slope) #declare MJHMat117Slope = material { texture {MJHTex117Slope} interior {lc_ior_block}} #end #end

// row 88 - Aqua
#ifdef (lc_Aqua) #ifndef (MJHTex118) #declare MJHTex118 = texture {lc_Aqua} #end #end
#ifdef (lc_Aqua) #ifndef (MJHTex118Slope) #declare MJHTex118Slope = texture {lc_Aqua  normal {lc_slope_normal}} #end #end
#ifdef (lc_Aqua) #ifndef (MJHMat118) #declare MJHMat118 = material {texture {MJHTex118} interior {lc_ior_block}} #end #end
#ifdef (lc_Aqua) #ifndef (MJHMat118Slope) #declare MJHMat118Slope = material { texture {MJHTex118Slope} interior {lc_ior_block}} #end #end

// row 89 - Light_Lime
#ifdef (lc_Light_Lime) #ifndef (MJHTex120) #declare MJHTex120 = texture {lc_Light_Lime} #end #end
#ifdef (lc_Light_Lime) #ifndef (MJHTex120Slope) #declare MJHTex120Slope = texture {lc_Light_Lime  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Lime) #ifndef (MJHMat120) #declare MJHMat120 = material {texture {MJHTex120} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Lime) #ifndef (MJHMat120Slope) #declare MJHMat120Slope = material { texture {MJHTex120Slope} interior {lc_ior_block}} #end #end

// row 90 - Light_Orange
#ifdef (lc_Light_Orange) #ifndef (MJHTex125) #declare MJHTex125 = texture {lc_Light_Orange} #end #end
#ifdef (lc_Light_Orange) #ifndef (MJHTex125Slope) #declare MJHTex125Slope = texture {lc_Light_Orange  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Orange) #ifndef (MJHMat125) #declare MJHMat125 = material {texture {MJHTex125} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Orange) #ifndef (MJHMat125Slope) #declare MJHMat125Slope = material { texture {MJHTex125Slope} interior {lc_ior_block}} #end #end

// row 91 - Dark_Nougat
#ifdef (lc_Dark_Nougat) #ifndef (MJHTex128) #declare MJHTex128 = texture {lc_Dark_Nougat} #end #end
#ifdef (lc_Dark_Nougat) #ifndef (MJHTex128Slope) #declare MJHTex128Slope = texture {lc_Dark_Nougat  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Nougat) #ifndef (MJHMat128) #declare MJHMat128 = material {texture {MJHTex128} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Nougat) #ifndef (MJHMat128Slope) #declare MJHMat128Slope = material { texture {MJHTex128Slope} interior {lc_ior_block}} #end #end

// row 92 - Glitter_Trans_Purple
#ifdef (lc_Glitter_Trans_Purple) #ifndef (MJHTex129) #declare MJHTex129 = texture {lc_Glitter_Trans_Purple} #end #end
#ifdef (lc_Glitter_Trans_Purple) #ifndef (MJHTex129Slope) #declare MJHTex129Slope = texture {lc_Glitter_Trans_Purple  normal {lc_slope_normal}} #end #end
#ifdef (lc_Glitter_Trans_Purple) #ifndef (MJHMat129) #declare MJHMat129 = material {texture {MJHTex129} interior {lc_ior_block}} #end #end
#ifdef (lc_Glitter_Trans_Purple) #ifndef (MJHMat129Slope) #declare MJHMat129Slope = material { texture {MJHTex129Slope} interior {lc_ior_block}} #end #end

// row 93 - Speckle_Black_Silver
#ifdef (lc_Speckle_Black_Silver) #ifndef (MJHTex132) #declare MJHTex132 = texture {lc_Speckle_Black_Silver} #end #end
#ifdef (lc_Speckle_Black_Silver) #ifndef (MJHTex132Slope) #declare MJHTex132Slope = texture {lc_Speckle_Black_Silver  normal {lc_slope_normal}} #end #end
#ifdef (lc_Speckle_Black_Silver) #ifndef (MJHMat132) #declare MJHMat132 = material {texture {MJHTex132} interior {lc_ior_block}} #end #end
#ifdef (lc_Speckle_Black_Silver) #ifndef (MJHMat132Slope) #declare MJHMat132Slope = material { texture {MJHTex132Slope} interior {lc_ior_block}} #end #end

// row 94 - Speckle_Black_Gold
#ifdef (lc_Speckle_Black_Gold) #ifndef (MJHTex133) #declare MJHTex133 = texture {lc_Speckle_Black_Gold} #end #end
#ifdef (lc_Speckle_Black_Gold) #ifndef (MJHTex133Slope) #declare MJHTex133Slope = texture {lc_Speckle_Black_Gold  normal {lc_slope_normal}} #end #end
#ifdef (lc_Speckle_Black_Gold) #ifndef (MJHMat133) #declare MJHMat133 = material {texture {MJHTex133} interior {lc_ior_block}} #end #end
#ifdef (lc_Speckle_Black_Gold) #ifndef (MJHMat133Slope) #declare MJHMat133Slope = material { texture {MJHTex133Slope} interior {lc_ior_block}} #end #end

// row 95 - Copper
#ifdef (lc_Copper) #ifndef (MJHTex134) #declare MJHTex134 = texture {lc_Copper} #end #end
#ifdef (lc_Copper) #ifndef (MJHTex134Slope) #declare MJHTex134Slope = texture {lc_Copper  normal {lc_slope_normal}} #end #end
#ifdef (lc_Copper) #ifndef (MJHMat134) #declare MJHMat134 = material {texture {MJHTex134} interior {lc_ior_block}} #end #end
#ifdef (lc_Copper) #ifndef (MJHMat134Slope) #declare MJHMat134Slope = material { texture {MJHTex134Slope} interior {lc_ior_block}} #end #end

// row 96 - Pearl_Light_Grey
#ifdef (lc_Pearl_Light_Grey) #ifndef (MJHTex135) #declare MJHTex135 = texture {lc_Pearl_Light_Grey} #end #end
#ifdef (lc_Pearl_Light_Grey) #ifndef (MJHTex135Slope) #declare MJHTex135Slope = texture {lc_Pearl_Light_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Pearl_Light_Grey) #ifndef (MJHMat135) #declare MJHMat135 = material {texture {MJHTex135} interior {lc_ior_block}} #end #end
#ifdef (lc_Pearl_Light_Grey) #ifndef (MJHMat135Slope) #declare MJHMat135Slope = material { texture {MJHTex135Slope} interior {lc_ior_block}} #end #end

// row 97 - Metal_Blue
#ifdef (lc_Metal_Blue) #ifndef (MJHTex137) #declare MJHTex137 = texture {lc_Metal_Blue} #end #end
#ifdef (lc_Metal_Blue) #ifndef (MJHTex137Slope) #declare MJHTex137Slope = texture {lc_Metal_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Metal_Blue) #ifndef (MJHMat137) #declare MJHMat137 = material {texture {MJHTex137} interior {lc_ior_block}} #end #end
#ifdef (lc_Metal_Blue) #ifndef (MJHMat137Slope) #declare MJHMat137Slope = material { texture {MJHTex137Slope} interior {lc_ior_block}} #end #end

// row 98 - Pearl_Light_Gold
#ifdef (lc_Pearl_Light_Gold) #ifndef (MJHTex142) #declare MJHTex142 = texture {lc_Pearl_Light_Gold} #end #end
#ifdef (lc_Pearl_Light_Gold) #ifndef (MJHTex142Slope) #declare MJHTex142Slope = texture {lc_Pearl_Light_Gold  normal {lc_slope_normal}} #end #end
#ifdef (lc_Pearl_Light_Gold) #ifndef (MJHMat142) #declare MJHMat142 = material {texture {MJHTex142} interior {lc_ior_block}} #end #end
#ifdef (lc_Pearl_Light_Gold) #ifndef (MJHMat142Slope) #declare MJHMat142Slope = material { texture {MJHTex142Slope} interior {lc_ior_block}} #end #end

// row 99 - Pearl_Dark_Grey
#ifdef (lc_Pearl_Dark_Grey) #ifndef (MJHTex148) #declare MJHTex148 = texture {lc_Pearl_Dark_Grey} #end #end
#ifdef (lc_Pearl_Dark_Grey) #ifndef (MJHTex148Slope) #declare MJHTex148Slope = texture {lc_Pearl_Dark_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Pearl_Dark_Grey) #ifndef (MJHMat148) #declare MJHMat148 = material {texture {MJHTex148} interior {lc_ior_block}} #end #end
#ifdef (lc_Pearl_Dark_Grey) #ifndef (MJHMat148Slope) #declare MJHMat148Slope = material { texture {MJHTex148Slope} interior {lc_ior_block}} #end #end

// row 100 - Pearl_Very_Light_Grey
#ifdef (lc_Pearl_Very_Light_Grey) #ifndef (MJHTex150) #declare MJHTex150 = texture {lc_Pearl_Very_Light_Grey} #end #end
#ifdef (lc_Pearl_Very_Light_Grey) #ifndef (MJHTex150Slope) #declare MJHTex150Slope = texture {lc_Pearl_Very_Light_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Pearl_Very_Light_Grey) #ifndef (MJHMat150) #declare MJHMat150 = material {texture {MJHTex150} interior {lc_ior_block}} #end #end
#ifdef (lc_Pearl_Very_Light_Grey) #ifndef (MJHMat150Slope) #declare MJHMat150Slope = material { texture {MJHTex150Slope} interior {lc_ior_block}} #end #end

// row 101 - Very_Light_Bluish_Grey
#ifdef (lc_Very_Light_Bluish_Grey) #ifndef (MJHTex151) #declare MJHTex151 = texture {lc_Very_Light_Bluish_Grey} #end #end
#ifdef (lc_Very_Light_Bluish_Grey) #ifndef (MJHTex151Slope) #declare MJHTex151Slope = texture {lc_Very_Light_Bluish_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Very_Light_Bluish_Grey) #ifndef (MJHMat151) #declare MJHMat151 = material {texture {MJHTex151} interior {lc_ior_block}} #end #end
#ifdef (lc_Very_Light_Bluish_Grey) #ifndef (MJHMat151Slope) #declare MJHMat151Slope = material { texture {MJHTex151Slope} interior {lc_ior_block}} #end #end

// row 102 - Flat_Dark_Gold
#ifdef (lc_Flat_Dark_Gold) #ifndef (MJHTex178) #declare MJHTex178 = texture {lc_Flat_Dark_Gold} #end #end
#ifdef (lc_Flat_Dark_Gold) #ifndef (MJHTex178Slope) #declare MJHTex178Slope = texture {lc_Flat_Dark_Gold  normal {lc_slope_normal}} #end #end
#ifdef (lc_Flat_Dark_Gold) #ifndef (MJHMat178) #declare MJHMat178 = material {texture {MJHTex178} interior {lc_ior_block}} #end #end
#ifdef (lc_Flat_Dark_Gold) #ifndef (MJHMat178Slope) #declare MJHMat178Slope = material { texture {MJHTex178Slope} interior {lc_ior_block}} #end #end

// row 103 - Flat_Silver
#ifdef (lc_Flat_Silver) #ifndef (MJHTex179) #declare MJHTex179 = texture {lc_Flat_Silver} #end #end
#ifdef (lc_Flat_Silver) #ifndef (MJHTex179Slope) #declare MJHTex179Slope = texture {lc_Flat_Silver  normal {lc_slope_normal}} #end #end
#ifdef (lc_Flat_Silver) #ifndef (MJHMat179) #declare MJHMat179 = material {texture {MJHTex179} interior {lc_ior_block}} #end #end
#ifdef (lc_Flat_Silver) #ifndef (MJHMat179Slope) #declare MJHMat179Slope = material { texture {MJHTex179Slope} interior {lc_ior_block}} #end #end

// row 104 - Pearl_White
#ifdef (lc_Pearl_White) #ifndef (MJHTex183) #declare MJHTex183 = texture {lc_Pearl_White} #end #end
#ifdef (lc_Pearl_White) #ifndef (MJHTex183Slope) #declare MJHTex183Slope = texture {lc_Pearl_White  normal {lc_slope_normal}} #end #end
#ifdef (lc_Pearl_White) #ifndef (MJHMat183) #declare MJHMat183 = material {texture {MJHTex183} interior {lc_ior_block}} #end #end
#ifdef (lc_Pearl_White) #ifndef (MJHMat183Slope) #declare MJHMat183Slope = material { texture {MJHTex183Slope} interior {lc_ior_block}} #end #end

// row 105 - Metallic_Bright_Red
#ifdef (lc_Metallic_Bright_Red) #ifndef (MJHTex184) #declare MJHTex184 = texture {lc_Metallic_Bright_Red} #end #end
#ifdef (lc_Metallic_Bright_Red) #ifndef (MJHTex184Slope) #declare MJHTex184Slope = texture {lc_Metallic_Bright_Red  normal {lc_slope_normal}} #end #end
#ifdef (lc_Metallic_Bright_Red) #ifndef (MJHMat184) #declare MJHMat184 = material {texture {MJHTex184} interior {lc_ior_block}} #end #end
#ifdef (lc_Metallic_Bright_Red) #ifndef (MJHMat184Slope) #declare MJHMat184Slope = material { texture {MJHTex184Slope} interior {lc_ior_block}} #end #end

// row 106 - Metallic_Dark_Green
#ifdef (lc_Metallic_Dark_Green) #ifndef (MJHTex186) #declare MJHTex186 = texture {lc_Metallic_Dark_Green} #end #end
#ifdef (lc_Metallic_Dark_Green) #ifndef (MJHTex186Slope) #declare MJHTex186Slope = texture {lc_Metallic_Dark_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Metallic_Dark_Green) #ifndef (MJHMat186) #declare MJHMat186 = material {texture {MJHTex186} interior {lc_ior_block}} #end #end
#ifdef (lc_Metallic_Dark_Green) #ifndef (MJHMat186Slope) #declare MJHMat186Slope = material { texture {MJHTex186Slope} interior {lc_ior_block}} #end #end

// row 107 - Reddish_Gold
#ifdef (lc_Reddish_Gold) #ifndef (MJHTex189) #declare MJHTex189 = texture {lc_Reddish_Gold} #end #end
#ifdef (lc_Reddish_Gold) #ifndef (MJHTex189Slope) #declare MJHTex189Slope = texture {lc_Reddish_Gold  normal {lc_slope_normal}} #end #end
#ifdef (lc_Reddish_Gold) #ifndef (MJHMat189) #declare MJHMat189 = material {texture {MJHTex189} interior {lc_ior_block}} #end #end
#ifdef (lc_Reddish_Gold) #ifndef (MJHMat189Slope) #declare MJHMat189Slope = material { texture {MJHTex189Slope} interior {lc_ior_block}} #end #end

// row 108 - Bright_Light_Orange
#ifdef (lc_Bright_Light_Orange) #ifndef (MJHTex191) #declare MJHTex191 = texture {lc_Bright_Light_Orange} #end #end
#ifdef (lc_Bright_Light_Orange) #ifndef (MJHTex191Slope) #declare MJHTex191Slope = texture {lc_Bright_Light_Orange  normal {lc_slope_normal}} #end #end
#ifdef (lc_Bright_Light_Orange) #ifndef (MJHMat191) #declare MJHMat191 = material {texture {MJHTex191} interior {lc_ior_block}} #end #end
#ifdef (lc_Bright_Light_Orange) #ifndef (MJHMat191Slope) #declare MJHMat191Slope = material { texture {MJHTex191Slope} interior {lc_ior_block}} #end #end

// row 109 - Bright_Light_Blue
#ifdef (lc_Bright_Light_Blue) #ifndef (MJHTex212) #declare MJHTex212 = texture {lc_Bright_Light_Blue} #end #end
#ifdef (lc_Bright_Light_Blue) #ifndef (MJHTex212Slope) #declare MJHTex212Slope = texture {lc_Bright_Light_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Bright_Light_Blue) #ifndef (MJHMat212) #declare MJHMat212 = material {texture {MJHTex212} interior {lc_ior_block}} #end #end
#ifdef (lc_Bright_Light_Blue) #ifndef (MJHMat212Slope) #declare MJHMat212Slope = material { texture {MJHTex212Slope} interior {lc_ior_block}} #end #end

// row 110 - Rust
#ifdef (lc_Rust) #ifndef (MJHTex216) #declare MJHTex216 = texture {lc_Rust} #end #end
#ifdef (lc_Rust) #ifndef (MJHTex216Slope) #declare MJHTex216Slope = texture {lc_Rust  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rust) #ifndef (MJHMat216) #declare MJHMat216 = material {texture {MJHTex216} interior {lc_ior_block}} #end #end
#ifdef (lc_Rust) #ifndef (MJHMat216Slope) #declare MJHMat216Slope = material { texture {MJHTex216Slope} interior {lc_ior_block}} #end #end

// row 111 - Reddish_Lilac
#ifdef (lc_Reddish_Lilac) #ifndef (MJHTex218) #declare MJHTex218 = texture {lc_Reddish_Lilac} #end #end
#ifdef (lc_Reddish_Lilac) #ifndef (MJHTex218Slope) #declare MJHTex218Slope = texture {lc_Reddish_Lilac  normal {lc_slope_normal}} #end #end
#ifdef (lc_Reddish_Lilac) #ifndef (MJHMat218) #declare MJHMat218 = material {texture {MJHTex218} interior {lc_ior_block}} #end #end
#ifdef (lc_Reddish_Lilac) #ifndef (MJHMat218Slope) #declare MJHMat218Slope = material { texture {MJHTex218Slope} interior {lc_ior_block}} #end #end

// row 112 - Lilac
#ifdef (lc_Lilac) #ifndef (MJHTex219) #declare MJHTex219 = texture {lc_Lilac} #end #end
#ifdef (lc_Lilac) #ifndef (MJHTex219Slope) #declare MJHTex219Slope = texture {lc_Lilac  normal {lc_slope_normal}} #end #end
#ifdef (lc_Lilac) #ifndef (MJHMat219) #declare MJHMat219 = material {texture {MJHTex219} interior {lc_ior_block}} #end #end
#ifdef (lc_Lilac) #ifndef (MJHMat219Slope) #declare MJHMat219Slope = material { texture {MJHTex219Slope} interior {lc_ior_block}} #end #end

// row 113 - Bright_Light_Yellow
#ifdef (lc_Bright_Light_Yellow) #ifndef (MJHTex226) #declare MJHTex226 = texture {lc_Bright_Light_Yellow} #end #end
#ifdef (lc_Bright_Light_Yellow) #ifndef (MJHTex226Slope) #declare MJHTex226Slope = texture {lc_Bright_Light_Yellow  normal {lc_slope_normal}} #end #end
#ifdef (lc_Bright_Light_Yellow) #ifndef (MJHMat226) #declare MJHMat226 = material {texture {MJHTex226} interior {lc_ior_block}} #end #end
#ifdef (lc_Bright_Light_Yellow) #ifndef (MJHMat226Slope) #declare MJHMat226Slope = material { texture {MJHTex226Slope} interior {lc_ior_block}} #end #end

// row 114 - Trans_Bright_Light_Orange
#ifdef (lc_Trans_Bright_Light_Orange) #ifndef (MJHTex231) #declare MJHTex231 = texture {lc_Trans_Bright_Light_Orange} #end #end
#ifdef (lc_Trans_Bright_Light_Orange) #ifndef (MJHTex231Slope) #declare MJHTex231Slope = texture {lc_Trans_Bright_Light_Orange  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Bright_Light_Orange) #ifndef (MJHMat231) #declare MJHMat231 = material {texture {MJHTex231} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Bright_Light_Orange) #ifndef (MJHMat231Slope) #declare MJHMat231Slope = material { texture {MJHTex231Slope} interior {lc_ior_block}} #end #end

// row 115 - Sky_Blue
#ifdef (lc_Sky_Blue) #ifndef (MJHTex232) #declare MJHTex232 = texture {lc_Sky_Blue} #end #end
#ifdef (lc_Sky_Blue) #ifndef (MJHTex232Slope) #declare MJHTex232Slope = texture {lc_Sky_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Sky_Blue) #ifndef (MJHMat232) #declare MJHMat232 = material {texture {MJHTex232} interior {lc_ior_block}} #end #end
#ifdef (lc_Sky_Blue) #ifndef (MJHMat232Slope) #declare MJHMat232Slope = material { texture {MJHTex232Slope} interior {lc_ior_block}} #end #end

// row 116 - Trans_Fire_Yellow
#ifdef (lc_Trans_Fire_Yellow) #ifndef (MJHTex234) #declare MJHTex234 = texture {lc_Trans_Fire_Yellow} #end #end
#ifdef (lc_Trans_Fire_Yellow) #ifndef (MJHTex234Slope) #declare MJHTex234Slope = texture {lc_Trans_Fire_Yellow  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Fire_Yellow) #ifndef (MJHMat234) #declare MJHMat234 = material {texture {MJHTex234} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Fire_Yellow) #ifndef (MJHMat234Slope) #declare MJHMat234Slope = material { texture {MJHTex234Slope} interior {lc_ior_block}} #end #end

// row 117 - Rubber_Black
#ifdef (lc_Rubber_Black) #ifndef (MJHTex256) #declare MJHTex256 = texture {lc_Rubber_Black} #end #end
#ifdef (lc_Rubber_Black) #ifndef (MJHTex256Slope) #declare MJHTex256Slope = texture {lc_Rubber_Black  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Black) #ifndef (MJHMat256) #declare MJHMat256 = material {texture {MJHTex256} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Black) #ifndef (MJHMat256Slope) #declare MJHMat256Slope = material { texture {MJHTex256Slope} interior {lc_ior_block}} #end #end

// row 118 - Dark_Blue
#ifdef (lc_Dark_Blue) #ifndef (MJHTex272) #declare MJHTex272 = texture {lc_Dark_Blue} #end #end
#ifdef (lc_Dark_Blue) #ifndef (MJHTex272Slope) #declare MJHTex272Slope = texture {lc_Dark_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Blue) #ifndef (MJHMat272) #declare MJHMat272 = material {texture {MJHTex272} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Blue) #ifndef (MJHMat272Slope) #declare MJHMat272Slope = material { texture {MJHTex272Slope} interior {lc_ior_block}} #end #end

// row 119 - Rubber_Blue
#ifdef (lc_Rubber_Blue) #ifndef (MJHTex273) #declare MJHTex273 = texture {lc_Rubber_Blue} #end #end
#ifdef (lc_Rubber_Blue) #ifndef (MJHTex273Slope) #declare MJHTex273Slope = texture {lc_Rubber_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Blue) #ifndef (MJHMat273) #declare MJHMat273 = material {texture {MJHTex273} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Blue) #ifndef (MJHMat273Slope) #declare MJHMat273Slope = material { texture {MJHTex273Slope} interior {lc_ior_block}} #end #end

// row 120 - Trans_Reddish_Lilac
#ifdef (lc_Trans_Reddish_Lilac) #ifndef (MJHTex284) #declare MJHTex284 = texture {lc_Trans_Reddish_Lilac} #end #end
#ifdef (lc_Trans_Reddish_Lilac) #ifndef (MJHTex284Slope) #declare MJHTex284Slope = texture {lc_Trans_Reddish_Lilac  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Reddish_Lilac) #ifndef (MJHMat284) #declare MJHMat284 = material {texture {MJHTex284} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Reddish_Lilac) #ifndef (MJHMat284Slope) #declare MJHMat284Slope = material { texture {MJHTex284Slope} interior {lc_ior_block}} #end #end

// row 121 - Trans_Light_Green
#ifdef (lc_Trans_Light_Green) #ifndef (MJHTex285) #declare MJHTex285 = texture {lc_Trans_Light_Green} #end #end
#ifdef (lc_Trans_Light_Green) #ifndef (MJHTex285Slope) #declare MJHTex285Slope = texture {lc_Trans_Light_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Light_Green) #ifndef (MJHMat285) #declare MJHMat285 = material {texture {MJHTex285} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Light_Green) #ifndef (MJHMat285Slope) #declare MJHMat285Slope = material { texture {MJHTex285Slope} interior {lc_ior_block}} #end #end

// row 122 - Dark_Green
#ifdef (lc_Dark_Green) #ifndef (MJHTex288) #declare MJHTex288 = texture {lc_Dark_Green} #end #end
#ifdef (lc_Dark_Green) #ifndef (MJHTex288Slope) #declare MJHTex288Slope = texture {lc_Dark_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Green) #ifndef (MJHMat288) #declare MJHMat288 = material {texture {MJHTex288} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Green) #ifndef (MJHMat288Slope) #declare MJHMat288Slope = material { texture {MJHTex288Slope} interior {lc_ior_block}} #end #end

// row 123 - Trans_Light_Blue_Violet
#ifdef (lc_Trans_Light_Blue_Violet) #ifndef (MJHTex293) #declare MJHTex293 = texture {lc_Trans_Light_Blue_Violet} #end #end
#ifdef (lc_Trans_Light_Blue_Violet) #ifndef (MJHTex293Slope) #declare MJHTex293Slope = texture {lc_Trans_Light_Blue_Violet  normal {lc_slope_normal}} #end #end
#ifdef (lc_Trans_Light_Blue_Violet) #ifndef (MJHMat293) #declare MJHMat293 = material {texture {MJHTex293} interior {lc_ior_block}} #end #end
#ifdef (lc_Trans_Light_Blue_Violet) #ifndef (MJHMat293Slope) #declare MJHMat293Slope = material { texture {MJHTex293Slope} interior {lc_ior_block}} #end #end

// row 124 - Glow_In_Dark_Trans
#ifdef (lc_Glow_In_Dark_Trans) #ifndef (MJHTex294) #declare MJHTex294 = texture {lc_Glow_In_Dark_Trans} #end #end
#ifdef (lc_Glow_In_Dark_Trans) #ifndef (MJHTex294Slope) #declare MJHTex294Slope = texture {lc_Glow_In_Dark_Trans  normal {lc_slope_normal}} #end #end
#ifdef (lc_Glow_In_Dark_Trans) #ifndef (MJHMat294) #declare MJHMat294 = material {texture {MJHTex294} interior {lc_ior_block}} #end #end
#ifdef (lc_Glow_In_Dark_Trans) #ifndef (MJHMat294Slope) #declare MJHMat294Slope = material { texture {MJHTex294Slope} interior {lc_ior_block}} #end #end

// row 125 - Flamingo_Pink
#ifdef (lc_Flamingo_Pink) #ifndef (MJHTex295) #declare MJHTex295 = texture {lc_Flamingo_Pink} #end #end
#ifdef (lc_Flamingo_Pink) #ifndef (MJHTex295Slope) #declare MJHTex295Slope = texture {lc_Flamingo_Pink  normal {lc_slope_normal}} #end #end
#ifdef (lc_Flamingo_Pink) #ifndef (MJHMat295) #declare MJHMat295 = material {texture {MJHTex295} interior {lc_ior_block}} #end #end
#ifdef (lc_Flamingo_Pink) #ifndef (MJHMat295Slope) #declare MJHMat295Slope = material { texture {MJHTex295Slope} interior {lc_ior_block}} #end #end

// row 126 - Pearl_Gold
#ifdef (lc_Pearl_Gold) #ifndef (MJHTex297) #declare MJHTex297 = texture {lc_Pearl_Gold} #end #end
#ifdef (lc_Pearl_Gold) #ifndef (MJHTex297Slope) #declare MJHTex297Slope = texture {lc_Pearl_Gold  normal {lc_slope_normal}} #end #end
#ifdef (lc_Pearl_Gold) #ifndef (MJHMat297) #declare MJHMat297 = material {texture {MJHTex297} interior {lc_ior_block}} #end #end
#ifdef (lc_Pearl_Gold) #ifndef (MJHMat297Slope) #declare MJHMat297Slope = material { texture {MJHTex297Slope} interior {lc_ior_block}} #end #end

// row 127 - Metallic_Copper
#ifdef (lc_Metallic_Copper) #ifndef (MJHTex300) #declare MJHTex300 = texture {lc_Metallic_Copper} #end #end
#ifdef (lc_Metallic_Copper) #ifndef (MJHTex300Slope) #declare MJHTex300Slope = texture {lc_Metallic_Copper  normal {lc_slope_normal}} #end #end
#ifdef (lc_Metallic_Copper) #ifndef (MJHMat300) #declare MJHMat300 = material {texture {MJHTex300} interior {lc_ior_block}} #end #end
#ifdef (lc_Metallic_Copper) #ifndef (MJHMat300Slope) #declare MJHMat300Slope = material { texture {MJHTex300Slope} interior {lc_ior_block}} #end #end

// row 128 - Glitter_Trans_Light_Blue
#ifdef (lc_Glitter_Trans_Light_Blue) #ifndef (MJHTex302) #declare MJHTex302 = texture {lc_Glitter_Trans_Light_Blue} #end #end
#ifdef (lc_Glitter_Trans_Light_Blue) #ifndef (MJHTex302Slope) #declare MJHTex302Slope = texture {lc_Glitter_Trans_Light_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Glitter_Trans_Light_Blue) #ifndef (MJHMat302) #declare MJHMat302 = material {texture {MJHTex302} interior {lc_ior_block}} #end #end
#ifdef (lc_Glitter_Trans_Light_Blue) #ifndef (MJHMat302Slope) #declare MJHMat302Slope = material { texture {MJHTex302Slope} interior {lc_ior_block}} #end #end

// row 129 - Dark_Brown
#ifdef (lc_Dark_Brown) #ifndef (MJHTex308) #declare MJHTex308 = texture {lc_Dark_Brown} #end #end
#ifdef (lc_Dark_Brown) #ifndef (MJHTex308Slope) #declare MJHTex308Slope = texture {lc_Dark_Brown  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Brown) #ifndef (MJHMat308) #declare MJHMat308 = material {texture {MJHTex308} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Brown) #ifndef (MJHMat308Slope) #declare MJHMat308Slope = material { texture {MJHTex308Slope} interior {lc_ior_block}} #end #end

// row 130 - Maersk_Blue
#ifdef (lc_Maersk_Blue) #ifndef (MJHTex313) #declare MJHTex313 = texture {lc_Maersk_Blue} #end #end
#ifdef (lc_Maersk_Blue) #ifndef (MJHTex313Slope) #declare MJHTex313Slope = texture {lc_Maersk_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Maersk_Blue) #ifndef (MJHMat313) #declare MJHMat313 = material {texture {MJHTex313} interior {lc_ior_block}} #end #end
#ifdef (lc_Maersk_Blue) #ifndef (MJHMat313Slope) #declare MJHMat313Slope = material { texture {MJHTex313Slope} interior {lc_ior_block}} #end #end

// row 131 - Dark_Red
#ifdef (lc_Dark_Red) #ifndef (MJHTex320) #declare MJHTex320 = texture {lc_Dark_Red} #end #end
#ifdef (lc_Dark_Red) #ifndef (MJHTex320Slope) #declare MJHTex320Slope = texture {lc_Dark_Red  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Red) #ifndef (MJHMat320) #declare MJHMat320 = material {texture {MJHTex320} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Red) #ifndef (MJHMat320Slope) #declare MJHMat320Slope = material { texture {MJHTex320Slope} interior {lc_ior_block}} #end #end

// row 132 - Dark_Azure
#ifdef (lc_Dark_Azure) #ifndef (MJHTex321) #declare MJHTex321 = texture {lc_Dark_Azure} #end #end
#ifdef (lc_Dark_Azure) #ifndef (MJHTex321Slope) #declare MJHTex321Slope = texture {lc_Dark_Azure  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Azure) #ifndef (MJHMat321) #declare MJHMat321 = material {texture {MJHTex321} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Azure) #ifndef (MJHMat321Slope) #declare MJHMat321Slope = material { texture {MJHTex321Slope} interior {lc_ior_block}} #end #end

// row 133 - Medium_Azure
#ifdef (lc_Medium_Azure) #ifndef (MJHTex322) #declare MJHTex322 = texture {lc_Medium_Azure} #end #end
#ifdef (lc_Medium_Azure) #ifndef (MJHTex322Slope) #declare MJHTex322Slope = texture {lc_Medium_Azure  normal {lc_slope_normal}} #end #end
#ifdef (lc_Medium_Azure) #ifndef (MJHMat322) #declare MJHMat322 = material {texture {MJHTex322} interior {lc_ior_block}} #end #end
#ifdef (lc_Medium_Azure) #ifndef (MJHMat322Slope) #declare MJHMat322Slope = material { texture {MJHTex322Slope} interior {lc_ior_block}} #end #end

// row 134 - Light_Aqua
#ifdef (lc_Light_Aqua) #ifndef (MJHTex323) #declare MJHTex323 = texture {lc_Light_Aqua} #end #end
#ifdef (lc_Light_Aqua) #ifndef (MJHTex323Slope) #declare MJHTex323Slope = texture {lc_Light_Aqua  normal {lc_slope_normal}} #end #end
#ifdef (lc_Light_Aqua) #ifndef (MJHMat323) #declare MJHMat323 = material {texture {MJHTex323} interior {lc_ior_block}} #end #end
#ifdef (lc_Light_Aqua) #ifndef (MJHMat323Slope) #declare MJHMat323Slope = material { texture {MJHTex323Slope} interior {lc_ior_block}} #end #end

// row 135 - Rubber_Red
#ifdef (lc_Rubber_Red) #ifndef (MJHTex324) #declare MJHTex324 = texture {lc_Rubber_Red} #end #end
#ifdef (lc_Rubber_Red) #ifndef (MJHTex324Slope) #declare MJHTex324Slope = texture {lc_Rubber_Red  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Red) #ifndef (MJHMat324) #declare MJHMat324 = material {texture {MJHTex324} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Red) #ifndef (MJHMat324Slope) #declare MJHMat324Slope = material { texture {MJHTex324Slope} interior {lc_ior_block}} #end #end

// row 136 - Yellowish_Green
#ifdef (lc_Yellowish_Green) #ifndef (MJHTex326) #declare MJHTex326 = texture {lc_Yellowish_Green} #end #end
#ifdef (lc_Yellowish_Green) #ifndef (MJHTex326Slope) #declare MJHTex326Slope = texture {lc_Yellowish_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Yellowish_Green) #ifndef (MJHMat326) #declare MJHMat326 = material {texture {MJHTex326} interior {lc_ior_block}} #end #end
#ifdef (lc_Yellowish_Green) #ifndef (MJHMat326Slope) #declare MJHMat326Slope = material { texture {MJHTex326Slope} interior {lc_ior_block}} #end #end

// row 137 - Glow_In_Dark_White
#ifdef (lc_Glow_In_Dark_White) #ifndef (MJHTex329) #declare MJHTex329 = texture {lc_Glow_In_Dark_White} #end #end
#ifdef (lc_Glow_In_Dark_White) #ifndef (MJHTex329Slope) #declare MJHTex329Slope = texture {lc_Glow_In_Dark_White  normal {lc_slope_normal}} #end #end
#ifdef (lc_Glow_In_Dark_White) #ifndef (MJHMat329) #declare MJHMat329 = material {texture {MJHTex329} interior {lc_ior_block}} #end #end
#ifdef (lc_Glow_In_Dark_White) #ifndef (MJHMat329Slope) #declare MJHMat329Slope = material { texture {MJHTex329Slope} interior {lc_ior_block}} #end #end

// row 138 - Olive_Green
#ifdef (lc_Olive_Green) #ifndef (MJHTex330) #declare MJHTex330 = texture {lc_Olive_Green} #end #end
#ifdef (lc_Olive_Green) #ifndef (MJHTex330Slope) #declare MJHTex330Slope = texture {lc_Olive_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Olive_Green) #ifndef (MJHMat330) #declare MJHMat330 = material {texture {MJHTex330} interior {lc_ior_block}} #end #end
#ifdef (lc_Olive_Green) #ifndef (MJHMat330Slope) #declare MJHMat330Slope = material { texture {MJHTex330Slope} interior {lc_ior_block}} #end #end

// row 139 - Chrome_Gold
#ifdef (lc_Chrome_Gold) #ifndef (MJHTex334) #declare MJHTex334 = texture {lc_Chrome_Gold} #end #end
#ifdef (lc_Chrome_Gold) #ifndef (MJHTex334Slope) #declare MJHTex334Slope = texture {lc_Chrome_Gold  normal {lc_slope_normal}} #end #end
#ifdef (lc_Chrome_Gold) #ifndef (MJHMat334) #declare MJHMat334 = material {texture {MJHTex334} interior {lc_ior_block}} #end #end
#ifdef (lc_Chrome_Gold) #ifndef (MJHMat334Slope) #declare MJHMat334Slope = material { texture {MJHTex334Slope} interior {lc_ior_block}} #end #end

// row 140 - Sand_Red
#ifdef (lc_Sand_Red) #ifndef (MJHTex335) #declare MJHTex335 = texture {lc_Sand_Red} #end #end
#ifdef (lc_Sand_Red) #ifndef (MJHTex335Slope) #declare MJHTex335Slope = texture {lc_Sand_Red  normal {lc_slope_normal}} #end #end
#ifdef (lc_Sand_Red) #ifndef (MJHMat335) #declare MJHMat335 = material {texture {MJHTex335} interior {lc_ior_block}} #end #end
#ifdef (lc_Sand_Red) #ifndef (MJHMat335Slope) #declare MJHMat335Slope = material { texture {MJHTex335Slope} interior {lc_ior_block}} #end #end

// row 141 - Glitter_Trans_Neon_Green
#ifdef (lc_Glitter_Trans_Neon_Green) #ifndef (MJHTex339) #declare MJHTex339 = texture {lc_Glitter_Trans_Neon_Green} #end #end
#ifdef (lc_Glitter_Trans_Neon_Green) #ifndef (MJHTex339Slope) #declare MJHTex339Slope = texture {lc_Glitter_Trans_Neon_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Glitter_Trans_Neon_Green) #ifndef (MJHMat339) #declare MJHMat339 = material {texture {MJHTex339} interior {lc_ior_block}} #end #end
#ifdef (lc_Glitter_Trans_Neon_Green) #ifndef (MJHMat339Slope) #declare MJHMat339Slope = material { texture {MJHTex339Slope} interior {lc_ior_block}} #end #end

// row 142 - Rubber_Orange
#ifdef (lc_Rubber_Orange) #ifndef (MJHTex350) #declare MJHTex350 = texture {lc_Rubber_Orange} #end #end
#ifdef (lc_Rubber_Orange) #ifndef (MJHTex350Slope) #declare MJHTex350Slope = texture {lc_Rubber_Orange  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Orange) #ifndef (MJHMat350) #declare MJHMat350 = material {texture {MJHTex350} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Orange) #ifndef (MJHMat350Slope) #declare MJHMat350Slope = material { texture {MJHTex350Slope} interior {lc_ior_block}} #end #end

// row 143 - Medium_Dark_Pink
#ifdef (lc_Medium_Dark_Pink) #ifndef (MJHTex351) #declare MJHTex351 = texture {lc_Medium_Dark_Pink} #end #end
#ifdef (lc_Medium_Dark_Pink) #ifndef (MJHTex351Slope) #declare MJHTex351Slope = texture {lc_Medium_Dark_Pink  normal {lc_slope_normal}} #end #end
#ifdef (lc_Medium_Dark_Pink) #ifndef (MJHMat351) #declare MJHMat351 = material {texture {MJHTex351} interior {lc_ior_block}} #end #end
#ifdef (lc_Medium_Dark_Pink) #ifndef (MJHMat351Slope) #declare MJHMat351Slope = material { texture {MJHTex351Slope} interior {lc_ior_block}} #end #end

// row 145 - Earth_Orange
#ifdef (lc_Earth_Orange) #ifndef (MJHTex366) #declare MJHTex366 = texture {lc_Earth_Orange} #end #end
#ifdef (lc_Earth_Orange) #ifndef (MJHTex366Slope) #declare MJHTex366Slope = texture {lc_Earth_Orange  normal {lc_slope_normal}} #end #end
#ifdef (lc_Earth_Orange) #ifndef (MJHMat366) #declare MJHMat366 = material {texture {MJHTex366} interior {lc_ior_block}} #end #end
#ifdef (lc_Earth_Orange) #ifndef (MJHMat366Slope) #declare MJHMat366Slope = material { texture {MJHTex366Slope} interior {lc_ior_block}} #end #end

// row 146 - Sand_Purple
#ifdef (lc_Sand_Purple) #ifndef (MJHTex373) #declare MJHTex373 = texture {lc_Sand_Purple} #end #end
#ifdef (lc_Sand_Purple) #ifndef (MJHTex373Slope) #declare MJHTex373Slope = texture {lc_Sand_Purple  normal {lc_slope_normal}} #end #end
#ifdef (lc_Sand_Purple) #ifndef (MJHMat373) #declare MJHMat373 = material {texture {MJHTex373} interior {lc_ior_block}} #end #end
#ifdef (lc_Sand_Purple) #ifndef (MJHMat373Slope) #declare MJHMat373Slope = material { texture {MJHTex373Slope} interior {lc_ior_block}} #end #end

// row 147 - Rubber_Light_Grey
#ifdef (lc_Rubber_Light_Grey) #ifndef (MJHTex375) #declare MJHTex375 = texture {lc_Rubber_Light_Grey} #end #end
#ifdef (lc_Rubber_Light_Grey) #ifndef (MJHTex375Slope) #declare MJHTex375Slope = texture {lc_Rubber_Light_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Light_Grey) #ifndef (MJHMat375) #declare MJHMat375 = material {texture {MJHTex375} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Light_Grey) #ifndef (MJHMat375Slope) #declare MJHMat375Slope = material { texture {MJHTex375Slope} interior {lc_ior_block}} #end #end

// row 148 - Sand_Green
#ifdef (lc_Sand_Green) #ifndef (MJHTex378) #declare MJHTex378 = texture {lc_Sand_Green} #end #end
#ifdef (lc_Sand_Green) #ifndef (MJHTex378Slope) #declare MJHTex378Slope = texture {lc_Sand_Green  normal {lc_slope_normal}} #end #end
#ifdef (lc_Sand_Green) #ifndef (MJHMat378) #declare MJHMat378 = material {texture {MJHTex378} interior {lc_ior_block}} #end #end
#ifdef (lc_Sand_Green) #ifndef (MJHMat378Slope) #declare MJHMat378Slope = material { texture {MJHTex378Slope} interior {lc_ior_block}} #end #end

// row 149 - Sand_Blue
#ifdef (lc_Sand_Blue) #ifndef (MJHTex379) #declare MJHTex379 = texture {lc_Sand_Blue} #end #end
#ifdef (lc_Sand_Blue) #ifndef (MJHTex379Slope) #declare MJHTex379Slope = texture {lc_Sand_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Sand_Blue) #ifndef (MJHMat379) #declare MJHMat379 = material {texture {MJHTex379} interior {lc_ior_block}} #end #end
#ifdef (lc_Sand_Blue) #ifndef (MJHMat379Slope) #declare MJHMat379Slope = material { texture {MJHTex379Slope} interior {lc_ior_block}} #end #end

// row 150 - Chrome_Silver
#ifdef (lc_Chrome_Silver) #ifndef (MJHTex383) #declare MJHTex383 = texture {lc_Chrome_Silver} #end #end
#ifdef (lc_Chrome_Silver) #ifndef (MJHTex383Slope) #declare MJHTex383Slope = texture {lc_Chrome_Silver  normal {lc_slope_normal}} #end #end
#ifdef (lc_Chrome_Silver) #ifndef (MJHMat383) #declare MJHMat383 = material {texture {MJHTex383} interior {lc_ior_block}} #end #end
#ifdef (lc_Chrome_Silver) #ifndef (MJHMat383Slope) #declare MJHMat383Slope = material { texture {MJHTex383Slope} interior {lc_ior_block}} #end #end

// row 151 - Rubber_Dark_Blue
#ifdef (lc_Rubber_Dark_Blue) #ifndef (MJHTex406) #declare MJHTex406 = texture {lc_Rubber_Dark_Blue} #end #end
#ifdef (lc_Rubber_Dark_Blue) #ifndef (MJHTex406Slope) #declare MJHTex406Slope = texture {lc_Rubber_Dark_Blue  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Dark_Blue) #ifndef (MJHMat406) #declare MJHMat406 = material {texture {MJHTex406} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Dark_Blue) #ifndef (MJHMat406Slope) #declare MJHMat406Slope = material { texture {MJHTex406Slope} interior {lc_ior_block}} #end #end

// row 152 - Rubber_Purple
#ifdef (lc_Rubber_Purple) #ifndef (MJHTex449) #declare MJHTex449 = texture {lc_Rubber_Purple} #end #end
#ifdef (lc_Rubber_Purple) #ifndef (MJHTex449Slope) #declare MJHTex449Slope = texture {lc_Rubber_Purple  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Purple) #ifndef (MJHMat449) #declare MJHMat449 = material {texture {MJHTex449} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Purple) #ifndef (MJHMat449Slope) #declare MJHMat449Slope = material { texture {MJHTex449Slope} interior {lc_ior_block}} #end #end

// row 153 - Fabuland_Brown
#ifdef (lc_Fabuland_Brown) #ifndef (MJHTex450) #declare MJHTex450 = texture {lc_Fabuland_Brown} #end #end
#ifdef (lc_Fabuland_Brown) #ifndef (MJHTex450Slope) #declare MJHTex450Slope = texture {lc_Fabuland_Brown  normal {lc_slope_normal}} #end #end
#ifdef (lc_Fabuland_Brown) #ifndef (MJHMat450) #declare MJHMat450 = material {texture {MJHTex450} interior {lc_ior_block}} #end #end
#ifdef (lc_Fabuland_Brown) #ifndef (MJHMat450Slope) #declare MJHMat450Slope = material { texture {MJHTex450Slope} interior {lc_ior_block}} #end #end

// row 154 - Medium_Orange
#ifdef (lc_Medium_Orange) #ifndef (MJHTex462) #declare MJHTex462 = texture {lc_Medium_Orange} #end #end
#ifdef (lc_Medium_Orange) #ifndef (MJHTex462Slope) #declare MJHTex462Slope = texture {lc_Medium_Orange  normal {lc_slope_normal}} #end #end
#ifdef (lc_Medium_Orange) #ifndef (MJHMat462) #declare MJHMat462 = material {texture {MJHTex462} interior {lc_ior_block}} #end #end
#ifdef (lc_Medium_Orange) #ifndef (MJHMat462Slope) #declare MJHMat462Slope = material { texture {MJHTex462Slope} interior {lc_ior_block}} #end #end

// row 155 - Dark_Orange
#ifdef (lc_Dark_Orange) #ifndef (MJHTex484) #declare MJHTex484 = texture {lc_Dark_Orange} #end #end
#ifdef (lc_Dark_Orange) #ifndef (MJHTex484Slope) #declare MJHTex484Slope = texture {lc_Dark_Orange  normal {lc_slope_normal}} #end #end
#ifdef (lc_Dark_Orange) #ifndef (MJHMat484) #declare MJHMat484 = material {texture {MJHTex484} interior {lc_ior_block}} #end #end
#ifdef (lc_Dark_Orange) #ifndef (MJHMat484Slope) #declare MJHMat484Slope = material { texture {MJHTex484Slope} interior {lc_ior_block}} #end #end

// row 156 - Rubber_Lime
#ifdef (lc_Rubber_Lime) #ifndef (MJHTex490) #declare MJHTex490 = texture {lc_Rubber_Lime} #end #end
#ifdef (lc_Rubber_Lime) #ifndef (MJHTex490Slope) #declare MJHTex490Slope = texture {lc_Rubber_Lime  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Lime) #ifndef (MJHMat490) #declare MJHMat490 = material {texture {MJHTex490} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Lime) #ifndef (MJHMat490Slope) #declare MJHMat490Slope = material { texture {MJHTex490Slope} interior {lc_ior_block}} #end #end

// row 157 - Magnet
#ifdef (lc_Magnet) #ifndef (MJHTex493) #declare MJHTex493 = texture {lc_Magnet} #end #end
#ifdef (lc_Magnet) #ifndef (MJHTex493Slope) #declare MJHTex493Slope = texture {lc_Magnet  normal {lc_slope_normal}} #end #end
#ifdef (lc_Magnet) #ifndef (MJHMat493) #declare MJHMat493 = material {texture {MJHTex493} interior {lc_ior_block}} #end #end
#ifdef (lc_Magnet) #ifndef (MJHMat493Slope) #declare MJHMat493Slope = material { texture {MJHTex493Slope} interior {lc_ior_block}} #end #end

// row 158 - Electric_Contact_Alloy
#ifdef (lc_Electric_Contact_Alloy) #ifndef (MJHTex494) #declare MJHTex494 = texture {lc_Electric_Contact_Alloy} #end #end
#ifdef (lc_Electric_Contact_Alloy) #ifndef (MJHTex494Slope) #declare MJHTex494Slope = texture {lc_Electric_Contact_Alloy  normal {lc_slope_normal}} #end #end
#ifdef (lc_Electric_Contact_Alloy) #ifndef (MJHMat494) #declare MJHMat494 = material {texture {MJHTex494} interior {lc_ior_block}} #end #end
#ifdef (lc_Electric_Contact_Alloy) #ifndef (MJHMat494Slope) #declare MJHMat494Slope = material { texture {MJHTex494Slope} interior {lc_ior_block}} #end #end

// row 159 - Electric_Contact_Copper
#ifdef (lc_Electric_Contact_Copper) #ifndef (MJHTex495) #declare MJHTex495 = texture {lc_Electric_Contact_Copper} #end #end
#ifdef (lc_Electric_Contact_Copper) #ifndef (MJHTex495Slope) #declare MJHTex495Slope = texture {lc_Electric_Contact_Copper  normal {lc_slope_normal}} #end #end
#ifdef (lc_Electric_Contact_Copper) #ifndef (MJHMat495) #declare MJHMat495 = material {texture {MJHTex495} interior {lc_ior_block}} #end #end
#ifdef (lc_Electric_Contact_Copper) #ifndef (MJHMat495Slope) #declare MJHMat495Slope = material { texture {MJHTex495Slope} interior {lc_ior_block}} #end #end

// row 160 - Rubber_Light_Bluish_Grey
#ifdef (lc_Rubber_Light_Bluish_Grey) #ifndef (MJHTex496) #declare MJHTex496 = texture {lc_Rubber_Light_Bluish_Grey} #end #end
#ifdef (lc_Rubber_Light_Bluish_Grey) #ifndef (MJHTex496Slope) #declare MJHTex496Slope = texture {lc_Rubber_Light_Bluish_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Light_Bluish_Grey) #ifndef (MJHMat496) #declare MJHMat496 = material {texture {MJHTex496} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Light_Bluish_Grey) #ifndef (MJHMat496Slope) #declare MJHMat496Slope = material { texture {MJHTex496Slope} interior {lc_ior_block}} #end #end

// row 161 - Very_Light_Grey
#ifdef (lc_Very_Light_Grey) #ifndef (MJHTex503) #declare MJHTex503 = texture {lc_Very_Light_Grey} #end #end
#ifdef (lc_Very_Light_Grey) #ifndef (MJHTex503Slope) #declare MJHTex503Slope = texture {lc_Very_Light_Grey  normal {lc_slope_normal}} #end #end
#ifdef (lc_Very_Light_Grey) #ifndef (MJHMat503) #declare MJHMat503 = material {texture {MJHTex503} interior {lc_ior_block}} #end #end
#ifdef (lc_Very_Light_Grey) #ifndef (MJHMat503Slope) #declare MJHMat503Slope = material { texture {MJHTex503Slope} interior {lc_ior_block}} #end #end

// row 162 - Rubber_Flat_Silver
#ifdef (lc_Rubber_Flat_Silver) #ifndef (MJHTex504) #declare MJHTex504 = texture {lc_Rubber_Flat_Silver} #end #end
#ifdef (lc_Rubber_Flat_Silver) #ifndef (MJHTex504Slope) #declare MJHTex504Slope = texture {lc_Rubber_Flat_Silver  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_Flat_Silver) #ifndef (MJHMat504) #declare MJHMat504 = material {texture {MJHTex504} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_Flat_Silver) #ifndef (MJHMat504Slope) #declare MJHMat504Slope = material { texture {MJHTex504Slope} interior {lc_ior_block}} #end #end

// row 166 - Rubber_White
#ifdef (lc_Rubber_White) #ifndef (MJHTex511) #declare MJHTex511 = texture {lc_Rubber_White} #end #end
#ifdef (lc_Rubber_White) #ifndef (MJHTex511Slope) #declare MJHTex511Slope = texture {lc_Rubber_White  normal {lc_slope_normal}} #end #end
#ifdef (lc_Rubber_White) #ifndef (MJHMat511) #declare MJHMat511 = material {texture {MJHTex511} interior {lc_ior_block}} #end #end
#ifdef (lc_Rubber_White) #ifndef (MJHMat511Slope) #declare MJHMat511Slope = material { texture {MJHTex511Slope} interior {lc_ior_block}} #end #end
