void interrupt
Int(void)
{
if (RCIF)
	{
	RCIF=0;

	if (FERR == 1)
		{
		RESIV[Kol_Resiv++]=RCREG;
		RESIV[Kol_Resiv++]=RCREG;
	        }

	if (OERR == 1)
		{CREN = 0; CREN = 1;}

	RESIV[Kol_Resiv]=RCREG;

	Kol_Resiv++;
        RESIV[Kol_Resiv]=0;

	if (Kol_Resiv>=75)
		{Kol_Resiv=75;}
	}


if (T0IF)
	{
	T0IF=0;
	Cur_Wave();
	}


if (INTF)
	{INTF=0;}

if (RABIF)
	{RABIF=0;}

if (TMR1IF)
	{TMR1IF=0;}
}

