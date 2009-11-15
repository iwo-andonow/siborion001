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
//ABFGECDP
0b11101110,
0b01000100,
0b11011010,
0b11010110,
0b01110100,
0b10110110,
0b10111110,
0b11000100,
0b11111110,
0b11110110,
0,
0,
0,
0,
0,
0b00010000
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
unsigned char cTMP, i;

        start_i2c();

        wr_i2c(0x70);           /* PCF8576 address */
        wr_i2c(0xCE);           /* Device select   */
        wr_i2c(0xE0);           /* Mode set (Static) */
        wr_i2c(0xF8);           /* Bank select 2 */
        wr_i2c(0xF0);           /* Blink select (0xF0= off/0xF2= on) */
        wr_i2c(0x00);           /* Switch to data and reset pointer */


	for (i=0;i<=9;i++)
		{
		cTMP=Str[i];
		cTMP&=0b00001111;
		cTMP=DIG[cTMP];
	        wr_i2c(cTMP);
		}

        stop_i2c();

}
 