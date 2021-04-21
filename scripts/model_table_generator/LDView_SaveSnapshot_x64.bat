set LDVIEW_EXE="C:\Program Files (x86)\LDraw\LDView\LDView64.exe"
cd "D:\GitHub\Datsville\datsville_source"
for %%a in ( "*.dat", "*.ldr", "*.mpd", "*.xmpd" ) do %LDVIEW_EXE% "%%a" -SaveSnapshot=%%~na.png -PreferenceSet=Quality -SaveActualSize=0 -SaveImageType=1 -SaveZoomToFit=1 -SaveWidth=400 -SaveHeight=300 -DefaultZoom=0.95 -FOV=10 -DefaultLatLong=30,45
pause
