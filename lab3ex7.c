#include <avr/io.h>
#include <avr/interrupt.h>

volatile int no_overflows_timer0 = 0;


int main(void){
	
	DDRB = DDRB | (1<<5);			/*configure PB4,PB5 for output*/
	DDRB = DDRB | (1<<4);

	TIMSK0 = (1 << TOIE0);			/*Enable timer0 overflow interrupt(TOIE0)*/
	TIMSK1 = (1 << TOIE1);			/*Enable timer0 overflow interrupt(TOIE0)*/
	sei();							/*enable global interrupts*/

	/*use IO/256 prescaler ------> clock cycle period(1 increment period) = 256/16 = 16 microsec*/
	/*required no of increments = 50000/16 = 3125*/

	/*no of overflows = 3125/256 = 12.2*/

	TCNT0 = 204;  					/*Load timer counter register ------> 1+255-52=204*/

	TCCR0A = 0x00;					/*Set the Timer0 under normal mode with 1:256 prescaler*/
	TCCR0B = 0x04;


	/*use IO/256 prescaler ------> clock cycle period(1 increment period) = 256/16 = 16 microsec*/
	/*required no of increments = 500000/16 = 31250*/

	TCNT1 = 34286;  					/*Load timer counter register ------> 1+65535-31250=34286*/

	TCCR1A = 0x00;						/*Set the Timer1 under normal mode with 1:256 prescaler*/
	TCCR1B = 0x04;
	

	while(1){

	}	

}


ISR(TIMER0_OVF_vect){

	no_overflows_timer0++;

	if(no_overflows_timer0 > 12){
		PORTB = PORTB ^ (1<<4);
		TCNT0 = 0;
		no_overflows_timer0 = 0;
	}
	
}


ISR(TIMER1_OVF_vect){

	PORTB = PORTB ^ (1<<5);
	TCNT1 = 34286;
	
}
