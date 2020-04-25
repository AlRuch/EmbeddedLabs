#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 


int main (void){ 
	DDRB = 0xFF;            /* configurepin 5 of PORTB for output*/
	DDRD = DDRD & 0; 
	int count = 0;
	PORTB = 0;
	while(1){
		if(PIND & 128){
			count++;
			PORTB = count;
			_delay_ms(100);
		}
	
	}
}
