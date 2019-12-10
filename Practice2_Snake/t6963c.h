//HIGH LEVEL COMMANDS
void init_cpu(void);
void init_display(void);
void set_graphic_window(unsigned int address);  
void set_text_window(unsigned int address);
void copy_display_memory(unsigned int source, unsigned int destination, unsigned int length);
void clear_text(void);
void clear_graphics(void);
void pixel(unsigned char x,unsigned char y, unsigned char data); 
void write_string(unsigned char x, unsigned char y,  char* ptr);
void backlight(unsigned char backlight_command); 
void DrawBitmap(unsigned char flash* bitmap, unsigned char x, unsigned char y);
void Blank(unsigned char x, unsigned char y, unsigned char w, unsigned char h);
void Frame(int x0,int y0,int x1,int y1,int mask);
void Line(int startx, int starty, int endx, int endy,int mask);
void lcd_clear_full(void);
void lcd_row (unsigned char data);
void lcd_circle(int x, int y, int radius, unsigned char show);
void lcd_degree_line(int x, int y, int degree, int inner_radius, int outer_radius, unsigned char show);
circle_mass(int x, int y, int radius_out, int radius_in, unsigned char show);
void timer0_init(void);
void Ball(int W1,int W2,int W3, int x_Pos,int y_Pos,int size, int mask);
void Circle(int x,int y,int radius);
void _long_delay(void);
void RotatingObject(int W1,int W2,int W3, int x_Pos,int y_Pos,const int OBJ[][6],int cnt,int size);


//LOW LEVEL COMMANDS
void write_command(unsigned char data);
void write_data(unsigned char data);
unsigned char read_data(void);
unsigned char read_status (void);  
void set_address(unsigned int address);
