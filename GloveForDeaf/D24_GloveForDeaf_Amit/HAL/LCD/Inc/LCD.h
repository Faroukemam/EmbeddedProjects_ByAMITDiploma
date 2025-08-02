/*
 * LCD.h
 *
 *  Created on: Oct 26, 2021
 *      Author: ALKODS
 */

#ifndef LCD_H_
#define LCD_H_

#include "LCD_Cfg.h"
#define F_CPU   16000000
#include <util\delay.h>


void LCD_Init(void);

void LCD_WriteCommand(uint8 cmd);  // rs cmd reg walh data reg

void LCD_WriteChar(uint8 chr);

void LCD_WriteString(uint8* str); //alaa

void LCD_GoTo(uint8 row , uint8  col);	// 3az akteb feh ay mkan ana 3ayzh

void LCD_Clear(void);

void LCD_WriteInteger(sint32 intgr);

void LCD_WriteFloat (float32 fluat);

void LCD_WriteCustom (void);

void ADDCHAR (uint8* Array);

#endif /* LCD_H_ */
