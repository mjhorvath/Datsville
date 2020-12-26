#if (version < 3.7)
	#error "This POV code requires at least version 3.7\n"
#end

#macro gamma_color_adjust(in_color)
	#local out_gamma = 2.2;
	#local in_color = in_color + <0,0,0,0,0>;
	color rgbft
	<
		pow(in_color.red, out_gamma),
		pow(in_color.green, out_gamma),
		pow(in_color.blue, out_gamma),
		in_color.filter,
		in_color.transmit
	>
#end

//// Defines

#ifndef(L3Version)	#declare L3Version	= 1.4;	#end
#ifndef(L3Quality)	#declare L3Quality	= 2;	#end	// Quality level, 0=BBox, 1=no refr, 2=normal, 3=studlogo, 4=stud2logo
#ifndef(L3SW)		#declare L3SW		= 0.5;	#end	// Width of seam between two bricks
#ifndef(L3Studs)	#declare L3Studs	= 1;	#end	// 1=on 0=off
#ifndef(L3Bumps)	#declare L3Bumps	= 0;	#end	// 1=on 0=off
#ifndef(L3Ambient)	#declare L3Ambient	= 0.4;	#end
#ifndef(L3Diffuse)	#declare L3Diffuse	= 0.4;	#end
#ifndef(L3Ior)		#declare L3Ior		= 1.25;	#end
#ifndef(L3NormalBumps)	#declare L3NormalBumps	= normal { bumps 0.01 scale 20 }	#end
#ifndef(L3NormalSlope)	#declare L3NormalSlope	= normal { bumps 0.3 scale 0.5 }	#end
#ifndef(L3Phong)	#declare L3Phong	= 0.5;	#end
#ifndef(L3PhongSize)	#declare L3PhongSize	= 40;	#end
#ifndef(L3Reflection)	#declare L3Reflection	= 0.08;	#end	// was 0.08


#declare L3Logo = merge {
	sphere {<-59,0,-96>,6}
	cylinder {<-59,0,-96>,<59,0,-122>,6 open}
	sphere {<59,0,-122>,6}
	cylinder {<59,0,-122>,<59,0,-84>,6 open}
	sphere {<59,0,-84>,6}

	sphere {<-59,0,-36>,6}
	cylinder {<-59,0,-36>,<-59,0,1>,6 open}
	sphere {<-59,0,1>,6}
	cylinder {<0,0,-49>,<0,0,-25>,6 open}
	sphere {<0,0,-25>,6}
	sphere {<59,0,-62>,6}
	cylinder {<59,0,-62>,<59,0,-24>,6 open}
	sphere {<59,0,-24>,6}
	cylinder {<-59,0,-36>,<59,0,-62>,6 open}

	sphere {<-35.95,0,57>,6}
	torus {18.45,6 clipped_by{plane{<40,0,-9>,0}} translate<-40,0,39>}
	cylinder {<-44.05,0,21>,<35.95,0,3>,6 open}
	torus {18.45,6 clipped_by{plane{<-40,0,9>,0}} translate<40,0,21>}
	cylinder {<44.05,0,39>,<0,0,49>,6 open}
	sphere {<0,0,49>,6}
	cylinder {<0,0,49>,<0,0,34>,6 open}
	sphere {<0,0,34>,6}

	torus {18.45,6 clipped_by{plane{<40,0,-9>,0}} translate<-40,0,99>}
	cylinder {<-44.05,0,81>,<35.95,0,63>,6 open}
	torus {18.45,6 clipped_by{plane{<-40,0,9>,0}} translate<40,0,81>}
	cylinder {<44.05,0,99>,<-35.95,0,117>,6 open}

	scale 4.5/128
}




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
	pigment { gamma_color_adjust(<r/255,g/255,b/255>) }
	finish { L3FinishOpaque }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TextureChromeRGB)
#macro L3TextureChromeRGB(r,g,b)
texture {
	pigment { gamma_color_adjust(<r/255,g/255,b/255>) }
	finish { L3FinishChrome }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TexturePearlescentRGB)
#macro L3TexturePearlescentRGB(r,g,b)
texture {
	pigment { gamma_color_adjust(<r/255,g/255,b/255>) }
	finish { L3FinishPearlescent }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TextureRubberRGB)
#macro L3TextureRubberRGB(r,g,b)
texture {
	pigment { gamma_color_adjust(<r/255,g/255,b/255>) }
	finish { L3FinishRubber }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TextureMatte_metallicRGB)
#macro L3TextureMatte_metallicRGB(r,g,b)
texture {
	pigment { gamma_color_adjust(<r/255,g/255,b/255>) }
	finish { L3FinishMatte_metallic }
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

#ifndef (L3TextureMetalRGB)
#macro L3TextureMetalRGB(r,g,b)
texture {
	pigment { gamma_color_adjust(<r/255,g/255,b/255>) }
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
	pigment { gamma_color_adjust(<r/255,g/255,b/255>) #if (L3Quality > 1) filter f #end }
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



//// Color 7 Light_Gray (from ldconfig.ldr)
#ifndef (L3Texture7)
#declare L3Texture7 = L3TextureOpaqueRGB(156,153,153)
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


//// Color 0 Black (from ldconfig.ldr)
#ifndef (L3Texture0)
#declare L3Texture0 = L3TextureOpaqueRGB(33,33,33)
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


//// Color 2 Green (from ldconfig.ldr)
#ifndef (L3Texture2)
#declare L3Texture2 = L3TextureOpaqueRGB(0,140,20)
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


//// Color 8 Dark_Gray (from ldconfig.ldr)
#ifndef (L3Texture8)
#declare L3Texture8 = L3TextureOpaqueRGB(99,95,82)
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


//// Color 4 Red (from ldconfig.ldr)
#ifndef (L3Texture4)
#declare L3Texture4 = L3TextureOpaqueRGB(196,0,38)
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


//// Color 1 Blue (from ldconfig.ldr)
#ifndef (L3Texture1)
#declare L3Texture1 = L3TextureOpaqueRGB(0,51,178)
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


//// Color 355
#ifndef (L3Texture355)
#declare L3Texture355 = L3TextureOpaqueRGB(46,92.5,79.5)
#end
#ifndef (L3Texture355_slope)
#declare L3Texture355_slope = L3TextureSlope(L3Texture355)
#end
#ifndef (L3Color355)
#declare L3Color355 = L3Material(L3Texture355)
#end
#ifndef (L3Color355_slope)
#declare L3Color355_slope = L3Material(L3Texture355_slope)
#end


//// Color 46 Trans_Yellow (from ldconfig.ldr)
#ifndef (L3Texture46)
#declare L3Texture46 = L3TextureTransparentRGBA(202,176,0,128)
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


//// Color 14 Yellow (from ldconfig.ldr)
#ifndef (L3Texture14)
#declare L3Texture14 = L3TextureOpaqueRGB(255,220,0)
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


//// Color 6 Brown (from ldconfig.ldr)
#ifndef (L3Texture6)
#declare L3Texture6 = L3TextureOpaqueRGB(92,32,0)
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


//// Color 366 Earth_Orange (from ldconfig.ldr)
#ifndef (L3Texture366)
#declare L3Texture366 = L3TextureOpaqueRGB(209,131,4)
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


//// Color 43 Trans_Light_Blue (from ldconfig.ldr)
#ifndef (L3Texture43)
#declare L3Texture43 = L3TextureTransparentRGBA(174,239,236,128)
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


//// Color 47 Trans_Clear (from ldconfig.ldr)
#ifndef (L3Texture47)
#declare L3Texture47 = L3TextureTransparentRGBA(255,255,255,128)
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


//// Color 34 Trans_Green (from ldconfig.ldr)
#ifndef (L3Texture34)
#declare L3Texture34 = L3TextureTransparentRGBA(6,100,50,128)
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


//// Color 36 Trans_Red (from ldconfig.ldr)
#ifndef (L3Texture36)
#declare L3Texture36 = L3TextureTransparentRGBA(196,0,38,128)
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
#declare L3Texture38 = L3TextureTransparentRGBA(249,96,0,128)
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


//// Color 32 Trans_Black_IR_Lens (from ldconfig.ldr)
#ifndef (L3Texture32)
#declare L3Texture32 = L3TextureTransparentRGBA(0,0,0,220)
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


//// Color 35 Trans_Bright_Green (from ldconfig.ldr)
#ifndef (L3Texture35)
#declare L3Texture35 = L3TextureTransparentRGBA(217,228,167,128)
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


//// Color 41 Trans_Medium_Blue (from ldconfig.ldr)
#ifndef (L3Texture41)
#declare L3Texture41 = L3TextureTransparentRGBA(85,165,175,128)
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


//// Color 44 Trans_Light_Purple (from ldconfig.ldr)
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
#declare L3Texture45 = L3TextureTransparentRGBA(228,173,200,128)
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


//// Color 382
#ifndef (L3Texture382)
#declare L3Texture382 = L3TextureOpaqueRGB(205.5,186.5,76.5)
#end
#ifndef (L3Texture382_slope)
#declare L3Texture382_slope = L3TextureSlope(L3Texture382)
#end
#ifndef (L3Color382)
#declare L3Color382 = L3Material(L3Texture382)
#end
#ifndef (L3Color382_slope)
#declare L3Color382_slope = L3Material(L3Texture382_slope)
#end


//// Color 5 Dark_Pink (from ldconfig.ldr)
#ifndef (L3Texture5)
#declare L3Texture5 = L3TextureOpaqueRGB(223,102,149)
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


//// Color 13 Pink (from ldconfig.ldr)
#ifndef (L3Texture13)
#declare L3Texture13 = L3TextureOpaqueRGB(249,164,198)
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


//// Color 25 Orange (from ldconfig.ldr)
#ifndef (L3Texture25)
#declare L3Texture25 = L3TextureOpaqueRGB(249,96,0)
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


//// Color 487
#ifndef (L3Texture487)
#declare L3Texture487 = L3TextureOpaqueRGB(205.5,186.5,76.5)
#end
#ifndef (L3Texture487_slope)
#declare L3Texture487_slope = L3TextureSlope(L3Texture487)
#end
#ifndef (L3Color487)
#declare L3Color487 = L3Material(L3Texture487)
#end
#ifndef (L3Color487_slope)
#declare L3Color487_slope = L3Material(L3Texture487_slope)
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


//// Color 57 Trans_Orange (from ldconfig.ldr)
#ifndef (L3Texture57)
#declare L3Texture57 = L3TextureTransparentRGBA(224,152,100,128)
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


//// Color 3 Dark_Turquoise (from ldconfig.ldr)
#ifndef (L3Texture3)
#declare L3Texture3 = L3TextureOpaqueRGB(0,153,159)
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


//// Color 9 Light_Blue (from ldconfig.ldr)
#ifndef (L3Texture9)
#declare L3Texture9 = L3TextureOpaqueRGB(107,171,220)
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
#declare L3Texture10 = L3TextureOpaqueRGB(107,238,144)
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
#declare L3Texture11 = L3TextureOpaqueRGB(51,166,167)
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
#declare L3Texture12 = L3TextureOpaqueRGB(255,133,122)
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


//// Color 258
#ifndef (L3Texture258)
#declare L3Texture258 = L3TextureOpaqueRGB(16.5,86.5,26.5)
#end
#ifndef (L3Texture258_slope)
#declare L3Texture258_slope = L3TextureSlope(L3Texture258)
#end
#ifndef (L3Color258)
#declare L3Color258 = L3Material(L3Texture258)
#end
#ifndef (L3Color258_slope)
#declare L3Color258_slope = L3Material(L3Texture258_slope)
#end


//// Color 19 Tan (from ldconfig.ldr)
#ifndef (L3Texture19)
#declare L3Texture19 = L3TextureOpaqueRGB(232,207,161)
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


//// Color 277
#ifndef (L3Texture277)
#declare L3Texture277 = L3TextureOpaqueRGB(111.5,76.5,163.5)
#end
#ifndef (L3Texture277_slope)
#declare L3Texture277_slope = L3TextureSlope(L3Texture277)
#end
#ifndef (L3Color277)
#declare L3Color277 = L3Material(L3Texture277)
#end
#ifndef (L3Color277_slope)
#declare L3Color277_slope = L3Material(L3Texture277_slope)
#end


//// Color 492
#ifndef (L3Texture492)
#declare L3Texture492 = L3TextureOpaqueRGB(255,176.5,61)
#end
#ifndef (L3Texture492_slope)
#declare L3Texture492_slope = L3TextureSlope(L3Texture492)
#end
#ifndef (L3Color492)
#declare L3Color492 = L3Material(L3Texture492)
#end
#ifndef (L3Color492_slope)
#declare L3Color492_slope = L3Material(L3Texture492_slope)
#end

//// Color 110 Violet (from ldconfig.ldr)
#ifndef (L3Texture110)
#declare L3Texture110 = L3TextureOpaqueRGB(67,84,147)
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

//// Color 28 Dark_Tan (from ldconfig.ldr)
#ifndef (L3Texture28)
#declare L3Texture28 = L3TextureOpaqueRGB(197,151,80)
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

//// Color 21 Glow_In_Dark_Opaque (from ldconfig.ldr)
#ifndef (L3Texture21)
//#declare L3Texture21 = L3TextureOtherRGBFAL(224,255,176,0,250,15)
#declare L3Texture21 = L3TextureTransparentRGBA(224,255,176,250)
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
