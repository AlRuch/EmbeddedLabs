#include <avr/io.h>
#include <avr/interrupt.h>

volatile int no_overflows = 0;


int main(void){
	
	DDRB = DDRB | (1<<5);			/*configure PB5 for output*/

	TIMSK0 = (1 << TOIE0);			/*Enable timer0 overflow interrupt(TOIE0)*/
	sei();							/*enable global interrupts*/

	/*use IO/256 prescaler ------> clock cycle period(1 increment period) = 256/16 = 16 microsec*/
	/*required no of increments = 100000/16 = 6250*/

	/*no of overflows = 6250/256 = 24.4*/

	TCNT0 = 154;  					/*Load timer counter register ------> 1+255-102=154*/

	TCCR0A = 0x00;					/*Set the Timer0 under normal mode with 1:256 prescaler*/
	TCCR0B = 0x04;
	
	while(1){

	}	

}


ISR(TIMER0_OVF_vect){

	no_overflows++;

	if(no_overflows > 24){
		PORTB = PORTB ^ (1<<5);
		TCNT0 = 0;
		no_overflows = 0;
	}
	
}
