This program reads an MPD or XMPD model and ouputs a JSON representation of 
the model. It ignores all line types except line type 1 and a few recognized 
meta commands. You should not expect the conversion process to be reversible 
for these reasons. The program also will NOT search the file system and read 
sub-model files. That is why only the MPD and XMPD model formats are 
currently supported.

cscript mpd2json.js [input path]

[input path] must be an MPD or XMPD file.

You will need to use an external utility to pretty-print the JSON file. 
There are several JSON pretty-printers online.
