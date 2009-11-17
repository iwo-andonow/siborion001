del *.obj
del *.cce
del *.cof
del *.mcs


"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\save.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\init.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 

"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\lcd-1611.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 

"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\delay.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\key.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -C C:\_snv\siborion\hockey\FirmWare\at45.c -q --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 

"C:\Program Files\HI-TECH Software\PICC\std\9.60\bin\picc.exe" -osave.cof -msave.map --summary=default --output=default save.obj init.obj lcd-1611.obj delay.obj key.obj at45.obj --chip=16F690 -P --runtime=default --opt=default -D__DEBUG=1 -g --asmlist "--errformat=Error   [%n] %f; %l.%c %s" "--msgformat=Advisory[%n] %s" "--warnformat=Warning [%n] %f; %l.%c %s" 
