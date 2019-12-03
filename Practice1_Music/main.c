#include <mega128.h>
#include <delay.h>
#include <stdio.h>


#define Key1 ~PINF.5
#define Key2 ~PINF.6
#define Key3 ~PINF.7


#include "Ton.c"
unsigned char T1Reload;
bit Play;

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Reinitialize Timer's 0 value
 TCNT0 = T1Reload;
 if(T1Reload != Silence && Play)
  {
          PORTB.0 = !PORTB.0; // Speaker
  }
 else
  {
   PORTB.0 = 0;
  } 
}
// Timer 2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{
// Reinitialize Timer's 2 value
// TCNT2 = T2Reload;
// Place your code here
}

// Declare your global variables here

void main(void)
{
// Declare your local variables here
int Speed = 6; 
unsigned char Song = 0;

// Input/Output Ports initialization
// Port A
// Port B
PORTB=0x00;
DDRB=0x1f;

//PORTE=0x00;
//DDRE=0x00;
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 125,000 kHz
// Mode: Output Compare
// OC0 output: Disconnected
TCCR0=0x03;

TCNT0=0x30;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer 1 Stopped
// Mode: Output Compare
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 125,000 kHz
// Mode: Pulse Width Modulation
// OC2 output: Inverted PWM
TCCR2=0x00;
ASSR=0x00;
TCNT2=0x80;
OCR2=0x40;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off

MCUCR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x41;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;

// LCD module initialization

// Global enable interrupts
#asm("sei")
Play = 1;
TCCR0 = 0x03; // Standart octave
while (1)
      {
       unsigned char index;
       unsigned int lang; 

         if(Key1)  { Song--; index = 0; Play = 1; delay_ms(200);};
         if(Key2 && Play)  {index = 0; Play = 0; delay_ms(200); };
         if(Key2 && !Play)  {index = 0; Play = 1; delay_ms(200); };
         if(Key3)  { Song++; index = 0; Play = 1; delay_ms(200);};         
         
        // if(Key2)  TCCR0 = 0x02; // one octave higher (double Timer frequency
        //if(Key3)  Speed++; 
        // if(Key4)  if(Speed > 1) Speed--;  
        //if(Key5)  { Play = 1;};
 
       if(!Play) index = 0;
       // prepare the display

       
       switch(Song)
        {
         case 0:
               // end of Song?
               if(index >= WARS_LAENGE) { Play = 0;};
               // set the frequency
               T1Reload = WarsSong[index][0]; 
               // duration of this tone
               lang =     WarsSong[index][1] * Speed;
               break; 
         case 1:
               if(index >= AXEL_LAENGE) { Play = 0;};
               T1Reload = AxelSong[index][0];
               lang =     AxelSong[index][1] * Speed;
               break; 
         case 2:
               if(index >= HAYDN_LAENGE) { Play = 0;};
               T1Reload = HaydnSong[index][0];
               lang =     HaydnSong[index][1] * Speed;
               break; 
         case 3:
               if(index >= VOY_LAENGE) { Play = 0;};
               T1Reload = VoySong[index][0];
               lang =     VoySong[index][1] * Speed;
               break; 
         case 4:
               if(index >= BOND_LAENGE) { Play = 0;};
               T1Reload = BondSong[index][0];
               lang =     BondSong[index][1] * Speed;
               break; 
         case 5:
               if(index >= BABY_LAENGE) { Play = 0;};
               T1Reload = BabySong[index][0];
               lang =     BabySong[index][1] * Speed;
               break; 
         default: Song = 0;
               break; 
        }       
       
       // Set '*' 
     
       
       // wait for the duration of this tone
       for(;lang;lang--) 
        {
         delay_ms(25);
        } 

       // next tone
       index++;
       
       // make a pause between the tones
       T1Reload = Silence; 
       delay_ms(20);
      };
}
