set script_path=D:\GitHub\Datsville\scripts\model_joiner
set files_path=D:\GitHub\Datsville\scripts\model_joiner
cd %files_path%
cscript "%script_path%\model_joiner.js" streets_+1_+1_overlay.ldr streets_+1_+2_overlay.ldr streets_+1_-1_overlay.ldr streets_+1_-2_overlay.ldr streets_+2_+1_overlay.ldr streets_+2_-1_overlay.ldr streets_+2_-2_overlay.ldr streets_-1_+1_overlay.ldr streets_-1_+2_overlay.ldr streets_-1_-1_overlay.ldr streets_-1_-2_overlay.ldr streets_-2_+1_overlay.ldr streets_-2_+2_overlay.ldr streets_-2_-1_overlay.ldr streets_-2_-2_overlay.ldr -o streets_overlay.ldr
pause
