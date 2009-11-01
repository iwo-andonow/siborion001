del *.obj
del *.cce
del *.cof
del *.mcs
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"hockey.cce" "hockey.c" -O"hockey.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"init.cce" "init.c" -O"init.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"lcd-1611.cce" "lcd-1611.c" -O"lcd-1611.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"delay.cce" "delay.c" -O"delay.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"key.cce" "key.c" -O"key.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"at45.cce" "at45.c" -O"at45.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -E"hockey.lde" "C:\_SVN\51\hokkey\soft\pic\hockey.obj" "C:\_SVN\51\hokkey\soft\pic\init.obj" "C:\_SVN\51\hokkey\soft\pic\lcd-1611.obj" "C:\_SVN\51\hokkey\soft\pic\delay.obj" "C:\_SVN\51\hokkey\soft\pic\key.obj" "C:\_SVN\51\hokkey\soft\pic\at45.obj" -M"hockey.map" -O"hockey.cof" -O"hockey.hex" -Q -MPLAB -16F690





