#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int main (){

	DDRD &= ~(1<<2);								//PD2 (INTO) is an input - 0

	DDRD &= ~(1<<3);								//PD3 (INT1) is an input - 1

	DDRB |= 255;									//PORTB is set for output

	PORTB &= 0;
													
	EICRA |= (1<<ISC01)|(0<<ISC00);					//set for falling edge detection
	EICRA |= (1<<ISC11)|(0<<ISC10);

	sei();											//enable global interrupts

	EIMSK |= (1<<INT0);								//enable external interrupt for int0
	EIMSK |= (1<<INT1);

	while(1){

	}
	
	return 0;
	
}

ISR(INT0_vect){									//0 button

	if(PORTB != 0){
		PORTB = PORTB * 2;
	}else{
		PORTB = 0;
	}

}


ISR(INT1_vect){									//1 button

	PORTB = (PORTB * 2) + 1;

}
