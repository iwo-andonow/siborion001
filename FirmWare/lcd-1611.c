#include <pic.h>
#include "hockey.h"
#include "delay.h"
#include "lcd-1611.h"

void Lcd(unsigned char *Str) 
{
unsigned char i,j,k,TMP;
//unsigned const char DIG[16]={0b00001010,0b00000001,0b00000010,0b00000011,0b00000100,0b00000101,0b00000110,0b00000111,0b00001000,0b00001001,0b00000000,0,0,0,0,0};
unsigned const char DIG[16]={0b00001010,0b00000001,0b00000010,0b00000011,0b00000100,0b00000101,0b00000110,0b00000111,0b00001000,0b00001001,0b00000000,0,0,0,0,0b00001111};

Lcd_Clock =1;

/*
GIE=0;
for (i=0;i<=9;i++)
	{
	TMP=(Str[i]&0b00001111);
	for (j=0;j<=3;j++)
		{
		if (TMP&(0b00000001<<(3-j)))
			{Lcd_Data=1;}
		else
			{Lcd_Data=0;}
		Lcd_Clock=0;
	        NOP();
	        NOP();
	        NOP();
		Lcd_Clock=1;
		}
	}
GIE=1;
*/


Str[0]&=0b00001111;
Str[0]=DIG[Str[0]];

Str[1]&=0b00001111;
Str[1]=DIG[Str[1]];

Str[2]&=0b00001111;
Str[2]=DIG[Str[2]];

Str[3]&=0b00001111;
Str[3]=DIG[Str[3]];

Str[4]&=0b00001111;
Str[4]=DIG[Str[4]];

Str[5]&=0b00001111;
Str[5]=DIG[Str[5]];

Str[6]&=0b00001111;
Str[6]=DIG[Str[6]];

Str[7]&=0b00001111;
Str[7]=DIG[Str[7]];

Str[8]&=0b00001111;
Str[8]=DIG[Str[8]];

Str[9]&=0b00001111;
Str[9]=DIG[Str[9]];

//GIE=0;

/*
for (j=0;j<=3;j++)
	{
	if (Str[0]&(0b00000001<<(3-j)))
		{Lcd_Data=1;}
	else
		{Lcd_Data=0;}
	Lcd_Clock=0;
        NOP();
        NOP();
        NOP();
        NOP();
	Lcd_Clock=1;
	}
*/

if (Str[0]&0b00001000)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[0]&0b00000100)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[0]&0b00000010)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[0]&0b00000001)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

NOP();
NOP();
NOP();
NOP();



/*
for (j=0;j<=3;j++)
	{
	if (Str[1]&(0b00000001<<(3-j)))
		{Lcd_Data=1;}
	else
		{Lcd_Data=0;}
	Lcd_Clock=0;
        NOP();
        NOP();
        NOP();
        NOP();
	Lcd_Clock=1;
	}
*/


if (Str[1]&0b00001000)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[1]&0b00000100)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[1]&0b00000010)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[1]&0b00000001)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

NOP();
NOP();
NOP();
NOP();


/*
for (j=0;j<=3;j++)
	{
	if (Str[2]&(0b00000001<<(3-j)))
		{Lcd_Data=1;}
	else
		{Lcd_Data=0;}
	Lcd_Clock=0;
        NOP();
        NOP();
        NOP();
        NOP();
	Lcd_Clock=1;
	}
*/

if (Str[2]&0b00001000)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[2]&0b00000100)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[2]&0b00000010)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[2]&0b00000001)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

NOP();
NOP();
NOP();
NOP();


/*
for (j=0;j<=3;j++)
	{
	if (Str[3]&(0b00000001<<(3-j)))
		{Lcd_Data=1;}
	else
		{Lcd_Data=0;}
	Lcd_Clock=0;
        NOP();
        NOP();
        NOP();
        NOP();
	Lcd_Clock=1;
	}
*/

if (Str[3]&0b00001000)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[3]&0b00000100)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[3]&0b00000010)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[3]&0b00000001)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

NOP();
NOP();
NOP();
NOP();


/*
for (j=0;j<=3;j++)
	{
	if (Str[4]&(0b00000001<<(3-j)))
		{Lcd_Data=1;}
	else
		{Lcd_Data=0;}
	Lcd_Clock=0;
        NOP();
        NOP();
        NOP();
        NOP();
	Lcd_Clock=1;
	}
*/
if (Str[4]&0b00001000)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[4]&0b00000100)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[4]&0b00000010)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[4]&0b00000001)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

NOP();
NOP();
NOP();
NOP();


/*
for (j=0;j<=3;j++)
	{
	if (Str[5]&(0b00000001<<(3-j)))
		{Lcd_Data=1;}
	else
		{Lcd_Data=0;}
	Lcd_Clock=0;
        NOP();
        NOP();
        NOP();
        NOP();
	Lcd_Clock=1;
	}
*/

if (Str[5]&0b00001000)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[5]&0b00000100)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[5]&0b00000010)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[5]&0b00000001)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

NOP();
NOP();
NOP();
NOP();

/*
for (j=0;j<=3;j++)
	{
	if (Str[6]&(0b00000001<<(3-j)))
		{Lcd_Data=1;}
	else
		{Lcd_Data=0;}
	Lcd_Clock=0;
        NOP();
        NOP();
        NOP();
        NOP();
	Lcd_Clock=1;
	}
*/
if (Str[6]&0b00001000)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[6]&0b00000100)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[6]&0b00000010)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[6]&0b00000001)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

NOP();
NOP();
NOP();
NOP();

/*
for (j=0;j<=3;j++)
	{
	if (Str[7]&(0b00000001<<(3-j)))
		{Lcd_Data=1;}
	else
		{Lcd_Data=0;}
	Lcd_Clock=0;
        NOP();
        NOP();
        NOP();
        NOP();
	Lcd_Clock=1;
	}
*/
if (Str[7]&0b00001000)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[7]&0b00000100)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[7]&0b00000010)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[7]&0b00000001)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

NOP();
NOP();
NOP();
NOP();

/*
for (j=0;j<=3;j++)
	{
	if (Str[8]&(0b00000001<<(3-j)))
		{Lcd_Data=1;}
	else
		{Lcd_Data=0;}
	Lcd_Clock=0;
        NOP();
        NOP();
        NOP();
        NOP();
	Lcd_Clock=1;
	}
*/
if (Str[8]&0b00001000)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[8]&0b00000100)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[8]&0b00000010)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[8]&0b00000001)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

NOP();
NOP();
NOP();
NOP();


/*
for (j=0;j<=3;j++)
	{
	if (Str[9]&(0b00000001<<(3-j)))
		{Lcd_Data=1;}
	else
		{Lcd_Data=0;}
	Lcd_Clock=0;
        NOP();
        NOP();
        NOP();
        NOP();
	Lcd_Clock=1;
	}
*/

if (Str[9]&0b00001000)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[9]&0b00000100)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[9]&0b00000010)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;

if (Str[9]&0b00000001)
	{Lcd_Data=1;}
else
	{Lcd_Data=0;}
Lcd_Clock=0;
NOP();
NOP();
NOP();
NOP();
Lcd_Clock=1;



//GIE=1;
}
