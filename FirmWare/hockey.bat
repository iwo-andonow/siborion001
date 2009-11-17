del *.obj
del *.cce
del *.cof
del *.mcs
rem "C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"hockey.cce" "hockey.c" -O"hockey.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
rem "C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"init.cce" "init.c" -O"init.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
rem "C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"lcd-1611.cce" "lcd-1611.c" -O"lcd-1611.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
rem "C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"delay.cce" "delay.c" -O"delay.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
rem "C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"key.cce" "key.c" -O"key.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
rem "C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C -E"at45.cce" "at45.c" -O"at45.obj" -Zg9 -O -ASMLIST -Q -MPLAB -16F690
rem "C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -E"hockey.lde" "C:\_svn\siborion\hockey\FirmWare\hockey.obj" "C:\_svn\siborion\hockey\FirmWare\init.obj" "C:\_svn\siborion\hockey\FirmWare\lcd-1611.obj" "C:\_svn\siborion\hockey\FirmWare\delay.obj" "C:\_svn\siborion\hockey\FirmWare\key.obj" "C:\_svn\siborion\hockey\FirmWare\at45.obj" -M"hockey.map" -O"hockey.cof" -O"hockey.hex" -Q -MPLAB -16F690


"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\hockey.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\init.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
rem "C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\lcd-1611.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\delay.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\key.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\at45.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\i2c.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 



rem "C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\mt-10t11.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\lcd-1611.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 


rem "C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -ohockey.cof -mhockey.map --summary=default --output=default hockey.obj init.obj delay.obj key.obj at45.obj mt-10t11.obj --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -ohockey.cof -mhockey.map --summary=default --output=default hockey.obj init.obj delay.obj key.obj at45.obj lcd-1611.obj --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 










