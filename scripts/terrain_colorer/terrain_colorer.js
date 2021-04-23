// Caption: LDraw Terrain Colorer
// Authors: Michael Horvath
// Version: 1.0.4
// Created: 2013/10/27
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
var fso;
var WshShell;

// only continue if the script is run via Windows Scripting Host
if (typeof(WScript) != 'undefined')
{
	var ProgArgs = WScript.Arguments;
	if ((ProgArgs.length < 1) || (ProgArgs.length > 2))
	{
		var usage_text = 
'Invalid number of parameters.\n\n' +
'cscript terrain_colorer.js [input path] [-o]\n\n' +
'[input path] may be a file or folder.\n' +
'[-o] specifies to overwrite the input files.';
		WScript.Echo(usage_text);
	}
	else if (ProgArgs.length == 1)
	{
		if (ProgArgs(0) != '-o')
		{
			CanContinue = 1;
		}
	}
	else if (ProgArgs.length == 2)
	{
		if (ProgArgs(1) == '-o')
		{
			CanOverwrite = 1;
			CanContinue = 1;
		}
		else
		{
			WScript.Echo('Invalid parameter ' + ProgArgs(1));
		}
	}
	if (CanContinue)
	{
		var InputPath = ProgArgs(0);
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

function Convert_File(ThisFile)
{
	WScript.Echo('Processing file: ' + ThisFile);

	// read the input file and store its contents as a string
	var InputFileObject = fso.OpenTextFile(ThisFile, 1);
	var OutputFileString = '';
	var LineCount = 0;

	while (!InputFileObject.AtEndOfStream)
	{
		var TempString = InputFileObject.ReadLine();
		var TempArray = TempString.split(' ');
		if (TempArray[0] == '3')
		{
			LineCount += 1;
			if (LineCount % 2 == 1)
			{
				var OutColor = '11';
			}
			else
			{
				var OutColor = '13';
			}
			var NewTempString = '';
			for (var i = 0, n = TempArray.length; i < n; i++)
			{
				if (i == 1)
				{
					NewTempString += OutColor + ' ';
				}
				else
				{
					NewTempString += TempArray[i] + ' ';
				}
			}
			OutputFileString += NewTempString + '\r\n';
		}
		else
		{
			OutputFileString += TempString + '\r\n';
		}
	}

	InputFileObject.Close();
	OutputFileString += '0 Mesh modified using "terrain_colorer.js" by Michael Horvath.\r\n';

	// write a copy of the converted file
	var OutFile = ThisFile;
	if (!CanOverwrite)
	{
		OutFile += '.new.ldr';
	}
	var OutputFileObject = fso.OpenTextFile(OutFile, 2, 1, 0);
	OutputFileObject.Write(OutputFileString);
	OutputFileObject.Close();

//	WScript.Echo('Done.')
}
