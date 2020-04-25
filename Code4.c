#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BLINK_DELAY_MS 

int count=0; 

int main (void){            
	DDRD &= ~(1<<2); 
	DDRD &= ~(1<<3);
	DDRD |= (1<<7);
	DDRB = 0xFF; 

	EICRA |= (1 << ISC01);
	EICRA &= ~(1 << ISC00);

	EICRA |= (1 << ISC11);
	EICRA &= ~(1 << ISC10);

	sei();

	EIMSK |= (1<<INT0);
	EIMSK |= (1<<INT1);

	while(1){}
	return 0;
}

ISR(INT0_vect){

	if(count > 6){
		count = 0;
		PORTB = 0;
	}

	PORTB |= (1<< count);
	count++;
	_delay_ms(500);
}


ISR(INT1_vect){
	
	if(count > 6){
		count = 0;
		PORTB = 0;
	}

	PORTB &= ~(1<< count);
	count++;
	_delay_ms(500);
}
