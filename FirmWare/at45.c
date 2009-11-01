#include <pic.h>
#include "hockey.h"
#include "delay.h"


void Spi_Init(void)
{
SSPSTAT=0b01000000;
SSPCON= 0b00100000;
}



unsigned char Spi_Out(unsigned char VAL)
{
unsigned char Spi_Tmp;
Spi_Tmp=SSPBUF;
SSPBUF=VAL;
//while (!BF)
	//{}
return SSPBUF;
}




void Read_All_Flash(unsigned int ADR)
{
Cs=0;

ADR<<=2;
Spi_Out(0xE8);		//Команда на чтение
Spi_Out(ADR>>8);
Spi_Out(ADR&0b11111111);
Spi_Out(0);

Spi_Out(0);
Spi_Out(0);
Spi_Out(0);
Spi_Out(0);

Spi_Out(0);  //Это ужо чтение первого байта

}








unsigned char Read_Flash(unsigned int ADR)
{
unsigned int i;
unsigned char Tmp;

Cs=0;

ADR<<=2;
Spi_Out(0xE8);		//Команда на чтение
Spi_Out(ADR>>8);
Spi_Out(ADR&0b11111111);
Spi_Out(0);
Spi_Out(0);
Spi_Out(0);
Spi_Out(0);
Spi_Out(0);

Spi_Out(0);

Tmp=SSPBUF;

Cs=1;

return (Tmp);
}




void Write_Flash(unsigned int ADR, unsigned int SIZE, unsigned const char *Str)
{
unsigned int i;
unsigned char Chip;
unsigned int ADR_TMP;

Cs=0;

ADR<<=2;
Spi_Out(0x85);
Spi_Out(ADR>>8);
Spi_Out(ADR&0b11111111);
Spi_Out(0);


for (i=0;i<SIZE;i++)
	{Spi_Out(Str[i]);}

//Spi_Out(0);
//Spi_Out(0);
//Spi_Out(0);
DelayMs(200);
Cs=1;
DelayMs(200);

}




void Start_Write_Flash(unsigned int ADR)
{
unsigned int i;
unsigned char Chip;
unsigned int ADR_TMP;

Cs=0;

ADR<<=2;
Spi_Out(0x85);
Spi_Out(ADR>>8);
Spi_Out(ADR&0b11111111);
Spi_Out(0);

}




 