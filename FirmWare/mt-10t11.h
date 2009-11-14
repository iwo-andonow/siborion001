#define	SCL		RA4		/* clock on port B bit 2 */
#define	SCL_DIR		TRISA4

#define SDA             RA2             /* data on port B bit 1 */
#define	SDA_DIR		TRISA2
#define I2CTRIS TRISA

#define I2C_INPUT	1		/* data direction input */
#define I2C_OUTPUT	0		/* data direction output */

#define SCL_HIGH() SCL = 1; SCL_DIR = I2C_OUTPUT
#define SCL_LOW()  SCL = 0; SCL_DIR = I2C_OUTPUT
#define SDA_HIGH() SDA = 1; SDA_DIR = I2C_OUTPUT
#define SDA_LOW()  SDA = 0; SDA_DIR = I2C_OUTPUT

#define del 50

extern void Lcd(unsigned char *Str);  


