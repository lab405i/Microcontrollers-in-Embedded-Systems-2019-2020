#include <mega128.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <T6963c.h>
#include <t6963c.c>
 
int salut=180;
int i=0;
 int q=0;
 int zaderchka = 1000; 
 int god;
void main(void)
{
init_cpu();
timer0_init();
init_display();
clear_text();
clear_graphics();
lcd_clear_full();

DDRE=0b11110000;
PORTE=0b11111111;
DDRF=0b00000000;
PORTF=0b11100000;



 while(1)
 {     
   
    
   
     for(q=0;q<12;q++)
        {
         clear_graphics();
   lcd_circle (60,63,40,1); 
           switch (q)
        {
        case 0 :
          lcd_degree_line(60,63,0,5,40,1);
           
         lcd_degree_line(60,70,god,13,40,1);
         delay_ms(zaderchka);
       
        break;

        case 1 :
          lcd_degree_line(60,63,30,5,40,1); 
           
           lcd_degree_line(60,70,god,13,40,1);
           delay_ms(zaderchka);
       
        break; 
         case 2 :
          lcd_degree_line(60,63,60,5,40,1);  
           
            lcd_degree_line(60,70,god,13,40,1); 
             delay_ms(zaderchka);
       
        break;
        case 3 :
         lcd_degree_line(60,63,90,5,40,1); 
         
          lcd_degree_line(60,70,god,13,40,1);
          delay_ms(zaderchka);
      
        break;
        case 4 :
           lcd_degree_line(60,63,120,5,40,1); 
            
             lcd_degree_line(60,70,god,13,40,1);
             delay_ms(zaderchka);
        
        break;
        case 5 :
         lcd_degree_line(60,63,150,5,40,1);
          
             lcd_degree_line(60,70,god,13,40,1);
             delay_ms(zaderchka);
       
        break;
        case 6 :
        lcd_degree_line(60,63,180,5,40,1); 
         
               lcd_degree_line(60,70,god,13,40,1);
               delay_ms(zaderchka);
      
        break;
        case 7 :
        lcd_degree_line(60,63,210,5,40,1); 
          
               lcd_degree_line(60,70,god,13,40,1);
                delay_ms(zaderchka);
       
        break;
        case 8 :
         lcd_degree_line(60,63,240,5,40,1);
         
            lcd_degree_line(60,70,god,13,40,1); 
             delay_ms(zaderchka);
         
        break;
        case 9 :
          lcd_degree_line(60,63,270,5,40,1); 
          
            lcd_degree_line(60,70,god,13,40,1);
             delay_ms(zaderchka);
         
        break;
        case 10 :
        lcd_degree_line(60,63,300,5,40,1);
        
          lcd_degree_line(60,70,god,13,40,1);
          delay_ms(zaderchka);
       
        break;
        case 11 :
          lcd_degree_line(60,63,330,5,40,1); 
           
          lcd_degree_line(60,70,god,13,40,1); 
          delay_ms(zaderchka);
            
        break; 
                 
        }
        
     
  } 
      
   for(i=0;i<360;){
     
   lcd_degree_line(salut,63,i,5,40,1);  
    delay_ms(500);
      
     i=i+10;

 }  
  
  }
 
  }
