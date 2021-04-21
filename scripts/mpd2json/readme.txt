This program reads an MPD or XMPD model and outputs a JSON representation of the file. 
It currently totally ignores most meta tags such as BFC. It also ignores all 
comments. You should not expect the conversion process to be reversible for 
these reasons.

syntax example: cscript mpd2json.js [input path]

[input path] must be an MPD or XMPD file.

You will need to use an external tool to pretty-print the JSON. There are 
several JSON pretty-printers online.
