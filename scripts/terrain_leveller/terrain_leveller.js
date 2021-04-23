// LDraw Terrain Leveler
// Author: Michael Horvath
// Version: 0.1.1
// Created: 2015/08/21
// Updated: 2021/04/23
//
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

var MssgDebug = false;
var MssgVerbose = true;
var ReplacementCount = 0;
var FileCount = 0;
var CanOverwrite = 0;
var CanContinue = 0;
var InputPath;
var ThresholdAngle;
var fso;
var WshShell;

// only continue if the script is run via Windows Scripting Host
if (typeof(WScript) != 'undefined')
{
	var usage_text = 
'Invalid number of parameters.\n\n' +
'cscript terrain_stepper.js [input path] [-a <angle>] [-o]\n\n' +
'[input path] the file and path you want to modify.\n' +
'[-a] specifies the angle below which everything is considered flat.\n' +
'[-o] specifies to overwrite the input files. (Optional.)';
	var ProgArgs = WScript.Arguments;
	if ((ProgArgs.length < 3) || (ProgArgs.length > 4))
	{
		WScript.Echo(usage_text);
		WScript.Echo('step 1');
	}
	else if (ProgArgs.length == 3)
	{
		if (ProgArgs(1) == '-a')
		{
			CanContinue = 1;
		}
		else
		{
			WScript.Echo(usage_text);
			WScript.Echo('step 2');
		}
	}
	else if (ProgArgs.length == 4)
	{
		if ((ProgArgs(1) == '-a') && (ProgArgs(3) == '-o'))
		{
			CanOverwrite = 1;
			CanContinue = 1;
		}
		else
		{
			WScript.Echo(usage_text);
			WScript.Echo('step 3');
		}
	}
	if (CanContinue)
	{
		InputPath = ProgArgs(0);
		ThresholdAngle = parseFloat(ProgArgs(2)) * Math.PI/180;
		Get_Input(InputPath);
	}
}

function Get_Input(InputPath)
{
	fso = new ActiveXObject('Scripting.FileSystemObject');
	WshShell = new ActiveXObject('WScript.Shell');

	// list of valid file extensions
	var Test_a = /\.[lL][dD][rR]$/;
	var Test_b = /\.[dD][aA][tT]$/;

	try
	{
		fso.GetFile(InputPath);
		if (Test_a.test(InputPath) || Test_b.test(InputPath))
		{
			var InputRoot = InputPath.substring(0, InputPath.lastIndexOf('\\') + 1);
			var InputFile = InputPath;
			if (InputRoot == '')
			{
				InputRoot = WshShell.CurrentDirectory + '\\';
				InputFile = InputRoot + InputPath;
			}
			Convert_File(InputFile);
		}
		else
		{
			WScript.Echo('Invalid file type: input file must have an .ldr or .dat extension.');
		}
	}
	catch (e_1)
	{
		WScript.echo('Error: ' + e_1);
	}
}

function Get_Angle(vertex_1, vertex_2, vertex_3)
{
	// get two vectors in the triangle
	var vector_u =
	[
		vertex_2[0] - vertex_1[0],
		vertex_2[1] - vertex_1[1],
		vertex_2[2] - vertex_1[2]
	];
	var vector_v =
	[
		vertex_3[0] - vertex_1[0],
		vertex_3[1] - vertex_1[1],
		vertex_3[2] - vertex_1[2]
	];
	// calculate the cross product to get the normal
	var vector_n =
	[
		vector_u[1] * vector_v[2] - vector_u[2] * vector_v[1],
		vector_u[2] * vector_v[0] - vector_u[0] * vector_v[2],
		vector_u[0] * vector_v[1] - vector_u[1] * vector_v[0]
	];
	// get the magnitude or length of the normal vector
	var magnitude_n = Math.sqrt(vector_n[0] * vector_n[0] + vector_n[1] * vector_n[1] + vector_n[2] * vector_n[2]);
	// normalize the normal vector
	vector_n =
	[
		vector_n[0]/magnitude_n,
		vector_n[1]/magnitude_n,
		vector_n[2]/magnitude_n
	];
	// get the normal of the ground plane
	var vector_r = [0,1,0];
	// calculate the dot product of vector_n and vector_r
	var dot_product = vector_n[0] * vector_r[0] + vector_n[1] * vector_r[1] + vector_n[2] * vector_r[2];
	// calculate the angle between vector_n and vector_r
	var angle_between = Math.acos(dot_product);
	// returned value is less than or equal to pi
	return angle_between;
}

function Convert_File(ThisFile)
{
	WScript.Echo('Processing file: ' + ThisFile);

	// read the input file and store its contents as a string
	var InputFileObject = fso.OpenTextFile(ThisFile, 1);
	var OutputFileString = '';
	var LineCount = 0;

	while (!InputFileObject.AtEndOfStream)
	{
		LineCount += 1;
		var TempString = InputFileObject.ReadLine();
		var TempArray = TempString.split(' ');
		var LineType = TempArray[0];
		if (LineType == '3')
		{
			var LineColor = 1;
			var vertex_1 = [parseFloat(TempArray[2]),parseFloat(TempArray[3]),parseFloat(TempArray[4])];
			var vertex_2 = [parseFloat(TempArray[5]),parseFloat(TempArray[6]),parseFloat(TempArray[7])];
			var vertex_3 = [parseFloat(TempArray[8]),parseFloat(TempArray[9]),parseFloat(TempArray[10])];
			var slope_angle = Get_Angle(vertex_1, vertex_2, vertex_3);
			if (slope_angle >= Math.PI - ThresholdAngle)
			{
				LineColor = 2;
				var average_height = (vertex_1[1] + vertex_2[1] + vertex_3[1])/3;
				var rounded_height = Math.round(average_height/24) * 24;
				vertex_1[1] = rounded_height;
				vertex_2[1] = rounded_height;
				vertex_3[1] = rounded_height;
			}
			var NewTempString =
			'3 ' + LineColor + ' ' +
			vertex_1[0] + ' ' + vertex_1[1] + ' ' + vertex_1[2] + ' ' +
			vertex_2[0] + ' ' + vertex_2[1] + ' ' + vertex_2[2] + ' ' +
			vertex_3[0] + ' ' + vertex_3[1] + ' ' + vertex_3[2];
			OutputFileString += NewTempString + '\r\n';
		}
		else
		{
			OutputFileString += TempString + '\r\n';
		}
	}

	OutputFileString += '0 Mesh modified using "terrain_leveller.js" by Michael Horvath.\r\n';
	InputFileObject.Close();

	// write a copy of the converted file
	var OutFile = ThisFile;
	if (!CanOverwrite)
	{
		OutFile += '.new.ldr';
	}
	var OutputFileObject = fso.OpenTextFile(OutFile, 2, 1, 0);
	OutputFileObject.Write(OutputFileString);
	OutputFileObject.Close();

//	WScript.Echo('Done.');
}
