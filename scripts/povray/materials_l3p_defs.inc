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
// Does not support SSLT or blurred reflections. Use LDC materials instead.


#version 3.7


//// Finishes
#ifndef (L3FinishOpaque)
#declare L3FinishOpaque = finish {
	ambient L3Ambient
	diffuse L3Diffuse
	#if (L3Quality >= 2)
		phong L3Phong
		phong_size L3PhongSize
		reflection L3Reflection
	#end
}
#end

#ifndef (L3FinishChrome)
#declare L3FinishChrome = finish {
	ambient 0.25
	diffuse 0.6
	#if (L3Quality >= 2)
		brilliance 5
		metallic
		specular 0.80
		roughness 1/100
		reflection 0.65
	#end
}
#end

#ifndef (L3FinishPearlescent)
//Not supported yet, using Opaque
#declare L3FinishPearlescent = finish { L3FinishOpaque }
#end

#ifndef (L3FinishRubber)
#declare L3FinishRubber = finish {
	ambient L3Ambient
	diffuse L3Diffuse
	#if (L3Quality >= 2)
		phong 0.1
		phong_size 10
		reflection 0
	#end
}
#end

#ifndef (L3FinishMatte_metallic)
//Not supported yet, using Opaque
#declare L3FinishMatte_metallic = finish { L3FinishOpaque }
#end

#ifndef (L3FinishMetal)
//Not supported yet, using Opaque
#declare L3FinishMetal = finish { L3FinishOpaque }
#end

#ifndef (L3FinishTransparent)
#declare L3FinishTransparent = finish {
	ambient L3Ambient
	diffuse L3Diffuse
	#if (L3Quality >= 2)
		phong L3Phong
		phong_size L3PhongSize
		reflection 0.2
	#end
}
#end



//// Macros
#ifndef (L3TextureOpaqueRGB)
#macro L3TextureOpaqueRGB(r,g,b)
texture {
	pigment { color rgb <r/255,g/255,b/255> }
	finish { L3FinishOpaque }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TextureChromeRGB)
#macro L3TextureChromeRGB(r,g,b)
texture {
	pigment { color rgb <r/255,g/255,b/255> }
	finish { L3FinishChrome }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TexturePearlescentRGB)
#macro L3TexturePearlescentRGB(r,g,b)
texture {
	pigment { color rgb <r/255,g/255,b/255> }
	finish { L3FinishPearlescent }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TextureRubberRGB)
#macro L3TextureRubberRGB(r,g,b)
texture {
	pigment { color rgb <r/255,g/255,b/255> }
	finish { L3FinishRubber }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TextureMatte_metallicRGB)
#macro L3TextureMatte_metallicRGB(r,g,b)
texture {
	pigment { color rgb <r/255,g/255,b/255> }
	finish { L3FinishMatte_metallic }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TextureMetalRGB)
#macro L3TextureMetalRGB(r,g,b)
texture {
	pigment { color rgb <r/255,g/255,b/255> }
	finish { L3FinishMetal }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TextureTransparentRGBA)
#macro L3TextureTransparentRGBA(r,g,b,a)
// Alpha -> Filter: 255 -> 1.00, 128 -> 0.85, 0 -> 0
#local f = (a >= 128 ? 0.85 + (a-128) * 0.15 / (255-128) : a * 0.85 / 255);
texture {
	pigment { color rgb <r/255,g/255,b/255> #if (L3Quality > 1) filter f #end }
	finish { L3FinishTransparent }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TextureSlope)
#macro L3TextureSlope(tex)
texture {
	tex
	#if (L3Quality > 1) normal { L3NormalSlope } #end
}
#end
#end

#ifndef (L3Material)
#macro L3Material(tex)
material {
	texture { tex }
}
#end
#end

#ifndef (L3MaterialT)
#macro L3MaterialT(tex)
material {
	texture { tex }
	#if (L3Quality > 1)
		interior { ior L3Ior }
	#end
}
#end
#end


//// Color 0 Black (from ldconfig.ldr)
#ifndef (L3Texture0)
#declare L3Texture0 = L3TextureOpaqueRGB(5,19,29)
#end
#ifndef (L3Texture0_slope)
#declare L3Texture0_slope = L3TextureSlope(L3Texture0)
#end
#ifndef (L3Color0)
#declare L3Color0 = L3Material(L3Texture0)
#end
#ifndef (L3Color0_slope)
#declare L3Color0_slope = L3Material(L3Texture0_slope)
#end


//// Color 1 Blue (from ldconfig.ldr)
#ifndef (L3Texture1)
#declare L3Texture1 = L3TextureOpaqueRGB(0,85,191)
#end
#ifndef (L3Texture1_slope)
#declare L3Texture1_slope = L3TextureSlope(L3Texture1)
#end
#ifndef (L3Color1)
#declare L3Color1 = L3Material(L3Texture1)
#end
#ifndef (L3Color1_slope)
#declare L3Color1_slope = L3Material(L3Texture1_slope)
#end


//// Color 2 Green (from ldconfig.ldr)
#ifndef (L3Texture2)
#declare L3Texture2 = L3TextureOpaqueRGB(37,122,62)
#end
#ifndef (L3Texture2_slope)
#declare L3Texture2_slope = L3TextureSlope(L3Texture2)
#end
#ifndef (L3Color2)
#declare L3Color2 = L3Material(L3Texture2)
#end
#ifndef (L3Color2_slope)
#declare L3Color2_slope = L3Material(L3Texture2_slope)
#end


//// Color 3 Dark_Turquoise (from ldconfig.ldr)
#ifndef (L3Texture3)
#declare L3Texture3 = L3TextureOpaqueRGB(0,131,143)
#end
#ifndef (L3Texture3_slope)
#declare L3Texture3_slope = L3TextureSlope(L3Texture3)
#end
#ifndef (L3Color3)
#declare L3Color3 = L3Material(L3Texture3)
#end
#ifndef (L3Color3_slope)
#declare L3Color3_slope = L3Material(L3Texture3_slope)
#end


//// Color 4 Red (from ldconfig.ldr)
#ifndef (L3Texture4)
#declare L3Texture4 = L3TextureOpaqueRGB(201,26,9)
#end
#ifndef (L3Texture4_slope)
#declare L3Texture4_slope = L3TextureSlope(L3Texture4)
#end
#ifndef (L3Color4)
#declare L3Color4 = L3Material(L3Texture4)
#end
#ifndef (L3Color4_slope)
#declare L3Color4_slope = L3Material(L3Texture4_slope)
#end


//// Color 5 Dark_Pink (from ldconfig.ldr)
#ifndef (L3Texture5)
#declare L3Texture5 = L3TextureOpaqueRGB(200,112,160)
#end
#ifndef (L3Texture5_slope)
#declare L3Texture5_slope = L3TextureSlope(L3Texture5)
#end
#ifndef (L3Color5)
#declare L3Color5 = L3Material(L3Texture5)
#end
#ifndef (L3Color5_slope)
#declare L3Color5_slope = L3Material(L3Texture5_slope)
#end


//// Color 6 Brown (from ldconfig.ldr)
#ifndef (L3Texture6)
#declare L3Texture6 = L3TextureOpaqueRGB(88,57,39)
#end
#ifndef (L3Texture6_slope)
#declare L3Texture6_slope = L3TextureSlope(L3Texture6)
#end
#ifndef (L3Color6)
#declare L3Color6 = L3Material(L3Texture6)
#end
#ifndef (L3Color6_slope)
#declare L3Color6_slope = L3Material(L3Texture6_slope)
#end


//// Color 7 Light_Grey (from ldconfig.ldr)
#ifndef (L3Texture7)
#declare L3Texture7 = L3TextureOpaqueRGB(155,161,157)
#end
#ifndef (L3Texture7_slope)
#declare L3Texture7_slope = L3TextureSlope(L3Texture7)
#end
#ifndef (L3Color7)
#declare L3Color7 = L3Material(L3Texture7)
#end
#ifndef (L3Color7_slope)
#declare L3Color7_slope = L3Material(L3Texture7_slope)
#end


//// Color 8 Dark_Grey (from ldconfig.ldr)
#ifndef (L3Texture8)
#declare L3Texture8 = L3TextureOpaqueRGB(109,110,92)
#end
#ifndef (L3Texture8_slope)
#declare L3Texture8_slope = L3TextureSlope(L3Texture8)
#end
#ifndef (L3Color8)
#declare L3Color8 = L3Material(L3Texture8)
#end
#ifndef (L3Color8_slope)
#declare L3Color8_slope = L3Material(L3Texture8_slope)
#end


//// Color 9 Light_Blue (from ldconfig.ldr)
#ifndef (L3Texture9)
#declare L3Texture9 = L3TextureOpaqueRGB(180,210,227)
#end
#ifndef (L3Texture9_slope)
#declare L3Texture9_slope = L3TextureSlope(L3Texture9)
#end
#ifndef (L3Color9)
#declare L3Color9 = L3Material(L3Texture9)
#end
#ifndef (L3Color9_slope)
#declare L3Color9_slope = L3Material(L3Texture9_slope)
#end


//// Color 10 Bright_Green (from ldconfig.ldr)
#ifndef (L3Texture10)
#declare L3Texture10 = L3TextureOpaqueRGB(75,159,74)
#end
#ifndef (L3Texture10_slope)
#declare L3Texture10_slope = L3TextureSlope(L3Texture10)
#end
#ifndef (L3Color10)
#declare L3Color10 = L3Material(L3Texture10)
#end
#ifndef (L3Color10_slope)
#declare L3Color10_slope = L3Material(L3Texture10_slope)
#end


//// Color 11 Light_Turquoise (from ldconfig.ldr)
#ifndef (L3Texture11)
#declare L3Texture11 = L3TextureOpaqueRGB(85,165,175)
#end
#ifndef (L3Texture11_slope)
#declare L3Texture11_slope = L3TextureSlope(L3Texture11)
#end
#ifndef (L3Color11)
#declare L3Color11 = L3Material(L3Texture11)
#end
#ifndef (L3Color11_slope)
#declare L3Color11_slope = L3Material(L3Texture11_slope)
#end


//// Color 12 Salmon (from ldconfig.ldr)
#ifndef (L3Texture12)
#declare L3Texture12 = L3TextureOpaqueRGB(242,112,94)
#end
#ifndef (L3Texture12_slope)
#declare L3Texture12_slope = L3TextureSlope(L3Texture12)
#end
#ifndef (L3Color12)
#declare L3Color12 = L3Material(L3Texture12)
#end
#ifndef (L3Color12_slope)
#declare L3Color12_slope = L3Material(L3Texture12_slope)
#end


//// Color 13 Pink (from ldconfig.ldr)
#ifndef (L3Texture13)
#declare L3Texture13 = L3TextureOpaqueRGB(252,151,172)
#end
#ifndef (L3Texture13_slope)
#declare L3Texture13_slope = L3TextureSlope(L3Texture13)
#end
#ifndef (L3Color13)
#declare L3Color13 = L3Material(L3Texture13)
#end
#ifndef (L3Color13_slope)
#declare L3Color13_slope = L3Material(L3Texture13_slope)
#end


//// Color 14 Yellow (from ldconfig.ldr)
#ifndef (L3Texture14)
#declare L3Texture14 = L3TextureOpaqueRGB(242,205,55)
#end
#ifndef (L3Texture14_slope)
#declare L3Texture14_slope = L3TextureSlope(L3Texture14)
#end
#ifndef (L3Color14)
#declare L3Color14 = L3Material(L3Texture14)
#end
#ifndef (L3Color14_slope)
#declare L3Color14_slope = L3Material(L3Texture14_slope)
#end


//// Color 15 White (from ldconfig.ldr)
#ifndef (L3Texture15)
#declare L3Texture15 = L3TextureOpaqueRGB(255,255,255)
#end
#ifndef (L3Texture15_slope)
#declare L3Texture15_slope = L3TextureSlope(L3Texture15)
#end
#ifndef (L3Color15)
#declare L3Color15 = L3Material(L3Texture15)
#end
#ifndef (L3Color15_slope)
#declare L3Color15_slope = L3Material(L3Texture15_slope)
#end


//// Color 17 Light_Green (from ldconfig.ldr)
#ifndef (L3Texture17)
#declare L3Texture17 = L3TextureOpaqueRGB(194,218,184)
#end
#ifndef (L3Texture17_slope)
#declare L3Texture17_slope = L3TextureSlope(L3Texture17)
#end
#ifndef (L3Color17)
#declare L3Color17 = L3Material(L3Texture17)
#end
#ifndef (L3Color17_slope)
#declare L3Color17_slope = L3Material(L3Texture17_slope)
#end


//// Color 18 Light_Yellow (from ldconfig.ldr)
#ifndef (L3Texture18)
#declare L3Texture18 = L3TextureOpaqueRGB(251,230,150)
#end
#ifndef (L3Texture18_slope)
#declare L3Texture18_slope = L3TextureSlope(L3Texture18)
#end
#ifndef (L3Color18)
#declare L3Color18 = L3Material(L3Texture18)
#end
#ifndef (L3Color18_slope)
#declare L3Color18_slope = L3Material(L3Texture18_slope)
#end


//// Color 19 Tan (from ldconfig.ldr)
#ifndef (L3Texture19)
#declare L3Texture19 = L3TextureOpaqueRGB(228,205,158)
#end
#ifndef (L3Texture19_slope)
#declare L3Texture19_slope = L3TextureSlope(L3Texture19)
#end
#ifndef (L3Color19)
#declare L3Color19 = L3Material(L3Texture19)
#end
#ifndef (L3Color19_slope)
#declare L3Color19_slope = L3Material(L3Texture19_slope)
#end


//// Color 20 Light_Violet (from ldconfig.ldr)
#ifndef (L3Texture20)
#declare L3Texture20 = L3TextureOpaqueRGB(201,202,226)
#end
#ifndef (L3Texture20_slope)
#declare L3Texture20_slope = L3TextureSlope(L3Texture20)
#end
#ifndef (L3Color20)
#declare L3Color20 = L3Material(L3Texture20)
#end
#ifndef (L3Color20_slope)
#declare L3Color20_slope = L3Material(L3Texture20_slope)
#end


//// Color 21 Glow_In_Dark_Opaque (from ldconfig.ldr)
#ifndef (L3Texture21)
#declare L3Texture21 = L3TextureOtherRGBFAL(224,255,176,0,240,15)
#end
#ifndef (L3Texture21_slope)
#declare L3Texture21_slope = L3TextureSlope(L3Texture21)
#end
#ifndef (L3Color21)
#declare L3Color21 = L3MaterialT(L3Texture21)
#end
#ifndef (L3Color21_slope)
#declare L3Color21_slope = L3MaterialT(L3Texture21_slope)
#end


//// Color 22 Purple (from ldconfig.ldr)
#ifndef (L3Texture22)
#declare L3Texture22 = L3TextureOpaqueRGB(129,0,123)
#end
#ifndef (L3Texture22_slope)
#declare L3Texture22_slope = L3TextureSlope(L3Texture22)
#end
#ifndef (L3Color22)
#declare L3Color22 = L3Material(L3Texture22)
#end
#ifndef (L3Color22_slope)
#declare L3Color22_slope = L3Material(L3Texture22_slope)
#end


//// Color 23 Dark_Blue_Violet (from ldconfig.ldr)
#ifndef (L3Texture23)
#declare L3Texture23 = L3TextureOpaqueRGB(32,50,176)
#end
#ifndef (L3Texture23_slope)
#declare L3Texture23_slope = L3TextureSlope(L3Texture23)
#end
#ifndef (L3Color23)
#declare L3Color23 = L3Material(L3Texture23)
#end
#ifndef (L3Color23_slope)
#declare L3Color23_slope = L3Material(L3Texture23_slope)
#end


//// Color 25 Orange (from ldconfig.ldr)
#ifndef (L3Texture25)
#declare L3Texture25 = L3TextureOpaqueRGB(254,138,24)
#end
#ifndef (L3Texture25_slope)
#declare L3Texture25_slope = L3TextureSlope(L3Texture25)
#end
#ifndef (L3Color25)
#declare L3Color25 = L3Material(L3Texture25)
#end
#ifndef (L3Color25_slope)
#declare L3Color25_slope = L3Material(L3Texture25_slope)
#end


//// Color 26 Magenta (from ldconfig.ldr)
#ifndef (L3Texture26)
#declare L3Texture26 = L3TextureOpaqueRGB(146,57,120)
#end
#ifndef (L3Texture26_slope)
#declare L3Texture26_slope = L3TextureSlope(L3Texture26)
#end
#ifndef (L3Color26)
#declare L3Color26 = L3Material(L3Texture26)
#end
#ifndef (L3Color26_slope)
#declare L3Color26_slope = L3Material(L3Texture26_slope)
#end


//// Color 27 Lime (from ldconfig.ldr)
#ifndef (L3Texture27)
#declare L3Texture27 = L3TextureOpaqueRGB(187,233,11)
#end
#ifndef (L3Texture27_slope)
#declare L3Texture27_slope = L3TextureSlope(L3Texture27)
#end
#ifndef (L3Color27)
#declare L3Color27 = L3Material(L3Texture27)
#end
#ifndef (L3Color27_slope)
#declare L3Color27_slope = L3Material(L3Texture27_slope)
#end


//// Color 28 Dark_Tan (from ldconfig.ldr)
#ifndef (L3Texture28)
#declare L3Texture28 = L3TextureOpaqueRGB(149,138,115)
#end
#ifndef (L3Texture28_slope)
#declare L3Texture28_slope = L3TextureSlope(L3Texture28)
#end
#ifndef (L3Color28)
#declare L3Color28 = L3Material(L3Texture28)
#end
#ifndef (L3Color28_slope)
#declare L3Color28_slope = L3Material(L3Texture28_slope)
#end


//// Color 29 Bright_Pink (from ldconfig.ldr)
#ifndef (L3Texture29)
#declare L3Texture29 = L3TextureOpaqueRGB(228,173,200)
#end
#ifndef (L3Texture29_slope)
#declare L3Texture29_slope = L3TextureSlope(L3Texture29)
#end
#ifndef (L3Color29)
#declare L3Color29 = L3Material(L3Texture29)
#end
#ifndef (L3Color29_slope)
#declare L3Color29_slope = L3Material(L3Texture29_slope)
#end


//// Color 30 Medium_Lavender (from ldconfig.ldr)
#ifndef (L3Texture30)
#declare L3Texture30 = L3TextureOpaqueRGB(172,120,186)
#end
#ifndef (L3Texture30_slope)
#declare L3Texture30_slope = L3TextureSlope(L3Texture30)
#end
#ifndef (L3Color30)
#declare L3Color30 = L3Material(L3Texture30)
#end
#ifndef (L3Color30_slope)
#declare L3Color30_slope = L3Material(L3Texture30_slope)
#end


//// Color 31 Lavender (from ldconfig.ldr)
#ifndef (L3Texture31)
#declare L3Texture31 = L3TextureOpaqueRGB(225,213,237)
#end
#ifndef (L3Texture31_slope)
#declare L3Texture31_slope = L3TextureSlope(L3Texture31)
#end
#ifndef (L3Color31)
#declare L3Color31 = L3Material(L3Texture31)
#end
#ifndef (L3Color31_slope)
#declare L3Color31_slope = L3Material(L3Texture31_slope)
#end


//// Color 32 Trans_Black_IR_Lens (from ldconfig.ldr)
#ifndef (L3Texture32)
#declare L3Texture32 = L3TextureTransparentRGBA(0,0,0,210)
#end
#ifndef (L3Texture32_slope)
#declare L3Texture32_slope = L3TextureSlope(L3Texture32)
#end
#ifndef (L3Color32)
#declare L3Color32 = L3MaterialT(L3Texture32)
#end
#ifndef (L3Color32_slope)
#declare L3Color32_slope = L3MaterialT(L3Texture32_slope)
#end


//// Color 33 Trans_Dark_Blue (from ldconfig.ldr)
#ifndef (L3Texture33)
#declare L3Texture33 = L3TextureTransparentRGBA(0,32,160,128)
#end
#ifndef (L3Texture33_slope)
#declare L3Texture33_slope = L3TextureSlope(L3Texture33)
#end
#ifndef (L3Color33)
#declare L3Color33 = L3MaterialT(L3Texture33)
#end
#ifndef (L3Color33_slope)
#declare L3Color33_slope = L3MaterialT(L3Texture33_slope)
#end


//// Color 34 Trans_Green (from ldconfig.ldr)
#ifndef (L3Texture34)
#declare L3Texture34 = L3TextureTransparentRGBA(35,120,65,128)
#end
#ifndef (L3Texture34_slope)
#declare L3Texture34_slope = L3TextureSlope(L3Texture34)
#end
#ifndef (L3Color34)
#declare L3Color34 = L3MaterialT(L3Texture34)
#end
#ifndef (L3Color34_slope)
#declare L3Color34_slope = L3MaterialT(L3Texture34_slope)
#end


//// Color 35 Trans_Bright_Green (from ldconfig.ldr)
#ifndef (L3Texture35)
#declare L3Texture35 = L3TextureTransparentRGBA(86,230,70,128)
#end
#ifndef (L3Texture35_slope)
#declare L3Texture35_slope = L3TextureSlope(L3Texture35)
#end
#ifndef (L3Color35)
#declare L3Color35 = L3MaterialT(L3Texture35)
#end
#ifndef (L3Color35_slope)
#declare L3Color35_slope = L3MaterialT(L3Texture35_slope)
#end


//// Color 36 Trans_Red (from ldconfig.ldr)
#ifndef (L3Texture36)
#declare L3Texture36 = L3TextureTransparentRGBA(201,26,9,128)
#end
#ifndef (L3Texture36_slope)
#declare L3Texture36_slope = L3TextureSlope(L3Texture36)
#end
#ifndef (L3Color36)
#declare L3Color36 = L3MaterialT(L3Texture36)
#end
#ifndef (L3Color36_slope)
#declare L3Color36_slope = L3MaterialT(L3Texture36_slope)
#end


//// Color 37 Trans_Dark_Pink (from ldconfig.ldr)
#ifndef (L3Texture37)
#declare L3Texture37 = L3TextureTransparentRGBA(223,102,149,128)
#end
#ifndef (L3Texture37_slope)
#declare L3Texture37_slope = L3TextureSlope(L3Texture37)
#end
#ifndef (L3Color37)
#declare L3Color37 = L3MaterialT(L3Texture37)
#end
#ifndef (L3Color37_slope)
#declare L3Color37_slope = L3MaterialT(L3Texture37_slope)
#end


//// Color 38 Trans_Neon_Orange (from ldconfig.ldr)
#ifndef (L3Texture38)
#declare L3Texture38 = L3TextureTransparentRGBA(255,128,13,128)
#end
#ifndef (L3Texture38_slope)
#declare L3Texture38_slope = L3TextureSlope(L3Texture38)
#end
#ifndef (L3Color38)
#declare L3Color38 = L3MaterialT(L3Texture38)
#end
#ifndef (L3Color38_slope)
#declare L3Color38_slope = L3MaterialT(L3Texture38_slope)
#end


//// Color 39 Trans_Very_Light_Blue (from ldconfig.ldr)
#ifndef (L3Texture39)
#declare L3Texture39 = L3TextureTransparentRGBA(193,223,240,128)
#end
#ifndef (L3Texture39_slope)
#declare L3Texture39_slope = L3TextureSlope(L3Texture39)
#end
#ifndef (L3Color39)
#declare L3Color39 = L3MaterialT(L3Texture39)
#end
#ifndef (L3Color39_slope)
#declare L3Color39_slope = L3MaterialT(L3Texture39_slope)
#end


//// Color 40 Trans_Black (from ldconfig.ldr)
#ifndef (L3Texture40)
#declare L3Texture40 = L3TextureTransparentRGBA(99,95,82,128)
#end
#ifndef (L3Texture40_slope)
#declare L3Texture40_slope = L3TextureSlope(L3Texture40)
#end
#ifndef (L3Color40)
#declare L3Color40 = L3MaterialT(L3Texture40)
#end
#ifndef (L3Color40_slope)
#declare L3Color40_slope = L3MaterialT(L3Texture40_slope)
#end


//// Color 41 Trans_Medium_Blue (from ldconfig.ldr)
#ifndef (L3Texture41)
#declare L3Texture41 = L3TextureTransparentRGBA(85,154,183,128)
#end
#ifndef (L3Texture41_slope)
#declare L3Texture41_slope = L3TextureSlope(L3Texture41)
#end
#ifndef (L3Color41)
#declare L3Color41 = L3MaterialT(L3Texture41)
#end
#ifndef (L3Color41_slope)
#declare L3Color41_slope = L3MaterialT(L3Texture41_slope)
#end


//// Color 42 Trans_Neon_Green (from ldconfig.ldr)
#ifndef (L3Texture42)
#declare L3Texture42 = L3TextureTransparentRGBA(192,255,0,128)
#end
#ifndef (L3Texture42_slope)
#declare L3Texture42_slope = L3TextureSlope(L3Texture42)
#end
#ifndef (L3Color42)
#declare L3Color42 = L3MaterialT(L3Texture42)
#end
#ifndef (L3Color42_slope)
#declare L3Color42_slope = L3MaterialT(L3Texture42_slope)
#end


//// Color 43 Trans_Light_Blue (from ldconfig.ldr)
#ifndef (L3Texture43)
#declare L3Texture43 = L3TextureTransparentRGBA(174,233,239,128)
#end
#ifndef (L3Texture43_slope)
#declare L3Texture43_slope = L3TextureSlope(L3Texture43)
#end
#ifndef (L3Color43)
#declare L3Color43 = L3MaterialT(L3Texture43)
#end
#ifndef (L3Color43_slope)
#declare L3Color43_slope = L3MaterialT(L3Texture43_slope)
#end


//// Color 44 Trans_Bright_Reddish_Lilac (from ldconfig.ldr)
#ifndef (L3Texture44)
#declare L3Texture44 = L3TextureTransparentRGBA(150,112,159,128)
#end
#ifndef (L3Texture44_slope)
#declare L3Texture44_slope = L3TextureSlope(L3Texture44)
#end
#ifndef (L3Color44)
#declare L3Color44 = L3MaterialT(L3Texture44)
#end
#ifndef (L3Color44_slope)
#declare L3Color44_slope = L3MaterialT(L3Texture44_slope)
#end


//// Color 45 Trans_Pink (from ldconfig.ldr)
#ifndef (L3Texture45)
#declare L3Texture45 = L3TextureTransparentRGBA(252,151,172,128)
#end
#ifndef (L3Texture45_slope)
#declare L3Texture45_slope = L3TextureSlope(L3Texture45)
#end
#ifndef (L3Color45)
#declare L3Color45 = L3MaterialT(L3Texture45)
#end
#ifndef (L3Color45_slope)
#declare L3Color45_slope = L3MaterialT(L3Texture45_slope)
#end


//// Color 46 Trans_Yellow (from ldconfig.ldr)
#ifndef (L3Texture46)
#declare L3Texture46 = L3TextureTransparentRGBA(245,205,47,128)
#end
#ifndef (L3Texture46_slope)
#declare L3Texture46_slope = L3TextureSlope(L3Texture46)
#end
#ifndef (L3Color46)
#declare L3Color46 = L3MaterialT(L3Texture46)
#end
#ifndef (L3Color46_slope)
#declare L3Color46_slope = L3MaterialT(L3Texture46_slope)
#end


//// Color 47 Trans_Clear (from ldconfig.ldr)
#ifndef (L3Texture47)
#declare L3Texture47 = L3TextureTransparentRGBA(252,252,252,128)
#end
#ifndef (L3Texture47_slope)
#declare L3Texture47_slope = L3TextureSlope(L3Texture47)
#end
#ifndef (L3Color47)
#declare L3Color47 = L3MaterialT(L3Texture47)
#end
#ifndef (L3Color47_slope)
#declare L3Color47_slope = L3MaterialT(L3Texture47_slope)
#end


//// Color 52 Trans_Purple (from ldconfig.ldr)
#ifndef (L3Texture52)
#declare L3Texture52 = L3TextureTransparentRGBA(165,165,203,128)
#end
#ifndef (L3Texture52_slope)
#declare L3Texture52_slope = L3TextureSlope(L3Texture52)
#end
#ifndef (L3Color52)
#declare L3Color52 = L3MaterialT(L3Texture52)
#end
#ifndef (L3Color52_slope)
#declare L3Color52_slope = L3MaterialT(L3Texture52_slope)
#end


//// Color 54 Trans_Neon_Yellow (from ldconfig.ldr)
#ifndef (L3Texture54)
#declare L3Texture54 = L3TextureTransparentRGBA(218,176,0,128)
#end
#ifndef (L3Texture54_slope)
#declare L3Texture54_slope = L3TextureSlope(L3Texture54)
#end
#ifndef (L3Color54)
#declare L3Color54 = L3MaterialT(L3Texture54)
#end
#ifndef (L3Color54_slope)
#declare L3Color54_slope = L3MaterialT(L3Texture54_slope)
#end


//// Color 57 Trans_Orange (from ldconfig.ldr)
#ifndef (L3Texture57)
#declare L3Texture57 = L3TextureTransparentRGBA(240,143,28,128)
#end
#ifndef (L3Texture57_slope)
#declare L3Texture57_slope = L3TextureSlope(L3Texture57)
#end
#ifndef (L3Color57)
#declare L3Color57 = L3MaterialT(L3Texture57)
#end
#ifndef (L3Color57_slope)
#declare L3Color57_slope = L3MaterialT(L3Texture57_slope)
#end


//// Color 60 Chrome_Antique_Brass (from ldconfig.ldr)
#ifndef (L3Texture60)
#declare L3Texture60 = L3TextureChromeRGB(100,90,76)
#end
#ifndef (L3Texture60_slope)
#declare L3Texture60_slope = L3TextureSlope(L3Texture60)
#end
#ifndef (L3Color60)
#declare L3Color60 = L3Material(L3Texture60)
#end
#ifndef (L3Color60_slope)
#declare L3Color60_slope = L3Material(L3Texture60_slope)
#end


//// Color 61 Chrome_Blue (from ldconfig.ldr)
#ifndef (L3Texture61)
#declare L3Texture61 = L3TextureChromeRGB(108,150,191)
#end
#ifndef (L3Texture61_slope)
#declare L3Texture61_slope = L3TextureSlope(L3Texture61)
#end
#ifndef (L3Color61)
#declare L3Color61 = L3Material(L3Texture61)
#end
#ifndef (L3Color61_slope)
#declare L3Color61_slope = L3Material(L3Texture61_slope)
#end


//// Color 62 Chrome_Green (from ldconfig.ldr)
#ifndef (L3Texture62)
#declare L3Texture62 = L3TextureChromeRGB(60,179,113)
#end
#ifndef (L3Texture62_slope)
#declare L3Texture62_slope = L3TextureSlope(L3Texture62)
#end
#ifndef (L3Color62)
#declare L3Color62 = L3Material(L3Texture62)
#end
#ifndef (L3Color62_slope)
#declare L3Color62_slope = L3Material(L3Texture62_slope)
#end


//// Color 63 Chrome_Pink (from ldconfig.ldr)
#ifndef (L3Texture63)
#declare L3Texture63 = L3TextureChromeRGB(170,77,142)
#end
#ifndef (L3Texture63_slope)
#declare L3Texture63_slope = L3TextureSlope(L3Texture63)
#end
#ifndef (L3Color63)
#declare L3Color63 = L3Material(L3Texture63)
#end
#ifndef (L3Color63_slope)
#declare L3Color63_slope = L3Material(L3Texture63_slope)
#end


//// Color 64 Chrome_Black (from ldconfig.ldr)
#ifndef (L3Texture64)
#declare L3Texture64 = L3TextureChromeRGB(27,42,52)
#end
#ifndef (L3Texture64_slope)
#declare L3Texture64_slope = L3TextureSlope(L3Texture64)
#end
#ifndef (L3Color64)
#declare L3Color64 = L3Material(L3Texture64)
#end
#ifndef (L3Color64_slope)
#declare L3Color64_slope = L3Material(L3Texture64_slope)
#end


//// Color 65 Rubber_Yellow (from ldconfig.ldr)
#ifndef (L3Texture65)
#declare L3Texture65 = L3TextureRubberRGB(245,205,47)
#end
#ifndef (L3Texture65_slope)
#declare L3Texture65_slope = L3TextureSlope(L3Texture65)
#end
#ifndef (L3Color65)
#declare L3Color65 = L3Material(L3Texture65)
#end
#ifndef (L3Color65_slope)
#declare L3Color65_slope = L3Material(L3Texture65_slope)
#end


//// Color 66 Rubber_Trans_Yellow (from ldconfig.ldr)
#ifndef (L3Texture66)
#declare L3Texture66 = L3TextureOtherRGBFAL(202,176,0,3,128,-1)
#end
#ifndef (L3Texture66_slope)
#declare L3Texture66_slope = L3TextureSlope(L3Texture66)
#end
#ifndef (L3Color66)
#declare L3Color66 = L3MaterialT(L3Texture66)
#end
#ifndef (L3Color66_slope)
#declare L3Color66_slope = L3MaterialT(L3Texture66_slope)
#end


//// Color 67 Rubber_Trans_Clear (from ldconfig.ldr)
#ifndef (L3Texture67)
#declare L3Texture67 = L3TextureOtherRGBFAL(255,255,255,3,128,-1)
#end
#ifndef (L3Texture67_slope)
#declare L3Texture67_slope = L3TextureSlope(L3Texture67)
#end
#ifndef (L3Color67)
#declare L3Color67 = L3MaterialT(L3Texture67)
#end
#ifndef (L3Color67_slope)
#declare L3Color67_slope = L3MaterialT(L3Texture67_slope)
#end


//// Color 68 Very_Light_Orange (from ldconfig.ldr)
#ifndef (L3Texture68)
#declare L3Texture68 = L3TextureOpaqueRGB(243,207,155)
#end
#ifndef (L3Texture68_slope)
#declare L3Texture68_slope = L3TextureSlope(L3Texture68)
#end
#ifndef (L3Color68)
#declare L3Color68 = L3Material(L3Texture68)
#end
#ifndef (L3Color68_slope)
#declare L3Color68_slope = L3Material(L3Texture68_slope)
#end


//// Color 69 Bright_Reddish_Lilac (from ldconfig.ldr)
#ifndef (L3Texture69)
#declare L3Texture69 = L3TextureOpaqueRGB(205,98,152)
#end
#ifndef (L3Texture69_slope)
#declare L3Texture69_slope = L3TextureSlope(L3Texture69)
#end
#ifndef (L3Color69)
#declare L3Color69 = L3Material(L3Texture69)
#end
#ifndef (L3Color69_slope)
#declare L3Color69_slope = L3Material(L3Texture69_slope)
#end


//// Color 70 Reddish_Brown (from ldconfig.ldr)
#ifndef (L3Texture70)
#declare L3Texture70 = L3TextureOpaqueRGB(88,42,18)
#end
#ifndef (L3Texture70_slope)
#declare L3Texture70_slope = L3TextureSlope(L3Texture70)
#end
#ifndef (L3Color70)
#declare L3Color70 = L3Material(L3Texture70)
#end
#ifndef (L3Color70_slope)
#declare L3Color70_slope = L3Material(L3Texture70_slope)
#end


//// Color 71 Light_Bluish_Grey (from ldconfig.ldr)
#ifndef (L3Texture71)
#declare L3Texture71 = L3TextureOpaqueRGB(160,165,169)
#end
#ifndef (L3Texture71_slope)
#declare L3Texture71_slope = L3TextureSlope(L3Texture71)
#end
#ifndef (L3Color71)
#declare L3Color71 = L3Material(L3Texture71)
#end
#ifndef (L3Color71_slope)
#declare L3Color71_slope = L3Material(L3Texture71_slope)
#end


//// Color 72 Dark_Bluish_Grey (from ldconfig.ldr)
#ifndef (L3Texture72)
#declare L3Texture72 = L3TextureOpaqueRGB(108,110,104)
#end
#ifndef (L3Texture72_slope)
#declare L3Texture72_slope = L3TextureSlope(L3Texture72)
#end
#ifndef (L3Color72)
#declare L3Color72 = L3Material(L3Texture72)
#end
#ifndef (L3Color72_slope)
#declare L3Color72_slope = L3Material(L3Texture72_slope)
#end


//// Color 73 Medium_Blue (from ldconfig.ldr)
#ifndef (L3Texture73)
#declare L3Texture73 = L3TextureOpaqueRGB(92,157,209)
#end
#ifndef (L3Texture73_slope)
#declare L3Texture73_slope = L3TextureSlope(L3Texture73)
#end
#ifndef (L3Color73)
#declare L3Color73 = L3Material(L3Texture73)
#end
#ifndef (L3Color73_slope)
#declare L3Color73_slope = L3Material(L3Texture73_slope)
#end


//// Color 74 Medium_Green (from ldconfig.ldr)
#ifndef (L3Texture74)
#declare L3Texture74 = L3TextureOpaqueRGB(115,220,161)
#end
#ifndef (L3Texture74_slope)
#declare L3Texture74_slope = L3TextureSlope(L3Texture74)
#end
#ifndef (L3Color74)
#declare L3Color74 = L3Material(L3Texture74)
#end
#ifndef (L3Color74_slope)
#declare L3Color74_slope = L3Material(L3Texture74_slope)
#end


//// Color 75 Speckle_Black_Copper (from ldconfig.ldr)
#ifndef (L3Texture75)
#declare L3Texture75 = L3TextureOpaqueRGB(0,0,0)
#end
#ifndef (L3Texture75_slope)
#declare L3Texture75_slope = L3TextureSlope(L3Texture75)
#end
#ifndef (L3Color75)
#declare L3Color75 = L3Material(L3Texture75)
#end
#ifndef (L3Color75_slope)
#declare L3Color75_slope = L3Material(L3Texture75_slope)
#end


//// Color 76 Speckle_Dark_Bluish_Grey_Silver (from ldconfig.ldr)
#ifndef (L3Texture76)
#declare L3Texture76 = L3TextureOpaqueRGB(99,95,97)
#end
#ifndef (L3Texture76_slope)
#declare L3Texture76_slope = L3TextureSlope(L3Texture76)
#end
#ifndef (L3Color76)
#declare L3Color76 = L3Material(L3Texture76)
#end
#ifndef (L3Color76_slope)
#declare L3Color76_slope = L3Material(L3Texture76_slope)
#end


//// Color 77 Light_Pink (from ldconfig.ldr)
#ifndef (L3Texture77)
#declare L3Texture77 = L3TextureOpaqueRGB(254,204,207)
#end
#ifndef (L3Texture77_slope)
#declare L3Texture77_slope = L3TextureSlope(L3Texture77)
#end
#ifndef (L3Color77)
#declare L3Color77 = L3Material(L3Texture77)
#end
#ifndef (L3Color77_slope)
#declare L3Color77_slope = L3Material(L3Texture77_slope)
#end


//// Color 78 Light_Flesh (from ldconfig.ldr)
#ifndef (L3Texture78)
#declare L3Texture78 = L3TextureOpaqueRGB(246,215,179)
#end
#ifndef (L3Texture78_slope)
#declare L3Texture78_slope = L3TextureSlope(L3Texture78)
#end
#ifndef (L3Color78)
#declare L3Color78 = L3Material(L3Texture78)
#end
#ifndef (L3Color78_slope)
#declare L3Color78_slope = L3Material(L3Texture78_slope)
#end


//// Color 79 Milky_White (from ldconfig.ldr)
#ifndef (L3Texture79)
#declare L3Texture79 = L3TextureTransparentRGBA(255,255,255,240)
#end
#ifndef (L3Texture79_slope)
#declare L3Texture79_slope = L3TextureSlope(L3Texture79)
#end
#ifndef (L3Color79)
#declare L3Color79 = L3MaterialT(L3Texture79)
#end
#ifndef (L3Color79_slope)
#declare L3Color79_slope = L3MaterialT(L3Texture79_slope)
#end


//// Color 80 Metallic_Silver (from ldconfig.ldr)
#ifndef (L3Texture80)
#declare L3Texture80 = L3TextureMetalRGB(165,169,180)
#end
#ifndef (L3Texture80_slope)
#declare L3Texture80_slope = L3TextureSlope(L3Texture80)
#end
#ifndef (L3Color80)
#declare L3Color80 = L3Material(L3Texture80)
#end
#ifndef (L3Color80_slope)
#declare L3Color80_slope = L3Material(L3Texture80_slope)
#end


//// Color 81 Metallic_Green (from ldconfig.ldr)
#ifndef (L3Texture81)
#declare L3Texture81 = L3TextureMetalRGB(137,155,95)
#end
#ifndef (L3Texture81_slope)
#declare L3Texture81_slope = L3TextureSlope(L3Texture81)
#end
#ifndef (L3Color81)
#declare L3Color81 = L3Material(L3Texture81)
#end
#ifndef (L3Color81_slope)
#declare L3Color81_slope = L3Material(L3Texture81_slope)
#end


//// Color 82 Metallic_Gold (from ldconfig.ldr)
#ifndef (L3Texture82)
#declare L3Texture82 = L3TextureMetalRGB(219,172,52)
#end
#ifndef (L3Texture82_slope)
#declare L3Texture82_slope = L3TextureSlope(L3Texture82)
#end
#ifndef (L3Color82)
#declare L3Color82 = L3Material(L3Texture82)
#end
#ifndef (L3Color82_slope)
#declare L3Color82_slope = L3Material(L3Texture82_slope)
#end


//// Color 83 Metallic_Black (from ldconfig.ldr)
#ifndef (L3Texture83)
#declare L3Texture83 = L3TextureMetalRGB(26,40,49)
#end
#ifndef (L3Texture83_slope)
#declare L3Texture83_slope = L3TextureSlope(L3Texture83)
#end
#ifndef (L3Color83)
#declare L3Color83 = L3Material(L3Texture83)
#end
#ifndef (L3Color83_slope)
#declare L3Color83_slope = L3Material(L3Texture83_slope)
#end


//// Color 84 Medium_Dark_Flesh (from ldconfig.ldr)
#ifndef (L3Texture84)
#declare L3Texture84 = L3TextureOpaqueRGB(204,112,42)
#end
#ifndef (L3Texture84_slope)
#declare L3Texture84_slope = L3TextureSlope(L3Texture84)
#end
#ifndef (L3Color84)
#declare L3Color84 = L3Material(L3Texture84)
#end
#ifndef (L3Color84_slope)
#declare L3Color84_slope = L3Material(L3Texture84_slope)
#end


//// Color 85 Medium_Lilac (from ldconfig.ldr)
#ifndef (L3Texture85)
#declare L3Texture85 = L3TextureOpaqueRGB(63,54,145)
#end
#ifndef (L3Texture85_slope)
#declare L3Texture85_slope = L3TextureSlope(L3Texture85)
#end
#ifndef (L3Color85)
#declare L3Color85 = L3Material(L3Texture85)
#end
#ifndef (L3Color85_slope)
#declare L3Color85_slope = L3Material(L3Texture85_slope)
#end


//// Color 86 Dark_Flesh (from ldconfig.ldr)
#ifndef (L3Texture86)
#declare L3Texture86 = L3TextureOpaqueRGB(124,80,58)
#end
#ifndef (L3Texture86_slope)
#declare L3Texture86_slope = L3TextureSlope(L3Texture86)
#end
#ifndef (L3Color86)
#declare L3Color86 = L3Material(L3Texture86)
#end
#ifndef (L3Color86_slope)
#declare L3Color86_slope = L3Material(L3Texture86_slope)
#end


//// Color 87 Metallic_Dark_Grey (from ldconfig.ldr)
#ifndef (L3Texture87)
#declare L3Texture87 = L3TextureMetalRGB(109,110,92)
#end
#ifndef (L3Texture87_slope)
#declare L3Texture87_slope = L3TextureSlope(L3Texture87)
#end
#ifndef (L3Color87)
#declare L3Color87 = L3Material(L3Texture87)
#end
#ifndef (L3Color87_slope)
#declare L3Color87_slope = L3Material(L3Texture87_slope)
#end


//// Color 89 Blue_Violet (from ldconfig.ldr)
#ifndef (L3Texture89)
#declare L3Texture89 = L3TextureOpaqueRGB(76,97,219)
#end
#ifndef (L3Texture89_slope)
#declare L3Texture89_slope = L3TextureSlope(L3Texture89)
#end
#ifndef (L3Color89)
#declare L3Color89 = L3Material(L3Texture89)
#end
#ifndef (L3Color89_slope)
#declare L3Color89_slope = L3Material(L3Texture89_slope)
#end


//// Color 92 Flesh (from ldconfig.ldr)
#ifndef (L3Texture92)
#declare L3Texture92 = L3TextureOpaqueRGB(208,145,104)
#end
#ifndef (L3Texture92_slope)
#declare L3Texture92_slope = L3TextureSlope(L3Texture92)
#end
#ifndef (L3Color92)
#declare L3Color92 = L3Material(L3Texture92)
#end
#ifndef (L3Color92_slope)
#declare L3Color92_slope = L3Material(L3Texture92_slope)
#end


//// Color 100 Light_Salmon (from ldconfig.ldr)
#ifndef (L3Texture100)
#declare L3Texture100 = L3TextureOpaqueRGB(254,186,189)
#end
#ifndef (L3Texture100_slope)
#declare L3Texture100_slope = L3TextureSlope(L3Texture100)
#end
#ifndef (L3Color100)
#declare L3Color100 = L3Material(L3Texture100)
#end
#ifndef (L3Color100_slope)
#declare L3Color100_slope = L3Material(L3Texture100_slope)
#end


//// Color 110 Violet (from ldconfig.ldr)
#ifndef (L3Texture110)
#declare L3Texture110 = L3TextureOpaqueRGB(67,84,163)
#end
#ifndef (L3Texture110_slope)
#declare L3Texture110_slope = L3TextureSlope(L3Texture110)
#end
#ifndef (L3Color110)
#declare L3Color110 = L3Material(L3Texture110)
#end
#ifndef (L3Color110_slope)
#declare L3Color110_slope = L3Material(L3Texture110_slope)
#end


//// Color 112 Medium_Violet (from ldconfig.ldr)
#ifndef (L3Texture112)
#declare L3Texture112 = L3TextureOpaqueRGB(104,116,202)
#end
#ifndef (L3Texture112_slope)
#declare L3Texture112_slope = L3TextureSlope(L3Texture112)
#end
#ifndef (L3Color112)
#declare L3Color112 = L3Material(L3Texture112)
#end
#ifndef (L3Color112_slope)
#declare L3Color112_slope = L3Material(L3Texture112_slope)
#end


//// Color 114 Glitter_Trans_Dark_Pink (from ldconfig.ldr)
#ifndef (L3Texture114)
#declare L3Texture114 = L3TextureTransparentRGBA(223,102,149,128)
#end
#ifndef (L3Texture114_slope)
#declare L3Texture114_slope = L3TextureSlope(L3Texture114)
#end
#ifndef (L3Color114)
#declare L3Color114 = L3MaterialT(L3Texture114)
#end
#ifndef (L3Color114_slope)
#declare L3Color114_slope = L3MaterialT(L3Texture114_slope)
#end


//// Color 115 Medium_Lime (from ldconfig.ldr)
#ifndef (L3Texture115)
#declare L3Texture115 = L3TextureOpaqueRGB(199,210,60)
#end
#ifndef (L3Texture115_slope)
#declare L3Texture115_slope = L3TextureSlope(L3Texture115)
#end
#ifndef (L3Color115)
#declare L3Color115 = L3Material(L3Texture115)
#end
#ifndef (L3Color115_slope)
#declare L3Color115_slope = L3Material(L3Texture115_slope)
#end


//// Color 117 Glitter_Trans_Clear (from ldconfig.ldr)
#ifndef (L3Texture117)
#declare L3Texture117 = L3TextureTransparentRGBA(255,255,255,128)
#end
#ifndef (L3Texture117_slope)
#declare L3Texture117_slope = L3TextureSlope(L3Texture117)
#end
#ifndef (L3Color117)
#declare L3Color117 = L3MaterialT(L3Texture117)
#end
#ifndef (L3Color117_slope)
#declare L3Color117_slope = L3MaterialT(L3Texture117_slope)
#end


//// Color 118 Aqua (from ldconfig.ldr)
#ifndef (L3Texture118)
#declare L3Texture118 = L3TextureOpaqueRGB(179,215,209)
#end
#ifndef (L3Texture118_slope)
#declare L3Texture118_slope = L3TextureSlope(L3Texture118)
#end
#ifndef (L3Color118)
#declare L3Color118 = L3Material(L3Texture118)
#end
#ifndef (L3Color118_slope)
#declare L3Color118_slope = L3Material(L3Texture118_slope)
#end


//// Color 120 Light_Lime (from ldconfig.ldr)
#ifndef (L3Texture120)
#declare L3Texture120 = L3TextureOpaqueRGB(217,228,167)
#end
#ifndef (L3Texture120_slope)
#declare L3Texture120_slope = L3TextureSlope(L3Texture120)
#end
#ifndef (L3Color120)
#declare L3Color120 = L3Material(L3Texture120)
#end
#ifndef (L3Color120_slope)
#declare L3Color120_slope = L3Material(L3Texture120_slope)
#end


//// Color 125 Light_Orange (from ldconfig.ldr)
#ifndef (L3Texture125)
#declare L3Texture125 = L3TextureOpaqueRGB(249,186,97)
#end
#ifndef (L3Texture125_slope)
#declare L3Texture125_slope = L3TextureSlope(L3Texture125)
#end
#ifndef (L3Color125)
#declare L3Color125 = L3Material(L3Texture125)
#end
#ifndef (L3Color125_slope)
#declare L3Color125_slope = L3Material(L3Texture125_slope)
#end


//// Color 128 Dark_Nougat (from ldconfig.ldr)
#ifndef (L3Texture128)
#declare L3Texture128 = L3TextureOpaqueRGB(173,97,64)
#end
#ifndef (L3Texture128_slope)
#declare L3Texture128_slope = L3TextureSlope(L3Texture128)
#end
#ifndef (L3Color128)
#declare L3Color128 = L3Material(L3Texture128)
#end
#ifndef (L3Color128_slope)
#declare L3Color128_slope = L3Material(L3Texture128_slope)
#end


//// Color 129 Glitter_Trans_Purple (from ldconfig.ldr)
#ifndef (L3Texture129)
#declare L3Texture129 = L3TextureTransparentRGBA(100,0,97,128)
#end
#ifndef (L3Texture129_slope)
#declare L3Texture129_slope = L3TextureSlope(L3Texture129)
#end
#ifndef (L3Color129)
#declare L3Color129 = L3MaterialT(L3Texture129)
#end
#ifndef (L3Color129_slope)
#declare L3Color129_slope = L3MaterialT(L3Texture129_slope)
#end


//// Color 132 Speckle_Black_Silver (from ldconfig.ldr)
#ifndef (L3Texture132)
#declare L3Texture132 = L3TextureOpaqueRGB(0,0,0)
#end
#ifndef (L3Texture132_slope)
#declare L3Texture132_slope = L3TextureSlope(L3Texture132)
#end
#ifndef (L3Color132)
#declare L3Color132 = L3Material(L3Texture132)
#end
#ifndef (L3Color132_slope)
#declare L3Color132_slope = L3Material(L3Texture132_slope)
#end


//// Color 133 Speckle_Black_Gold (from ldconfig.ldr)
#ifndef (L3Texture133)
#declare L3Texture133 = L3TextureOpaqueRGB(0,0,0)
#end
#ifndef (L3Texture133_slope)
#declare L3Texture133_slope = L3TextureSlope(L3Texture133)
#end
#ifndef (L3Color133)
#declare L3Color133 = L3Material(L3Texture133)
#end
#ifndef (L3Color133_slope)
#declare L3Color133_slope = L3Material(L3Texture133_slope)
#end


//// Color 134 Copper (from ldconfig.ldr)
#ifndef (L3Texture134)
#declare L3Texture134 = L3TexturePearlescentRGB(150,74,39)
#end
#ifndef (L3Texture134_slope)
#declare L3Texture134_slope = L3TextureSlope(L3Texture134)
#end
#ifndef (L3Color134)
#declare L3Color134 = L3Material(L3Texture134)
#end
#ifndef (L3Color134_slope)
#declare L3Color134_slope = L3Material(L3Texture134_slope)
#end


//// Color 135 Pearl_Light_Grey (from ldconfig.ldr)
#ifndef (L3Texture135)
#declare L3Texture135 = L3TexturePearlescentRGB(156,163,168)
#end
#ifndef (L3Texture135_slope)
#declare L3Texture135_slope = L3TextureSlope(L3Texture135)
#end
#ifndef (L3Color135)
#declare L3Color135 = L3Material(L3Texture135)
#end
#ifndef (L3Color135_slope)
#declare L3Color135_slope = L3Material(L3Texture135_slope)
#end


//// Color 137 Metal_Blue (from ldconfig.ldr)
#ifndef (L3Texture137)
#declare L3Texture137 = L3TexturePearlescentRGB(86,119,186)
#end
#ifndef (L3Texture137_slope)
#declare L3Texture137_slope = L3TextureSlope(L3Texture137)
#end
#ifndef (L3Color137)
#declare L3Color137 = L3Material(L3Texture137)
#end
#ifndef (L3Color137_slope)
#declare L3Color137_slope = L3Material(L3Texture137_slope)
#end


//// Color 142 Pearl_Light_Gold (from ldconfig.ldr)
#ifndef (L3Texture142)
#declare L3Texture142 = L3TexturePearlescentRGB(220,190,97)
#end
#ifndef (L3Texture142_slope)
#declare L3Texture142_slope = L3TextureSlope(L3Texture142)
#end
#ifndef (L3Color142)
#declare L3Color142 = L3Material(L3Texture142)
#end
#ifndef (L3Color142_slope)
#declare L3Color142_slope = L3Material(L3Texture142_slope)
#end


//// Color 148 Pearl_Dark_Grey (from ldconfig.ldr)
#ifndef (L3Texture148)
#declare L3Texture148 = L3TexturePearlescentRGB(87,88,87)
#end
#ifndef (L3Texture148_slope)
#declare L3Texture148_slope = L3TextureSlope(L3Texture148)
#end
#ifndef (L3Color148)
#declare L3Color148 = L3Material(L3Texture148)
#end
#ifndef (L3Color148_slope)
#declare L3Color148_slope = L3Material(L3Texture148_slope)
#end


//// Color 150 Pearl_Very_Light_Grey (from ldconfig.ldr)
#ifndef (L3Texture150)
#declare L3Texture150 = L3TexturePearlescentRGB(187,189,188)
#end
#ifndef (L3Texture150_slope)
#declare L3Texture150_slope = L3TextureSlope(L3Texture150)
#end
#ifndef (L3Color150)
#declare L3Color150 = L3Material(L3Texture150)
#end
#ifndef (L3Color150_slope)
#declare L3Color150_slope = L3Material(L3Texture150_slope)
#end


//// Color 151 Very_Light_Bluish_Grey (from ldconfig.ldr)
#ifndef (L3Texture151)
#declare L3Texture151 = L3TextureOpaqueRGB(230,227,224)
#end
#ifndef (L3Texture151_slope)
#declare L3Texture151_slope = L3TextureSlope(L3Texture151)
#end
#ifndef (L3Color151)
#declare L3Color151 = L3Material(L3Texture151)
#end
#ifndef (L3Color151_slope)
#declare L3Color151_slope = L3Material(L3Texture151_slope)
#end


//// Color 178 Flat_Dark_Gold (from ldconfig.ldr)
#ifndef (L3Texture178)
#declare L3Texture178 = L3TexturePearlescentRGB(180,136,62)
#end
#ifndef (L3Texture178_slope)
#declare L3Texture178_slope = L3TextureSlope(L3Texture178)
#end
#ifndef (L3Color178)
#declare L3Color178 = L3Material(L3Texture178)
#end
#ifndef (L3Color178_slope)
#declare L3Color178_slope = L3Material(L3Texture178_slope)
#end


//// Color 179 Flat_Silver (from ldconfig.ldr)
#ifndef (L3Texture179)
#declare L3Texture179 = L3TexturePearlescentRGB(137,135,136)
#end
#ifndef (L3Texture179_slope)
#declare L3Texture179_slope = L3TextureSlope(L3Texture179)
#end
#ifndef (L3Color179)
#declare L3Color179 = L3Material(L3Texture179)
#end
#ifndef (L3Color179_slope)
#declare L3Color179_slope = L3Material(L3Texture179_slope)
#end


//// Color 183 Pearl_White (from ldconfig.ldr)
#ifndef (L3Texture183)
#declare L3Texture183 = L3TexturePearlescentRGB(242,243,242)
#end
#ifndef (L3Texture183_slope)
#declare L3Texture183_slope = L3TextureSlope(L3Texture183)
#end
#ifndef (L3Color183)
#declare L3Color183 = L3Material(L3Texture183)
#end
#ifndef (L3Color183_slope)
#declare L3Color183_slope = L3Material(L3Texture183_slope)
#end


//// Color 184 Metallic_Bright_Red (from ldconfig.ldr)
#ifndef (L3Texture184)
#declare L3Texture184 = L3TextureMetalRGB(214,0,38)
#end
#ifndef (L3Texture184_slope)
#declare L3Texture184_slope = L3TextureSlope(L3Texture184)
#end
#ifndef (L3Color184)
#declare L3Color184 = L3Material(L3Texture184)
#end
#ifndef (L3Color184_slope)
#declare L3Color184_slope = L3Material(L3Texture184_slope)
#end


//// Color 186 Metallic_Dark_Green (from ldconfig.ldr)
#ifndef (L3Texture186)
#declare L3Texture186 = L3TextureMetalRGB(0,142,60)
#end
#ifndef (L3Texture186_slope)
#declare L3Texture186_slope = L3TextureSlope(L3Texture186)
#end
#ifndef (L3Color186)
#declare L3Color186 = L3Material(L3Texture186)
#end
#ifndef (L3Color186_slope)
#declare L3Color186_slope = L3Material(L3Texture186_slope)
#end


//// Color 189 Reddish_Gold (from ldconfig.ldr)
#ifndef (L3Texture189)
#declare L3Texture189 = L3TexturePearlescentRGB(172,130,71)
#end
#ifndef (L3Texture189_slope)
#declare L3Texture189_slope = L3TextureSlope(L3Texture189)
#end
#ifndef (L3Color189)
#declare L3Color189 = L3Material(L3Texture189)
#end
#ifndef (L3Color189_slope)
#declare L3Color189_slope = L3Material(L3Texture189_slope)
#end


//// Color 191 Bright_Light_Orange (from ldconfig.ldr)
#ifndef (L3Texture191)
#declare L3Texture191 = L3TextureOpaqueRGB(248,187,61)
#end
#ifndef (L3Texture191_slope)
#declare L3Texture191_slope = L3TextureSlope(L3Texture191)
#end
#ifndef (L3Color191)
#declare L3Color191 = L3Material(L3Texture191)
#end
#ifndef (L3Color191_slope)
#declare L3Color191_slope = L3Material(L3Texture191_slope)
#end


//// Color 212 Bright_Light_Blue (from ldconfig.ldr)
#ifndef (L3Texture212)
#declare L3Texture212 = L3TextureOpaqueRGB(134,193,225)
#end
#ifndef (L3Texture212_slope)
#declare L3Texture212_slope = L3TextureSlope(L3Texture212)
#end
#ifndef (L3Color212)
#declare L3Color212 = L3Material(L3Texture212)
#end
#ifndef (L3Color212_slope)
#declare L3Color212_slope = L3Material(L3Texture212_slope)
#end


//// Color 216 Rust (from ldconfig.ldr)
#ifndef (L3Texture216)
#declare L3Texture216 = L3TextureOpaqueRGB(179,16,4)
#end
#ifndef (L3Texture216_slope)
#declare L3Texture216_slope = L3TextureSlope(L3Texture216)
#end
#ifndef (L3Color216)
#declare L3Color216 = L3Material(L3Texture216)
#end
#ifndef (L3Color216_slope)
#declare L3Color216_slope = L3Material(L3Texture216_slope)
#end


//// Color 218 Reddish_Lilac (from ldconfig.ldr)
#ifndef (L3Texture218)
#declare L3Texture218 = L3TextureOpaqueRGB(142,85,151)
#end
#ifndef (L3Texture218_slope)
#declare L3Texture218_slope = L3TextureSlope(L3Texture218)
#end
#ifndef (L3Color218)
#declare L3Color218 = L3Material(L3Texture218)
#end
#ifndef (L3Color218_slope)
#declare L3Color218_slope = L3Material(L3Texture218_slope)
#end


//// Color 219 Lilac (from ldconfig.ldr)
#ifndef (L3Texture219)
#declare L3Texture219 = L3TextureOpaqueRGB(86,78,157)
#end
#ifndef (L3Texture219_slope)
#declare L3Texture219_slope = L3TextureSlope(L3Texture219)
#end
#ifndef (L3Color219)
#declare L3Color219 = L3Material(L3Texture219)
#end
#ifndef (L3Color219_slope)
#declare L3Color219_slope = L3Material(L3Texture219_slope)
#end


//// Color 226 Bright_Light_Yellow (from ldconfig.ldr)
#ifndef (L3Texture226)
#declare L3Texture226 = L3TextureOpaqueRGB(255,240,58)
#end
#ifndef (L3Texture226_slope)
#declare L3Texture226_slope = L3TextureSlope(L3Texture226)
#end
#ifndef (L3Color226)
#declare L3Color226 = L3Material(L3Texture226)
#end
#ifndef (L3Color226_slope)
#declare L3Color226_slope = L3Material(L3Texture226_slope)
#end


//// Color 231 Trans_Bright_Light_Orange (from ldconfig.ldr)
#ifndef (L3Texture231)
#declare L3Texture231 = L3TextureTransparentRGBA(252,183,109,128)
#end
#ifndef (L3Texture231_slope)
#declare L3Texture231_slope = L3TextureSlope(L3Texture231)
#end
#ifndef (L3Color231)
#declare L3Color231 = L3MaterialT(L3Texture231)
#end
#ifndef (L3Color231_slope)
#declare L3Color231_slope = L3MaterialT(L3Texture231_slope)
#end


//// Color 232 Sky_Blue (from ldconfig.ldr)
#ifndef (L3Texture232)
#declare L3Texture232 = L3TextureOpaqueRGB(86,190,214)
#end
#ifndef (L3Texture232_slope)
#declare L3Texture232_slope = L3TextureSlope(L3Texture232)
#end
#ifndef (L3Color232)
#declare L3Color232 = L3Material(L3Texture232)
#end
#ifndef (L3Color232_slope)
#declare L3Color232_slope = L3Material(L3Texture232_slope)
#end


//// Color 234 Trans_Fire_Yellow (from ldconfig.ldr)
#ifndef (L3Texture234)
#declare L3Texture234 = L3TextureTransparentRGBA(251,232,144,128)
#end
#ifndef (L3Texture234_slope)
#declare L3Texture234_slope = L3TextureSlope(L3Texture234)
#end
#ifndef (L3Color234)
#declare L3Color234 = L3MaterialT(L3Texture234)
#end
#ifndef (L3Color234_slope)
#declare L3Color234_slope = L3MaterialT(L3Texture234_slope)
#end


//// Color 256 Rubber_Black (from ldconfig.ldr)
#ifndef (L3Texture256)
#declare L3Texture256 = L3TextureRubberRGB(33,33,33)
#end
#ifndef (L3Texture256_slope)
#declare L3Texture256_slope = L3TextureSlope(L3Texture256)
#end
#ifndef (L3Color256)
#declare L3Color256 = L3Material(L3Texture256)
#end
#ifndef (L3Color256_slope)
#declare L3Color256_slope = L3Material(L3Texture256_slope)
#end


//// Color 272 Dark_Blue (from ldconfig.ldr)
#ifndef (L3Texture272)
#declare L3Texture272 = L3TextureOpaqueRGB(13,50,91)
#end
#ifndef (L3Texture272_slope)
#declare L3Texture272_slope = L3TextureSlope(L3Texture272)
#end
#ifndef (L3Color272)
#declare L3Color272 = L3Material(L3Texture272)
#end
#ifndef (L3Color272_slope)
#declare L3Color272_slope = L3Material(L3Texture272_slope)
#end


//// Color 273 Rubber_Blue (from ldconfig.ldr)
#ifndef (L3Texture273)
#declare L3Texture273 = L3TextureRubberRGB(0,51,178)
#end
#ifndef (L3Texture273_slope)
#declare L3Texture273_slope = L3TextureSlope(L3Texture273)
#end
#ifndef (L3Color273)
#declare L3Color273 = L3Material(L3Texture273)
#end
#ifndef (L3Color273_slope)
#declare L3Color273_slope = L3Material(L3Texture273_slope)
#end


//// Color 284 Trans_Reddish_Lilac (from ldconfig.ldr)
#ifndef (L3Texture284)
#declare L3Texture284 = L3TextureTransparentRGBA(194,129,165,128)
#end
#ifndef (L3Texture284_slope)
#declare L3Texture284_slope = L3TextureSlope(L3Texture284)
#end
#ifndef (L3Color284)
#declare L3Color284 = L3MaterialT(L3Texture284)
#end
#ifndef (L3Color284_slope)
#declare L3Color284_slope = L3MaterialT(L3Texture284_slope)
#end


//// Color 285 Trans_Light_Green (from ldconfig.ldr)
#ifndef (L3Texture285)
#declare L3Texture285 = L3TextureTransparentRGBA(125,194,145,128)
#end
#ifndef (L3Texture285_slope)
#declare L3Texture285_slope = L3TextureSlope(L3Texture285)
#end
#ifndef (L3Color285)
#declare L3Color285 = L3MaterialT(L3Texture285)
#end
#ifndef (L3Color285_slope)
#declare L3Color285_slope = L3MaterialT(L3Texture285_slope)
#end


//// Color 288 Dark_Green (from ldconfig.ldr)
#ifndef (L3Texture288)
#declare L3Texture288 = L3TextureOpaqueRGB(24,70,50)
#end
#ifndef (L3Texture288_slope)
#declare L3Texture288_slope = L3TextureSlope(L3Texture288)
#end
#ifndef (L3Color288)
#declare L3Color288 = L3Material(L3Texture288)
#end
#ifndef (L3Color288_slope)
#declare L3Color288_slope = L3Material(L3Texture288_slope)
#end


//// Color 293 Trans_Light_Blue_Violet (from ldconfig.ldr)
#ifndef (L3Texture293)
#declare L3Texture293 = L3TextureTransparentRGBA(107,171,228,128)
#end
#ifndef (L3Texture293_slope)
#declare L3Texture293_slope = L3TextureSlope(L3Texture293)
#end
#ifndef (L3Color293)
#declare L3Color293 = L3MaterialT(L3Texture293)
#end
#ifndef (L3Color293_slope)
#declare L3Color293_slope = L3MaterialT(L3Texture293_slope)
#end


//// Color 294 Glow_In_Dark_Trans (from ldconfig.ldr)
#ifndef (L3Texture294)
#declare L3Texture294 = L3TextureOtherRGBFAL(189,198,173,0,240,15)
#end
#ifndef (L3Texture294_slope)
#declare L3Texture294_slope = L3TextureSlope(L3Texture294)
#end
#ifndef (L3Color294)
#declare L3Color294 = L3MaterialT(L3Texture294)
#end
#ifndef (L3Color294_slope)
#declare L3Color294_slope = L3MaterialT(L3Texture294_slope)
#end


//// Color 295 Flamingo_Pink (from ldconfig.ldr)
#ifndef (L3Texture295)
#declare L3Texture295 = L3TextureOpaqueRGB(255,148,194)
#end
#ifndef (L3Texture295_slope)
#declare L3Texture295_slope = L3TextureSlope(L3Texture295)
#end
#ifndef (L3Color295)
#declare L3Color295 = L3Material(L3Texture295)
#end
#ifndef (L3Color295_slope)
#declare L3Color295_slope = L3Material(L3Texture295_slope)
#end


//// Color 297 Pearl_Gold (from ldconfig.ldr)
#ifndef (L3Texture297)
#declare L3Texture297 = L3TexturePearlescentRGB(204,156,43)
#end
#ifndef (L3Texture297_slope)
#declare L3Texture297_slope = L3TextureSlope(L3Texture297)
#end
#ifndef (L3Color297)
#declare L3Color297 = L3Material(L3Texture297)
#end
#ifndef (L3Color297_slope)
#declare L3Color297_slope = L3Material(L3Texture297_slope)
#end


//// Color 300 Metallic_Copper (from ldconfig.ldr)
#ifndef (L3Texture300)
#declare L3Texture300 = L3TextureMetalRGB(194,127,83)
#end
#ifndef (L3Texture300_slope)
#declare L3Texture300_slope = L3TextureSlope(L3Texture300)
#end
#ifndef (L3Color300)
#declare L3Color300 = L3Material(L3Texture300)
#end
#ifndef (L3Color300_slope)
#declare L3Color300_slope = L3Material(L3Texture300_slope)
#end


//// Color 302 Glitter_Trans_Light_Blue (from ldconfig.ldr)
#ifndef (L3Texture302)
#declare L3Texture302 = L3TextureTransparentRGBA(174,233,239,128)
#end
#ifndef (L3Texture302_slope)
#declare L3Texture302_slope = L3TextureSlope(L3Texture302)
#end
#ifndef (L3Color302)
#declare L3Color302 = L3MaterialT(L3Texture302)
#end
#ifndef (L3Color302_slope)
#declare L3Color302_slope = L3MaterialT(L3Texture302_slope)
#end


//// Color 308 Dark_Brown (from ldconfig.ldr)
#ifndef (L3Texture308)
#declare L3Texture308 = L3TextureOpaqueRGB(53,33,0)
#end
#ifndef (L3Texture308_slope)
#declare L3Texture308_slope = L3TextureSlope(L3Texture308)
#end
#ifndef (L3Color308)
#declare L3Color308 = L3Material(L3Texture308)
#end
#ifndef (L3Color308_slope)
#declare L3Color308_slope = L3Material(L3Texture308_slope)
#end


//// Color 313 Maersk_Blue (from ldconfig.ldr)
#ifndef (L3Texture313)
#declare L3Texture313 = L3TextureOpaqueRGB(84,169,200)
#end
#ifndef (L3Texture313_slope)
#declare L3Texture313_slope = L3TextureSlope(L3Texture313)
#end
#ifndef (L3Color313)
#declare L3Color313 = L3Material(L3Texture313)
#end
#ifndef (L3Color313_slope)
#declare L3Color313_slope = L3Material(L3Texture313_slope)
#end


//// Color 320 Dark_Red (from ldconfig.ldr)
#ifndef (L3Texture320)
#declare L3Texture320 = L3TextureOpaqueRGB(114,14,15)
#end
#ifndef (L3Texture320_slope)
#declare L3Texture320_slope = L3TextureSlope(L3Texture320)
#end
#ifndef (L3Color320)
#declare L3Color320 = L3Material(L3Texture320)
#end
#ifndef (L3Color320_slope)
#declare L3Color320_slope = L3Material(L3Texture320_slope)
#end


//// Color 321 Dark_Azure (from ldconfig.ldr)
#ifndef (L3Texture321)
#declare L3Texture321 = L3TextureOpaqueRGB(20,152,215)
#end
#ifndef (L3Texture321_slope)
#declare L3Texture321_slope = L3TextureSlope(L3Texture321)
#end
#ifndef (L3Color321)
#declare L3Color321 = L3Material(L3Texture321)
#end
#ifndef (L3Color321_slope)
#declare L3Color321_slope = L3Material(L3Texture321_slope)
#end


//// Color 322 Medium_Azure (from ldconfig.ldr)
#ifndef (L3Texture322)
#declare L3Texture322 = L3TextureOpaqueRGB(62,194,221)
#end
#ifndef (L3Texture322_slope)
#declare L3Texture322_slope = L3TextureSlope(L3Texture322)
#end
#ifndef (L3Color322)
#declare L3Color322 = L3Material(L3Texture322)
#end
#ifndef (L3Color322_slope)
#declare L3Color322_slope = L3Material(L3Texture322_slope)
#end


//// Color 323 Light_Aqua (from ldconfig.ldr)
#ifndef (L3Texture323)
#declare L3Texture323 = L3TextureOpaqueRGB(189,220,216)
#end
#ifndef (L3Texture323_slope)
#declare L3Texture323_slope = L3TextureSlope(L3Texture323)
#end
#ifndef (L3Color323)
#declare L3Color323 = L3Material(L3Texture323)
#end
#ifndef (L3Color323_slope)
#declare L3Color323_slope = L3Material(L3Texture323_slope)
#end


//// Color 324 Rubber_Red (from ldconfig.ldr)
#ifndef (L3Texture324)
#declare L3Texture324 = L3TextureRubberRGB(196,0,38)
#end
#ifndef (L3Texture324_slope)
#declare L3Texture324_slope = L3TextureSlope(L3Texture324)
#end
#ifndef (L3Color324)
#declare L3Color324 = L3Material(L3Texture324)
#end
#ifndef (L3Color324_slope)
#declare L3Color324_slope = L3Material(L3Texture324_slope)
#end


//// Color 326 Yellowish_Green (from ldconfig.ldr)
#ifndef (L3Texture326)
#declare L3Texture326 = L3TextureOpaqueRGB(223,238,165)
#end
#ifndef (L3Texture326_slope)
#declare L3Texture326_slope = L3TextureSlope(L3Texture326)
#end
#ifndef (L3Color326)
#declare L3Color326 = L3Material(L3Texture326)
#end
#ifndef (L3Color326_slope)
#declare L3Color326_slope = L3Material(L3Texture326_slope)
#end


//// Color 329 Glow_In_Dark_White (from ldconfig.ldr)
#ifndef (L3Texture329)
#declare L3Texture329 = L3TextureOtherRGBFAL(245,243,215,0,240,15)
#end
#ifndef (L3Texture329_slope)
#declare L3Texture329_slope = L3TextureSlope(L3Texture329)
#end
#ifndef (L3Color329)
#declare L3Color329 = L3MaterialT(L3Texture329)
#end
#ifndef (L3Color329_slope)
#declare L3Color329_slope = L3MaterialT(L3Texture329_slope)
#end


//// Color 330 Olive_Green (from ldconfig.ldr)
#ifndef (L3Texture330)
#declare L3Texture330 = L3TextureOpaqueRGB(155,154,90)
#end
#ifndef (L3Texture330_slope)
#declare L3Texture330_slope = L3TextureSlope(L3Texture330)
#end
#ifndef (L3Color330)
#declare L3Color330 = L3Material(L3Texture330)
#end
#ifndef (L3Color330_slope)
#declare L3Color330_slope = L3Material(L3Texture330_slope)
#end


//// Color 334 Chrome_Gold (from ldconfig.ldr)
#ifndef (L3Texture334)
#declare L3Texture334 = L3TextureChromeRGB(187,165,61)
#end
#ifndef (L3Texture334_slope)
#declare L3Texture334_slope = L3TextureSlope(L3Texture334)
#end
#ifndef (L3Color334)
#declare L3Color334 = L3Material(L3Texture334)
#end
#ifndef (L3Color334_slope)
#declare L3Color334_slope = L3Material(L3Texture334_slope)
#end


//// Color 335 Sand_Red (from ldconfig.ldr)
#ifndef (L3Texture335)
#declare L3Texture335 = L3TextureOpaqueRGB(214,117,114)
#end
#ifndef (L3Texture335_slope)
#declare L3Texture335_slope = L3TextureSlope(L3Texture335)
#end
#ifndef (L3Color335)
#declare L3Color335 = L3Material(L3Texture335)
#end
#ifndef (L3Color335_slope)
#declare L3Color335_slope = L3Material(L3Texture335_slope)
#end


//// Color 339 Glitter_Trans_Neon_Green (from ldconfig.ldr)
#ifndef (L3Texture339)
#declare L3Texture339 = L3TextureTransparentRGBA(192,255,0,128)
#end
#ifndef (L3Texture339_slope)
#declare L3Texture339_slope = L3TextureSlope(L3Texture339)
#end
#ifndef (L3Color339)
#declare L3Color339 = L3MaterialT(L3Texture339)
#end
#ifndef (L3Color339_slope)
#declare L3Color339_slope = L3MaterialT(L3Texture339_slope)
#end


//// Color 350 Rubber_Orange (from ldconfig.ldr)
#ifndef (L3Texture350)
#declare L3Texture350 = L3TextureRubberRGB(208,102,16)
#end
#ifndef (L3Texture350_slope)
#declare L3Texture350_slope = L3TextureSlope(L3Texture350)
#end
#ifndef (L3Color350)
#declare L3Color350 = L3Material(L3Texture350)
#end
#ifndef (L3Color350_slope)
#declare L3Color350_slope = L3Material(L3Texture350_slope)
#end


//// Color 351 Medium_Dark_Pink (from ldconfig.ldr)
#ifndef (L3Texture351)
#declare L3Texture351 = L3TextureOpaqueRGB(247,133,177)
#end
#ifndef (L3Texture351_slope)
#declare L3Texture351_slope = L3TextureSlope(L3Texture351)
#end
#ifndef (L3Color351)
#declare L3Color351 = L3Material(L3Texture351)
#end
#ifndef (L3Color351_slope)
#declare L3Color351_slope = L3Material(L3Texture351_slope)
#end


//// Color 366 Earth_Orange (from ldconfig.ldr)
#ifndef (L3Texture366)
#declare L3Texture366 = L3TextureOpaqueRGB(250,156,28)
#end
#ifndef (L3Texture366_slope)
#declare L3Texture366_slope = L3TextureSlope(L3Texture366)
#end
#ifndef (L3Color366)
#declare L3Color366 = L3Material(L3Texture366)
#end
#ifndef (L3Color366_slope)
#declare L3Color366_slope = L3Material(L3Texture366_slope)
#end


//// Color 373 Sand_Purple (from ldconfig.ldr)
#ifndef (L3Texture373)
#declare L3Texture373 = L3TextureOpaqueRGB(132,94,132)
#end
#ifndef (L3Texture373_slope)
#declare L3Texture373_slope = L3TextureSlope(L3Texture373)
#end
#ifndef (L3Color373)
#declare L3Color373 = L3Material(L3Texture373)
#end
#ifndef (L3Color373_slope)
#declare L3Color373_slope = L3Material(L3Texture373_slope)
#end


//// Color 375 Rubber_Light_Grey (from ldconfig.ldr)
#ifndef (L3Texture375)
#declare L3Texture375 = L3TextureRubberRGB(193,194,193)
#end
#ifndef (L3Texture375_slope)
#declare L3Texture375_slope = L3TextureSlope(L3Texture375)
#end
#ifndef (L3Color375)
#declare L3Color375 = L3Material(L3Texture375)
#end
#ifndef (L3Color375_slope)
#declare L3Color375_slope = L3Material(L3Texture375_slope)
#end


//// Color 378 Sand_Green (from ldconfig.ldr)
#ifndef (L3Texture378)
#declare L3Texture378 = L3TextureOpaqueRGB(160,188,172)
#end
#ifndef (L3Texture378_slope)
#declare L3Texture378_slope = L3TextureSlope(L3Texture378)
#end
#ifndef (L3Color378)
#declare L3Color378 = L3Material(L3Texture378)
#end
#ifndef (L3Color378_slope)
#declare L3Color378_slope = L3Material(L3Texture378_slope)
#end


//// Color 379 Sand_Blue (from ldconfig.ldr)
#ifndef (L3Texture379)
#declare L3Texture379 = L3TextureOpaqueRGB(89,113,132)
#end
#ifndef (L3Texture379_slope)
#declare L3Texture379_slope = L3TextureSlope(L3Texture379)
#end
#ifndef (L3Color379)
#declare L3Color379 = L3Material(L3Texture379)
#end
#ifndef (L3Color379_slope)
#declare L3Color379_slope = L3Material(L3Texture379_slope)
#end


//// Color 383 Chrome_Silver (from ldconfig.ldr)
#ifndef (L3Texture383)
#declare L3Texture383 = L3TextureChromeRGB(224,224,224)
#end
#ifndef (L3Texture383_slope)
#declare L3Texture383_slope = L3TextureSlope(L3Texture383)
#end
#ifndef (L3Color383)
#declare L3Color383 = L3Material(L3Texture383)
#end
#ifndef (L3Color383_slope)
#declare L3Color383_slope = L3Material(L3Texture383_slope)
#end


//// Color 406 Rubber_Dark_Blue (from ldconfig.ldr)
#ifndef (L3Texture406)
#declare L3Texture406 = L3TextureRubberRGB(0,29,104)
#end
#ifndef (L3Texture406_slope)
#declare L3Texture406_slope = L3TextureSlope(L3Texture406)
#end
#ifndef (L3Color406)
#declare L3Color406 = L3Material(L3Texture406)
#end
#ifndef (L3Color406_slope)
#declare L3Color406_slope = L3Material(L3Texture406_slope)
#end


//// Color 449 Rubber_Purple (from ldconfig.ldr)
#ifndef (L3Texture449)
#declare L3Texture449 = L3TextureRubberRGB(129,0,123)
#end
#ifndef (L3Texture449_slope)
#declare L3Texture449_slope = L3TextureSlope(L3Texture449)
#end
#ifndef (L3Color449)
#declare L3Color449 = L3Material(L3Texture449)
#end
#ifndef (L3Color449_slope)
#declare L3Color449_slope = L3Material(L3Texture449_slope)
#end


//// Color 450 Fabuland_Brown (from ldconfig.ldr)
#ifndef (L3Texture450)
#declare L3Texture450 = L3TextureOpaqueRGB(182,123,80)
#end
#ifndef (L3Texture450_slope)
#declare L3Texture450_slope = L3TextureSlope(L3Texture450)
#end
#ifndef (L3Color450)
#declare L3Color450 = L3Material(L3Texture450)
#end
#ifndef (L3Color450_slope)
#declare L3Color450_slope = L3Material(L3Texture450_slope)
#end


//// Color 462 Medium_Orange (from ldconfig.ldr)
#ifndef (L3Texture462)
#declare L3Texture462 = L3TextureOpaqueRGB(255,167,11)
#end
#ifndef (L3Texture462_slope)
#declare L3Texture462_slope = L3TextureSlope(L3Texture462)
#end
#ifndef (L3Color462)
#declare L3Color462 = L3Material(L3Texture462)
#end
#ifndef (L3Color462_slope)
#declare L3Color462_slope = L3Material(L3Texture462_slope)
#end


//// Color 484 Dark_Orange (from ldconfig.ldr)
#ifndef (L3Texture484)
#declare L3Texture484 = L3TextureOpaqueRGB(169,85,0)
#end
#ifndef (L3Texture484_slope)
#declare L3Texture484_slope = L3TextureSlope(L3Texture484)
#end
#ifndef (L3Color484)
#declare L3Color484 = L3Material(L3Texture484)
#end
#ifndef (L3Color484_slope)
#declare L3Color484_slope = L3Material(L3Texture484_slope)
#end


//// Color 490 Rubber_Lime (from ldconfig.ldr)
#ifndef (L3Texture490)
#declare L3Texture490 = L3TextureRubberRGB(215,240,0)
#end
#ifndef (L3Texture490_slope)
#declare L3Texture490_slope = L3TextureSlope(L3Texture490)
#end
#ifndef (L3Color490)
#declare L3Color490 = L3Material(L3Texture490)
#end
#ifndef (L3Color490_slope)
#declare L3Color490_slope = L3Material(L3Texture490_slope)
#end


//// Color 493 Magnet (from ldconfig.ldr)
#ifndef (L3Texture493)
#declare L3Texture493 = L3TextureMetalRGB(101,103,97)
#end
#ifndef (L3Texture493_slope)
#declare L3Texture493_slope = L3TextureSlope(L3Texture493)
#end
#ifndef (L3Color493)
#declare L3Color493 = L3Material(L3Texture493)
#end
#ifndef (L3Color493_slope)
#declare L3Color493_slope = L3Material(L3Texture493_slope)
#end


//// Color 494 Electric_Contact_Alloy (from ldconfig.ldr)
#ifndef (L3Texture494)
#declare L3Texture494 = L3TextureMetalRGB(208,208,208)
#end
#ifndef (L3Texture494_slope)
#declare L3Texture494_slope = L3TextureSlope(L3Texture494)
#end
#ifndef (L3Color494)
#declare L3Color494 = L3Material(L3Texture494)
#end
#ifndef (L3Color494_slope)
#declare L3Color494_slope = L3Material(L3Texture494_slope)
#end


//// Color 495 Electric_Contact_Copper (from ldconfig.ldr)
#ifndef (L3Texture495)
#declare L3Texture495 = L3TextureMetalRGB(174,122,89)
#end
#ifndef (L3Texture495_slope)
#declare L3Texture495_slope = L3TextureSlope(L3Texture495)
#end
#ifndef (L3Color495)
#declare L3Color495 = L3Material(L3Texture495)
#end
#ifndef (L3Color495_slope)
#declare L3Color495_slope = L3Material(L3Texture495_slope)
#end


//// Color 496 Rubber_Light_Bluish_Grey (from ldconfig.ldr)
#ifndef (L3Texture496)
#declare L3Texture496 = L3TextureRubberRGB(163,162,164)
#end
#ifndef (L3Texture496_slope)
#declare L3Texture496_slope = L3TextureSlope(L3Texture496)
#end
#ifndef (L3Color496)
#declare L3Color496 = L3Material(L3Texture496)
#end
#ifndef (L3Color496_slope)
#declare L3Color496_slope = L3Material(L3Texture496_slope)
#end


//// Color 503 Very_Light_Grey (from ldconfig.ldr)
#ifndef (L3Texture503)
#declare L3Texture503 = L3TextureOpaqueRGB(230,227,218)
#end
#ifndef (L3Texture503_slope)
#declare L3Texture503_slope = L3TextureSlope(L3Texture503)
#end
#ifndef (L3Color503)
#declare L3Color503 = L3Material(L3Texture503)
#end
#ifndef (L3Color503_slope)
#declare L3Color503_slope = L3Material(L3Texture503_slope)
#end


//// Color 504 Rubber_Flat_Silver (from ldconfig.ldr)
#ifndef (L3Texture504)
#declare L3Texture504 = L3TextureRubberRGB(137,135,136)
#end
#ifndef (L3Texture504_slope)
#declare L3Texture504_slope = L3TextureSlope(L3Texture504)
#end
#ifndef (L3Color504)
#declare L3Color504 = L3Material(L3Texture504)
#end
#ifndef (L3Color504_slope)
#declare L3Color504_slope = L3Material(L3Texture504_slope)
#end


//// Color 511 Rubber_White (from ldconfig.ldr)
#ifndef (L3Texture511)
#declare L3Texture511 = L3TextureRubberRGB(250,250,250)
#end
#ifndef (L3Texture511_slope)
#declare L3Texture511_slope = L3TextureSlope(L3Texture511)
#end
#ifndef (L3Color511)
#declare L3Color511 = L3Material(L3Texture511)
#end
#ifndef (L3Color511_slope)
#declare L3Color511_slope = L3Material(L3Texture511_slope)
#end
