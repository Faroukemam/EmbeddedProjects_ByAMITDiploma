/*
 * Atmega32_Register.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ALKODS
 */

#ifndef ATMEGA32_REGISTER_H_
#define ATMEGA32_REGISTER_H_
#include "STD.h"

#define PORTA			*((uint8*)0x3B)
#define DDRA			*((uint8*)0x3A)
#define PINA			*((volatile uint8*)0x39)

#define PORTB			*((uint8*)0x38)
#define DDRB			*((uint8*)0x37)
#define PINB			*((volatile uint8*)0x36)

#define PORTC			*((uint8*)0x35)
#define DDRC			*((uint8*)0x34)
#define PINC			*((volatile uint8*)0x33)

#define PORTD			*((uint8*)0x32)
#define DDRD			*((uint8*)0x31)
#define PIND			*((volatile uint8*)0x30)

/**************************************External Interrupt Registers************************/

#define SREG 	 (*(volatile uint8*)(0x5F))

#define GICR 	 (*(volatile uint8*)(0x5B))

#define GIFR 	 (*(volatile uint8*)(0x5A))

#define MCUCR	 (*(volatile uint8*)(0x55))

#define MCUCSR	 (*(volatile uint8*)(0x54))

/**************************************ADC Registers**************************************/

#define ADMUX_REG		(*(volatile uint8 *)(0x27))
#define ADCSRA_REG		(*(volatile uint8 *)(0x26))
#define	ADCH_REG		(*(volatile uint8 *)(0x25))
#define	ADCL_REG		(*(volatile uint8 *)(0x24))
#define ADC_ADJUST_REG	(*(volatile uint16 *)(0x24))
#define	SFIOR_REG		(*(volatile uint8 *)(0x50))


#endif /* ATMEGA32_REGISTER_H_ */
