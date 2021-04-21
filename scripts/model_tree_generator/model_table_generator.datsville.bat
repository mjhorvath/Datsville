set mpdcalcpos_path="D:\GitHub\Datsville\scripts\model_tree_generator"
set jsonmodel_path="D:\GitHub\Datsville\models_processed"
cscript "%mpdcalcpos_path%\model_table_generator.js" "%jsonmodel_path%\datsville_rev006.086_inlined_n_boxed_n.xmpd.json" -m
pause
