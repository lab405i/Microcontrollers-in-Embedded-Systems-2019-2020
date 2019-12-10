#include <mega128.h>
#include <math.h>
//------------------------------------------------------------
#define	GRAPHICS_HOME0		0x281
#define	GRAPHICS_WIDTH		40  
#define	GRAPHICS_LINES			128
#define	TEXT_HOME0				0x0000  
#define	TEXT_WIDTH				40
#define	TEXT_LINES					16     
#define MUL 								256      
//------------------------------------------------------------
#define LCD_DATA     		(*((volatile unsigned char*)(0x8000)))
#define LCD_COMMAND  	(*((volatile unsigned char*)(0x8101)))   
//------------------------------------------------------------
void init_cpu(void)
{
DDRB  	= 	0xff;
//PORTB 	= 	0xff;   
DDRD  	= 	0xff;
PORTD 	=	0xff;
DDRF  	= 	0x00;
PORTF 	= 	0x00;
DDRE  	= 	0x00;
PORTE 	= 	0xff;
MCUCR 	= 	0x8a;
XMCRA 	= 	0xff;
SFIOR 	= 	0x10;
}
//------------------------------------------------------------
void write_command(unsigned char data)
{
LCD_COMMAND=data; while(((LCD_COMMAND) & 3)!=3);   
}
//------------------------------------------------------------
void write_data(unsigned char data)
{
LCD_DATA=data; while(((LCD_COMMAND) & 3)!=3);   
}
//------------------------------------------------------------
void init_display(void)
{
	write_command(0xB2);		//automode reset
	
	set_graphic_window(GRAPHICS_HOME0);
	
	write_data(GRAPHICS_WIDTH);     //low byte
	write_data(0x00);       	//high byte
	write_command(0x43);	      	//set graphics line length 
	
	set_text_window(TEXT_HOME0);
	
	write_data(TEXT_WIDTH);         //low byte
	write_data(0x00);            	//high byte
	write_command(0x41);          	//text line length
	write_command(0b10000000);  	//mode set 
	write_command(0b10011100);	//display mode
	write_command(0xA3);		//cursor pattern select
	write_command(0x01);
	write_command(0x00);
	write_command(0x21);		//cursor position set
	return;
}            
//------------------------------------------------------------------
void set_graphic_window(unsigned int address)
{
	unsigned char data;
	
	data=address&0xFF;	
	write_data(data);		//low byte
	data=(address>>8)&0xFF;
	write_data(data);		//high byte
	write_command(0x42);		//set graphics home address
	return;
}           
//--------------------------------------------------------------------
void set_text_window(unsigned int address)
{
	unsigned char data;  
	
	data=address&0xFF;
	write_data(data);            	//low byte
	data=(address>>8)&0xFF;
	write_data(data);             	//high byte
	write_command(0x40);           	//Text home address 
	return;
}	   
//---------------------------------------------------------------------
void copy_display_memory(unsigned int source, unsigned int destination, unsigned int length)
{	
	unsigned int i;
	unsigned char data;
	
	for(i=0;i<length;i++)
	{
		set_address(source+i);
		data=read_data();
		set_address(destination+i);
		write_data(data);
		write_command(0xC0);
	}
	
	return;
}
//--------------------------------------------------------------------		
unsigned char read_data(void)
{
	unsigned char data=0;
	
	write_command(0xC1);		//read then increase address pointer
	while(((LCD_COMMAND) & 3)!=3);   

	delay_us(5);			//5uS marginal, 10uS maybe better
	data=LCD_DATA;
	return data;
}		
//---------------------------------------------------------------------
void clear_text(void)
{
	unsigned int i=0;
	set_address(TEXT_HOME0);
	
	for (i;i<TEXT_WIDTH*TEXT_LINES;i++)
	{
		write_data(0);
		write_command(0xC0);
	}
	 
	return;
}     
//----------------------------------------------------------------------
void clear_graphics(void)
{
	Blank(0,0,GRAPHICS_WIDTH,GRAPHICS_LINES);
	return;
}
//----------------------------------------------------------------------
void set_address(unsigned int address)
{
	write_data(address&0xFF);
	write_data(address>>8&0xFF);
	write_command(0x24);		
	return;
}
//********************************************************************
void pixel(unsigned char x,unsigned char y, unsigned char data)
{
	unsigned char bit_pos;
	bit_pos=x%8;
	x/=8;
	set_address(GRAPHICS_HOME0+((unsigned int)y*GRAPHICS_WIDTH)+x);
	write_command(0xF0|data<<3|(7-bit_pos));
	return;
}
//********************************************************************
void write_string(unsigned char x, unsigned char y,  char* ptr)
{
	set_address(TEXT_HOME0+((unsigned int)y*TEXT_WIDTH)+x);
	
	while (*ptr)
	{
 		write_data(*ptr-0x20);
 		write_command(0xC0);       	
		ptr++;                 
	}
	return;
}
//-----------------------------------------------------------------------------------------------------
void DrawBitmap(unsigned char flash* bitmap, unsigned char x, unsigned char y)
{
	unsigned char w;
	unsigned char h;
	unsigned int i;
	unsigned char xi; 
	unsigned int address;

	address=(GRAPHICS_HOME0+((unsigned int)y*GRAPHICS_WIDTH)+x);
	
	set_address(address); 
	
	i=0;
	w=bitmap[i++];
	h=bitmap[i++]; 

	while(h--)
	{
		xi=w;
		while(xi--)
		{    
			write_data(bitmap[i++]);
			write_command(0xC0);
		}
		
		address+=GRAPHICS_WIDTH;				
		set_address(address);
	}
	
	return;
} 
//---------------------------------------------------------------------------------------------------
void Blank(unsigned char x, unsigned char y, unsigned char w, unsigned char h)
{
	unsigned char xi; 
	unsigned int address;

	address=GRAPHICS_HOME0+(unsigned int)y*GRAPHICS_WIDTH+x;
	
	set_address(address); 

	while(h--)
	{
		xi=w;
		while(xi--)
		{    
			write_data(0);
			write_command(0xC0);
		}
		
		address+=GRAPHICS_WIDTH;				
		set_address(address);
	}
	
	return;  
} 
//-------------------------------------------------------------------------
void Line(int startx, int starty, int endx, int endy, int mask)
{
   int t, distance;
   int xerr=0,yerr=0,delta_x,delta_y;
   int incx, incy;

   delta_x=endx-startx;
   delta_y=endy-starty;    

   if (delta_x>0) incx=1;
   else  if (delta_x==0) incx=0;
   else  incx= -1;
   if (delta_y>0) incy=1;
   else  if (delta_y==0) incy=0;
   else  incy= -1;
          
   if(delta_x<0) delta_x=-delta_x;
   if(delta_y<0) delta_y=-delta_y;
   if (delta_x>delta_y) distance=delta_x;
   else                 distance=delta_y;

   for (t=0; t<=distance+1; t++) 
   {
      pixel(startx,starty, mask);
      xerr+=delta_x;
      yerr+=delta_y;
      if (xerr>distance)   {xerr-=distance; startx+=incx; }
      if (yerr>distance)   {yerr-=distance; starty+=incy; }
   }
} 
//***********************************************
void Frame(int x0,int y0,int x1,int y1,int mask)
{    
   Line(x0,y0,x1,y0, mask);
   Line(x1,y0,x1,y1, mask);
   Line(x0,y1,x1,y1, mask);
   Line(x0,y0,x0,y1, mask);
}
//***********************************************
void lcd_clear_full(void)
{

	unsigned int y;
	unsigned char d=0;

	LCD_DATA = 0x00;				//low byte
	LCD_DATA = 0x00;				//high byte
	LCD_COMMAND = 0x24;			//set start of text position
	LCD_COMMAND =0xB0;			//set autodata mode on

	for ( y=0;y<8192;y++)			// 8 kb. ram cleaning
	{
		LCD_DATA = d;
	}

	LCD_COMMAND =0xB2;			//set autodata mode off
	 
	LCD_DATA = 0x00;				//low byte
	LCD_DATA = 0x00;				//high byte
	LCD_COMMAND =0x24;			//set start of text position

	LCD_DATA = 0x00;				//low byte
	LCD_DATA = 0x00;				//high byte
	LCD_COMMAND =0x21;			//set cursor position

	 return;
} 
//---------------------------------------------------------------------------
void lcd_row (unsigned char data)
{
	unsigned int address;
	unsigned char low_byte;
	unsigned char high_byte;
	address=(data*40);
	low_byte=address&0xFF;
	address>>=8;
	high_byte=address&0xFF;
	LCD_DATA = low_byte;
	LCD_DATA = high_byte;
	LCD_COMMAND = 0x24;			//set start of text position
}
//----------------------------------------------------------------------------     
void lcd_circle(int x, int y, int radius, unsigned char show)
{
  int xc = 0;
  int yc; 
  int p; 
  yc = radius;
  p= 3 - (radius<<1);

  while (xc <= yc)  
  {
    pixel(x + xc, y + yc, show);
    pixel(x + xc, y - yc, show);
    pixel(x - xc, y + yc, show);
    pixel(x - xc, y - yc, show);
    pixel(x + yc, y + xc, show);
    pixel(x + yc, y - xc, show);
    pixel(x - yc, y + xc, show);
    pixel(x - yc, y - xc, show);
    if (p < 0)
      p += (xc++ << 2) + 6;
    else
      p += ((xc++ - yc--)<<2) + 10;
  }
}
//----------------------------------------------------------------
void lcd_degree_line(int x, int y, int degree, int inner_radius, int outer_radius, unsigned char show)
{
  int fx,fy,tx,ty;
  fx = x + (inner_radius * sin(degree * 3.14 / 180));
  fy = y - (inner_radius * cos(degree * 3.14 / 180));
  tx = x + (outer_radius * sin(degree * 3.14 / 180));
  ty = y - (outer_radius * cos(degree * 3.14 / 180));
  Line(fx,fy,tx,ty,show);
}
//----------------------------------------------------------------
circle_mass(int x, int y, int radius_out, int radius_in, unsigned char show)
{
int i;
int dr;
dr = radius_out - radius_in;
lcd_circle(x,y,radius_out,1);
for (i=0;i<=dr;i++)
lcd_circle(x,y,radius_out--,1);
}
//----------------------------------------------------------------
void timer0_init(void)
{
TCCR0 = 0x00; 
ASSR  = 0x08; 
TCNT0 = 0x00;
TIMSK = 0x01; 
TCCR0 = 0x05;
}
//-----------------------------------------------------------------------
/*
void RotatingObject(int W1,int W2,int W3, int x_Pos,int y_Pos,const int OBJ[][6],int cnt,int size)
{
 int M[4][4];   
 register int g,i;
 int z1,z2 ;
 int x1,x2 ;
 int y1,y2 ;
 int xr1,xr2 ;
 int yr1,yr2 ;
 int zr1,zr2 ;

  // Rotation-Matrix 
  // calculates the new position of the single vectors
  M[1][1] = ((long) COS[W2]*COS[W3]) /256;
  M[2][1] = ((long)-COS[W2]*SIN[W3]) /256;
  M[3][1] = SIN[W2];

  M[1][2] =  ((long)COS[W1]*SIN[W3])/256  + ((long)SIN[W1]*SIN[W2]*COS[W3])/(256*256);
  M[2][2] =  ((long)COS[W1]*COS[W3])/256  - ((long)SIN[W1]*SIN[W2]*SIN[W3])/(256*256);
  M[3][2] = ((long)-SIN[W1]*COS[W2])/256;

  M[1][3] =  ((long)SIN[W1]*SIN[W3])/256  - ((long)COS[W1]*SIN[W2]*COS[W3])/(256*256);
  M[2][3] =  ((long)SIN[W1]*COS[W3])/256  + ((long)COS[W1]*SIN[W2]*SIN[W3])/(256*256);
  M[3][3] =  ((long)COS[W1]*COS[W2])/256;

 if(size!=128)  // recalculate the size
  {
   for(g=1;g<4;g++) for(i=1;i<4;i++) M[g][i] =  (M[g][i] * size) / 128;
  };

 for(i=0;i<cnt;i++)  // draws the single lines
  {
    // get the line (from x1,y1,z1 to x2,y2,z2)
    x1 = OBJ[i][0];
    y1 = OBJ[i][1];					    
    z1 = OBJ[i][2];
    x2 = OBJ[i][3];
    y2 = OBJ[i][4];
    z2 = OBJ[i][5];

    // Convert the vector through the Rotation-Matrix
    xr1 = (M[1][1] * x1)/MUL + (M[2][1]*y1)/MUL + (M[3][1]*z1)/MUL;
    yr1 = (M[1][2] * x1)/MUL + (M[2][2]*y1)/MUL + (M[3][2]*z1)/MUL;
    xr2 = (M[1][1] * x2)/MUL + (M[2][1]*y2)/MUL + (M[3][1]*z2)/MUL;
    yr2 = (M[1][2] * x2)/MUL + (M[2][2]*y2)/MUL + (M[3][2]*z2)/MUL;

	// Draws the line
    Line( xr1 + x_Pos, yr1 + y_Pos, xr2 + x_Pos, yr2 + y_Pos, 1);
   }
}
//-----------------------------------------------------------------------------------------------
/*void _long_delay(void)
{
long t = 1000;
while (t--);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// draws a circle by the simple equation : x = cos(i) and y = sin(i)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Circle(int x,int y,int radius)
{
int i;
  for(i=0; i<63;i++)  // 0 to 2*Pi
   { 
   pixel( x + (COS[i] * radius) / 256 , y + (SIN[i] * radius) / 256, 1);
   }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// draws the Ball (planet?)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Ball(int W1,int W2,int W3, int x_Pos,int y_Pos,int size, int mask)
{
 int M[4][4];

register int g,i;
 int x,y,z;
 int xa,ya,za;
 int xb,yb;

  M[1][1] = ((long) COS[W2]*COS[W3]) /256;
  M[2][1] = ((long)-COS[W2]*SIN[W3]) /256;
  M[3][1] = SIN[W2];

  M[1][2] =  ((long)COS[W1]*SIN[W3])/256  + ((long)SIN[W1]*SIN[W2]*COS[W3])/(256*256);
  M[2][2] =  ((long)COS[W1]*COS[W3])/256  - ((long)SIN[W1]*SIN[W2]*SIN[W3])/(256*256);
  M[3][2] = ((long)-SIN[W1]*COS[W2])/256;

  M[1][3] =  ((long)SIN[W1]*SIN[W3])/256  - ((long)COS[W1]*SIN[W2]*COS[W3])/(256*256);
  M[2][3] =  ((long)SIN[W1]*COS[W3])/256  + ((long)COS[W1]*SIN[W2]*SIN[W3])/(256*256);
  M[3][3] =  ((long)COS[W1]*COS[W2])/256;

 if(size!=128)
  {
   for(g=1;g<4;g++) for(i=1;i<4;i++) M[g][i] =  (M[g][i] * size) / 128;
  };


 for (g=0;g<31;g+=8)
 {
   for (i=0;i<62;i++)
   {
    z = SIN[i] / 8;
    x = ((COS[i]/2) * (COS[g]/2)) / (2 * 256);
    y = ((COS[i]/2) * (SIN[g]/2)) / (2 * 256);

    ya = (M[1][2] * x)/MUL + (M[2][2]*y)/MUL + (M[3][2]*z)/MUL;
    if (ya >=0)	// just the positive y-values; otherwise the Ball is transparent
     {
       xa = (M[1][1] * x)/MUL + (M[2][1]*y)/MUL + (M[3][1]*z)/MUL;
       za = (M[1][3] * x)/MUL + (M[2][3]*y)/MUL + (M[3][3]*z)/MUL;
       xb = x_Pos + xa ;
       yb = y_Pos + za ;
	   pixel(xb,yb, mask);
     };
   }
 }
 for (i=15;i < 45;i+=4)  
 {
   for (g=0;g < 62; g++) 
   {
    z = SIN[i] / 8;
    x = ((COS[i]/2) * (COS[g]/2)) / (2 * 256);
    y = ((COS[i]/2) * (SIN[g]/2)) / (2 * 256);

    ya = (M[1][2] * x)/MUL + (M[2][2]*y)/MUL + (M[3][2]*z)/MUL;
     if (ya >=0) // just the positive y-values; otherwise the Ball is transparent
     {
       xa = (M[1][1] * x)/MUL + (M[2][1]*y)/MUL + (M[3][1]*z)/MUL;
       za = (M[1][3] * x)/MUL + (M[2][3]*y)/MUL + (M[3][3]*z)/MUL;
       xb = x_Pos + xa ;
       yb = y_Pos + za ;
	   pixel(xb,yb, mask);
     };
   }
 }
} */
//-------------------------------------------------------------------------------------------------