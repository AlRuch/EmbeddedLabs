#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define switch_debounce_period 100

int main (){

	DDRD &= ~(1<<2);								//PD2 (INTO) is input

	DDRB |= (1<<0);									//PB0 is output

	PORTB |= (1<<0);

	EICRA |= (1<<ISC01)|(0<<ISC00);					//set for falling edge detection

	sei();											//enable global interrupts

	EIMSK |= (1<<INT0);								//enable external interrupt for int0
	
	while(1){
	
	}
	
	return 0;

}

ISR(INT0_vect){

	if(PINB & (1<<0)){
		PORTB &= ~(1<<0);
		_delay_ms(switch_debounce_period);

	}else{
		PORTB |= (1<<0);
		_delay_ms(switch_debounce_period);
	}


}
