/*
 * D24_GloveForDeaf_Amit.c
 *
 * Created: 10/4/2022 5:46:15 PM
 * Author : ALKODS
 */ 


#include "APP/Processing/Inc/Processing.h"


int main(void)
{
	Flexsensor_Init();
	LCD_Init();
    
	uint8 sign;
    while (1) 
    {
		sign =CheckSign();
		TranslateSign(sign);
    }
	
}

