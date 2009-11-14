#include <pic.h>
#include "hockey.h"
#include "init.h"
#include "lcd-1611.h"
#include "delay.h"
#include "at45.h"
#include "key.h"
#include "mt-10t11.h"

__CONFIG  (UNPROTECT &  BORDIS & PWRTEN & WDTDIS & INTIO & MCLRDIS); // & CP);


__EEPROM_DATA(6,0,'+','C','I','P','C','S');



unsigned char SOUND;
unsigned char TMP;

unsigned char TMP_LCD;

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

unsigned char IND[10];

unsigned char Key3_DEL;
unsigned char Key4_DEL;


static bit Tic0132;
static bit ChLcd;
static bit Sound;

static bit Save;

static bit Flash;

static bit Start;

signed int Do_Save;

static bit Pause;



void main(void)
{
Do_Save=-1;
Init();
//RS_Init();
Spi_Init();

TIME.PART.MIN=5;
TIME.PART.SEC=0;

SCHET1=0;
SCHET2=0;


/*
Lcd(&IND[0]);
IND[0]=0;
IND[1]=1;
IND[2]=2;
IND[3]=3;
IND[4]=4;
IND[5]=5;
IND[6]=6;
IND[7]=7;
IND[8]=8;
*/


Sound_Dis=0;

SOUND=0b00000000+1;

Led_Out=1;


TIME.PART.SEC=0;
TIME.PART.MIN=EEPROM_READ(0);
if (TIME.PART.MIN>20)
	{TIME.PART.MIN=2;}


if ((!Key1)&&(!Key2))
	{
	Sound=0;
	Cs=1;
	DelayMs(100);
	Sound_Dis=0;
	ChLcd=1;
	Read_All_Flash(2001);
//	Read_All_Flash(101);
	SOUND_DEL=0;
	SOUND_SIZE=(62000);
//	SOUND_SIZE=(11900);
	Sound=1;

	DelayMs(100);
	DelayMs(100);
	DelayMs(100);
	DelayMs(100);

	}



Start=0;

for (;;)
	{

		if (In1)
			{
			if (Key3_DEL==0)
				{
				Key3_DEL=Key_Delay;
				if ((Start)&&(!Pause))
					{
					Sound=0;
					Cs=1;
					DelayMs(100);
					SCHET1++;
					Sound_Dis=0;
					ChLcd=1;
					Read_All_Flash(101);
					SOUND_DEL=0;
					SOUND_SIZE=(11000);
					Sound=1;
					}
				}
			else
				{Key3_DEL=250;}
			}
		else
			{
			if (Key3_DEL)
				{Key3_DEL--;}
			}


		if (In2)
			{
			if (Key4_DEL==0)
				{
				Key4_DEL=Key_Delay;
				if ((Start)&&(!Pause))
					{
					Sound=0;
					Cs=1;
					DelayMs(100);
					SCHET2++;
					Sound_Dis=0;
					ChLcd=1;
					Read_All_Flash(101);
					SOUND_DEL=0;
					SOUND_SIZE=(11000);
					Sound=1;
					}
				}
			else
				{Key4_DEL=250;}
			}
		else
			{
			if (Key4_DEL)
				{Key4_DEL--;}
			}




	if (Tic0132)
		{
		Tic0132=0;

		if ((DEL_LCD++)>=8)
			{
			DEL_LCD=0;
			if ((Start)&&(!Pause)&&(TIME.ALL))
				{
				TIME.ALL--;
				if (TIME.PART.SEC>=60)
					{TIME.PART.SEC=59;}

				if (TIME.ALL==0)
					{
					Start=0;
					Sound_Dis=0;
					ChLcd=1;
					Read_All_Flash(201);
					SOUND_DEL=0;
					SOUND_SIZE=(21000);
					Sound=1;
					}				
				}

			ChLcd=1;
			}
		
		if (ChLcd)
			{
			ChLcd=0;
			IND[0]=IND[1]=IND[2]=IND[3]=IND[4]=IND[5]=IND[6]=IND[7]=IND[8]=IND[9]=0;

			TMP_LCD=SCHET1;
			while (TMP_LCD>=10)
				{
				IND[0]++;
				TMP_LCD-=10;
				}
			if (IND[0]>9)
				{IND[0]=9;}
	
			
			while (TMP_LCD>=1)
				{
				IND[1]++;
				TMP_LCD--;
				}
			if (IND[1]>9)
				{IND[1]=9;}


			IND[2]=15;

			TMP_LCD=SCHET2;
			while (TMP_LCD>=10)
				{
				IND[3]++;
				TMP_LCD-=10;
				}
			if (IND[3]>9)
				{IND[3]=9;}

			while (TMP_LCD>=1)
				{
				IND[4]++;
				TMP_LCD--;
				}
			if (IND[4]>9)
				{IND[4]=9;}



			IND[5]=14;


			TMP_LCD=TIME.PART.MIN;
			while (TMP_LCD>=1)
				{
				IND[6]++;
				TMP_LCD--;
				}

			Flash^=1;
			if (Flash)
				{IND[7]=15;}
			else
				{IND[7]=14;}

			TMP_LCD=TIME.PART.SEC;
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

			IND[0]=0;
			IND[1]=1;
			IND[2]=2;
			IND[3]=3;
			IND[4]=4;
			IND[5]=5;
			IND[6]=6;
			IND[7]=7;
			IND[8]=8;
			IND[9]=9;

			Lcd(IND);
			}

		if (TMP_KEY=Key())
			{
			if (TMP_KEY&0b00010001)
				{
				Sound=0;
				Cs=1;
				DelayMs(100);
				Start=0;
				TIME.PART.SEC=0;
				TIME.PART.MIN=EEPROM_READ(0);
				TIME.PART.MIN++;
				if (TIME.PART.MIN>9)
					{TIME.PART.MIN=2;}
				EEPROM_WRITE(0,TIME.PART.MIN);
				while (WR)
					{}
				Sound_Dis=0;
				ChLcd=1;
				Read_All_Flash(2050);
				SOUND_DEL=0;
				SOUND_SIZE=(528);
				Sound=1;
				}
			
			if (TMP_KEY&0b00100000)
				{
				Sound=0;
				Cs=1;
				DelayMs(100);
				Start=1; 
				Pause=0; 
				TIME.PART.SEC=0;
				TIME.PART.MIN=EEPROM_READ(0);
				if (TIME.PART.MIN>20)
					{TIME.PART.MIN=2;}
				SCHET1=SCHET2=0;
				Sound_Dis=0;
				ChLcd=1;
				Read_All_Flash(1);
				SOUND_DEL=0;
				SOUND_SIZE=(3500);
				Sound=1;
				}


			if (TMP_KEY&0b00000010)
				{
				if (Start)
					{Pause^=1;}
				Cs=1;
				DelayMs(100);
				Sound_Dis=0;
				ChLcd=1;
				Read_All_Flash(2050);
				SOUND_DEL=0;
				SOUND_SIZE=(528);
				Sound=1;
				}

/*
			if (TMP_KEY&0b00000100)
				{
				if ((Start)&&(!Pause))
					{
					Sound=0;
					Cs=1;
					DelayMs(100);
					SCHET1++;
					Sound_Dis=0;
					ChLcd=1;
					Read_All_Flash(1001);
					SOUND_DEL=0;
					SOUND_SIZE=(305000);
					Sound=1;
					}
				}

			if (TMP_KEY&0b00001000)
				{
				if ((Start)&&(!Pause))
					{
					Sound=0;
					Cs=1;
					DelayMs(100);
					SCHET2++;
					Sound_Dis=0;
					ChLcd=1;
					Read_All_Flash(1001);
					SOUND_DEL=0;
					SOUND_SIZE=(305000);
					Sound=1;
					}
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
	RESIV=RCREG;
	RESIV=RCREG;
	}


if (T0IF)
	{
	T0IF=0;
	if (Sound)
		{
		TMP=SSPBUF;
		SSPBUF=0;
		CCP1CON&=0b11001111;
		CCP1CON|=((TMP<<4)&0b00110000);
		CCPR1L=(TMP>>2);
	
		SOUND_DEL++;
		if (SOUND_DEL>=SOUND_SIZE)
			{
			Sound_Dis=1;
			Sound=0;
			Cs=1;
			CCPR1L=100;
			CCP1CON&=0b11001111;
			}
		}


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


