 #include <mega128.h>
 #include <io.h>
 #include <delay.h>
 #include <stdio.h> 
 #include <stdbool.h>
 
 
 int y;
 int z = 0;
 unsigned char line_1 = 254;
 unsigned char line_2 = 126;
 unsigned char line_3 = 60;
 unsigned char line_4 = 254;
 unsigned char line_5 = 254;
 unsigned char line_6 = 254;
 unsigned char line_7 = 254;
 unsigned char line_8 = 254;

 void main ()
 { 
 
 int x;
 x=1;
 y=24;
 

 DDRB = 0xFF;
 DDRF = 0b000111111; 
 delay_ms(5);   
 PORTF = 0b00001001;
 //PORTB = 0b00000000;
 
 while (1){
 
for (z = 0; z <= 250; z++)
{    
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
// delay_ms(5);
}

 //delay_ms(2000);
// PORTF = 0b00000000;


     // PORTF++;
// delay_ms (1500);
//line_1--;
//delay_ms(500); 
for (z = 0; z <= 250; z++)
{    
PORTB = line_1;    //1
PORTF = 0b00001001;
 //for (z = 0; z <= 255; z++)
 
//line_1--;
//delay_ms(50); 
 delay_ms(x);            
 PORTB = line_2;       //2
 PORTF = 0b00001010;   
 delay_ms(x);                
 PORTB = line_3;          //3
 PORTF = 0b00011000;   
 delay_ms(x);                
 PORTB = 0b00011000;             //4
 PORTF = 0b00011010;   
 delay_ms(x);                
 PORTB = 0b00001000;                //5
 PORTF = 0b00001100;   
 delay_ms(x);                
 PORTB = 0b00011100;                   //6
 PORTF = 0b00001110;   
 delay_ms(x);                
 PORTB = 0b00111110;                //7
 PORTF = 0b00011100;   
 delay_ms(x);                
 PORTB = 0b01111110;              //8
 PORTF = 0b00011111;  
 delay_ms(x);
// delay_ms(5);
}


//delay_ms(2000);
//PORTF = 0b00000000;


/*
if (line_1 < 02)
{
line_1 = 254;
}
*/






} }
