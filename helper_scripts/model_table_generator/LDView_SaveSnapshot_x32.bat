set LDVIEW_EXE="C:\Program Files (x86)\LDView\LDView.exe"
cd "W:\LDraw\datsville\svn\trunk\datsville"
for %%a in ( "*.dat", "*.ldr", "*.mpd" ) do %LDVIEW_EXE% "%%a" -SaveSnapshot=%%~na.png -PreferenceSet=DatsvilleSVN -SaveActualSize=0 -SaveImageType=1 -SaveZoomToFit=1 -SaveWidth=400 -SaveHeight=300 -DefaultZoom=0.95 -FOV=10 -DefaultLatLong=30,45
pause
