#include <mega128.h>
#include <io.h>
#include <delay.h>
#include <stdio.h>
void main ()

{ int x;
int i;
x=2;

DDRB = 0xFF;
DDRF = 0xFF;
delay_ms(5);
PORTF = 0b00001001;

while (1){
//PORTF++;
for (i=0; i<=5; i++){

//PORTB = 0b10000000;
PORTF = 0b00001000;
delay_ms(x);
PORTB = 0b10000000;
PORTF = 0b00001000;
delay_ms(x);
PORTB = 0b10000000;
PORTF = 0b00001010;
delay_ms(x);
PORTB = 0b10000000;
PORTF = 0b00011000;
delay_ms(x);
PORTB = 0b10000000;
PORTF = 0b00011010;
delay_ms(x);
PORTB = 0b10000000;
PORTF = 0b00001100;
delay_ms(x);
PORTB = 0b10000000;
PORTF = 0b00001110;
delay_ms(x);
PORTB = 0b10000000;
PORTF = 0b00011100;
delay_ms(x);
PORTB = 0b10000000;
PORTF = 0b00011110;
delay_ms(x);
delay_ms(5);
}
for (i=0; i<=5; i++){
PORTB = 0b01000000;
PORTF = 0b00001000;
delay_ms(x);
PORTB = 0b01000000;
PORTF = 0b00001010;
delay_ms(x);
PORTB = 0b01000000;
PORTF = 0b00011000;
delay_ms(x);
PORTB = 0b01000000;
PORTF = 0b00011010;
delay_ms(x);
PORTB = 0b01000000;
PORTF = 0b00001100;
delay_ms(x);
PORTB = 0b01000000;
PORTF = 0b00001110;
delay_ms(x);
PORTB = 0b01000000;
PORTF = 0b00011100;
delay_ms(x);
PORTB = 0b01000000;
PORTF = 0b00011110;
delay_ms(x);
}
}}