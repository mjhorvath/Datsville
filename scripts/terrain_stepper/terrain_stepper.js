// Caption: LDraw Terrain Stepper
// Authors: Michael Horvath
// Version: 1.0.3
// Created: 2015/08/19
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
var StepMultiple;
var fso;
var WshShell;

// only continue if the script is run via Windows Scripting Host
if (typeof(WScript) != 'undefined')
{
	var usage_text = 
'Invalid number of parameters.\n\n' +
'cscript terrain_stepper.js [input path] [-n <number>] [-o]\n\n' +
'[input path] is the path to the file you want to modify.\n' +
'[-n] specifies the integer multiple to round the height values to.\n' +
'[-o] indicates that you want to overwrite the input file. (Optional.)';
	var ProgArgs = WScript.Arguments;
	if ((ProgArgs.length < 3) || (ProgArgs.length > 4))
	{
		WScript.Echo(usage_text);
		WScript.Echo('step 1');
	}
	else if (ProgArgs.length == 3)
	{
		if (ProgArgs(1) == '-n')
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
		if ((ProgArgs(1) == '-n') && (ProgArgs(3) == '-o'))
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
		StepMultiple = ProgArgs(2);
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
			var LineColor = TempArray[1];
			// TempArray[2],TempArray[3],TempArray[4],
			// TempArray[5],TempArray[6],TempArray[7],
			// TempArray[8],TempArray[9],TempArray[10]
			var NewTempString = '3 ' + LineColor + ' ' +
				TempArray[2] + ' ' + Math.round(TempArray[3]/StepMultiple) * StepMultiple + ' ' + TempArray[4] + ' ' +
				TempArray[5] + ' ' + Math.round(TempArray[6]/StepMultiple) * StepMultiple + ' ' + TempArray[7] + ' ' +
				TempArray[8] + ' ' + Math.round(TempArray[9]/StepMultiple) * StepMultiple + ' ' + TempArray[10];
			OutputFileString += NewTempString + '\r\n';
		}
		else
		{
			OutputFileString += TempString + '\r\n';
		}
	}

	OutputFileString += '0 Mesh modified using "terrain_stepper.js" by Michael Horvath.\r\n';
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
