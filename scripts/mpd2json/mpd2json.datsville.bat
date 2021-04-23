set script_path=D:\GitHub\Datsville\scripts\mpd2json
set model_path=D:\GitHub\Datsville\models_processed
cscript "%script_path%\mpd2json.js" "%model_path%\datsville_rev006.106_inlined_n_boxed_n.xmpd"
::set model_path=D:\GitHub\Datsville\models_source
::cscript "%script_path%\mpd2json.js" "%model_path%\datsville.ldr"
pause
