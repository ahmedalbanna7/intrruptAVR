/*
 * ATmega32_interupt.h
 *
 * Created: 8/20/2019 7:36:09 PM
 *  Author: kirollous
 */ 


#ifndef ATMEGA32_INTERUPT_H_
#define ATMEGA32_INTERUPT_H_


#include "Common_Macros.h"
#include "STDTypes.h"
#include "uC_Config.h"
#include "ATmega32A_GPIO.h"

#define SREG	((volatile reg8 *)0X5F)
#define	MCUCR	((volatile reg8 *)0x55)
#define MCUCSR	((volatile reg8 *)0x54)
#define GICR	((volatile reg8 *)0x5B)
#define GIFR	((volatile reg8 *)0x5A)

#define GLOBAL_INTERRUPT_ENABLE()	{SREG->Bits.B7 = 1;}
#define GLOBAL_INTERRUPT_DISABLE()	{SREG->Bits.B7 = 0;}

extern void (*ISR0_ptr)(void);
extern void (*ISR1_ptr)(void);
extern void (*ISR2_ptr)(void);

typedef enum
{
	Interrupt0,
	Interrupt1,
	Interrupt2,
	
	}ATMEGA32_EXTERNALINTERRUPTS;


typedef enum
{
	RisingMode,
	FallingMode,
	BothEdges,
	LOW_Level,
	
	}Ex_InterruptsModes;
	
void Ext_InterruptsEnable(
							ATMEGA32_EXTERNALINTERRUPTS int_num,
							Ex_InterruptsModes Mode);
							
void Ext_InterruptsDisable(ATMEGA32_EXTERNALINTERRUPTS int_num);

void ExInt_UserWaring_Error(void);


#endif /* ATMEGA32_INTERUPT_H_ */