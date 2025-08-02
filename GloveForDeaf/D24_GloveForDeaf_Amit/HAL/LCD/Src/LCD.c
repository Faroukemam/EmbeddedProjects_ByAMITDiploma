/*
 * LCD.c
 *
 *  Created on: Oct 26, 2021
 *      Author: ALKODS
 */

#include "../Inc/LCD.h"

#define NO_CSTOM_CHAR		  8
#define NO_CSTOM_CHAR_BYTES   8

uint8 customChar[NO_CSTOM_CHAR][NO_CSTOM_CHAR_BYTES];
uint8 CHAR_COUNTER = 0;


void ADDCHAR(uint8* Array)
{
	uint8 CHAR_INDEX = 0;
	for (CHAR_INDEX=0;CHAR_INDEX < NO_CSTOM_CHAR_BYTES; CHAR_INDEX++)
	{
		customChar[CHAR_COUNTER][CHAR_INDEX] = Array[CHAR_INDEX];
	}
	CHAR_COUNTER++;
}


void Lcd_WriteCustom(void)
{
	uint8 loc_ByteIndex=0;
	uint8 loc_CharIndx=0;
	CHAR_COUNTER=0;
	for (loc_CharIndx=0;loc_CharIndx<NO_CSTOM_CHAR;loc_CharIndx++)
	{
		LCD_WriteCommand(0x40 +(loc_CharIndx*8));
		for (loc_ByteIndex =0; loc_ByteIndex<NO_CSTOM_CHAR_BYTES;loc_ByteIndex++)
		{
			LCD_WriteChar(customChar[loc_CharIndx][loc_ByteIndex]);
		}
	}
	LCD_WriteCommand(0x02);  // kadh 3malth return to home
	
}


void LCD_Init(void)
{
	#if LCD_MODE  ==  8 //init the pins dir in 8bit mode

	DIO_SetPinDir(LCD_8BIT_CMD_PORT,LCD_RS_PIN, DIO_PIN_OUTPUT );
	DIO_SetPinDir(LCD_8BIT_CMD_PORT,LCD_RW_PIN, DIO_PIN_OUTPUT );
	DIO_SetPinDir(LCD_8BIT_CMD_PORT,LCD_E_PIN, DIO_PIN_OUTPUT );
	DIO_SetPortDir(LCD_8BIT_DATA_PORT,DIO_PORT_OUTPUT);

	_delay_ms(100);
	// send commands to lcd for init as 8 bit mode
	LCD_WriteCommand(0x38);  // sad3et kadh fun write 0x38
	LCD_WriteCommand(0x0c);     //kadh close cursor
	LCD_WriteCommand(0x01);    //kadh clear lcd
	LCD_WriteCommand(0x06);   // kadh cursor right or inc
	LCD_WriteCommand(0x02);  // kadh 3malth return to home
	
	#elif LCD_MODE == 4 //init the pins dir in 4bit mode

	DIO_SetPinDir(LCD_4BIT_CMD_PORT,LCD_RS_PIN, DIO_PIN_OUTPUT );
	DIO_SetPinDir(LCD_4BIT_CMD_PORT,LCD_RW_PIN, DIO_PIN_OUTPUT );
	DIO_SetPinDir(LCD_4BIT_CMD_PORT,LCD_E_PIN, DIO_PIN_OUTPUT );

	DIO_SetPinDir(LCD_4BIT_DATA_PORT, D4_PIN, DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT, D5_PIN, DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT, D6_PIN, DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT, D7_PIN, DIO_PIN_OUTPUT);

	_delay_ms(100);
	// send commands to lcd for init as 4 bit mode
	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	Lcd_WriteCustom();
	LCD_WriteCommand(0x0c);     //kadh close cursor
	LCD_WriteCommand(0x01);    //kadh clear lcd
	LCD_WriteCommand(0x06);   // kadh cursor right or inc
	LCD_WriteCommand(0x02);  // kadh 3malth return to home
	#endif
}

void LCD_WriteCommand(uint8 cmd)  // rs cmd reg walh data reg
{
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_LOW );
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW );
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );

	PORTB = (cmd & 0xf0)|(PORTB & 0x0f);

	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1); // bta3 latch
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );

	PORTB = (cmd << 4)|(PORTB & 0x0f);

	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1); // bta3 latch
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );

	_delay_ms(5);
}
void LCD_WriteChar(uint8 chr)
{
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_HIGH ); // Rs High bass kadh htktb 3lah data reg
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW );
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );

	PORTB = (chr & 0xf0)|(PORTB & 0x0f);

	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1); // bta3 latch
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );

	PORTB = (chr << 4)|(PORTB & 0x0f);

	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1); // bta3 latch
	DIO_SetPinVal(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );

	_delay_ms(5);
}

void LCD_WriteString(uint8* str)
{
	uint8 i=0;
	while(str[i] != '\0')
	{
		LCD_WriteChar(str[i]);
		i++;
	}
}
void LCD_GoTo(uint8 row , uint8  col) // 3az akteb feh ay mkan ana 3ayzh
{
	uint8 pos[2]={0x80,0xc0};
	LCD_WriteCommand(pos[row]+col);
}
void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}

void LCD_WriteInteger(sint32 integr)
{
	sint32 y= 1 ;

	if (integr <0)
	{
		LCD_WriteChar('-');
		integr *= -1;
	}
	while (integr > 0)
	{
		y = ((y*10)+(integr%10));
		integr /= 10;
	}
	while (y>1)
	{
		LCD_WriteChar(((y%10)+48));
		y /= 10;
	}
	/*LCD_WriteChar(integr/1000+'0');
	LCD_WriteChar(integr%1000/100+'0');
	LCD_WriteChar(integr%1000%100/10+'0');
	LCD_WriteChar(integr%1000%100%10+'0');*/
}
void LCD_WriteFloat (float32 fluat)
{
	uint16 intpart =0;
	float32 fractiontemp = 0;
	uint16 fractionpart = 0;

	intpart = (uint16) fluat;
	fractiontemp = fluat - intpart;
	fractionpart = fractiontemp*100;
	LCD_WriteInteger(intpart);
	LCD_WriteChar('.');
	LCD_WriteInteger(fractionpart);
}

