extern unsigned char Spi_Out(unsigned char VAL);
extern unsigned char Read_Flash(unsigned int ADR);
extern void Write_Flash(unsigned int ADR, unsigned int SIZE, unsigned char *Str);
extern void Spi_Init(void);
extern void Read_All_Flash(unsigned int ADR);

extern void Start_Write_Flash(unsigned int ADR);


