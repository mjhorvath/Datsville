This program reads an MPD or XMPD model and ouputs a JSON representation of it. 
It currently totally ignores most meta tags such as BFC. It also ignores all 
comments. You should not expect the conversion process to be reversible for 
these reasons.

syntax example: cscript mpd2json.js [input path]

[input path] must be an MPD or XMPD file.

XMPD files will work, but the file naming for the top-level object is not 
handled properly in the JSON output yet. You will have to fix the file naming 
manually. Sorry.

You will need to use an external tool to pretty-print the JSON. There are 
several JSON pretty-printers online.
