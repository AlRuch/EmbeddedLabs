#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BLINK_DELAY_MS 

int count=0; 

int main (void){            
	DDRD &= ~(1<<2); 
	DDRD |= (1<<7);
	DDRB = 0xFF; 

	EICRA |= (1 << ISC01);
	EICRA &= ~(1 << ISC00);

	sei();

	EIMSK |= (1<<INT0);

	while(1){}
	return 0;
}

ISR(INT0_vect){
	PORTD ^= (1<<7);
	count++;
	PORTB = count;
}

