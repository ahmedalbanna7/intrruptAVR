/*
 * ATmega32A_FirmWare.c
 *
 * Created: 8/4/2019 9:17:00 PM
 *  Author: banna
 */ 


#include <ATmega32A_GPIO.h>
#include <ATmega32_interupt.h>
void int0_Event(void);
void int1_Event(void);


int main(void)
{
	//DEFINE LEDS AS AN OUTPUT 
	GPIO_DirectionSet(GPIOC,PIN0,OUTPUT);
	GPIO_DirectionSet(GPIOC,PIN1,OUTPUT);	
	GPIO_DirectionSet(GPIOC,PIN2,OUTPUT);
	
	// Enable interrupt HW (0,1) to different Modes 
	
	Ext_InterruptsEnable(Interrupt0,RisingMode);
	Ext_InterruptsEnable(Interrupt1,BothEdges);
	
	ISR0_ptr=int0_Event;
	ISR1_ptr=int1_Event;
	
	// Enable interrupt circuit @avr MCU
	GLOBAL_INTERRUPT_ENABLE();
	
	DigitalValues Ledstate = HIGH;
	
	
    while(1)
    {
		GPIO_OutputHandle(GPIOC,PIN0,Ledstate);
		Ledstate= !Ledstate;
		_delay_ms(1000);
		
        
    }
}

void int0_Event(void)
{
	GPIO_OutputHandle(GPIOC,PIN1,HIGH);
		GPIO_OutputHandle(GPIOC,PIN2,LOW);
	
}
void int1_Event(void)
{
	GPIO_OutputHandle(GPIOC,PIN2,HIGH);
		GPIO_OutputHandle(GPIOC,PIN1,LOW);

}