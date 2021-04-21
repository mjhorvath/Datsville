// Deafult LDView output when LGEO parts are used.
// Some materials need to be updated for assumed_gamma changes.
// +am3 +r9 +a0.002 +ac0.99
// +am = sampling method
// +r = antialias depth
// +a = antialias threshold
// +ac = ???

#version 3.7;

#include "lg_color.inc"


#ifndef (LDXColor0) // Black
#declare LDXColor0 = #if (version >= 3.1) material { #end
	texture {
		lg_black
	}
#if (version >= 3.1) } #end
#declare LDXColor0_slope = #if (version >= 3.1) material { #end
	texture {
		lg_black
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor1) // Blue
#declare LDXColor1 = #if (version >= 3.1) material { #end
	texture {
		lg_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor1_slope = #if (version >= 3.1) material { #end
	texture {
		lg_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor2) // Green
#declare LDXColor2 = #if (version >= 3.1) material { #end
	texture {
		lg_green
	}
#if (version >= 3.1) } #end
#declare LDXColor2_slope = #if (version >= 3.1) material { #end
	texture {
		lg_green
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor3) // Dark Turquoise
#declare LDXColor3 = #if (version >= 3.1) material { #end
	texture {
		lg_cyan
	}
#if (version >= 3.1) } #end
#declare LDXColor3_slope = #if (version >= 3.1) material { #end
	texture {
		lg_cyan
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor4) // Red
#declare LDXColor4 = #if (version >= 3.1) material { #end
	texture {
		lg_red
	}
#if (version >= 3.1) } #end
#declare LDXColor4_slope = #if (version >= 3.1) material { #end
	texture {
		lg_red
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor5) // Dark Pink
#declare LDXColor5 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_pink
	}
#if (version >= 3.1) } #end
#declare LDXColor5_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_pink
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor6) // Brown
#declare LDXColor6 = #if (version >= 3.1) material { #end
	texture {
		lg_brown
	}
#if (version >= 3.1) } #end
#declare LDXColor6_slope = #if (version >= 3.1) material { #end
	texture {
		lg_brown
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor7) // Light Grey
#declare LDXColor7 = #if (version >= 3.1) material { #end
	texture {
		lg_grey
	}
#if (version >= 3.1) } #end
#declare LDXColor7_slope = #if (version >= 3.1) material { #end
	texture {
		lg_grey
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor8) // Dark Grey
#declare LDXColor8 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_grey
	}
#if (version >= 3.1) } #end
#declare LDXColor8_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_grey
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor9) // Light Blue
#declare LDXColor9 = #if (version >= 3.1) material { #end
	texture {
		lg_light_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor9_slope = #if (version >= 3.1) material { #end
	texture {
		lg_light_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor10) // Bright Green
#declare LDXColor10 = #if (version >= 3.1) material { #end
	texture {
		lg_bright_green
	}
#if (version >= 3.1) } #end
#declare LDXColor10_slope = #if (version >= 3.1) material { #end
	texture {
		lg_bright_green
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor11) // Light Turquoise
#declare LDXColor11 = #if (version >= 3.1) material { #end
	texture {
		lg_turquoise
	}
#if (version >= 3.1) } #end
#declare LDXColor11_slope = #if (version >= 3.1) material { #end
	texture {
		lg_turquoise
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor12) // Salmon
#declare LDXColor12 = #if (version >= 3.1) material { #end
	texture {
		lg_salmon
	}
#if (version >= 3.1) } #end
#declare LDXColor12_slope = #if (version >= 3.1) material { #end
	texture {
		lg_salmon
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor13) // Pink
#declare LDXColor13 = #if (version >= 3.1) material { #end
	texture {
		lg_pink
	}
#if (version >= 3.1) } #end
#declare LDXColor13_slope = #if (version >= 3.1) material { #end
	texture {
		lg_pink
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor14) // Yellow
#declare LDXColor14 = #if (version >= 3.1) material { #end
	texture {
		lg_yellow
	}
#if (version >= 3.1) } #end
#declare LDXColor14_slope = #if (version >= 3.1) material { #end
	texture {
		lg_yellow
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor15) // White
#declare LDXColor15 = #if (version >= 3.1) material { #end
	texture {
		lg_white
	}
#if (version >= 3.1) } #end
#declare LDXColor15_slope = #if (version >= 3.1) material { #end
	texture {
		lg_white
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor17) // Light Green
#declare LDXColor17 = #if (version >= 3.1) material { #end
	texture {
		lg_light_green
	}
#if (version >= 3.1) } #end
#declare LDXColor17_slope = #if (version >= 3.1) material { #end
	texture {
		lg_light_green
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor18) // Light Yellow
#declare LDXColor18 = #if (version >= 3.1) material { #end
	texture {
		lg_light_yellow
	}
#if (version >= 3.1) } #end
#declare LDXColor18_slope = #if (version >= 3.1) material { #end
	texture {
		lg_light_yellow
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor19) // Tan
#declare LDXColor19 = #if (version >= 3.1) material { #end
	texture {
		lg_tan
	}
#if (version >= 3.1) } #end
#declare LDXColor19_slope = #if (version >= 3.1) material { #end
	texture {
		lg_tan
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor20) // Light Violet
#declare LDXColor20 = #if (version >= 3.1) material { #end
	texture {
		lg_light_violet
	}
#if (version >= 3.1) } #end
#declare LDXColor20_slope = #if (version >= 3.1) material { #end
	texture {
		lg_light_violet
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor21) // Glow In Dark Opaque
#declare LDXColor21 = #if (version >= 3.1) material { #end
	texture {
		lg_glow_in_dark_opaque
	}
#if (version >= 3.1) } #end
#declare LDXColor21_slope = #if (version >= 3.1) material { #end
	texture {
		lg_glow_in_dark_opaque
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor22) // Purple
#declare LDXColor22 = #if (version >= 3.1) material { #end
	texture {
		lg_purple
	}
#if (version >= 3.1) } #end
#declare LDXColor22_slope = #if (version >= 3.1) material { #end
	texture {
		lg_purple
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor23) // Dark Blue Violet
#declare LDXColor23 = #if (version >= 3.1) material { #end
	texture {
		lg_violet_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor23_slope = #if (version >= 3.1) material { #end
	texture {
		lg_violet_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXSkipOpaqueColorMacro)
#macro LDXOpaqueColor(r, g, b)
#if (version >= 3.1) material { #end
	texture {
#if (version >= 3.7)
		pigment { srgbf <r,g,b,0> }
#else
		pigment { rgbf <r,g,b,0> }
#end
#if (LDXQual > 1)
		finish { ambient LDXAmb diffuse LDXDif }
		finish { phong LDXPhong phong_size LDXPhongS reflection LDXRefl }
		normal { LDXOpaqueNormal }
#end
	}
#if (version >= 3.1) } #end
#end
#end

#ifndef (LDXColor24) // Edge Colour
#declare LDXColor24 = LDXOpaqueColor(0.498039,0.498039,0.498039)
#end

#ifndef (LDXColor25) // Orange
#declare LDXColor25 = #if (version >= 3.1) material { #end
	texture {
		lg_orange
	}
#if (version >= 3.1) } #end
#declare LDXColor25_slope = #if (version >= 3.1) material { #end
	texture {
		lg_orange
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor26) // Magenta
#declare LDXColor26 = #if (version >= 3.1) material { #end
	texture {
		lg_magenta
	}
#if (version >= 3.1) } #end
#declare LDXColor26_slope = #if (version >= 3.1) material { #end
	texture {
		lg_magenta
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor27) // Lime
#declare LDXColor27 = #if (version >= 3.1) material { #end
	texture {
		lg_lime
	}
#if (version >= 3.1) } #end
#declare LDXColor27_slope = #if (version >= 3.1) material { #end
	texture {
		lg_lime
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor28) // Dark Tan
#declare LDXColor28 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_tan
	}
#if (version >= 3.1) } #end
#declare LDXColor28_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_tan
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor29) // Bright Pink
#declare LDXColor29 = #if (version >= 3.1) material { #end
	texture {
		lg_light_purple
	}
#if (version >= 3.1) } #end
#declare LDXColor29_slope = #if (version >= 3.1) material { #end
	texture {
		lg_light_purple
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor30) // Medium Lavender
#declare LDXColor30 = #if (version >= 3.1) material { #end
	texture {
		lg_medium_lavender
	}
#if (version >= 3.1) } #end
#declare LDXColor30_slope = #if (version >= 3.1) material { #end
	texture {
		lg_medium_lavender
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor31) // Lavender
#declare LDXColor31 = #if (version >= 3.1) material { #end
	texture {
		lg_lavender
	}
#if (version >= 3.1) } #end
#declare LDXColor31_slope = #if (version >= 3.1) material { #end
	texture {
		lg_lavender
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor32) // Trans Black IR Lens
#declare LDXColor32 = #if (version >= 3.1) material { #end
	texture {
		lg_black_ir
	}
#if (version >= 3.1) } #end
#declare LDXColor32_slope = #if (version >= 3.1) material { #end
	texture {
		lg_black_ir
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor33) // Trans Dark Blue
#declare LDXColor33 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor33_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor34) // Trans Green
#declare LDXColor34 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_green
	}
#if (version >= 3.1) } #end
#declare LDXColor34_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_green
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor35) // Trans Bright Green
#declare LDXColor35 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_bright_green
	}
#if (version >= 3.1) } #end
#declare LDXColor35_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_bright_green
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor36) // Trans Red
#declare LDXColor36 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_red
	}
#if (version >= 3.1) } #end
#declare LDXColor36_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_red
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor37) // Trans Dark Pink
#declare LDXColor37 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_pink
	}
#if (version >= 3.1) } #end
#declare LDXColor37_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_pink
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor38) // Trans Neon Orange
#declare LDXColor38 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_neon_orange
	}
#if (version >= 3.1) } #end
#declare LDXColor38_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_neon_orange
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXSkipTransColorMacro)
#macro LDXTransColor(r, g, b)
#if (version >= 3.1) material { #end
	texture {
#if (version >= 3.7)
		pigment { #if (LDXQual > 1) srgbf <r,g,b,LDXTFilt> #else srgbf <0.6,0.6,0.6,0> #end }
#else
		pigment { #if (LDXQual > 1) rgbf <r,g,b,LDXTFilt> #else rgbf <0.6,0.6,0.6,0> #end }
#end
#if (LDXQual > 1)
		finish { ambient LDXAmb diffuse LDXDif }
		finish { phong LDXPhong phong_size LDXPhongS reflection LDXTRefl }
		normal { LDXTransNormal }
		#if (version >= 3.1) #else finish { refraction 1 ior LDXIoR } #end
#end
	}
#if (version >= 3.1) #if (LDXQual > 1)
	interior { ior LDXIoR }
#end #end
#if (version >= 3.1) } #end
#end
#end

#ifndef (LDXColor39) // Trans Very Light Blue
#declare LDXColor39 = LDXTransColor(0.975686,0.987451,0.994118)
#end

#ifndef (LDXColor40) // Trans Black
#declare LDXColor40 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_brown
	}
#if (version >= 3.1) } #end
#declare LDXColor40_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_brown
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor41) // Trans Medium Blue
#declare LDXColor41 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_cyan
	}
#if (version >= 3.1) } #end
#declare LDXColor41_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_cyan
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor42) // Trans Neon Green
#declare LDXColor42 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_neon_yellow
	}
#if (version >= 3.1) } #end
#declare LDXColor42_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_neon_yellow
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor43) // Trans Light Blue
#declare LDXColor43 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_light_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor43_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_light_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor44) // Trans Bright Reddish Lilac
#declare LDXColor44 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_light_purple
	}
#if (version >= 3.1) } #end
#declare LDXColor44_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_light_purple
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor45) // Trans Pink
#declare LDXColor45 = LDXTransColor(0.998824,0.959216,0.967451)
#end

#ifndef (LDXColor46) // Trans Yellow
#declare LDXColor46 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_yellow
	}
#if (version >= 3.1) } #end
#declare LDXColor46_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_yellow
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor47) // Trans Clear
#declare LDXColor47 = #if (version >= 3.1) material { #end
	texture {
		lg_clear
	}
#if (version >= 3.1) } #end
#declare LDXColor47_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor52) // Trans Purple
#declare LDXColor52 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_violet
	}
#if (version >= 3.1) } #end
#declare LDXColor52_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_violet
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor54) // Trans Neon Yellow
#declare LDXColor54 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_neon_yellow
	}
#if (version >= 3.1) } #end
#declare LDXColor54_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_neon_yellow
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor57) // Trans Orange
#declare LDXColor57 = #if (version >= 3.1) material { #end
	texture {
		lg_clear_neon_orange
	}
#if (version >= 3.1) } #end
#declare LDXColor57_slope = #if (version >= 3.1) material { #end
	texture {
		lg_clear_neon_orange
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXSkipChromeColorMacro)
#macro LDXChromeColor(r, g, b)
#if (version >= 3.1) material { #end
	texture {
#if (version >= 3.7)
		pigment { srgbf <r,g,b,0> }
#else
		pigment { rgbf <r,g,b,0> }
#end
#if (LDXQual > 1)
		finish { ambient LDXAmb diffuse LDXDif }
		finish { phong LDXPhong phong_size LDXPhongS reflection LDXChromeRefl brilliance LDXChromeBril metallic specular LDXChromeSpec roughness LDXChromeRough}
#end
	}
#if (version >= 3.1) } #end
#end
#end

#ifndef (LDXColor60) // Chrome Antique Brass
#declare LDXColor60 = LDXChromeColor(0.392157,0.352941,0.298039)
#end

#ifndef (LDXColor61) // Chrome Blue
#declare LDXColor61 = LDXChromeColor(0.423529,0.588235,0.74902)
#end

#ifndef (LDXColor62) // Chrome Green
#declare LDXColor62 = LDXChromeColor(0.235294,0.701961,0.443137)
#end

#ifndef (LDXColor63) // Chrome Pink
#declare LDXColor63 = LDXChromeColor(0.666667,0.301961,0.556863)
#end

#ifndef (LDXColor64) // Chrome Black
#declare LDXColor64 = LDXChromeColor(0.105882,0.164706,0.203922)
#end

#ifndef (LDXColor65) // Rubber Yellow
#declare LDXColor65 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_yellow
	}
#if (version >= 3.1) } #end
#declare LDXColor65_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_yellow
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor66) // Rubber Trans Yellow
#declare LDXColor66 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_clear_yellow
	}
#if (version >= 3.1) } #end
#declare LDXColor66_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_clear_yellow
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor67) // Rubber Trans Clear
#declare LDXColor67 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_clear
	}
#if (version >= 3.1) } #end
#declare LDXColor67_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_clear
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor68) // Very Light Orange
#declare LDXColor68 = #if (version >= 3.1) material { #end
	texture {
		lg_very_light_orange
	}
#if (version >= 3.1) } #end
#declare LDXColor68_slope = #if (version >= 3.1) material { #end
	texture {
		lg_very_light_orange
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor69) // Bright Reddish Lilac
#declare LDXColor69 = #if (version >= 3.1) material { #end
	texture {
		lg_bright_purple
	}
#if (version >= 3.1) } #end
#declare LDXColor69_slope = #if (version >= 3.1) material { #end
	texture {
		lg_bright_purple
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor70) // Reddish Brown
#declare LDXColor70 = #if (version >= 3.1) material { #end
	texture {
		lg_reddish_brown
	}
#if (version >= 3.1) } #end
#declare LDXColor70_slope = #if (version >= 3.1) material { #end
	texture {
		lg_reddish_brown
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor71) // Light Bluish Grey
#declare LDXColor71 = #if (version >= 3.1) material { #end
	texture {
		lg_bluish_grey
	}
#if (version >= 3.1) } #end
#declare LDXColor71_slope = #if (version >= 3.1) material { #end
	texture {
		lg_bluish_grey
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor72) // Dark Bluish Grey
#declare LDXColor72 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_bluish_grey
	}
#if (version >= 3.1) } #end
#declare LDXColor72_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_bluish_grey
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor73) // Medium Blue
#declare LDXColor73 = #if (version >= 3.1) material { #end
	texture {
		lg_medium_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor73_slope = #if (version >= 3.1) material { #end
	texture {
		lg_medium_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor74) // Medium Green
#declare LDXColor74 = #if (version >= 3.1) material { #end
	texture {
		lg_medium_green
	}
#if (version >= 3.1) } #end
#declare LDXColor74_slope = #if (version >= 3.1) material { #end
	texture {
		lg_medium_green
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor75) // Speckle Black Copper
#declare LDXColor75 = LDXOpaqueColor(0,0,0)
#end

#ifndef (LDXColor76) // Speckle Dark Bluish Grey Silver
#declare LDXColor76 = LDXOpaqueColor(0.388235,0.372549,0.380392)
#end

#ifndef (LDXColor77) // Light Pink
#declare LDXColor77 = #if (version >= 3.1) material { #end
	texture {
		lg_paradisa_pink
	}
#if (version >= 3.1) } #end
#declare LDXColor77_slope = #if (version >= 3.1) material { #end
	texture {
		lg_paradisa_pink
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor78) // Light Flesh
#declare LDXColor78 = #if (version >= 3.1) material { #end
	texture {
		lg_light_flesh
	}
#if (version >= 3.1) } #end
#declare LDXColor78_slope = #if (version >= 3.1) material { #end
	texture {
		lg_light_flesh
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor79) // Milky White
#declare LDXColor79 = #if (version >= 3.1) material { #end
	texture {
		lg_milky_white
	}
#if (version >= 3.1) } #end
#declare LDXColor79_slope = #if (version >= 3.1) material { #end
	texture {
		lg_milky_white
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor80) // Metallic Silver
#declare LDXColor80 = #if (version >= 3.1) material { #end
	texture {
		lg_metallic_silver
	}
#if (version >= 3.1) } #end
#declare LDXColor80_slope = #if (version >= 3.1) material { #end
	texture {
		lg_metallic_silver
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor81) // Metallic Green
#declare LDXColor81 = LDXOpaqueColor(0.537255,0.607843,0.372549)
#end

#ifndef (LDXColor82) // Metallic Gold
#declare LDXColor82 = #if (version >= 3.1) material { #end
	texture {
		lg_metallic_gold
	}
#if (version >= 3.1) } #end
#declare LDXColor82_slope = #if (version >= 3.1) material { #end
	texture {
		lg_metallic_gold
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor83) // Metallic Black
#declare LDXColor83 = LDXOpaqueColor(0.101961,0.156863,0.192157)
#end

#ifndef (LDXColor84) // Medium Dark Flesh
#declare LDXColor84 = #if (version >= 3.1) material { #end
	texture {
		lg_medium_dark_flesh
	}
#if (version >= 3.1) } #end
#declare LDXColor84_slope = #if (version >= 3.1) material { #end
	texture {
		lg_medium_dark_flesh
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor85) // Medium Lilac
#declare LDXColor85 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_purple
	}
#if (version >= 3.1) } #end
#declare LDXColor85_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_purple
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor86) // Dark Flesh
#declare LDXColor86 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_flesh
	}
#if (version >= 3.1) } #end
#declare LDXColor86_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_flesh
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor87) // Metallic Dark Grey
#declare LDXColor87 = LDXOpaqueColor(0.427451,0.431373,0.360784)
#end

#ifndef (LDXColor89) // Blue Violet
#declare LDXColor89 = #if (version >= 3.1) material { #end
	texture {
		lg_royal_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor89_slope = #if (version >= 3.1) material { #end
	texture {
		lg_royal_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor92) // Flesh
#declare LDXColor92 = #if (version >= 3.1) material { #end
	texture {
		lg_flesh
	}
#if (version >= 3.1) } #end
#declare LDXColor92_slope = #if (version >= 3.1) material { #end
	texture {
		lg_flesh
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor100) // Light Salmon
#declare LDXColor100 = #if (version >= 3.1) material { #end
	texture {
		lg_light_salmon
	}
#if (version >= 3.1) } #end
#declare LDXColor100_slope = #if (version >= 3.1) material { #end
	texture {
		lg_light_salmon
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor110) // Violet
#declare LDXColor110 = LDXOpaqueColor(0.262745,0.329412,0.639216)
#end

#ifndef (LDXColor112) // Medium Violet
#declare LDXColor112 = #if (version >= 3.1) material { #end
	texture {
		lg_medium_violet
	}
#if (version >= 3.1) } #end
#declare LDXColor112_slope = #if (version >= 3.1) material { #end
	texture {
		lg_medium_violet
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor114) // Glitter Trans Dark Pink
#declare LDXColor114 = LDXTransColor(0.987451,0.6,0.958431)
#end

#ifndef (LDXColor115) // Medium Lime
#declare LDXColor115 = #if (version >= 3.1) material { #end
	texture {
		lg_medium_lime
	}
#if (version >= 3.1) } #end
#declare LDXColor115_slope = #if (version >= 3.1) material { #end
	texture {
		lg_medium_lime
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor117) // Glitter Trans Clear
#declare LDXColor117 = LDXTransColor(1,1,1)
#end

#ifndef (LDXColor118) // Aqua
#declare LDXColor118 = LDXOpaqueColor(0.701961,0.843137,0.819608)
#end

#ifndef (LDXColor120) // Light Lime
#declare LDXColor120 = LDXOpaqueColor(0.85098,0.894118,0.654902)
#end

#ifndef (LDXColor125) // Light Orange
#declare LDXColor125 = LDXOpaqueColor(0.976471,0.729412,0.380392)
#end

#ifndef (LDXColor128) // Dark Nougat
#declare LDXColor128 = LDXOpaqueColor(0.678431,0.380392,0.25098)
#end

#ifndef (LDXColor129) // Glitter Trans Purple
#declare LDXColor129 = LDXTransColor(0.588235,0,0.570588)
#end

#ifndef (LDXColor132) // Speckle Black Silver
#declare LDXColor132 = LDXOpaqueColor(0,0,0)
#end

#ifndef (LDXColor133) // Speckle Black Gold
#declare LDXColor133 = LDXOpaqueColor(0,0,0)
#end

#ifndef (LDXColor134) // Copper
#declare LDXColor134 = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_copper
	}
#if (version >= 3.1) } #end
#declare LDXColor134_slope = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_copper
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor135) // Pearl Light Grey
#declare LDXColor135 = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_grey
	}
#if (version >= 3.1) } #end
#declare LDXColor135_slope = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_grey
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor137) // Metal Blue
#declare LDXColor137 = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor137_slope = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor142) // Pearl Light Gold
#declare LDXColor142 = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_gold
	}
#if (version >= 3.1) } #end
#declare LDXColor142_slope = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_gold
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor148) // Pearl Dark Grey
#declare LDXColor148 = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_dark_grey
	}
#if (version >= 3.1) } #end
#declare LDXColor148_slope = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_dark_grey
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor150) // Pearl Very Light Grey
#declare LDXColor150 = LDXOpaqueColor(0.733333,0.741176,0.737255)
#end

#ifndef (LDXColor151) // Very Light Bluish Grey
#declare LDXColor151 = #if (version >= 3.1) material { #end
	texture {
		lg_very_light_bluish_grey
	}
#if (version >= 3.1) } #end
#declare LDXColor151_slope = #if (version >= 3.1) material { #end
	texture {
		lg_very_light_bluish_grey
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor178) // Flat Dark Gold
#declare LDXColor178 = LDXOpaqueColor(0.705882,0.533333,0.243137)
#end

#ifndef (LDXColor179) // Flat Silver
#declare LDXColor179 = #if (version >= 3.1) material { #end
	texture {
		lg_flat_silver
	}
#if (version >= 3.1) } #end
#declare LDXColor179_slope = #if (version >= 3.1) material { #end
	texture {
		lg_flat_silver
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor183) // Pearl White
#declare LDXColor183 = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_white
	}
#if (version >= 3.1) } #end
#declare LDXColor183_slope = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_white
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor184) // Metallic Bright Red
#declare LDXColor184 = LDXOpaqueColor(0.839216,0,0.14902)
#end

#ifndef (LDXColor186) // Metallic Dark Green
#declare LDXColor186 = LDXOpaqueColor(0,0.556863,0.235294)
#end

#ifndef (LDXColor189) // Reddish Gold
#declare LDXColor189 = LDXOpaqueColor(0.67451,0.509804,0.278431)
#end

#ifndef (LDXColor191) // Bright Light Orange
#declare LDXColor191 = #if (version >= 3.1) material { #end
	texture {
		lg_bright_light_orange
	}
#if (version >= 3.1) } #end
#declare LDXColor191_slope = #if (version >= 3.1) material { #end
	texture {
		lg_bright_light_orange
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor212) // Bright Light Blue
#declare LDXColor212 = #if (version >= 3.1) material { #end
	texture {
		lg_bright_light_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor212_slope = #if (version >= 3.1) material { #end
	texture {
		lg_bright_light_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor216) // Rust
#declare LDXColor216 = #if (version >= 3.1) material { #end
	texture {
		lg_rust
	}
#if (version >= 3.1) } #end
#declare LDXColor216_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rust
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor218) // Reddish Lilac
#declare LDXColor218 = LDXOpaqueColor(0.556863,0.333333,0.592157)
#end

#ifndef (LDXColor219) // Lilac
#declare LDXColor219 = LDXOpaqueColor(0.337255,0.305882,0.615686)
#end

#ifndef (LDXColor226) // Bright Light Yellow
#declare LDXColor226 = #if (version >= 3.1) material { #end
	texture {
		lg_bright_light_yellow
	}
#if (version >= 3.1) } #end
#declare LDXColor226_slope = #if (version >= 3.1) material { #end
	texture {
		lg_bright_light_yellow
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor231) // Trans Bright Light Orange
#declare LDXColor231 = LDXTransColor(0.998824,0.971765,0.641176)
#end

#ifndef (LDXColor232) // Sky Blue
#declare LDXColor232 = #if (version >= 3.1) material { #end
	texture {
		lg_sky_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor232_slope = #if (version >= 3.1) material { #end
	texture {
		lg_sky_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor234) // Trans Fire Yellow
#declare LDXColor234 = LDXTransColor(0.998431,0.99098,0.956471)
#end

#ifndef (LDXColor256) // Rubber Black
#declare LDXColor256 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_black
	}
#if (version >= 3.1) } #end
#declare LDXColor256_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_black
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor272) // Dark Blue
#declare LDXColor272 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor272_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor273) // Rubber Blue
#declare LDXColor273 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor273_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor284) // Trans Reddish Lilac
#declare LDXColor284 = LDXTransColor(0.976078,0.950588,0.964706)
#end

#ifndef (LDXColor285) // Trans Light Green
#declare LDXColor285 = LDXTransColor(0.735294,0.976078,0.956863)
#end

#ifndef (LDXColor288) // Dark Green
#declare LDXColor288 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_green
	}
#if (version >= 3.1) } #end
#declare LDXColor288_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_green
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor293) // Trans Light Blue Violet
#declare LDXColor293 = LDXTransColor(0.629412,0.967059,0.989412)
#end

#ifndef (LDXColor294) // Glow In Dark Trans
#declare LDXColor294 = #if (version >= 3.1) material { #end
	texture {
		lg_glow_in_dark_clear
	}
#if (version >= 3.1) } #end
#declare LDXColor294_slope = #if (version >= 3.1) material { #end
	texture {
		lg_glow_in_dark_clear
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor295) // Flamingo Pink
#declare LDXColor295 = LDXOpaqueColor(1,0.580392,0.760784)
#end

#ifndef (LDXColor297) // Pearl Gold
#declare LDXColor297 = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_gold
	}
#if (version >= 3.1) } #end
#declare LDXColor297_slope = #if (version >= 3.1) material { #end
	texture {
		lg_pearl_gold
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor300) // Metallic Copper
#declare LDXColor300 = LDXOpaqueColor(0.760784,0.498039,0.32549)
#end

#ifndef (LDXColor302) // Glitter Trans Light Blue
#declare LDXColor302 = LDXTransColor(0.968235,0.991373,0.993725)
#end

#ifndef (LDXColor308) // Dark Brown
#declare LDXColor308 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_brown
	}
#if (version >= 3.1) } #end
#declare LDXColor308_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_brown
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor313) // Maersk Blue
#declare LDXColor313 = #if (version >= 3.1) material { #end
	texture {
		lg_maersk_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor313_slope = #if (version >= 3.1) material { #end
	texture {
		lg_maersk_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor320) // Dark Red
#declare LDXColor320 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_red
	}
#if (version >= 3.1) } #end
#declare LDXColor320_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_red
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor321) // Dark Azure
#declare LDXColor321 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_azur
	}
#if (version >= 3.1) } #end
#declare LDXColor321_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_azur
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor322) // Medium Azure
#declare LDXColor322 = #if (version >= 3.1) material { #end
	texture {
		lg_medium_azur
	}
#if (version >= 3.1) } #end
#declare LDXColor322_slope = #if (version >= 3.1) material { #end
	texture {
		lg_medium_azur
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor323) // Light Aqua
#declare LDXColor323 = #if (version >= 3.1) material { #end
	texture {
		lg_light_aqua
	}
#if (version >= 3.1) } #end
#declare LDXColor323_slope = #if (version >= 3.1) material { #end
	texture {
		lg_light_aqua
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor324) // Rubber Red
#declare LDXColor324 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_red
	}
#if (version >= 3.1) } #end
#declare LDXColor324_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_red
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor326) // Yellowish Green
#declare LDXColor326 = #if (version >= 3.1) material { #end
	texture {
		lg_spring_yellowish_green
	}
#if (version >= 3.1) } #end
#declare LDXColor326_slope = #if (version >= 3.1) material { #end
	texture {
		lg_spring_yellowish_green
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor329) // Glow In Dark White
#declare LDXColor329 = LDXTransColor(0.996078,0.995294,0.984314)
#end

#ifndef (LDXColor330) // Olive Green
#declare LDXColor330 = #if (version >= 3.1) material { #end
	texture {
		lg_olive_green
	}
#if (version >= 3.1) } #end
#declare LDXColor330_slope = #if (version >= 3.1) material { #end
	texture {
		lg_olive_green
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor334) // Chrome Gold
#declare LDXColor334 = #if (version >= 3.1) material { #end
	texture {
		lg_chrome_gold
	}
#if (version >= 3.1) } #end
#declare LDXColor334_slope = #if (version >= 3.1) material { #end
	texture {
		lg_chrome_gold
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor335) // Sand Red
#declare LDXColor335 = #if (version >= 3.1) material { #end
	texture {
		lg_sand_red
	}
#if (version >= 3.1) } #end
#declare LDXColor335_slope = #if (version >= 3.1) material { #end
	texture {
		lg_sand_red
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor339) // Glitter Trans Neon Green
#declare LDXColor339 = LDXTransColor(0.975294,1,0)
#end

#ifndef (LDXSkipRubberColorMacro)
#macro LDXRubberColor(r, g, b)
#if (version >= 3.1) material { #end
	texture {
#if (version >= 3.7)
		pigment { srgbf <r,g,b,0> }
#else
		pigment { rgbf <r,g,b,0> }
#end
#if (LDXQual > 1)
		finish { ambient LDXAmb diffuse LDXDif }
		finish { phong LDXRubberPhong phong_size LDXRubberPhongS reflection LDXRubberRefl }
#end
	}
#if (version >= 3.1) } #end
#end
#end

#ifndef (LDXColor350) // Rubber Orange
#declare LDXColor350 = LDXRubberColor(0.815686,0.4,0.062745)
#end

#ifndef (LDXColor351) // Medium Dark Pink
#declare LDXColor351 = LDXOpaqueColor(0.968627,0.521569,0.694118)
#end

#ifndef (LDXColor366) // Earth Orange
#declare LDXColor366 = #if (version >= 3.1) material { #end
	texture {
		lg_earth_orange
	}
#if (version >= 3.1) } #end
#declare LDXColor366_slope = #if (version >= 3.1) material { #end
	texture {
		lg_earth_orange
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor373) // Sand Purple
#declare LDXColor373 = #if (version >= 3.1) material { #end
	texture {
		lg_sand_purple
	}
#if (version >= 3.1) } #end
#declare LDXColor373_slope = #if (version >= 3.1) material { #end
	texture {
		lg_sand_purple
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor375) // Rubber Light Grey
#declare LDXColor375 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_light_gray
	}
#if (version >= 3.1) } #end
#declare LDXColor375_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_light_gray
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor378) // Sand Green
#declare LDXColor378 = #if (version >= 3.1) material { #end
	texture {
		lg_sand_green
	}
#if (version >= 3.1) } #end
#declare LDXColor378_slope = #if (version >= 3.1) material { #end
	texture {
		lg_sand_green
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor379) // Sand Blue
#declare LDXColor379 = #if (version >= 3.1) material { #end
	texture {
		lg_sand_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor379_slope = #if (version >= 3.1) material { #end
	texture {
		lg_sand_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor383) // Chrome Silver
#declare LDXColor383 = #if (version >= 3.1) material { #end
	texture {
		lg_chrome
	}
#if (version >= 3.1) } #end
#declare LDXColor383_slope = #if (version >= 3.1) material { #end
	texture {
		lg_chrome
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor406) // Rubber Dark Blue
#declare LDXColor406 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_dark_blue
	}
#if (version >= 3.1) } #end
#declare LDXColor406_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_dark_blue
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor449) // Rubber Purple
#declare LDXColor449 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_purple
	}
#if (version >= 3.1) } #end
#declare LDXColor449_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_purple
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor450) // Fabuland Brown
#declare LDXColor450 = #if (version >= 3.1) material { #end
	texture {
		lg_fabuland_brown
	}
#if (version >= 3.1) } #end
#declare LDXColor450_slope = #if (version >= 3.1) material { #end
	texture {
		lg_fabuland_brown
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor462) // Medium Orange
#declare LDXColor462 = #if (version >= 3.1) material { #end
	texture {
		lg_light_orange
	}
#if (version >= 3.1) } #end
#declare LDXColor462_slope = #if (version >= 3.1) material { #end
	texture {
		lg_light_orange
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor484) // Dark Orange
#declare LDXColor484 = #if (version >= 3.1) material { #end
	texture {
		lg_dark_orange
	}
#if (version >= 3.1) } #end
#declare LDXColor484_slope = #if (version >= 3.1) material { #end
	texture {
		lg_dark_orange
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor490) // Rubber Lime
#declare LDXColor490 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_lime
	}
#if (version >= 3.1) } #end
#declare LDXColor490_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_lime
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor493) // Magnet
#declare LDXColor493 = #if (version >= 3.1) material { #end
	texture {
		lg_magnet
	}
#if (version >= 3.1) } #end
#declare LDXColor493_slope = #if (version >= 3.1) material { #end
	texture {
		lg_magnet
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor494) // Electric Contact Alloy
#declare LDXColor494 = #if (version >= 3.1) material { #end
	texture {
		lg_electric_contact_alloy
	}
#if (version >= 3.1) } #end
#declare LDXColor494_slope = #if (version >= 3.1) material { #end
	texture {
		lg_electric_contact_alloy
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor495) // Electric Contact Copper
#declare LDXColor495 = LDXOpaqueColor(0.682353,0.478431,0.34902)
#end

#ifndef (LDXColor496) // Rubber Light Bluish Grey
#declare LDXColor496 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_light_bluish_gray
	}
#if (version >= 3.1) } #end
#declare LDXColor496_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_light_bluish_gray
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor503) // Very Light Grey
#declare LDXColor503 = #if (version >= 3.1) material { #end
	texture {
		lg_very_light_grey
	}
#if (version >= 3.1) } #end
#declare LDXColor503_slope = #if (version >= 3.1) material { #end
	texture {
		lg_very_light_grey
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor504) // Rubber Flat Silver
#declare LDXColor504 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_flat_silver
	}
#if (version >= 3.1) } #end
#declare LDXColor504_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_flat_silver
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end

#ifndef (LDXColor511) // Rubber White
#declare LDXColor511 = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_white
	}
#if (version >= 3.1) } #end
#declare LDXColor511_slope = #if (version >= 3.1) material { #end
	texture {
		lg_rubber_white
		#if (LDXQual > 1) normal { bumps 0.3 scale 25*0.02 } #end
	}
#if (version >= 3.1) } #end
#end
