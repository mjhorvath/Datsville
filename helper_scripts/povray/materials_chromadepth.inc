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


// -------------------------------------------------------------
// Chromadepth - centered on camera look_at

// This script assumes the depth effect is *linear* from near to far, which may not be the case in reality. For all I know it may be logarithmic.
// We don't want any magenta, so stop at hue #240 (blue).
// red, green, blue
#macro MakeChromadepthTextureCameraRGB(CameraLocation, CameraLookAt, FudgePercent)
	#local FudgeDec = FudgePercent/100;
	#local FudgeMin = FudgeDec/2;
	#local FudgeMax = 1 - FudgeDec/2;
	pigment
	{
		spherical
		color_map
		{
			[0 color srgb CHSL2RGB(<240, 1, 1/2>)]
			#for (i, 0, 240, 1)
				#local iThis = FudgeMin + i/240 * (1-FudgeDec);
				[iThis color srgb CHSL2RGB(<240 - i, 1, 1/2>)]
			#end
			[1 color srgb CHSL2RGB(<000, 1, 1/2>)]
		}
	}
//	finish
//	{
//		ambient 1
//		diffuse 0
//	}
	scale vlength(CameraLocation - CameraLookAt) * 2
	translate CameraLocation
#end


// This script assumes the depth effect is *linear* from near to far, which may not be the case in reality. For all I know it may be logarithmic.
// red, white, blue
#macro MakeChromadepthTextureCameraRWB(CameraLocation, CameraLookAt, FudgePercent)
	#local FudgeDec = FudgePercent/100;
	#local FudgeMin = FudgeDec/2;
	#local FudgeMax = 1 - FudgeDec/2;
	pigment
	{
		spherical
		color_map
		{
			[0.0		color srgb <0,0,1>]
			[FudgeMin	color srgb <0,0,1>]
			[0.5		color srgb <1,1,1>]
			[FudgeMax	color srgb <1,0,0>]
			[1.0		color srgb <1,0,0>]
		}
	}
//	finish
//	{
//		ambient 1
//		diffuse 0
//	}
	scale vlength(CameraLocation - CameraLookAt) * 2
	translate CameraLocation
#end

// -------------------------------------------------------------
// Chromadepth - centered on object - script by Kenneth

// red, green, blue
#macro MakeChromadepthTextureObjectRGB(CameraLocation, BBoxMin, BBoxMax)
	#local BBoxMid = (BBoxMin + BBoxMax)/2;
	#if (CameraLocation.x < BBoxMid.x)
		#local NearCorner_x = BBoxMin.x;
		#local FarCorner_x = BBoxMax.x;
	#else
		#local NearCorner_x = BBoxMax.x;
		#local FarCorner_x = BBoxMin.x;
	#end
	#if (CameraLocation.y < BBoxMid.y)
		#local NearCorner_y = BBoxMin.y;
		#local FarCorner_y = BBoxMax.y;
	#else
		#local NearCorner_y = BBoxMax.y;
		#local FarCorner_y = BBoxMin.y;
	#end
	#if (CameraLocation.z < BBoxMid.z)
		#local NearCorner_z = BBoxMin.z;
		#local FarCorner_z = BBoxMax.z;
	#else
		#local NearCorner_z = BBoxMax.z;
		#local FarCorner_z = BBoxMin.z;
	#end
	#local NearCorner = <NearCorner_x,NearCorner_y,NearCorner_z>;
	#local FarCorner = <FarCorner_x,FarCorner_y,FarCorner_z>;

//	#debug "\n"
//	#debug concat("NearCorner = <", vstr(3,NearCorner,",",0,-1), ">\n")
//	#debug concat("FarCorner = <", vstr(3,FarCorner,",",0,-1), ">\n")
//	#debug "\n"

	#local Ch_L_1 = vlength(NearCorner - CameraLocation);  // or - 1.68 FUDGE FACTOR or - 1.70 FUDGE FACTOR
	#local Ch_L_2 = vlength( FarCorner - CameraLocation);  // or + 1.44 FUDGE FACTOR or + 1.65 FUDGE FACTOR
	#local Ch_S = Ch_L_1/Ch_L_2;
	#local Ch_T = 1.0 - Ch_S;

//	#debug "\n"
//	#debug concat("\n", "Ch_L_1/Ch_L_2 = ",str(Ch_L_1/Ch_L_2,0,9),"  (should never go over 1.0 !)","\n")
//	#debug concat("\n", "Ch_T = ",str(Ch_T,0,9),"\n")
//	#debug "\n"

	pigment
	{
		spherical
		color_map
		{
			[0 color srgb 3]
			[0 color srgb CHSL2RGB(<240, 1, 1/2>)]
			#for (i, 0, 240, 1)
				#local iThis = i/240;
				[iThis*Ch_T color srgb CHSL2RGB(<240 - i, 1, 1/2>)]
			#end
			[Ch_T color srgb CHSL2RGB(<000, 1, 1/2>)]
			[Ch_T color srgb 3]
		}
		scale Ch_L_2
		translate CameraLocation
	}
//	finish
//	{
//		ambient 1
//		diffuse 0
//	}
#end


// red, white, blue
#macro MakeChromadepthTextureObjectRWB(CameraLocation, BBoxMin, BBoxMax)
	#local BBoxMid = (BBoxMin + BBoxMax)/2;
	#if (CameraLocation.x < BBoxMid.x)
		#local NearCorner_x = BBoxMin.x;
		#local FarCorner_x = BBoxMax.x;
	#else
		#local NearCorner_x = BBoxMax.x;
		#local FarCorner_x = BBoxMin.x;
	#end
	#if (CameraLocation.y < BBoxMid.y)
		#local NearCorner_y = BBoxMin.y;
		#local FarCorner_y = BBoxMax.y;
	#else
		#local NearCorner_y = BBoxMax.y;
		#local FarCorner_y = BBoxMin.y;
	#end
	#if (CameraLocation.z < BBoxMid.z)
		#local NearCorner_z = BBoxMin.z;
		#local FarCorner_z = BBoxMax.z;
	#else
		#local NearCorner_z = BBoxMax.z;
		#local FarCorner_z = BBoxMin.z;
	#end
	#local NearCorner = <NearCorner_x,NearCorner_y,NearCorner_z>;
	#local FarCorner = <FarCorner_x,FarCorner_y,FarCorner_z>;

//	#debug "\n"
//	#debug concat("NearCorner = <", vstr(3,NearCorner,",",0,-1), ">\n")
//	#debug concat("FarCorner = <", vstr(3,FarCorner,",",0,-1), ">\n")
//	#debug "\n"

	#local Ch_L_1 = vlength(NearCorner - CameraLocation);  // or - 1.68 FUDGE FACTOR or - 1.70 FUDGE FACTOR
	#local Ch_L_2 = vlength( FarCorner - CameraLocation);  // or + 1.44 FUDGE FACTOR or + 1.65 FUDGE FACTOR
	#local Ch_S = Ch_L_1/Ch_L_2;
	#local Ch_T = 1.0 - Ch_S;

//	#debug "\n"
//	#debug concat("\n", "Ch_L_1/Ch_L_2 = ",str(Ch_L_1/Ch_L_2,0,9),"  (should never go over 1.0 !)","\n")
//	#debug concat("\n", "Ch_T = ",str(Ch_T,0,9),"\n")
//	#debug "\n"

	pigment
	{
		spherical
		color_map
		{
			[0 srgb 3]
			[0 srgb <0,0,1>]				// BLUE -- outside edge of pattern
			[0.5*Ch_T srgb <1,1,1>]		// YELLOW
			[Ch_T srgb <1,0,0>]			// RED
			[Ch_T srgb 3]
		}
		scale Ch_L_2
		translate CameraLocation
	}
//	finish
//	{
//		ambient 1
//		diffuse 0
//	}
#end
