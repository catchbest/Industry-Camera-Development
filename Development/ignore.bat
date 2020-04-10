cd Samples\VC
rd ipch /s /q
del *.sdf *.suo *.log *.user *.filters *.ipch *.aps /s
for /d %%i in (*) do ( 
cd %%i
rd x86 x64 /s /q
del *.sdf *.suo *.log *.user *.filters *.ipch *.aps /s
cd..)
cd..
cd QT
for /d %%i in (*) do ( 
cd %%i
rd x86 x64 /s /q
del *.sdf *.suo *.log *.user *.filters *.ipch *.aps /s
cd..)
cd..
cd OpenCV\VC\KSJDemoVC_Opencv
rd x86 x64 /s /q
del *.sdf *.suo *.log *.user *.filters *.ipch *.aps /s
cd.. 
cd.. 
cd..
cd Halcon\VC\KSJDemoVC_Halcon
rd x86 x64 /s /q
del *.sdf *.suo *.log *.user *.filters *.ipch *.aps /s
cd.. 
cd..
cd C#\KSJDemoCSharp_Halcon
rd obj /s /q
del *.suo /s
cd.. 
cd.. 
cd..
cd C#\KSJDemoCSharp_Callback
rd obj /s /q
del *.suo /s