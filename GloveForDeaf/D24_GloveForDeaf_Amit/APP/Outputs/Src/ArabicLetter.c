/*
 * ArabicLetter.c
 *
 * Created: 10/3/2022 11:29:27 PM
 *  Author: ALKODS
 */ 

#include "../Inc/ArabicLetter.h"
#include "../../../Services/ArabicHex.h"

#define DELAY    4000

void YOU(void)
{
	LCD_Clear();
	ADDCHAR(ALEF);
	ADDCHAR(NOON);
	ADDCHAR(TAA_END);
	Lcd_WriteCustom();
	
	LCD_WriteChar(2);
	LCD_WriteChar(1);
	LCD_WriteChar(0);
	_delay_ms(DELAY);
}
void IM_WATCHING(void)
{
	LCD_Clear();
	ADDCHAR(ALEF);
	ADDCHAR(NOON);
	ADDCHAR(ALEF_END);
	ADDCHAR(RAA);
	ADDCHAR(QAF);
	ADDCHAR(BAA);
	ADDCHAR(KAF);
	Lcd_WriteCustom();
	
	LCD_WriteChar(6);
	LCD_WriteChar(5);
	LCD_WriteChar(4);
	//LCD_WriteChar(0);
	LCD_WriteChar(0);
	LCD_WriteChar(3);
	LCD_WriteChar(0);
	LCD_WriteChar(' ');
	LCD_WriteChar(2);
	LCD_WriteChar(1);
	LCD_WriteChar(0);
	_delay_ms(DELAY);
}
void REALLY_LOVE_U(void)
{
	LCD_Clear();
	ADDCHAR(HAA);
	ADDCHAR(QAF);
	ADDCHAR(ALEF);
	ADDCHAR(ALEF_END);
	ADDCHAR(BAA);
	ADDCHAR(KAF);
	Lcd_WriteCustom();
	
	LCD_WriteChar(5);
	LCD_WriteChar(4);
	LCD_WriteChar(0);
	LCD_WriteChar(2);
	LCD_WriteChar(' ');
	LCD_WriteChar(3);
	LCD_WriteChar(1);
	LCD_WriteChar(0);
	_delay_ms(DELAY);
}
void LOVE_U(void)
{
	LCD_Clear();
	ADDCHAR(ALEF);
	ADDCHAR(HAA);
	ADDCHAR(BAA);
	ADDCHAR(KAF);
	Lcd_WriteCustom();
	
	LCD_WriteChar(3);
	LCD_WriteChar(2);
	LCD_WriteChar(1);
	LCD_WriteChar(0);
	_delay_ms(DELAY);
}
void THATS_RAHEEB(void)
{
	LCD_Clear();
	ADDCHAR(HEH);
	ADDCHAR(ZALL);
	ADDCHAR(ALEF);
	ADDCHAR(RAA);
	ADDCHAR(YAA);
	ADDCHAR(BAA_END);
	Lcd_WriteCustom();
	
	LCD_WriteChar(5);
	LCD_WriteChar(4);
	LCD_WriteChar(0);
	LCD_WriteChar(3);
	LCD_WriteChar(' ');
	LCD_WriteChar(2);
	LCD_WriteChar(1);
	LCD_WriteChar(0);
	_delay_ms(DELAY);
}
void I_WISH_U_HAPPY_LIFE(void)
{
	LCD_Clear();
	ADDCHAR(ALEF);
	ADDCHAR(TAA);
	ADDCHAR(MEEM);
	ADDCHAR(NOON);
	ADDCHAR(YAA_END);
	ADDCHAR(LAM);
	ADDCHAR(KAF);
	Lcd_WriteCustom();
	
	LCD_WriteChar(6);
	LCD_WriteChar(5);
	LCD_WriteChar(' ');
	LCD_WriteChar(4);
	LCD_WriteChar(3);
	LCD_WriteChar(2);
	LCD_WriteChar(1);
	LCD_WriteChar(0);
	_delay_ms(DELAY);
	
	
	LCD_Clear();
	ADDCHAR(HAA);//0
	ADDCHAR(YAA);//1
	ADDCHAR(ALEF_END);//2
	ADDCHAR(TEH_MARBOUTA);//3
	ADDCHAR(SEEN);//4
	ADDCHAR(AAN);//5
	ADDCHAR(DALL);//6
	Lcd_WriteCustom();
	
	LCD_WriteChar(3);
	LCD_WriteChar(6);
	LCD_WriteChar(1);
	LCD_WriteChar(5);
	LCD_WriteChar(4);
	LCD_WriteChar(' ');
	LCD_WriteChar(3);
	LCD_WriteChar(2);
	LCD_WriteChar(1);
	LCD_WriteChar(0);
	_delay_ms(DELAY);
	
}
void GOOD_JOB(void)
{
	LCD_Clear();
	ADDCHAR(AAN);
	ADDCHAR(MEEM);
	ADDCHAR(LAM_END);
	ADDCHAR(JEEM);
	ADDCHAR(YAA);
	ADDCHAR(DALL);
	Lcd_WriteCustom();
	
	LCD_WriteChar(5);
	LCD_WriteChar(4);
	LCD_WriteChar(3);
	LCD_WriteChar(' ');
	LCD_WriteChar(2);
	LCD_WriteChar(1);
	LCD_WriteChar(0);
	_delay_ms(DELAY);
}