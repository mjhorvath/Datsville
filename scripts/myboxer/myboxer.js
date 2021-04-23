// Authors: Michael Horvath
// Version: 1.1.2
// Created: 2011/09/08
// Updated: 2021/04/23
//
// This program searches for parts within a model that can be replaced with 
// simplified variants in order to reduce the complexity (and polygon count) of 
// a model. You need to install the variant parts first before running this 
// program however.
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

var AppName = 'MyBoxer';
var AppVersion = '1.1.0';
var MssgDebug = false;
var MssgVerbose = true;
var BatchReplacementCount = 0;
var BatchLineCount = 0;
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
'cscript myboxer.js [input path] [-o]\n\n' +
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
			WScript.Echo('Invalid parameter \'' + ProgArgs(1) + '\'');
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

	// read the list of boxes and store its contents as an array
	var ScriptPath = WScript.ScriptFullName.replace('myboxer.js', '');
	var BoxListPath = ScriptPath + 'box_list.ini';
	var BoxListObject = fso.OpenTextFile(BoxListPath, 1);
	var BoxListString = BoxListObject.ReadAll();
	BoxListObject.Close();
	BoxListArray = BoxListString.split('\r\n');

	// list of valid file extensions
	var Test_a = /\.[mM][pP][dD]$/;
	var Test_b = /\.[lL][dD][rR]$/;
	var Test_c = /\.[dD][aA][tT]$/;
	var Test_d = /\.[xX][mM][pP][dD]$/;

	try
	{
		var InputRoot = InputPath.substring(0, InputPath.lastIndexOf('\\') + 1);
		var InputName = InputPath.substring(InputPath.lastIndexOf('\\') + 1, InputPath.length);
		if (Test_a.test(InputName) || Test_b.test(InputName) || Test_c.test(InputName) || Test_d.test(InputName))
		{
			if (InputRoot == '')
			{
				InputRoot = ScriptPath;
			}
			Convert_File(InputRoot, InputName);
		}
		else
		{
			WScript.Echo('Invalid file type: input file must have an .dat, .ldr, .mpd, or .xmpd extension.');
		}
	}
	catch (e_1)
	{
		WScript.echo('Error1 type: ' + e_1);
		WScript.echo('Error1 desc: ' + e_1.description);
		try
		{
			var InputRoot = InputPath;
			var FolderObject = fso.GetFolder(InputRoot);
			var FilesCollection = new Enumerator(FolderObject.files);
			while (!FilesCollection.atEnd())
			{
				var InputName = FilesCollection.item().Name;
				if (Test_a.test(InputName) || Test_b.test(InputName) || Test_c.test(InputName) || Test_d.test(InputName))
				{
					Convert_File(InputRoot, InputName);
				}
				// should maybe count skipped files here too
//				else
//				{
//					WScript.Echo('Skipping file: ' + InputName);
//				}
				FilesCollection.moveNext();
			}
		}
		catch (e_2)
		{
			WScript.echo('Error2 type: ' + e_2);
			WScript.echo('Error2 desc: ' + e_2.description);
		}
	}
	var BatchReplacementPercent = BatchReplacementCount/BatchLineCount * 100;
	WScript.Echo(BatchReplacementCount + '/' + BatchLineCount + ' (' + BatchReplacementPercent.toFixed(2) + '%) lines altered in ' + FileCount + ' files.');
}

function Convert_File(ThisRoot, ThisName)
{
	WScript.Echo('Processing file root: ' + ThisRoot);
	WScript.Echo('Processing file name: ' + ThisName);

	// read the input file and store its contents as a string
	var InputFileObject = fso.OpenTextFile(ThisRoot + ThisName, 1);
	var OutputFileString = '';
	var FileReplacementCount = 0;
	var FileContents = [];
	while (!InputFileObject.AtEndOfStream)
	{
		var TempString = InputFileObject.ReadLine();
		FileContents.push(TempString);
	}
	InputFileObject.Close();

	var FileLineCount = FileContents.length;
	for (var ii = 0; ii < FileLineCount; ii++)
	{
		var TempString = FileContents[ii];
		for (var i = 0, n = BoxListArray.length; i < n; i++)
		{
			var CheckFirst = /[Bb]\\/;
			var ThisBox = BoxListArray[i];
			if ((ThisBox != '') && (!CheckFirst.test(TempString)) && (TempString.search(ThisBox) != -1))
			{
				TempString = TempString.replace(' ' + ThisBox, ' b\\a' + ThisBox);
				FileReplacementCount += 1;
				break;
			}
		}
		WScript.Echo((ii+1) + '/' + FileLineCount + ': ' + TempString);
		OutputFileString += TempString + '\n';
	}

	var FileReplacementPercent = FileReplacementCount/FileLineCount * 100;
	OutputFileString += '0 // ' + FileReplacementCount + '/' + FileLineCount + ' (' + FileReplacementPercent.toFixed(2) + '%) lines altered using ' + AppName + ' v' + AppVersion + '.\n';

	// write a copy of the converted file
	var OutFile = ThisRoot + ThisName;
	if (!CanOverwrite)
	{
		OutFile = ThisRoot + 'boxed_full_' + ThisName;
	}
	var OutputFileObject = fso.OpenTextFile(OutFile, 2, 1, 0);
	OutputFileObject.Write(OutputFileString);
	OutputFileObject.Close();

	BatchReplacementCount += FileReplacementCount;
	BatchLineCount += FileLineCount;
	FileCount += 1;
}
