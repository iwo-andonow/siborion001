#include <pic.h>
#include "hockey.h"
#include "init.h"
#include "lcd-1611.h"
#include "delay.h"
#include "at45.h"
#include "key.h"

__CONFIG  (UNPROTECT &  BORDIS & PWRTEN & WDTDIS & INTIO & MCLRDIS);


__EEPROM_DATA('A','T','+','C','I','P','C','S');



unsigned char SOUND;
unsigned char TMP;

unsigned int TMP_LCD;

unsigned char TMP_KEY;
unsigned int  SOUND_ZIKL;
unsigned char DEL_TIC;
unsigned char DEL_SEC;
unsigned char DEL_LCD;

unsigned long  SOUND_SIZE;
unsigned long  SOUND_DEL;

unsigned char SCHET1;
unsigned char SCHET2;


union {
unsigned int ALL;
struct{ 
	unsigned char SEC;
	unsigned char MIN;
} PART;
} TIME;


unsigned char RESIV;
unsigned int Kol_Resiv;
unsigned int Nom_Resiv;
unsigned int Kol_Resiv_33;

unsigned char IND[10];

static bit Tic0132;
static bit ChLcd;
static bit Sound;

static bit Save;
signed int Do_Save;



void main(void)
{
Do_Save=-1;
Init();
Spi_Init();
RS_Init();
Nom_Resiv=0;

IND[0]=IND[1]=IND[2]=IND[3]=IND[4]=IND[5]=IND[6]=IND[7]=IND[8]=IND[9]=Nom_Resiv;


for (;;)
	{
	if (Do_Save>=0)
		{
		Start_Write_Flash(Do_Save);
		Kol_Resiv_33=Kol_Resiv=0;
		Save=1;
		Do_Save=-1;
	        TXREG='A';
		}



	if (Tic0132)
		{
		Tic0132=0;

/*
		if ((DEL_LCD++)>=8)
			{
			DEL_LCD=0;

			IND[0]=IND[1]=IND[2]=IND[3]=IND[4]=IND[5]=IND[6]=IND[7]=IND[8]=IND[9]=0;

			TMP_LCD=Kol_Resiv;

			while (TMP_LCD>=100)
				{
				IND[7]++;
				TMP_LCD-=100;
				}

			while (TMP_LCD>=10)
				{
				IND[8]++;
				TMP_LCD-=10;
				}
			while (TMP_LCD>=1)
				{
				IND[9]++;
				TMP_LCD--;
				}


			
			Lcd(IND);
			}
*/


		if (TMP_KEY=Key())
			{
			if (TMP_KEY&0b00000001)
				{Do_Save=Nom_Resiv=200;}

/*
			if (TMP_KEY&0b00000010)
				{
				}
*/
			}
		}
	}
}



void interrupt
Int(void)
{
if (RCIF)
	{
	RCIF=0;

	if (FERR == 1)
		{
		RESIV=RCREG;
		RESIV=RCREG;
	    }

	if (OERR == 1)
		{CREN = 0; CREN = 1;}


	if (Save)
		{
		Kol_Resiv++;

		if (Kol_Resiv>=33)
			{
			Kol_Resiv=0;
			Kol_Resiv_33++;

			SSPBUF=RCREG;

			if (Kol_Resiv_33>=16)
				{
				Save=0;
				Nom_Resiv++;
				DelayMs(1);
				Cs=1;
				DelayMs(50);
				Do_Save=Nom_Resiv;
				}
			else
				{TXREG='A';}
			}
		else
			{SSPBUF=RCREG;}
		}
	}


if (T0IF)
	{
	T0IF=0;
	DEL_TIC++;
	if (DEL_TIC==0)
		{
		DEL_SEC++;
	
		if ((DEL_SEC&0b00000011)==0)
			{Tic0132=1;}
		}
	}


if (INTF)
	{INTF=0;}

if (RABIF)
	{RABIF=0;}

if (TMR1IF)
	{TMR1IF=0;}
}


