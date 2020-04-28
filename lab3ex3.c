#include <avr/io.h>

void delay_timer0(){

	/*use IO/1024 prescaler ------> clock cycle period(1 increment period) = 1024/16 = 64 microsec*/
	/*required no of increments = 500,000/64 = 7812.5*/

	/*no of overflows = 7812.5/256 = 30.5*/

	volatile int no_overflows = 31;
	TCNT0 = 128;  					/*Load timer counter register* -----> 1+255-(256/2)=128*/

	for(int x = 0; x < no_overflows; x++){	/*one loop represents one overflow*/

		TCCR0A = 0x00;				/*Set the Timer0 under normal mode with 1:8 prescaler*/
		TCCR0B = 0x05;

		while((TIFR0 & 0x01) == 0){	/*wait till timer overflow bit is set*/

		}	

		TCCR0A = 0x00;				/*Clear timer settings (this stops the timer)*/
		TCCR0B = 0x00;

		TIFR0 = 0x01;               /*Clear the timer overflow bit (T0V0) for the next round*/

		/*strange thing about this flag is that inorder to clear it we should write 1 to it.
		This rule applies to all flags of AVR chip*/

		TCNT0 = 0;
	}

}


int main(void){
	
	DDRB = DDRB | (1<<5);		/*configure pin 5 of PORTB for output*/

	while(1){
		PORTB = PORTB ^ (1<<5);
		delay_timer0();
	}	

}
