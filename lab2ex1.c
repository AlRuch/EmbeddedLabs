#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define switch_debounce_period 1000

volatile int no_times = 0;

int main (){

	DDRD &= ~(1<<7);							//PD7 is the input

	DDRB |= 63;									//PB0 - PB5 are outputs

	PORTB &= 0;									//initially all leds are turned off

	while(1){

		if(PIND & (1<<7)){
			no_times++;
			PORTB = no_times;
			_delay_ms(switch_debounce_period);
		}

	}
	
	return 0;

}

