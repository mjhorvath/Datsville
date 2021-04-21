// Default LDView output when LGEO parts are not used.
// Modified by Michael Horvath.
// Currently supports blurred reflections for some materials, but does not support SSLT at all.
// +am3 +r9 +a0.002 +ac0.99
// +am = sampling method
// +r = antialias depth
// +a = antialias threshold
// +ac = ???

#version 3.7;

#if (version >= 3.7) global_settings {assumed_gamma 1} #end

// All these values should really be tailored for each material type.
// Each material type needs to have an ior in order for SSLT to work.
// Pearl should have separate materials from opaque.
#declare LDXOpaqueSpecularity	= 1.0;
#declare LDXOpaqueRoughness		= 0.001;
#declare LDXOpaqueIor			= LDXIoR;
#declare LDXTransSpecularity	= 1.0;
#declare LDXTransRoughness		= 0.001;
#declare LDXTransIor			= LDXIoR;
#declare LDXChromeSpecularity	= 1.0;
#declare LDXChromeRoughness		= 0.001;
#declare LDXChromeIor			= LDXIoR;
#declare LDXPearlSpecularity	= 1.0;
#declare LDXPearlRoughness		= 0.001;
#declare LDXPearlIor			= LDXIoR;


#ifndef (LDXSkipOpaqueColorMacro)
#macro LDXOpaqueColor(r, g, b)
#if (version >= 3.7)
	#local texPigment = pigment { srgbf <r,g,b,0> }
#else
	#local texPigment = pigment { rgbf <r,g,b,0> }
#end
#if (version >= 3.1) material { #end
	texture {
#if (LDXQual > 1)
		#local texNormal = LDXOpaqueNormal;
		#if (Use_BlurRef = true)
			#if (Use_Uber = true)
				#local texFinish = finish
				{
					emission		0
					specular albedo	LDXOpaqueSpecularity
					roughness		LDXOpaqueRoughness
					fresnel			on
					reflection
					{
						LDXOpaqueSpecularity
						fresnel on
						roughness LDXOpaqueRoughness
					}
					conserve_energy
				}
				pigment {texPigment}
				finish {texFinish}
				normal {texNormal}
			#else
				#local texFinish = finish
				{
					ambient			0
					diffuse albedo	1
					specular albedo	LDXOpaqueSpecularity
					roughness		LDXOpaqueRoughness
					fresnel			on
					reflection
					{
						LDXOpaqueSpecularity
						fresnel on
					}
					conserve_energy
				}
				#if (Use_BlurTyp = 1)
					BlurredReflectionSingleNormals(texPigment, texFinish, texNormal, Use_BlurAmt)
				#elseif (Use_BlurTyp = 2)
					BlurredReflectionMultiNormals(texPigment, texFinish, texNormal, Use_BlurAmt, Use_BlurSmp)
				#elseif (Use_BlurTyp = 3)
					BlurredReflectionMultiTextures(texPigment, texFinish, texNormal, Use_BlurAmt, Use_BlurSmp)
				#end
			#end
		#else
			#local texFinish = finish
			{
				ambient LDXAmb
				diffuse LDXDif
				phong LDXPhong
				phong_size LDXPhongS
				reflection LDXRefl
			}
			pigment {texPigment}
			finish {texFinish}
			normal { texNormal }
		#end
#else
		pigment {texPigment}
#end
	}
#if (version >= 3.1) #if (LDXQual > 1)
	interior { ior LDXOpaqueIor }
#end #end
#if (version >= 3.1) } #end
#end
#end

#ifndef (LDXSkipTransColorMacro)
#macro LDXTransColor(r, g, b)
#if (version >= 3.7)
	#local texPigment = pigment { #if (LDXQual > 1) srgbf <r,g,b,LDXTFilt> #else srgbf <0.6,0.6,0.6,0> #end }
#else
	#local texPigment = pigment { #if (LDXQual > 1) rgbf <r,g,b,LDXTFilt> #else rgbf <0.6,0.6,0.6,0> #end }
#end
#if (version >= 3.1) material { #end
	texture {
#if (LDXQual > 1)
		#local texNormal = LDXTransNormal;
		#if (Use_BlurRef = true)
			#if (Use_Uber = true)
				#local texFinish = finish
				{
					emission		0
					specular albedo	LDXTransSpecularity
					roughness		LDXTransRoughness
					fresnel			on
					reflection
					{
						LDXTransSpecularity
						fresnel on
						roughness LDXTransRoughness
					}
					conserve_energy
				}
				pigment {texPigment}
				finish {texFinish}
				normal {texNormal}
			#else
				#local texFinish = finish
				{
					ambient			0
					diffuse albedo	1
					specular albedo	LDXTransSpecularity
					roughness		LDXTransRoughness
					fresnel			on
					reflection
					{
						LDXTransSpecularity
						fresnel on
					}
					conserve_energy
				}
				#if (Use_BlurTyp = 1)
					BlurredReflectionSingleNormals(texPigment, texFinish, texNormal, Use_BlurAmt)
				#elseif (Use_BlurTyp = 2)
					BlurredReflectionMultiNormals(texPigment, texFinish, texNormal, Use_BlurAmt, Use_BlurSmp)
				#elseif (Use_BlurTyp = 3)
					BlurredReflectionMultiTextures(texPigment, texFinish, texNormal, Use_BlurAmt, Use_BlurSmp)
				#end
			#end
		#else
			#local texFinish = finish
			{
				ambient LDXAmb
				diffuse LDXDif
				phong LDXPhong
				phong_size LDXPhongS
				reflection LDXTRefl
			}
			pigment {texPigment}
			finish {texFinish}
			normal {texNormal}
		#end
#else
		pigment {texPigment}
#end
	}
#if (version >= 3.1) #if (LDXQual > 1)
	interior { refraction 1 ior LDXTransIor }
#end #end
#if (version >= 3.1) } #end
#end
#end

#ifndef (LDXSkipRubberColorMacro)
#macro LDXRubberColor(r, g, b)
#if (version >= 3.7)
	#local texPigment = pigment { srgbf <r,g,b,0> }
#else
	#local texPigment = pigment { rgbf <r,g,b,0> }
#end
#if (version >= 3.1) material { #end
	texture {
#if (LDXQual > 1)
//		#local texNormal = normal {LDXRubberNormal}		// LDXRubberNormal doesn't exist yet
		#if (false = true)
			#if (Use_Uber = true)
				// to do
			#else
				// to do
			#end
		#else
			#local texFinish = finish
			{
				ambient LDXAmb
				diffuse LDXDif
				phong LDXRubberPhong
				phong_size LDXRubberPhongS
				reflection LDXRubberRefl
			}
			pigment {texPigment}
			finish {texFinish}
//			normal {texNormal}
		#end
#end
	}
	// needs an interior and ior here as well in order for SSLT to work
#if (version >= 3.1) } #end
#end
#end

#ifndef (LDXSkipChromeColorMacro)
#macro LDXChromeColor(r, g, b)
#if (version >= 3.7)
	#local texPigment = pigment { srgbf <r,g,b,0> }
#else
	#local texPigment = pigment { rgbf <r,g,b,0> }
#end
#if (version >= 3.1) material { #end
	texture {
#if (LDXQual > 1)
//		#local texNormal = normal {LDXChromeNormal}		// LDXChromeNormal doesn't exist yet
		#if (false = true)
			#if (Use_Uber = true)
				// to do
			#else
				// to do
			#end
		#else
			#local texFinish = finish
			{
				ambient LDXAmb
				diffuse LDXDif
				phong LDXPhong
				phong_size LDXPhongS
				reflection LDXChromeRefl
				brilliance LDXChromeBril
				metallic specular LDXChromeSpec
				roughness LDXChromeRough
			}
			pigment {texPigment}
			finish {texFinish}
//			normal {texNormal}
		#end
#end
	}
	// needs an interior and ior here as well in order for SSLT to work
#if (version >= 3.1) } #end
#end
#end

// to do
//#ifndef (LDXSkipPearlColorMacro)
//#macro LDXPearlColor(r, g, b)
//#end
//#end

#ifndef (LDXColor0) // Black
#declare LDXColor0 = LDXOpaqueColor(0.019608,0.07451,0.113725)
#end

#ifndef (LDXColor1) // Blue
#declare LDXColor1 = LDXOpaqueColor(0,0.333333,0.74902)
#end

#ifndef (LDXColor2) // Green
#declare LDXColor2 = LDXOpaqueColor(0.145098,0.478431,0.243137)
#end

#ifndef (LDXColor3) // Dark Turquoise
#declare LDXColor3 = LDXOpaqueColor(0,0.513725,0.560784)
#end

#ifndef (LDXColor4) // Red
#declare LDXColor4 = LDXOpaqueColor(0.788235,0.101961,0.035294)
#end

#ifndef (LDXColor5) // Dark Pink
#declare LDXColor5 = LDXOpaqueColor(0.784314,0.439216,0.627451)
#end

#ifndef (LDXColor6) // Brown
#declare LDXColor6 = LDXOpaqueColor(0.345098,0.223529,0.152941)
#end

#ifndef (LDXColor7) // Light Grey
#declare LDXColor7 = LDXOpaqueColor(0.607843,0.631373,0.615686)
#end

#ifndef (LDXColor8) // Dark Grey
#declare LDXColor8 = LDXOpaqueColor(0.427451,0.431373,0.360784)
#end

#ifndef (LDXColor9) // Light Blue
#declare LDXColor9 = LDXOpaqueColor(0.705882,0.823529,0.890196)
#end

#ifndef (LDXColor10) // Bright Green
#declare LDXColor10 = LDXOpaqueColor(0.294118,0.623529,0.290196)
#end

#ifndef (LDXColor11) // Light Turquoise
#declare LDXColor11 = LDXOpaqueColor(0.333333,0.647059,0.686275)
#end

#ifndef (LDXColor12) // Salmon
#declare LDXColor12 = LDXOpaqueColor(0.94902,0.439216,0.368627)
#end

#ifndef (LDXColor13) // Pink
#declare LDXColor13 = LDXOpaqueColor(0.988235,0.592157,0.67451)
#end

#ifndef (LDXColor14) // Yellow
#declare LDXColor14 = LDXOpaqueColor(0.94902,0.803922,0.215686)
#end

#ifndef (LDXColor15) // White
#declare LDXColor15 = LDXOpaqueColor(1,1,1)
#end

#ifndef (LDXColor17) // Light Green
#declare LDXColor17 = LDXOpaqueColor(0.760784,0.854902,0.721569)
#end

#ifndef (LDXColor18) // Light Yellow
#declare LDXColor18 = LDXOpaqueColor(0.984314,0.901961,0.588235)
#end

#ifndef (LDXColor19) // Tan
#declare LDXColor19 = LDXOpaqueColor(0.894118,0.803922,0.619608)
#end

#ifndef (LDXColor20) // Light Violet
#declare LDXColor20 = LDXOpaqueColor(0.788235,0.792157,0.886275)
#end

#ifndef (LDXColor21) // Glow In Dark Opaque
#declare LDXColor21 = LDXTransColor(0.987843,1,0.96902)
#end

#ifndef (LDXColor22) // Purple
#declare LDXColor22 = LDXOpaqueColor(0.505882,0,0.482353)
#end

#ifndef (LDXColor23) // Dark Blue Violet
#declare LDXColor23 = LDXOpaqueColor(0.12549,0.196078,0.690196)
#end

#ifndef (LDXColor24) // Edge Colour
#declare LDXColor24 = LDXOpaqueColor(0.498039,0.498039,0.498039)
#end

#ifndef (LDXColor25) // Orange
#declare LDXColor25 = LDXOpaqueColor(0.996078,0.541176,0.094118)
#end

#ifndef (LDXColor26) // Magenta
#declare LDXColor26 = LDXOpaqueColor(0.572549,0.223529,0.470588)
#end

#ifndef (LDXColor27) // Lime
#declare LDXColor27 = LDXOpaqueColor(0.733333,0.913725,0.043137)
#end

#ifndef (LDXColor28) // Dark Tan
#declare LDXColor28 = LDXOpaqueColor(0.584314,0.541176,0.45098)
#end

#ifndef (LDXColor29) // Bright Pink
#declare LDXColor29 = LDXOpaqueColor(0.894118,0.678431,0.784314)
#end

#ifndef (LDXColor30) // Medium Lavender
#declare LDXColor30 = LDXOpaqueColor(0.67451,0.470588,0.729412)
#end

#ifndef (LDXColor31) // Lavender
#declare LDXColor31 = LDXOpaqueColor(0.882353,0.835294,0.929412)
#end

#ifndef (LDXColor32) // Trans Black IR Lens
#declare LDXColor32 = LDXTransColor(0,0,0)
#end

#ifndef (LDXColor33) // Trans Dark Blue
#declare LDXColor33 = LDXTransColor(0,0.188235,0.962745)
#end

#ifndef (LDXColor34) // Trans Green
#declare LDXColor34 = LDXTransColor(0.205882,0.705882,0.382353)
#end

#ifndef (LDXColor35) // Trans Bright Green
#declare LDXColor35 = LDXTransColor(0.505882,0.990196,0.411765)
#end

#ifndef (LDXColor36) // Trans Red
#declare LDXColor36 = LDXTransColor(0.978824,0.152941,0.052941)
#end

#ifndef (LDXColor37) // Trans Dark Pink
#declare LDXColor37 = LDXTransColor(0.987451,0.6,0.958431)
#end

#ifndef (LDXColor38) // Trans Neon Orange
#declare LDXColor38 = LDXTransColor(1,0.950196,0.076471)
#end

#ifndef (LDXColor39) // Trans Very Light Blue
#declare LDXColor39 = LDXTransColor(0.975686,0.987451,0.994118)
#end

#ifndef (LDXColor40) // Trans Black
#declare LDXColor40 = LDXTransColor(0.582353,0.558824,0.482353)
#end

#ifndef (LDXColor41) // Trans Medium Blue
#declare LDXColor41 = LDXTransColor(0.5,0.960392,0.971765)
#end

#ifndef (LDXColor42) // Trans Neon Green
#declare LDXColor42 = LDXTransColor(0.975294,1,0)
#end

#ifndef (LDXColor43) // Trans Light Blue
#declare LDXColor43 = LDXTransColor(0.968235,0.991373,0.993725)
#end

#ifndef (LDXColor44) // Trans Bright Reddish Lilac
#declare LDXColor44 = LDXTransColor(0.958824,0.658824,0.962353)
#end

#ifndef (LDXColor45) // Trans Pink
#declare LDXColor45 = LDXTransColor(0.998824,0.959216,0.967451)
#end

#ifndef (LDXColor46) // Trans Yellow
#declare LDXColor46 = LDXTransColor(0.996078,0.980392,0.276471)
#end

#ifndef (LDXColor47) // Trans Clear
#declare LDXColor47 = LDXTransColor(0.998824,0.998824,0.998824)
#end

#ifndef (LDXColor52) // Trans Purple
#declare LDXColor52 = LDXTransColor(0.964706,0.964706,0.979608)
#end

#ifndef (LDXColor54) // Trans Neon Yellow
#declare LDXColor54 = LDXTransColor(0.98549,0.96902,0)
#end

#ifndef (LDXColor57) // Trans Orange
#declare LDXColor57 = LDXTransColor(0.994118,0.956078,0.164706)
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
#declare LDXColor65 = LDXRubberColor(0.960784,0.803922,0.184314)
#end

#ifndef (LDXColor66) // Rubber Trans Yellow
#declare LDXColor66 = LDXTransColor(0.979216,0.96902,0)
#end

#ifndef (LDXColor67) // Rubber Trans Clear
#declare LDXColor67 = LDXTransColor(1,1,1)
#end

#ifndef (LDXColor68) // Very Light Orange
#declare LDXColor68 = LDXOpaqueColor(0.952941,0.811765,0.607843)
#end

#ifndef (LDXColor69) // Bright Reddish Lilac
#declare LDXColor69 = LDXOpaqueColor(0.803922,0.384314,0.596078)
#end

#ifndef (LDXColor70) // Reddish Brown
#declare LDXColor70 = LDXOpaqueColor(0.345098,0.164706,0.070588)
#end

#ifndef (LDXColor71) // Light Bluish Grey
#declare LDXColor71 = LDXOpaqueColor(0.627451,0.647059,0.662745)
#end

#ifndef (LDXColor72) // Dark Bluish Grey
#declare LDXColor72 = LDXOpaqueColor(0.423529,0.431373,0.407843)
#end

#ifndef (LDXColor73) // Medium Blue
#declare LDXColor73 = LDXOpaqueColor(0.360784,0.615686,0.819608)
#end

#ifndef (LDXColor74) // Medium Green
#declare LDXColor74 = LDXOpaqueColor(0.45098,0.862745,0.631373)
#end

#ifndef (LDXColor75) // Speckle Black Copper
#declare LDXColor75 = LDXOpaqueColor(0,0,0)
#end

#ifndef (LDXColor76) // Speckle Dark Bluish Grey Silver
#declare LDXColor76 = LDXOpaqueColor(0.388235,0.372549,0.380392)
#end

#ifndef (LDXColor77) // Light Pink
#declare LDXColor77 = LDXOpaqueColor(0.996078,0.8,0.811765)
#end

#ifndef (LDXColor78) // Light Flesh
#declare LDXColor78 = LDXOpaqueColor(0.964706,0.843137,0.701961)
#end

#ifndef (LDXColor79) // Milky White
#declare LDXColor79 = LDXTransColor(1,1,1)
#end

#ifndef (LDXColor80) // Metallic Silver
#declare LDXColor80 = LDXOpaqueColor(0.647059,0.662745,0.705882)
#end

#ifndef (LDXColor81) // Metallic Green
#declare LDXColor81 = LDXOpaqueColor(0.537255,0.607843,0.372549)
#end

#ifndef (LDXColor82) // Metallic Gold
#declare LDXColor82 = LDXOpaqueColor(0.858824,0.67451,0.203922)
#end

#ifndef (LDXColor83) // Metallic Black
#declare LDXColor83 = LDXOpaqueColor(0.101961,0.156863,0.192157)
#end

#ifndef (LDXColor84) // Medium Dark Flesh
#declare LDXColor84 = LDXOpaqueColor(0.8,0.439216,0.164706)
#end

#ifndef (LDXColor85) // Medium Lilac
#declare LDXColor85 = LDXOpaqueColor(0.247059,0.211765,0.568627)
#end

#ifndef (LDXColor86) // Dark Flesh
#declare LDXColor86 = LDXOpaqueColor(0.486275,0.313725,0.227451)
#end

#ifndef (LDXColor87) // Metallic Dark Grey
#declare LDXColor87 = LDXOpaqueColor(0.427451,0.431373,0.360784)
#end

#ifndef (LDXColor89) // Blue Violet
#declare LDXColor89 = LDXOpaqueColor(0.298039,0.380392,0.858824)
#end

#ifndef (LDXColor92) // Flesh
#declare LDXColor92 = LDXOpaqueColor(0.815686,0.568627,0.407843)
#end

#ifndef (LDXColor100) // Light Salmon
#declare LDXColor100 = LDXOpaqueColor(0.996078,0.729412,0.741176)
#end

#ifndef (LDXColor110) // Violet
#declare LDXColor110 = LDXOpaqueColor(0.262745,0.329412,0.639216)
#end

#ifndef (LDXColor112) // Medium Violet
#declare LDXColor112 = LDXOpaqueColor(0.407843,0.454902,0.792157)
#end

#ifndef (LDXColor114) // Glitter Trans Dark Pink
#declare LDXColor114 = LDXTransColor(0.987451,0.6,0.958431)
#end

#ifndef (LDXColor115) // Medium Lime
#declare LDXColor115 = LDXOpaqueColor(0.780392,0.823529,0.235294)
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
#declare LDXColor134 = LDXOpaqueColor(0.588235,0.290196,0.152941)
#end

#ifndef (LDXColor135) // Pearl Light Grey
#declare LDXColor135 = LDXOpaqueColor(0.611765,0.639216,0.658824)
#end

#ifndef (LDXColor137) // Metal Blue
#declare LDXColor137 = LDXOpaqueColor(0.337255,0.466667,0.729412)
#end

#ifndef (LDXColor142) // Pearl Light Gold
#declare LDXColor142 = LDXOpaqueColor(0.862745,0.745098,0.380392)
#end

#ifndef (LDXColor148) // Pearl Dark Grey
#declare LDXColor148 = LDXOpaqueColor(0.341176,0.345098,0.341176)
#end

#ifndef (LDXColor150) // Pearl Very Light Grey
#declare LDXColor150 = LDXOpaqueColor(0.733333,0.741176,0.737255)
#end

#ifndef (LDXColor151) // Very Light Bluish Grey
#declare LDXColor151 = LDXOpaqueColor(0.901961,0.890196,0.878431)
#end

#ifndef (LDXColor178) // Flat Dark Gold
#declare LDXColor178 = LDXOpaqueColor(0.705882,0.533333,0.243137)
#end

#ifndef (LDXColor179) // Flat Silver
#declare LDXColor179 = LDXOpaqueColor(0.537255,0.529412,0.533333)
#end

#ifndef (LDXColor183) // Pearl White
#declare LDXColor183 = LDXOpaqueColor(0.94902,0.952941,0.94902)
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
#declare LDXColor191 = LDXOpaqueColor(0.972549,0.733333,0.239216)
#end

#ifndef (LDXColor212) // Bright Light Blue
#declare LDXColor212 = LDXOpaqueColor(0.52549,0.756863,0.882353)
#end

#ifndef (LDXColor216) // Rust
#declare LDXColor216 = LDXOpaqueColor(0.701961,0.062745,0.015686)
#end

#ifndef (LDXColor218) // Reddish Lilac
#declare LDXColor218 = LDXOpaqueColor(0.556863,0.333333,0.592157)
#end

#ifndef (LDXColor219) // Lilac
#declare LDXColor219 = LDXOpaqueColor(0.337255,0.305882,0.615686)
#end

#ifndef (LDXColor226) // Bright Light Yellow
#declare LDXColor226 = LDXOpaqueColor(1,0.941176,0.227451)
#end

#ifndef (LDXColor231) // Trans Bright Light Orange
#declare LDXColor231 = LDXTransColor(0.998824,0.971765,0.641176)
#end

#ifndef (LDXColor232) // Sky Blue
#declare LDXColor232 = LDXOpaqueColor(0.337255,0.745098,0.839216)
#end

#ifndef (LDXColor234) // Trans Fire Yellow
#declare LDXColor234 = LDXTransColor(0.998431,0.99098,0.956471)
#end

#ifndef (LDXColor256) // Rubber Black
#declare LDXColor256 = LDXRubberColor(0.129412,0.129412,0.129412)
#end

#ifndef (LDXColor272) // Dark Blue
#declare LDXColor272 = LDXOpaqueColor(0.05098,0.196078,0.356863)
#end

#ifndef (LDXColor273) // Rubber Blue
#declare LDXColor273 = LDXRubberColor(0,0.2,0.698039)
#end

#ifndef (LDXColor284) // Trans Reddish Lilac
#declare LDXColor284 = LDXTransColor(0.976078,0.950588,0.964706)
#end

#ifndef (LDXColor285) // Trans Light Green
#declare LDXColor285 = LDXTransColor(0.735294,0.976078,0.956863)
#end

#ifndef (LDXColor288) // Dark Green
#declare LDXColor288 = LDXOpaqueColor(0.094118,0.27451,0.196078)
#end

#ifndef (LDXColor293) // Trans Light Blue Violet
#declare LDXColor293 = LDXTransColor(0.629412,0.967059,0.989412)
#end

#ifndef (LDXColor294) // Glow In Dark Trans
#declare LDXColor294 = LDXTransColor(0.974118,0.977647,0.967843)
#end

#ifndef (LDXColor295) // Flamingo Pink
#declare LDXColor295 = LDXOpaqueColor(1,0.580392,0.760784)
#end

#ifndef (LDXColor297) // Pearl Gold
#declare LDXColor297 = LDXOpaqueColor(0.8,0.611765,0.168627)
#end

#ifndef (LDXColor300) // Metallic Copper
#declare LDXColor300 = LDXOpaqueColor(0.760784,0.498039,0.32549)
#end

#ifndef (LDXColor302) // Glitter Trans Light Blue
#declare LDXColor302 = LDXTransColor(0.968235,0.991373,0.993725)
#end

#ifndef (LDXColor308) // Dark Brown
#declare LDXColor308 = LDXOpaqueColor(0.207843,0.129412,0)
#end

#ifndef (LDXColor313) // Maersk Blue
#declare LDXColor313 = LDXOpaqueColor(0.329412,0.662745,0.784314)
#end

#ifndef (LDXColor320) // Dark Red
#declare LDXColor320 = LDXOpaqueColor(0.447059,0.054902,0.058824)
#end

#ifndef (LDXColor321) // Dark Azure
#declare LDXColor321 = LDXOpaqueColor(0.078431,0.596078,0.843137)
#end

#ifndef (LDXColor322) // Medium Azure
#declare LDXColor322 = LDXOpaqueColor(0.243137,0.760784,0.866667)
#end

#ifndef (LDXColor323) // Light Aqua
#declare LDXColor323 = LDXOpaqueColor(0.741176,0.862745,0.847059)
#end

#ifndef (LDXColor324) // Rubber Red
#declare LDXColor324 = LDXRubberColor(0.768627,0,0.14902)
#end

#ifndef (LDXColor326) // Yellowish Green
#declare LDXColor326 = LDXOpaqueColor(0.87451,0.933333,0.647059)
#end

#ifndef (LDXColor329) // Glow In Dark White
#declare LDXColor329 = LDXTransColor(0.996078,0.995294,0.984314)
#end

#ifndef (LDXColor330) // Olive Green
#declare LDXColor330 = LDXOpaqueColor(0.607843,0.603922,0.352941)
#end

#ifndef (LDXColor334) // Chrome Gold
#declare LDXColor334 = LDXChromeColor(0.733333,0.647059,0.239216)
#end

#ifndef (LDXColor335) // Sand Red
#declare LDXColor335 = LDXOpaqueColor(0.839216,0.458824,0.447059)
#end

#ifndef (LDXColor339) // Glitter Trans Neon Green
#declare LDXColor339 = LDXTransColor(0.975294,1,0)
#end

#ifndef (LDXColor350) // Rubber Orange
#declare LDXColor350 = LDXRubberColor(0.815686,0.4,0.062745)
#end

#ifndef (LDXColor351) // Medium Dark Pink
#declare LDXColor351 = LDXOpaqueColor(0.968627,0.521569,0.694118)
#end

#ifndef (LDXColor366) // Earth Orange
#declare LDXColor366 = LDXOpaqueColor(0.980392,0.611765,0.109804)
#end

#ifndef (LDXColor373) // Sand Purple
#declare LDXColor373 = LDXOpaqueColor(0.517647,0.368627,0.517647)
#end

#ifndef (LDXColor375) // Rubber Light Grey
#declare LDXColor375 = LDXRubberColor(0.756863,0.760784,0.756863)
#end

#ifndef (LDXColor378) // Sand Green
#declare LDXColor378 = LDXOpaqueColor(0.627451,0.737255,0.67451)
#end

#ifndef (LDXColor379) // Sand Blue
#declare LDXColor379 = LDXOpaqueColor(0.34902,0.443137,0.517647)
#end

#ifndef (LDXColor383) // Chrome Silver
#declare LDXColor383 = LDXChromeColor(0.878431,0.878431,0.878431)
#end

#ifndef (LDXColor406) // Rubber Dark Blue
#declare LDXColor406 = LDXRubberColor(0,0.113725,0.407843)
#end

#ifndef (LDXColor449) // Rubber Purple
#declare LDXColor449 = LDXRubberColor(0.505882,0,0.482353)
#end

#ifndef (LDXColor450) // Fabuland Brown
#declare LDXColor450 = LDXOpaqueColor(0.713725,0.482353,0.313725)
#end

#ifndef (LDXColor462) // Medium Orange
#declare LDXColor462 = LDXOpaqueColor(1,0.654902,0.043137)
#end

#ifndef (LDXColor484) // Dark Orange
#declare LDXColor484 = LDXOpaqueColor(0.662745,0.333333,0)
#end

#ifndef (LDXColor490) // Rubber Lime
#declare LDXColor490 = LDXRubberColor(0.843137,0.941176,0)
#end

#ifndef (LDXColor493) // Magnet
#declare LDXColor493 = LDXOpaqueColor(0.396078,0.403922,0.380392)
#end

#ifndef (LDXColor494) // Electric Contact Alloy
#declare LDXColor494 = LDXOpaqueColor(0.815686,0.815686,0.815686)
#end

#ifndef (LDXColor495) // Electric Contact Copper
#declare LDXColor495 = LDXOpaqueColor(0.682353,0.478431,0.34902)
#end

#ifndef (LDXColor496) // Rubber Light Bluish Grey
#declare LDXColor496 = LDXRubberColor(0.639216,0.635294,0.643137)
#end

#ifndef (LDXColor503) // Very Light Grey
#declare LDXColor503 = LDXOpaqueColor(0.901961,0.890196,0.854902)
#end

#ifndef (LDXColor504) // Rubber Flat Silver
#declare LDXColor504 = LDXRubberColor(0.537255,0.529412,0.533333)
#end

#ifndef (LDXColor511) // Rubber White
#declare LDXColor511 = LDXRubberColor(0.980392,0.980392,0.980392)
#end
