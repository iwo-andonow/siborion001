#include <pic.h>
#include "key.h"
#include "hockey.h"

unsigned char Key1_DEL;
unsigned char Key2_DEL;
/*
unsigned char Key3_DEL;
unsigned char Key4_DEL;
unsigned char Key5_DEL;
*/
unsigned char Key(void)
{
unsigned char VAL=0;

/*
if (!Key1)
	{
	if (Key1_DEL==0)
		{
		VAL|=0b00000001;
		Key1_DEL=Key_Delay;
		}
	else
		{Key1_DEL=Key_Delay;}
	}
else
	{
	if (Key1_DEL)
		{Key1_DEL--;}
	}



if (!Key2)
	{
	if (Key2_DEL==0)
		{
		VAL|=0b00000010;
		Key2_DEL=Key_Delay;
		}
	else
		{Key2_DEL=Key_Delay;}
	}
else
	{
	if (Key2_DEL)
		{Key2_DEL--;}
	}
*/


if (!Key1)
	{
	if (Key1_DEL<Key_Long)
		{
		Key1_DEL++;
		if (Key1_DEL==Key_Long)
			{VAL|=0b00010000;}
		}
	}
else
	{
	if (Key1_DEL)
		{
		if (Key1_DEL<Key_Long)
			{VAL|=0b00000001;}
		}
	Key1_DEL=0;
	}


if (!Key2)
	{
	if (Key2_DEL<Key_Long)
		{
		Key2_DEL++;
		if (Key2_DEL==Key_Long)
			{VAL|=0b00100000;}
		}
	}
else
	{
	if (Key2_DEL)
		{
		if (Key2_DEL<Key_Long)
			{VAL|=0b00000010;}
		}
	Key2_DEL=0;
	}






/*
if (!In1)
	{
	if (Key3_DEL==0)
		{
		VAL|=0b00000100;
		Key3_DEL=Key_Delay;
		}
	else
		{Key3_DEL=Key_Delay;}
	}
else
	{
	if (Key3_DEL)
		{Key3_DEL--;}
	}


if (!In2)
	{
	if (Key4_DEL==0)
		{
		VAL|=0b00001000;
		Key4_DEL=Key_Delay;
		}
	else
		{Key4_DEL=Key_Delay;}
	}
else
	{
	if (Key4_DEL)
		{Key4_DEL--;}
	}
*/








return VAL;
}

