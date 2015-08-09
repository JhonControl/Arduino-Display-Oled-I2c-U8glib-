
#include "U8glib.h"
#include <math.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);	

String val;
int y_pos = 0;  // global variable

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( y_pos, y_pos, "Hello World!");
}
void setup() {
  
  
  
    Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  
  
}

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    
    
    //draw();
    
  char temp[5];  
 dtostrf(abs(y_pos),5,0,temp);// convertir int a char
  u8g.setFont(u8g_font_unifont);
    u8g.drawStr( 0, 10, temp); /// (horizontal,vertical,variable)
  
  
  u8g.setFont(u8g_font_gdr25);
  u8g.drawStr( (0 + y_pos), 40,  " VALOR "); /// (horizontal,vertical,variable)
  
  u8g.drawStr( (120 + y_pos), 40,temp); /// (horizontal,vertical,variable)
  
  
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr( y_pos, 60, temp); /// (horizontal,vertical,variable)

 
 
    
  } while( u8g.nextPage() );

  // Correct: Increase y_pos outside the picture loop
  y_pos++; 
  
   if(y_pos> 60)
 {
   y_pos=-100;
 }   
   
  // rebuild the picture after some delay
  delay(20);
}

