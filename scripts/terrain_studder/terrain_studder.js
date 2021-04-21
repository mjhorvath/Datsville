// LDraw Terrain Studder
// Author: Michael Horvath
// Version: 1.0.0
// Created: 2018/03/26
// Updated: 2018/03/26
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

var AppVersion = "1.0.0"
var MssgDebug = false
var MssgVerbose = true
var ReplacementCount = 0
var FileCount = 0
var CanOverwrite = 0
var CanContinue = 0
var fso
var WshShell

// only continue if the script is run via Windows Scripting Host
if (typeof(WScript) != 'undefined')
{
	var ProgArgs = WScript.Arguments
	if ((ProgArgs.length < 1) || (ProgArgs.length > 2))
	{
		var usage_text = 
'Invalid number of parameters.\n\n' +
'cscript terrain_colorer.js [input path] [-o]\n\n' +
'[input path] may be a file or folder.\n' +
'[-o] specifies whether to overwrite the input files.'
		WScript.Echo(usage_text)
	}
	else if (ProgArgs.length == 1)
	{
		if (ProgArgs(0) != '-o')
		{
			CanContinue = 1
		}
	}
	else if (ProgArgs.length == 2)
	{
		if (ProgArgs(1) == '-o')
		{
			CanOverwrite = 1
			CanContinue = 1
		}
		else
		{
			WScript.Echo('Invalid parameter ' + ProgArgs(1))
		}
	}
	if (CanContinue)
	{
		var InputPath = ProgArgs(0)
		Get_Input(InputPath)
	}
}

function Get_Input(InputPath)
{
	fso = new ActiveXObject('Scripting.FileSystemObject')
	WshShell = new ActiveXObject('WScript.Shell')

	// list of valid file extensions
	var Test_a = /\.[lL][dD][rR]$/
	var Test_b = /\.[dD][aA][tT]$/

	try
	{
		fso.GetFile(InputPath)
		if (Test_a.test(InputPath) || Test_b.test(InputPath))
		{
			var InputRoot = InputPath.substring(0, InputPath.lastIndexOf('\\') + 1)
			var InputFile = InputPath
			if (InputRoot == '')
			{
				InputRoot = WshShell.CurrentDirectory + '\\'
				InputFile = InputRoot + InputPath
			}
			Convert_File(InputFile)
		}
		else
		{
			WScript.Echo('Invalid file type: input file must have an .ldr or .dat extension.')
		}
	}
	catch (e_1)
	{
		WScript.echo('Error: ' + e_2)
	}
}

function Convert_File(ThisFile)
{
	WScript.Echo('Processing file: ' + ThisFile)

	var InputLineArray = []
	var LineCount = 0
	var OutputFileString = ''

	// read the input file and store its contents as a table
	var InputFileObject = fso.OpenTextFile(ThisFile, 1)
	while (!InputFileObject.AtEndOfStream)
	{
		var TempString = InputFileObject.ReadLine()
		var TempArray = TempString.split(' ')
		if (TempArray[0] == '3')
			InputLineArray.push(TempString)
		OutputFileString += TempString + '\r\n'
	}
	InputFileObject.Close()

	// this loop starts at 1 on purpose
	for (var i = 1, n = InputLineArray.length; i < n; i += 2)
	{
		var ThisLineArray = InputLineArray[i].split(' ')
		var LastLineArray = InputLineArray[i-1].split(' ')
		var FirstTriColor = parseInt(ThisLineArray[1])

		for (var j = 0, o = ThisLineArray.length; j < o; j++)
			ThisLineArray[j] = parseFloat(ThisLineArray[j])
		for (var j = 0, o = LastLineArray.length; j < o; j++)
			LastLineArray[j] = parseFloat(LastLineArray[j])

		var FirstVertCooY = ThisLineArray[3]
		if ((ThisLineArray[6] != FirstVertCooY) || (ThisLineArray[9] != FirstVertCooY) || (LastLineArray[3] != FirstVertCooY) || (LastLineArray[6] != FirstVertCooY) || (LastLineArray[9] != FirstVertCooY))
			continue
		var AllVertMinX = Math.min(ThisLineArray[2], ThisLineArray[5], ThisLineArray[8], LastLineArray[2], LastLineArray[5], LastLineArray[8])
		var AllVertMaxX = Math.max(ThisLineArray[2], ThisLineArray[5], ThisLineArray[8], LastLineArray[2], LastLineArray[5], LastLineArray[8])
		var AllVertMinZ = Math.min(ThisLineArray[4], ThisLineArray[7], ThisLineArray[10], LastLineArray[4], LastLineArray[7], LastLineArray[10])
		var AllVertMaxZ = Math.max(ThisLineArray[4], ThisLineArray[7], ThisLineArray[10], LastLineArray[4], LastLineArray[7], LastLineArray[10])
		var AllVertMidX = (AllVertMinX + AllVertMaxX)/2
		var AllVertMidZ = (AllVertMinZ + AllVertMaxZ)/2
		var TempString = '1 ' + FirstTriColor + ' ' + AllVertMidX + ' ' +  FirstVertCooY + ' ' + AllVertMidZ + ' 1 0 0 0 1 0 0 0 1 stud.dat'
		OutputFileString += TempString + '\r\n'
	}

	OutputFileString += '0 Mesh modified using "terrain_studder.js" version ' + AppVersion + ' by Michael Horvath.\r\n'

	// write a copy of the converted file
	var OutFile = ThisFile
	if (!CanOverwrite)
	{
		OutFile += '.new.ldr'
	}
	var OutputFileObject = fso.OpenTextFile(OutFile, 2, 1, 0)
	OutputFileObject.Write(OutputFileString)
	OutputFileObject.Close()

//	WScript.Echo('Done.')
}
