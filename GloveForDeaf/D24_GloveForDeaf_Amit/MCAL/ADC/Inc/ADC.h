/*
 * ADC.h
 *
 *  Created on: Feb 18, 2022
 *      Author: ALKODS
 */

#ifndef ADC_H_
#define ADC_H_

#include "../../../LIB/Atmega32_Register.h"
#include "../../../LIB/BIT_Math.h"
#include "ADC_Cfg.h"

void	ADC_voidInit(void);
void	ADC_voidDisable(void);

void	ADC_voidEnableInterrupt(void);
void	ADC_voidDisableInterrupt(void);

void	ADC_voidSetChannel(uint8 ChannelId);
uint16	ADC_read (void);

#endif /* ADC_H_ */
