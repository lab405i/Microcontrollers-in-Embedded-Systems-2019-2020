 #include <mega128.h>
 #include <io.h>
 #include <delay.h>
 #include <stdio.h>
 void main ()
 { 
 
 int x;
 x=1;
 DDRB = 0xFF;
 DDRF = 0xFF; 
 delay_ms(5);   
 PORTF = 0b00001001;
 
 while (1){
 // PORTF++;
 PORTB = 0b00011000;    //1
 PORTF = 0b00001000;   
 delay_ms(x);           
 PORTB = 0b00100100;       //2
 PORTF = 0b00001010;   
 delay_ms(x);                
 PORTB = 0b01000010;          //3
 PORTF = 0b00011000;   
 delay_ms(x);                
 PORTB = 0b01000010;             //4
 PORTF = 0b00011010;   
 delay_ms(x);                
 PORTB = 0b01111110;                //5
 PORTF = 0b00001100;   
 delay_ms(x);                
 PORTB = 0b01000010;                   //6
 PORTF = 0b00001110;   
 delay_ms(x);                
 PORTB = 0b01000010;                      //7
 PORTF = 0b00011100;   
 delay_ms(x);                
 PORTB = 0b01000010;                      //8
 PORTF = 0b00011110;   
 delay_ms(x);   
} }