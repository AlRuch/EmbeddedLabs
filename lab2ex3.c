#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define switch_debounce_period 60

volatile int no_toggles = 0;

int main (){

	DDRD &= ~(1<<2);								//PD2 (INTO) is input

	DDRB |= 15;										//PB0 is output for toggle
													//PB1, PB2, PB3 represent
													//the no of toggles

	PORTB |= (1<<0);

	EICRA |= (1<<ISC01)|(0<<ISC00);					//set for falling edge detection

	sei();											//enable global interrupts

	EIMSK |= (1<<INT0);								//enable external interrupt for int0
	
	while(1){

	}
	
	return 0;
	
}

ISR(INT0_vect){
	
	_delay_ms(switch_debounce_period);

	no_toggles++;

	if(no_toggles > 7){
		no_toggles = 1;
	}

	if(PINB & (1<<0)){								//if led is on
		PORTB = (no_toggles << 1);
		
	}else{											//if led is off
		PORTB = (no_toggles << 1) + 1;
	}

}
