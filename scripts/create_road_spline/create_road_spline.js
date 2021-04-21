// Script authored by: Michael Horvath
// Road design by: Michael Gallagher
// Version: 1.0.0
// Created: 2013/11/05
// Updated: 2013/11/05
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3 of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

var point_1_x
var point_1_y
var point_2_x
var point_2_y
var point_3_x
var point_3_y
var point_4_x
var point_4_y
var C_x
var C_y

var sOutString =	'0 ROTATION CENTER 0 0 0 1 "Custom"\n' +
			'0 ROTATION CONFIG 0 0\n'

var fso
var WshShell
var OutputFileName

var rotxMat_1 =
[
	[1, 0, 0],		// |1,4,7|
	[0, 0, 1],		// |2,5,8|
	[0,-1, 0]		// |3,6,9|
]
var rotxMat_2 =
[
	[1, 0, 0],		// |1,4,7|
	[0, 0,-1],		// |2,5,8|
	[0, 1, 0]		// |3,6,9|
]

var partSelect =
[
	[ 296, 40,  2,  true, 15, rotxMat_1, '3004.dat', '3005.dat'],
	[ 272, 40,  2, false, 15, rotxMat_1, '3004.dat', '3005.dat'],
	[ 248, 40,  2,  true, 15, rotxMat_1, '3004.dat', '3005.dat'],
	[ 224, 40,  2, false, 15, rotxMat_1, '3004.dat', '3005.dat'],
	[ 200, 40,  2,  true, 15, rotxMat_1, '3004.dat', '3005.dat'],
	[ 192, 40,  2, false, 14, rotxMat_1, 'road_connect_1.ldr', '98138.dat'],
	[ 168, 40, 12,  true,  0, rotxMat_1, '3004.dat', '3005.dat'],
	[ 144, 40, 12, false,  0, rotxMat_1, '3004.dat', '3005.dat'],
	[ 120, 40, 12,  true,  0, rotxMat_1, '3004.dat', '3005.dat'],
	[  96, 40, 12, false,  0, rotxMat_1, '3004.dat', '3005.dat'],
	[  72, 40, 12,  true,  0, rotxMat_1, '3004.dat', '3005.dat'],
	[  48, 40, 12, false,  0, rotxMat_1, '3004.dat', '3005.dat'],
	[  24, 40, 12,  true,  0, rotxMat_1, '3004.dat', '3005.dat'],
	[  16, 40, 12, false,  0, rotxMat_1, '3023.dat', '3024.dat'],
	[   8, 40, 12,  true, 14, rotxMat_1, '3023.dat', '3024.dat'],
	[   0, 40, 12, false,  0, rotxMat_1, '3069b.dat', '3070b.dat'],
	// half way
	[   0, 40, 12, false,  0, rotxMat_2, '3069b.dat', '3070b.dat'],
	[  -8, 40, 12,  true, 14, rotxMat_2, '3023.dat', '3024.dat'],
	[ -16, 40, 12, false,  0, rotxMat_2, '3023.dat', '3024.dat'],
	[ -24, 40, 12,  true,  0, rotxMat_2, '3004.dat', '3005.dat'],
	[ -48, 40, 12, false,  0, rotxMat_2, '3004.dat', '3005.dat'],
	[ -72, 40, 12,  true,  0, rotxMat_2, '3004.dat', '3005.dat'],
	[ -96, 40, 12, false,  0, rotxMat_2, '3004.dat', '3005.dat'],
	[-120, 40, 12,  true,  0, rotxMat_2, '3004.dat', '3005.dat'],
	[-144, 40, 12, false,  0, rotxMat_2, '3004.dat', '3005.dat'],
	[-168, 40, 12,  true,  0, rotxMat_2, '3004.dat', '3005.dat'],
	[-192, 40,  2, false, 14, rotxMat_2, 'road_connect_2.ldr', '98138.dat'],
	[-200, 40,  2,  true, 15, rotxMat_2, '3004.dat', '3005.dat'],
	[-224, 40,  2, false, 15, rotxMat_2, '3004.dat', '3005.dat'],
	[-248, 40,  2,  true, 15, rotxMat_2, '3004.dat', '3005.dat'],
	[-272, 40,  2, false, 15, rotxMat_2, '3004.dat', '3005.dat'],
	[-296, 40,  2,  true, 15, rotxMat_2, '3004.dat', '3005.dat']
]

// only continue if the script is run via Windows Scripting Host
if (typeof(WScript) != 'undefined')
{
	fso = new ActiveXObject('Scripting.FileSystemObject')
	WshShell = new ActiveXObject('WScript.Shell')
	var ProgArgs = WScript.Arguments
	if (ProgArgs.length == 10)
	{
		for (var i = 1; i <= 5; i++)
		{
			switch (i)
			{
				case 1:
					var tempArray = eval(ProgArgs(i * 2 - 1))
					point_1_x = tempArray[0]
					point_1_y = tempArray[1]
				break
				case 2:
					var tempArray = eval(ProgArgs(i * 2 - 1))
					point_2_x = tempArray[0]
					point_2_y = tempArray[1]
				break
				case 3:
					var tempArray = eval(ProgArgs(i * 2 - 1))
					point_3_x = tempArray[0]
					point_3_y = tempArray[1]
				break
				case 4:
					var tempArray = eval(ProgArgs(i * 2 - 1))
					point_4_x = tempArray[0]
					point_4_y = tempArray[1]
				break
				case 5:
					OutputFileName = ProgArgs(i * 2 - 1)
				break
			}
		}
		C_x = 2 * point_3_x - point_4_x
		C_y = 2 * point_3_y - point_4_y
		var bPass = vDoStuff()
		if (bPass == 1)
			WScript.Echo('Error: The curvature of the spline exceeds 6 degrees at some point. Halting program.')
		else
			vWriteOutput()
	}
	else
	{
		WScript.Echo
		(
			'Invalid number of parameters.\n\n' +
			'Example:\n\n' +
			'\tcscript create_road_spline.js -p1 [-320,-64] -p2 [-120,-64] -p3 [320,64] -p4 [520,64] -o output_file_name.ldr\n'
		)
	}
}

function tCoordinates(t)
{
	return	[
		(point_3_x + 3 * point_2_x - 3 * C_x - point_1_x) * Math.pow(t, 3) + (3 * C_x - 6 * point_2_x + 3 * point_1_x) * Math.pow(t, 2) + (3 * point_2_x - 3 * point_1_x) * t + point_1_x,
		(point_3_y + 3 * point_2_y - 3 * C_y - point_1_y) * Math.pow(t, 3) + (3 * C_y - 6 * point_2_y + 3 * point_1_y) * Math.pow(t, 2) + (3 * point_2_y - 3 * point_1_y) * t + point_1_y
	]
}

function tDerivatives(t)
{
	return	[
		(point_3_x + 3 * point_2_x - 3 * C_x - point_1_x) * 3 * Math.pow(t, 2) + (3 * C_x - 6 * point_2_x + 3 * point_1_x) * 2 * t + (3 * point_2_x - 3 * point_1_x),
		(point_3_y + 3 * point_2_y - 3 * C_y - point_1_y) * 3 * Math.pow(t, 2) + (3 * C_y - 6 * point_2_y + 3 * point_1_y) * 2 * t + (3 * point_2_y - 3 * point_1_y)
	]
}

function fGetCurveLength()
{
	var fDistance = 0
	var iIterations = 1000
	for (var i = 1; i <= iIterations; i++)
	{
		var fTime_1 = (i - 1)/iIterations
		var fTime_2 = i/iIterations
		var tCoo_1 = tCoordinates(fTime_1)
		var tCoo_2 = tCoordinates(fTime_2)
		fDistance += vdistance(tCoo_1, tCoo_2)
	}
	return fDistance
}

function vdistance(tVec_1, tVec_2)
{
	return Math.sqrt(Math.pow(tVec_2[0] - tVec_1[0], 2) + Math.pow(tVec_2[1] - tVec_1[1], 2))
}

function vnormalize(tVec)
{
	return [
		tVec[0] / vdistance([0,0], tVec),
		tVec[1] / vdistance([0,0], tVec)
	]
}

function vmultiply(tVec, fVal)
{
	return [
		tVec[0] * fVal,
		tVec[1] * fVal,
	]
}

function fCalcTimePosition(fTime_1, fTime_2, fStepTime_1, fTargDist)
{
	var tCoo_1 = tCoordinates(fTime_1)
	var tCoo_2 = tCoordinates(fTime_2)
	var fThisDist = vdistance(tCoo_1, tCoo_2)
	var fMiniDist = 0.01
	var fStepTime_2 = fStepTime_1 * 9/10
	if (Math.abs(fThisDist - fTargDist) < fMiniDist)
	{
		return fTime_2
	}
	else if (fThisDist > fTargDist)
	{
		return fCalcTimePosition(fTime_1, fTime_2 - fStepTime_2, fStepTime_2, fTargDist)
	}
	else if (fThisDist < fTargDist)
	{
		return fCalcTimePosition(fTime_1, fTime_2 + fStepTime_2, fStepTime_2, fTargDist)
	}
	// this should never happen
//	else
//	{
//		return fTime_2
//	}
}

function fGetAngleDelta(fTime_1, fTime_2)
{
	var thisDiv_1 = vnormalize(tDerivatives(fTime_1))
	var thisDiv_2 = vnormalize(tDerivatives(fTime_2))
	var angle_1 = Math.acos(thisDiv_1[0]) * 180/Math.PI
	var angle_2 = Math.acos(thisDiv_2[0]) * 180/Math.PI
	return Math.abs(angle_1 - angle_2)
}

function vConstructSpline(fTime, tRow, sPart)
{
	var thisCoo = tCoordinates(fTime)
	var thisDiv = vnormalize(tDerivatives(fTime))
	var thisZCoo = tRow[0]
	var thisCol = tRow[4]
	var rotxMat = tRow[5]
	var transY = tRow[2]
	var thisMat =
	[
		[ thisDiv[0], thisDiv[1], 0],		// |A,D,G|
		[-thisDiv[1], thisDiv[0], 0],		// |B,E,H|
		[0, 0, 1]				// |C,F,I|
	]
	var outpMat = [[],[],[]]
	outpMat[0][0] = rotxMat[0][0] * thisMat[0][0] + rotxMat[0][1] * thisMat[1][0] + rotxMat[0][2] * thisMat[2][0]	// c00 = a00b00 + a01b10 + a02b20	// |c00,c01,c02|
	outpMat[0][1] = rotxMat[0][0] * thisMat[0][1] + rotxMat[0][1] * thisMat[1][1] + rotxMat[0][2] * thisMat[2][1]	// c01 = a00b01 + a01b11 + a02b21	// |c10,c11,c12|
	outpMat[0][2] = rotxMat[0][0] * thisMat[0][2] + rotxMat[0][1] * thisMat[1][2] + rotxMat[0][2] * thisMat[2][2]	// c02 = a00b02 + a01b12 + a02b22	// |c20,c21,c22|
	outpMat[1][0] = rotxMat[1][0] * thisMat[0][0] + rotxMat[1][1] * thisMat[1][0] + rotxMat[1][2] * thisMat[2][0]	// c10 = a10b00 + a11b10 + a12b20
	outpMat[1][1] = rotxMat[1][0] * thisMat[0][1] + rotxMat[1][1] * thisMat[1][1] + rotxMat[1][2] * thisMat[2][1]	// c11 = a10b01 + a11b11 + a12b21
	outpMat[1][2] = rotxMat[1][0] * thisMat[0][2] + rotxMat[1][1] * thisMat[1][2] + rotxMat[1][2] * thisMat[2][2]	// c12 = a10b02 + a11b12 + a12b22
	outpMat[2][0] = rotxMat[2][0] * thisMat[0][0] + rotxMat[2][1] * thisMat[1][0] + rotxMat[2][2] * thisMat[2][0]	// c20 = a20b00 + a21b10 + a22b20
	outpMat[2][1] = rotxMat[2][0] * thisMat[0][1] + rotxMat[2][1] * thisMat[1][1] + rotxMat[2][2] * thisMat[2][1]	// c21 = a20b01 + a21b11 + a22b21
	outpMat[2][2] = rotxMat[2][0] * thisMat[0][2] + rotxMat[2][1] * thisMat[1][2] + rotxMat[2][2] * thisMat[2][2]	// c22 = a20b02 + a21b12 + a22b22
	sOutString += '1 ' + thisCol + ' ' + thisCoo[0] + ' ' + (thisCoo[1] + transY) + ' ' + thisZCoo + ' ' + outpMat[0][0] + ' ' + outpMat[1][0] + ' ' + outpMat[2][0] + ' ' + outpMat[0][1] + ' ' + outpMat[1][1] + ' ' + outpMat[2][1] + ' ' + outpMat[0][2] + ' ' + outpMat[1][2] + ' ' + outpMat[2][2] + ' ' + sPart + '\n'
}

function vDoStuff()
{
	for (var i = 0, n = partSelect.length; i < n; i++)
	{
		var thisRow = partSelect[i]
		var target_distance = thisRow[1]
		var steps_distance_big = target_distance/fGetCurveLength() * 1/0.9
		var isOdd = thisRow[3]
		var fTime_1 = steps_distance_big/2
		var fTime_2 = 0
		var fAngleDelta = 0
		if (isOdd)
		{
			vConstructSpline(fTime_1 - steps_distance_big/4, thisRow, thisRow[7])
			fTime_2 = fCalcTimePosition(fTime_1 - steps_distance_big/2, fTime_1 + steps_distance_big/2, steps_distance_big, target_distance)
			fAngleDelta = fGetAngleDelta(fTime_1, fTime_2)
			//WScript.Echo(fAngleDelta)
			fTime_1 = fTime_2
			if (fAngleDelta > 6)
				return 1
		}
		while (fTime_1 <= (1 - steps_distance_big/2))
		{
			vConstructSpline(fTime_1, thisRow, thisRow[6])
			fTime_2 = fCalcTimePosition(fTime_1, fTime_1 + steps_distance_big, steps_distance_big, target_distance)
			fAngleDelta = fGetAngleDelta(fTime_1, fTime_2)
			//WScript.Echo(fAngleDelta)
			fTime_1 = fTime_2
			if (fAngleDelta > 6)
				return 1
		}
		// may not always be the case depending on the shape and size of the curve
		if (isOdd)
		{
			vConstructSpline(fTime_1 - steps_distance_big/4, thisRow, thisRow[7])
			fTime_2 = fCalcTimePosition(fTime_1 - steps_distance_big/2, fTime_1 + steps_distance_big/2, steps_distance_big, target_distance)
			fAngleDelta = fGetAngleDelta(fTime_1, fTime_2)
			//WScript.Echo(fAngleDelta)
			fTime_1 = fTime_2
			if (fAngleDelta > 6)
				return 1
		}
	}
	return 0
}

function vWriteOutput()
{
	var OutputFileObject = fso.OpenTextFile(OutputFileName, 2, 1, 0)
	OutputFileObject.Write(sOutString)
	OutputFileObject.Close()
}
