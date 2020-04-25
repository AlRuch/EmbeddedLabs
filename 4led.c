#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 1000
int main (void){
	DDRB = DDRB|((1<<5)|(1<<4)|(1<<3)|(1<<2)); 
	/* configure pin 5 , pin 4 , pin 3 , pin 2 of PORTB for output*/
	// DDRB = DDRB | (60);

	while(1){
		PORTB = PORTB|((1<<5)|(1<<4)|(1<<3)|(1<<2)); 
		/* set pin 5 , pin 4 , pin 3 , pin 2 high to turn led on */
		// PORTB = PORTB | (60);
		_delay_ms(BLINK_DELAY_MS);

		PORTB = PORTB & ~((1<<5)|(1<<4)|(1<<3)|(1<<2)); 
		/* set pin 5 , pin 4 , pin 3 , pin 2 low to turn led off */
		// PORTB = PORTB & ~(60);
		_delay_ms(BLINK_DELAY_MS);
	}
}
