#include <avr/io.h>

void delay_timer0(){

	/*use IO/256 prescaler ------> clock cycle period(1 increment period) = 256/16 = 16 microsec*/
	/*required no of increments = 2000/16 = 125*/

	TCNT0 = 131;  				/*Load timer counter register* -----> 1+255-125=131*/

	TCCR0A = 0x00;				/*Set the Timer0 under normal mode with 1:256 prescaler*/
	TCCR0B = 0x04;

	while((TIFR0 & 0x01) == 0);	/*wait till timer overflow bit is set*/

	TCCR0A = 0x00;				/*Clear timer settings (this stops the timer)*/
	TCCR0B = 0x00;

	TIFR0 = 0x01;               /*Clear the timer overflow bit (T0V0) for the next round*/

	/*strange thing about this flag is that inorder to clear it we should write 1 to it.
	This rule applies to all flags of AVR chip*/
}


int main(void){
	
	DDRB = DDRB | (1<<5);		/*configure pin 5 of PORTB for output*/

	while(1){
		PORTB = PORTB ^ (1<<5);

		// for(int x = 0; x < 500; x++){				
			delay_timer0();
		// }	
	}	

}

