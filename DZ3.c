#include <mega128.h>
 #include <io.h>
 #include <delay.h>
 #include <stdio.h>
 void main ()
 { 
 int x; 
 int i;
 x=20;
 DDRB = 0xFF;
 DDRF = 0xFF; 
 delay_ms(5000);     
 PORTF = 0b00001001;

 while (1){  
 // PORTF++;
 for (i=0; i<=5; i++){
  PORTB = 0b01000100;    
  PORTF = 0b00001000; 
  delay_ms(x);             
  PORTB = 0b01001000;       
  PORTF = 0b00001010;
  delay_ms(x);                   
  PORTB = 0b01010000;          
  PORTF = 0b00011000; 
  delay_ms(x);                 
  PORTB = 0b01100000;            
  PORTF = 0b00011010;
  delay_ms(x);                 
  PORTB = 0b01010000;                
  PORTF = 0b00001100; 
  delay_ms(x);                  
  PORTB = 0b01001000;                  
  PORTF = 0b00001110; 
  delay_ms(x);                  
  PORTB = 0b01000100;                  
  PORTF = 0b00011100; 
  delay_ms(x);                   
  PORTB = 0b00000000;                  
  PORTF = 0b00011110;  
  delay_ms(x); 
 } // Буква (к)
 for (i=0; i<=10; i++){
  PORTB = 0b01000010;    
  PORTF = 0b00001000; 
  delay_ms(x);             
  PORTB = 0b01000010;      
  PORTF = 0b00001010;
  delay_ms(x);                   
  PORTB = 0b01000110;        
  PORTF = 0b00011000; 
  delay_ms(x);                 
  PORTB = 0b01001010;           
  PORTF = 0b00011010;
  delay_ms(x);                 
  PORTB = 0b01010010;              
  PORTF = 0b00001100; 
  delay_ms(x);                  
  PORTB = 0b01100010;                
  PORTF = 0b00001110; 
  delay_ms(x);                  
  PORTB = 0b01000010;                    
  PORTF = 0b00011100; 
  delay_ms(x);                   
  PORTB = 0b00000000;                    
  PORTF = 0b00011110;  
  delay_ms(x); 
   }  // Буква (и)
 for (i=0; i<=15; i++){
  PORTB = 0b01100000;   
  PORTF = 0b00001000; 
  delay_ms(x);              
  PORTB = 0b01010000;      
  PORTF = 0b00001010; 
  delay_ms(x);                 
  PORTB = 0b01001000;        
  PORTF = 0b00011000;
  delay_ms(x);                  
  PORTB = 0b01001000;            
  PORTF = 0b00011010; 
  delay_ms(x);                 
  PORTB = 0b01100000;               
  PORTF = 0b00001100; 
  delay_ms(x);                   
  PORTB = 0b01000000;                 
  PORTF = 0b00001110;
  delay_ms(x);                  
  PORTB = 0b01000000;                   
  PORTF = 0b00011100;  
  delay_ms(x);                  
  PORTB = 0b01100110;                     
  PORTF = 0b00011110;  
  delay_ms(x); 
   } //Буква (р)
 for (i=0; i<=20; i++){
PORTB = 0b01000010;    
  PORTF = 0b00001000; 
  delay_ms(x);             
  PORTB = 0b01000010;      
  PORTF = 0b00001010;
  delay_ms(x);                   
  PORTB = 0b01000110;        
  PORTF = 0b00011000; 
  delay_ms(x);                 
  PORTB = 0b01001010;           
  PORTF = 0b00011010;
  delay_ms(x);                 
  PORTB = 0b01010010;              
  PORTF = 0b00001100; 
  delay_ms(x);                  
  PORTB = 0b01100010;                
  PORTF = 0b00001110; 
  delay_ms(x);                  
  PORTB = 0b01000010;                    
  PORTF = 0b00011100; 
  delay_ms(x);                   
  PORTB = 0b00000000;                    
  PORTF = 0b00011110;  
  delay_ms(x); 
   }    //Буква (и)
for (i=0; i<=20; i++){
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
  PORTB = 0b01111110;                    
  PORTF = 0b00011100; 
  delay_ms(x);                   
  PORTB = 0b00000000;                    
  PORTF = 0b00011110;  
  delay_ms(x); 
   } // Буква (L)
for (i=0; i<=20; i++){
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
  PORTB = 0b01111110;                    
  PORTF = 0b00011100; 
  delay_ms(x);                   
  PORTB = 0b00000000;                    
  PORTF = 0b00011110;  
  delay_ms(x); 
   } // Буква (L)
}       
}