#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 1000
int main (void){
DDRB = DDRB|((1<<5)|(1<<4)|(1<<3|(1<<2)); /* configure pin 5 , pin 4 , pin 3 , pin 2 of PORTB for output*/
// DDRB = DDRB | (60);

int counter;
int portNo;

while(1){
 PORTB = PORTB|(1<<5); /* set pin 5  high to turn led 1 on */ 
 _delay_ms(BLINK_DELAY_MS);
 
 PORTB = PORTB & ~(1<<5) /* set pin 5  low to turn led 1 off */
 PORTB = PORTB |(1<<4) /* set pin 4  high to turn led 2 on */
 _delay_ms(BLINK_DELAY_MS);
 
 PORTB = PORTB & ~(1<<4) /* set pin 4  low to turn led 2 off */
 PORTB = PORTB |(1<<3) /* set pin 3  high to turn led 3 on */
 _delay_ms(BLINK_DELAY_MS);
 
 PORTB = PORTB & ~(1<<3) /* set pin 3  low to turn led 3 off */
 PORTB = PORTB |(1<<2) /* set pin 2  high to turn led 4 on */
 _delay_ms(BLINK_DELAY_MS);
 
 PORTB = PORTB & ~(1<<2) /* set pin 2  low to turn led 4 off */
 PORTB = PORTB |(1<<3) /* set pin 3  high to turn led 3 on */
 _delay_ms(BLINK_DELAY_MS);
 
 PORTB = PORTB & ~(1<<3) /* set pin 3  low to turn led 3 off */
 PORTB = PORTB |(1<<4) /* set pin 4  high to turn led 2 on */
 _delay_ms(BLINK_DELAY_MS);
 
 PORTB = PORTB & ~(1<<4) /* set pin 4  low to turn led 2 off */ 
 _delay_ms(BLINK_DELAY_MS);
}
}