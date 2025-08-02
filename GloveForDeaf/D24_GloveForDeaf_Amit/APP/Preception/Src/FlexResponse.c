/*
 * FlexResponse.c
 *
 * Created: 10/4/2022 6:15:26 PM
 *  Author: ALKODS
 */ 


#include "../Inc/FlexResponse.h"


uint8	Flex0_u8CheckBending(void)
{
	uint16 Result = 0;
	
	ADC_voidSetChannel(FLEX0_CHANNEL);
	Result = Flexsensor_Read();
	if (Result < FLEX0_BENDING_VREF)
	{
		
		return 1;
	}
	else
	{
		
		return 0;
	}
	
}

uint8	Flex1_u8CheckBending(void)
{
	uint16 Result = 0;
	
	ADC_voidSetChannel(FLEX1_CHANNEL);
	Result = Flexsensor_Read();
	if (Result < FLEX1_BENDING_VREF)
	{
		
		return 1;
	}
	else
	{
		
		return 0;
	}
	
}

uint8	Flex2_u8CheckBending(void)
{
	uint16 Result = 0;
	
	ADC_voidSetChannel(FLEX2_CHANNEL);
	Result = Flexsensor_Read();
	if (Result < FLEX2_BENDING_VREF)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
	
}

uint8	Flex3_u8CheckBending(void)
{
	uint16 Result = 0;
	
	ADC_voidSetChannel(FLEX3_CHANNEL);
	Result = Flexsensor_Read();
	if (Result < FLEX3_BENDING_VREF)
	{
		
		return 1;
	}
	else
	{
		
		return 0;
	}
	
}

uint8	Flex4_u8CheckBending(void)
{
	
	uint16 Result = 0;
	
	ADC_voidSetChannel(FLEX4_CHANNEL);
	Result = Flexsensor_Read();
	if (Result < FLEX4_BENDING_VREF)
	{
		
		return 1;
	}
	else
	{
		return 0;
	}
	
}
