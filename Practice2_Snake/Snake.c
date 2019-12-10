/*---------------------------------Snake.c----------------------------------------------*/

#include <mega128.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <T6963c.h>
#include <t6963c.c>


/*--------------------------------------------------------------------------------------*/


#define DISPLAY_SIZE_X 239
#define DISPLAY_SIZE_Y 127

#define X_MAX 30
#define Y_MAX 16

#define BLOCK_SIZE 8 

#define BUTTON_UP (1<<PINE1)
#define BUTTON_DOWN (1<<PINE1)
#define BUTTON_LEFT (1<<PINE0)
#define BUTTON_RIGHT (1<<PINE2)
#define BUTTON_EXIT (1<<PINF7)
#define BUTTON_START (1<<PINF5)

#define LINE_1 (1<<PINE6)
#define LINE_2 (1<<PINE5)
#define LINE_3 (1<<PINE4)

int field[Y_MAX][X_MAX];

int xhead=X_MAX/2, yhead=Y_MAX/2, points=1, add_points=0, apples=0, Game_Over=0;
char direction='e';

char *word[]={"Hello!", "This is snake game","To play push PINF6 button","Controls:", "up - PINE1 line PORTE6", "down - PINE1 line PORTE4", "left - PINE0 line PORTE5", "right - PINE3 line PORTE5"};
char *sys_mess[]={"*PAUSE*"};
/*--------------------------------------------------------------------------------------*/

void init_field(void);
int scan_kbd_E(void);
//char scan_kbd_F(void);
void step(void);
void print_screen(void);
void print_block(unsigned char x, unsigned char y, char visible);
char start_screen();
void pause();

interrupt [TIM1_OVF] void timer1_overflow(void)
{
    step();
    print_screen();
} 

/*--------------------------------------------------------------------------------------*/


void main(void)
{
    char buff;
	init_cpu();                           
    timer0_init();                          
    init_display();                         
    clear_text();                           
    clear_graphics();                      
    lcd_clear_full(); 
	 
    //init_field();
    
	DDRE|=0b11110000;
	PORTE|=0b11111111;
    DDRF|=0b00000000;
    PORTF|=0b11100000;
    
    TCCR1A=0;
    TCCR1B=3;
    TIMSK=4;
    
   
    
	while(1)
	{
        init_field();
        
        start_screen();
        Game_Over=0;
        
        buff= PINF;
        delay_us(5);
        while(PINF&(1<<PINF6));
        
        clear_text();
        
        #asm("sei"); 
		
        
        while(Game_Over==0)
		{
			scan_kbd_E();
            if(buff&(1<<PINF6)){}
            
		}
        #asm("cli"); 
 
	}
	//return 0;	
}

void init_field(void)
{
	unsigned char i,j;
	
    xhead=5;
    yhead=5;
    
	for(i=0;i<Y_MAX;i++)
	{
		for(j=0;j<X_MAX;j++)
			field[i][j]=0;
		
	}
	field[xhead][yhead]=1;
    
    Game_Over=0;
    apples=0;
}

int scan_kbd_E(void)
{
    char buff;
	//Line 1 button Up
	PORTE&=~LINE_1;
    //PORTE&=0b10111111;
    
	delay_us(5);
    buff=PINE;
	if(!(buff&BUTTON_UP)) //if((PINE&(1<<PINE1))==0)
    {
		if(direction!='n')
		{
			direction='s';
			PORTE|=LINE_1;
            //PORTE|=0b11111111;
            return 1;
		}	
	}
	PORTE|=LINE_1;
	//PORTE|=0b11111111;
	//Line 2 buttons Left and Right
	PORTE&=~LINE_2;
	delay_us(5);
    buff=PINE;
	if(!(buff&BUTTON_LEFT))
	{
		if(direction!='w')
		{
			direction='e';
            PORTE|=LINE_2;
			return 1;
		}	
	}
	if(!(buff&BUTTON_RIGHT))
	{
		if(direction!='e')
		{
			direction='w';
            PORTE|=LINE_2;
			return 1;
		}	
	}
	PORTE|=LINE_2;
	
	//Line 3 button Down
	PORTE&=~LINE_3;
	delay_us(5);
    buff=PINE;
	if(!(PINE&BUTTON_DOWN))
	{
		if(direction!='s')
		{
			direction='n';
			PORTE|=LINE_3;
            return 1;
		}	
	}
	PORTE|=LINE_3;
    
    return 0;
}

void step(void)
{
	int xtemp,ytemp, i, r, m;
    
    xtemp=xhead;
    ytemp=yhead;
    
    if(direction=='w')
	{
		if(field[yhead-1][xhead]==-1) ++add_points;
		yhead--;
	} 
    if(direction=='e')
	{
		if(field[yhead+1][xhead]==-1) ++add_points;
		yhead++;
	}
    if(direction=='s')
	{
		if(field[yhead][xhead-1]==-1) ++add_points;
		xhead--;
	}
    if(direction=='n') 
	{
		if(field[yhead][xhead+1]==-1) ++add_points;
		xhead++;
	}
	
	
	if((field[yhead][xhead]!=0)&&(field[yhead][xhead]!=-1)||(xhead>(X_MAX-1))||(yhead>(Y_MAX-1))||(xhead<0)||(yhead<0))
	{
		Game_Over=1;
		return;
	}
	

    field[yhead][xhead]=1;
    
    for(i=1;i<points;i++)
    {
	    if(field[ytemp][xtemp+1]==(i+1))
        {
	    field[ytemp][xtemp]=i+1;
            xtemp++;
			continue;
        }
        if(field[ytemp][xtemp-1]==(i+1))
        {
            field[ytemp][xtemp]=i+1;
            xtemp--;
			continue;
        }
        if(field[ytemp+1][xtemp]==(i+1))
        {
            field[ytemp][xtemp]=i+1;
            ytemp++;
			continue;
        }
        if(field[ytemp-1][xtemp]==(i+1))
        {
            field[ytemp][xtemp]=i+1;
            ytemp--;
			continue;
        }
    }
    
    if(add_points)
    {
        add_points--;
        points++;
        apples--;
	field[ytemp][xtemp]=points;
        return;
    }
    field[ytemp][xtemp]=0;
    print_block(xtemp,ytemp,0);
    
    if(!apples)
    {
		do{
		r=rand()%Y_MAX;
		m=rand()%X_MAX;
		}while(field[r][m]!=0);
		field[r][m]=-1;
		apples++;
	}
	return;
}

void print_screen(void)
{
	unsigned char i,j;
	
	//clear_graphics();
	Frame(0,0,DISPLAY_SIZE_X,DISPLAY_SIZE_Y,1);
	for(i=0;i<Y_MAX;i++)
	{
		for(j=0;j<X_MAX;j++)
		{
			if(field[i][j]!=0)
			{
				print_block(j,i,1);
			}
		}
		
	}
    //delay_us(2000);
}

void print_block(unsigned char x, unsigned char y, char visible)
{
	unsigned char xpos,ypos,i;
	
	//xpos=(X_MAX-x)*BLOCK_SIZE;
	//ypos=(Y_MAX-y)*BLOCK_SIZE;
	xpos=(x)*BLOCK_SIZE;
	ypos=(y)*BLOCK_SIZE;
    
	for(i=0;i<BLOCK_SIZE;i++)
	{
		Line(xpos + i, ypos, xpos + i, ypos + BLOCK_SIZE, visible);
	}
}


char start_screen()
{
    clear_graphics();
	//print_screen();
    write_string(11, 2,  word[0]);
    write_string(5, 3,  word[1]);
    write_string(3, 4,  word[2]);
    write_string(4, 6,  word[3]);
    write_string(5, 8,  word[4]);
    write_string(3, 9,  word[5]);
    write_string(3, 10,  word[6]);
    write_string(2, 11,  word[7]);
    

    Frame(0,0,DISPLAY_SIZE_X,DISPLAY_SIZE_Y,1);
}    

void pause(void)
{
    #asm("cli"); 
    
    while(PINF&(1<<PINF6))
    {
        write_string(10, 2,  sys_mess[0]);
        delay_ms(1000);
        clear_text();
        delay_ms(1000);      
    }
    
    clear_text();  
    #asm("sei");
}    
