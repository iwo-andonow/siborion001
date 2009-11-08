del *.obj
del *.cce
del *.cof
del *.mcs
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"save.cce" "save.c" -O"save.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"init.cce" "init.c" -O"init.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"lcd-1611.cce" "lcd-1611.c" -O"lcd-1611.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"delay.cce" "delay.c" -O"delay.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"key.cce" "key.c" -O"key.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"at45.cce" "at45.c" -O"at45.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -E"save.lde" "C:\_svn\siborion\hockey\FirmWare\save.obj" "C:\_svn\siborion\hockey\FirmWare\init.obj" "C:\_svn\siborion\hockey\FirmWare\lcd-1611.obj" "C:\_svn\siborion\hockey\FirmWare\delay.obj" "C:\_svn\siborion\hockey\FirmWare\key.obj" "C:\_svn\siborion\hockey\FirmWare\at45.obj" -M"save.map" -O"save.cof" -O"save.hex" -Q -MPLAB -16F690





