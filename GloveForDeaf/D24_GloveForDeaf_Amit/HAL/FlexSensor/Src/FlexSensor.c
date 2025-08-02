/*
 * Temp.c
 *
 *  Created on: Feb 18, 2022
 *      Author: ALKODS
 */
#include "../Inc/FlexSensor.h"

void Flexsensor_Init (void)
{
	ADC_voidInit();
}

uint16 Flexsensor_Read (void)
{
	uint16 digital_value , analog_value , flex ;
	digital_value = ADC_read();
	analog_value =(digital_value*5000 / 1024) ;
	flex = analog_value / 10 ;
	return flex ;
}

