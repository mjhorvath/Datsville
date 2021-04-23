// Caption: LDraw model flattener
// Authors: Michael Horvath
// Version: 0.2.4
// Created: 2020/02/21
// Updated: 2021/04/22
// 
// This program calculates the positions of MPD sub-models in 3D space after 
// all matrix transformations have been applied. Requires as input a JSON file 
// created using mpd2json. The output is another JSON file.
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

var fso;
var arrayOne = [];
var arrayTwo = [];
var partCount = 0;
var modelCount = 0;
var objectCount = 0;
var outMode = 0;
var usageText = 
'Invalid usage.\n\n' +
'Example:\n' +
'\tcscript jsonflatten.js [input path] [-p|-m|-b]\n' +
'\t[input path] must point to a JSON file.\n' +
'\t[-p] parts only.\n' +
'\t[-s] sub-models only.\n' +
'\t[-b] both parts and sub-models.\n';

// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String/repeat
if (!String.prototype.repeat) {
  String.prototype.repeat = function(count) {
    'use strict';
    if (this == null)
      throw new TypeError('can\'t convert ' + this + ' to object');

    var str = '' + this;
    // To convert string to integer.
    count = +count;
    // Check NaN
    if (count != count)
      count = 0;

    if (count < 0)
      throw new RangeError('repeat count must be non-negative');

    if (count == Infinity)
      throw new RangeError('repeat count must be less than infinity');

    count = Math.floor(count);
    if (str.length == 0 || count == 0)
      return '';

    // Ensuring count is a 31-bit integer allows us to heavily optimize the
    // main part. But anyway, most current (August 2014) browsers can't handle
    // strings 1 << 28 chars or longer, so:
    if (str.length * count >= 1 << 28)
      throw new RangeError('repeat count must not overflow maximum string size');

    var maxCount = str.length * count;
    count = Math.floor(Math.log(count) / Math.log(2));
    while (count) {
       str += str;
       count--;
    }
    str += str.substring(0, maxCount - str.length);
    return str;
  }
}

// only continue if the script is run via Windows Scripting Host
if (typeof(WScript) != 'undefined')
{
	var progArgs = WScript.Arguments;
	var canContinue = true;
	var extensionA = /\.[jJ][sS][oO][nN]$/;
	if (progArgs.length != 2)
		canContinue = false;
	else if (!extensionA.test(progArgs(0)))
		canContinue = false;
	else if (progArgs(1) == '-b')
		outMode = 0;
	else if (progArgs(1) == '-p')
		outMode = 1;
	else if (progArgs(1) == '-m')
		outMode = 2;
	else
		canContinue = false;
	if (canContinue)
	{
		try
		{
			fso = new ActiveXObject('Scripting.FileSystemObject');
			var inputPath = fso.GetFile(progArgs(0)).Path;
			ProcessFile(inputPath);
		}
		catch (e1)
		{
			WScript.echo
			(
				'Error name: '			+ e1.name
				+ '\nError message: '		+ e1.message
				+ '\nError number: '		+ e1.number
				+ '\nError description: '	+ e1.description
			);
		}
	}
	else
		WScript.Echo(usageText);
}

function ProcessFile(thisPath)
{
	WScript.Echo('Processing file: ' + thisPath);

	// read the input file and store its contents as a string
	WScript.Echo('Reading input.');
	var inputFileObject = fso.OpenTextFile(thisPath, 1);
	var inputCodeString = inputFileObject.ReadAll();
	inputFileObject.Close();
//	WScript.Echo(inputCodeString);
	arrayOne = eval('(' + inputCodeString + ')');

	// collect hierarchy info
	WScript.Echo('Walking the tree.');
	var iModel = arrayOne[0];
	var iFile = iModel.fileName;
	var iSubs = iModel.subFiles;
	var iCoos = [0,0,0,1,0,0,0,1,0,0,0,1];
	PushFile(iFile, iCoos, 0);
	WalkTree(iSubs, iCoos, 0);
	modelCount += 1;
	objectCount += 1;

	// write a copy of the output
	WScript.Echo('Writing output.');
	var OutputFileString = ObjToSource(arrayTwo);
	var OutFile = thisPath + '.flattened.json';
	var OutputFileObject = fso.OpenTextFile(OutFile, 2, 1, 0);
	OutputFileObject.Write(OutputFileString);
	OutputFileObject.Close();

	// finishing up
	WScript.Echo('Done.');
	WScript.Echo(partCount + ' parts.');
	WScript.Echo(modelCount + ' models.');
	WScript.Echo(objectCount + ' objects.');
}

function DoMatrix(inCoos1, inCoos2)
{
	var X1 = inCoos1[0], X2 = inCoos2[0];
	var Y1 = inCoos1[1], Y2 = inCoos2[1];
	var Z1 = inCoos1[2], Z2 = inCoos2[2];
	var A1 = inCoos1[3], A2 = inCoos2[3];
	var B1 = inCoos1[4], B2 = inCoos2[4];
	var C1 = inCoos1[5], C2 = inCoos2[5];
	var D1 = inCoos1[6], D2 = inCoos2[6];
	var E1 = inCoos1[7], E2 = inCoos2[7];
	var F1 = inCoos1[8], F2 = inCoos2[8];
	var G1 = inCoos1[9], G2 = inCoos2[9];
	var H1 = inCoos1[10], H2 = inCoos2[10];
	var I1 = inCoos1[11], I2 = inCoos2[11];
	var X3 = A2*X1 + B2*Y1 + C2*Z1 + X2;
	var Y3 = D2*X1 + E2*Y1 + F2*Z1 + Y2;
	var Z3 = G2*X1 + H2*Y1 + I2*Z1 + Z2;
	var A3 = A2*A1 + B2*D1 + C2*G1;
	var B3 = A2*B1 + B2*E1 + C2*H1;
	var C3 = A2*C1 + B2*F1 + C2*I1;
	var D3 = D2*A1 + E2*D1 + F2*G1;
	var E3 = D2*B1 + E2*E1 + F2*H1;
	var F3 = D2*C1 + E2*F1 + F2*I1;
	var G3 = G2*A1 + H2*D1 + I2*G1;
	var H3 = G2*B1 + H2*E1 + I2*H1;
	var I3 = G2*C1 + H2*F1 + I2*I1;
	return [X3,Y3,Z3,A3,B3,C3,D3,E3,F3,G3,H3,I3];
}

function WalkTree(inSubFiles, inCoos, indentLevel)
{
	for (var k in inSubFiles)
	{
		var kModel = inSubFiles[k];
		var kFile = kModel.fileName;
		var kX = kModel.x, kD = kModel.d;
		var kY = kModel.y, kE = kModel.e;
		var kZ = kModel.z, kF = kModel.f;
		var kA = kModel.a, kG = kModel.g;
		var kB = kModel.b, kH = kModel.h;
		var kC = kModel.c, kI = kModel.i;
		var kCoos = [kX,kY,kZ,kA,kB,kC,kD,kE,kF,kG,kH,kI];
		var outCoos = DoMatrix(kCoos, inCoos);
		var subModels = [];
		var isSubModel = false;
		for (var i in arrayOne)
		{
			var iModel = arrayOne[i];
			var iFile = iModel.fileName;
			var iSubs = iModel.subFiles;
			if (kFile.toLowerCase() == iFile.toLowerCase())
			{
				subModels = iSubs;
				isSubModel = true;
				break;
			}
		}
		if (isSubModel == false)
		{
			if (outMode == 1) {PushFile(kFile, outCoos, indentLevel);}
			partCount += 1;
		}
		else
		{
			if (outMode == 2) {PushFile(kFile, outCoos, indentLevel);}
			modelCount += 1;
		}
		if (outMode == 0) {PushFile(kFile, outCoos, indentLevel);}
		WalkTree(subModels, outCoos, indentLevel+1);
		objectCount += 1;
	}
}

function PushFile(inFileName, inCoos, indentLevel)
{
	WScript.Echo('  '.repeat(indentLevel) + inFileName);
	arrayTwo.push({fileName:inFileName,matrix:FinalRound(inCoos)});
}

function EscapeQuotes(inString)
{
	return inString.replace(/\"/g,'\\"');
}

// https://stackoverflow.com/questions/11832914/round-to-at-most-2-decimal-places-only-if-necessary
// cc by-sa 4.0
// with modifications
function RoundMe(n, p)
{
	if (Number.EPSILON === undefined) {Number.EPSILON = Math.pow(2, -52);}
	var r = 0.5 * Number.EPSILON * n;
	var o = 1;
	while (p-- > 0) {o *= 10;}
	if (n < 0) {o *= -1;}
	return Math.round((n + r) * o) / o;
}

function FinalRound(inArray)
{
	for (var i in inArray) {inArray[i] = RoundMe(inArray[i], 6);}
	return inArray;
}

// https://stackoverflow.com/questions/957537/how-can-i-display-a-javascript-object
// cc by-sa 4.0
// with modifications, no indentation sadly
function ObjToSource(o)
{
	if (!o) {return 'null';}
	var k = '';
	var na = typeof(o.length) == 'undefined';
	var str = '';
	for (var p in o)
	{
		if (na) {k = '"' + p + '":';}
		if (typeof o[p] == 'string') {str += k + '"' + o[p] + '",';}
		else if (typeof o[p] == 'object') {str += k + ObjToSource(o[p]) + ',';}
		else {str += k + o[p] + ',';}
	}
	if (na) {return '{' + str.slice(0, -1) + '}';}
	else {return '[' + str.slice(0, -1) + ']';}
}
