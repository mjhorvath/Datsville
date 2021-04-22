set script_path=D:\GitHub\Datsville\scripts\model_joiner
set files_path=D:\GitHub\Datsville\scripts\model_joiner
cd %files_path%
cscript "%script_path%\model_joiner.js" streets_+1_+1_base.ldr streets_+1_+2_base.ldr streets_+1_-1_base.ldr streets_+1_-2_base.ldr streets_+2_+1_base.ldr streets_+2_-1_base.ldr streets_+2_-2_base.ldr streets_-1_+1_base.ldr streets_-1_+2_base.ldr streets_-1_-1_base.ldr streets_-1_-2_base.ldr streets_-2_+1_base.ldr streets_-2_+2_base.ldr streets_-2_-1_base.ldr streets_-2_-2_base.ldr -o streets_base.ldr
pause
