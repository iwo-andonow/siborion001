#include <pic.h>
#include "delay.h"
#include "mt-10t11.h"


//	CBAFGEDP

//	  A
//	F   B
//	  G
//	E   C
//	  D    P
unsigned const char DIG[16]={
//CBAFGEDP
0b01010101,
0b00000000,
0b00000000,
0b00000000,
0b00000000,
//CBAFGEDP
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00000000,
//CBAFGEDP
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00000000
};


/* Delay function */
static void delay(int time)
{
        int j;
        for(j = 0;j < time; j++);
}


/* Write of one byte */
void wr_i2c(unsigned char data)
{
        int i=0;
        delay(del);
        SCL_LOW();
        delay(del);
        for (i=0;i<8;i++)
		{
                if ((data & 0x80) == 0x80)
					{SDA_HIGH();}
				else
					{SDA_LOW();}

                data = data << 1;
                delay(del);
                SCL_HIGH();
                delay(del);
                SCL_LOW();
                delay(del);
        }
        SDA_LOW();
        delay(del);
        SCL_HIGH();
        delay(del);
        SCL_LOW();
        delay(del);
}

/* I2C STOP function */
void stop_i2c(void)
{
         delay(del);
         SDA_LOW();        /* data low */
         delay(del);
         SCL_HIGH();         /* clk high */
         delay(del);
         SDA_HIGH();         /* data high */
         delay(del);
}

/* I2C START function*/
void start_i2c(void)
{
         delay(del);
         SDA_HIGH();             /* data high */
         delay(del);
         SCL_HIGH();             /* clk high */
         delay(del);
         SDA_LOW();            /* data low */
         delay(del);
         SCL_LOW();            /* clk low */
         delay(del);
}

/* Controlling of Philips LCD-controller PCF8576 */
void Lcd(unsigned char *Str)
{
const char Logo10[10]={0xC0,0xB3,0xA7,0x80,0xF9,0x80,0xB8,0x80,0xF8,0x40};
unsigned char cTMP, i;
/*
IND[0]&=0b00001111;
IND[0]=DIG[IND[0]];

IND[1]&=0b00001111;
IND[1]=DIG[IND[1]];

IND[2]&=0b00001111;
IND[2]=DIG[IND[2]];

IND[3]&=0b00001111;
IND[3]=DIG[IND[3]];

IND[4]&=0b00001111;
IND[4]=DIG[IND[4]];

IND[5]&=0b00001111;
IND[5]=DIG[IND[5]];

IND[6]&=0b00001111;
IND[6]=DIG[IND[6]];

IND[7]&=0b00001111;
IND[7]=DIG[IND[7]];

IND[8]&=0b00001111;
IND[8]=DIG[IND[8]];

IND[9]&=0b00001111;
IND[9]=DIG[IND[9]];
*/


        start_i2c();
//        wr_i2c(0x70);           /* PCF8576 address */
//        wr_i2c(0xE0);           /* Device select   */
//        wr_i2c(0xCD);           /* Mode set (Static) */
//        wr_i2c(0xFB);           /* Bank select 2 */
//        wr_i2c(0xF0);           /* Blink select (0xF0= off/0xF2= on) */
//        wr_i2c(0x00);           /* Switch to data and reset pointer */
//	for (i=0;i<=9;i++)
//		{
//		cTMP=Str[i];
//		cTMP&=0b00001111;
//		cTMP=DIG[cTMP];
//	        wr_i2c(cTMP);
//		}



        wr_i2c(0x70);           /* PCF8576 address */
        wr_i2c(0xCE);           /* Device select   */
        wr_i2c(0xE0);           /* Mode set (Static) */
        wr_i2c(0xF8);           /* Bank select 2 */
        wr_i2c(0xF0);           /* Blink select (0xF0= off/0xF2= on) */
        wr_i2c(0x00);           /* Switch to data and reset pointer */

	for(i=0; i<10; i++) 
		{wr_i2c(Logo10[i]);}

        stop_i2c();


/*
        wr_i2c(IND[0]);            
        wr_i2c(IND[1]);            
        wr_i2c(IND[2]);            
        wr_i2c(IND[3]);            
        wr_i2c(IND[4]);            
        wr_i2c(IND[5]);            
        wr_i2c(IND[6]);            
        wr_i2c(IND[7]);            
        wr_i2c(IND[8]);            
        wr_i2c(IND[9]);            
*/


}
 