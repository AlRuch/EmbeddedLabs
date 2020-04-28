#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void delay_timer0(){

	/*use IO/256 prescaler ------> clock cycle period(1 increment period) = 256/16 = 16 microsec*/
	/*required no of increments = 81920/16 = 5120*/

	//no of overflows = 5120/256 = 20


	//delay is 81.92 ms

	volatile int no_overflows = 20;

	TCNT0 = 0;

	TCCR0A = 0x00;					/*Set the Timer0 under normal mode with 1:256 prescaler*/
	TCCR0B = 0x04;

	for(int x = 0; x < no_overflows; x++){
		while((TIFR0 & 0x01) == 0){}	/*wait till timer overflow bit is set*/
		TIFR0 = 0x01;               	/*Clear the timer overflow bit (T0V0) for the next round*/
	}  			

	TCCR0A = 0x00;				/*Clear timer settings (this stops the timer)*/
	TCCR0B = 0x00;

	/*strange thing about this flag is that inorder to clear it we should write 1 to it.
	This rule applies to all flags of AVR chip*/
}

int main(void){
	
	DDRB = DDRB | 62;			/*configure PB 1,2,3,4,5 of PORTB for output*/

	TIMSK1 = (1 << TOIE1);			/*Enable timer1 overflow interrupt(TOIE1)*/
	sei();							/*enable global interrupts*/


	/*use IO/256 prescaler ------> clock cycle period(1 increment period) = 256/16 = 16 microsec*/
	/*required no of increments = 1000000/16 = 62500*/

	TCNT1 = 3036;  					/*Load timer counter register ------> 1+65535-62500*/

	TCCR1A = 0x00;					/*Set the Timer0 under normal mode with 1:256 prescaler*/
	TCCR1B = 0x04;

	while(1){
		PORTB |= (1<<1);
		delay_timer0();
		PORTB &= ~(1<<1);
		PORTB |= (1<<2);
		delay_timer0();
		PORTB &= ~(1<<2);
		PORTB |= (1<<3);
		delay_timer0();
		PORTB &= ~(1<<3);
		PORTB |= (1<<4);
		delay_timer0();
		PORTB &= ~(1<<4);
		PORTB |= (1<<3);
		delay_timer0();
		PORTB &= ~(1<<3);
		PORTB |= (1<<2);
		delay_timer0();
		PORTB &= ~(1<<2);
	}	

}


ISR(TIMER1_OVF_vect){
	PORTB = PORTB ^ (1<<5);
	TCNT1 = 3036;
}
