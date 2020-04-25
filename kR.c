#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 100
int main (void){
DDRB = DDRB|((1<<5)|(1<<4)|(1<<3)|(1<<2)); /* configure pin 5 , pin 4 , pin 3 , pin 2 of PORTB for output*/
// DDRB = DDRB | (60);

int counter;
int portNo;

	while(1){
		
		
		
		for( counter = 5 ; counter > 2; counter--){
			PORTB = PORTB & ~(1<<counter);              
			PORTB = PORTB |(1<<(counter - 1));                
			_delay_ms(BLINK_DELAY_MS);
		}

		


		for( counter = 2 ; counter < 5; counter++){
			PORTB = PORTB & ~(1<<counter);              
			PORTB = PORTB |(1<<(counter + 1));                
			_delay_ms(BLINK_DELAY_MS);
		}

		
		
		
	}
}



	/*	PORTB = PORTB & ~(1<<5);              
		PORTB = PORTB |(1<<4);               
		_delay_ms(BLINK_DELAY_MS);

		PORTB = PORTB & ~(1<<4);              
		PORTB = PORTB |(1<<3);                
		_delay_ms(BLINK_DELAY_MS);

		PORTB = PORTB & ~(1<<3);              
		PORTB = PORTB |(1<<2);                
		_delay_ms(BLINK_DELAY_MS);

		PORTB = PORTB & ~(1<<2);              
		PORTB = PORTB |(1<<3);               
		_delay_ms(BLINK_DELAY_MS);

		PORTB = PORTB & ~(1<<3);             
		PORTB = PORTB |(1<<4);                
		_delay_ms(BLINK_DELAY_MS);

		PORTB = PORTB & ~(1<<4);               
		PORTB = PORTB|(1<<5);                
		_delay_ms(BLINK_DELAY_MS);

	 */
