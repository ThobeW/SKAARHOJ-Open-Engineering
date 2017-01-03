/*********************************************************************
  This library is inspired by the ... library from Adafruit
  written by Limor Fried/Ladyada  for Adafruit Industries. The original
  library is BSD licensed.

  Just like SKAARHOJ, Adafruit also invests time and resources providing
  open source code, so SKAARHOJ encourage you to support Adafruit and
  open-source hardware by purchasing products from Adafruit as well!
*********************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <SkaarhojOLED32x256.h>

SkaarhojOLED32x256 display;

// width x height = 128,13
static const uint8_t SKAARHOJLogo[] PROGMEM = {
  B00011111, B11111111, B00111000, B00011111, B00000011, B11000000, B00000011, B11000000, B01111111, B11111100, B00111100, B00000111, B10000001, B11111110, B00000000, B00001111, B01111111, B11111111, B00111000, B00111110, B00000011, B11100000, B00000011, B11100000, B01111111, B11111111, B00111100, B00000111, B10000111, B11111111, B11000000, B00001111, B11111111, B11111111, B00111000, B01111100, B00000111, B11110000, B00000111, B11100000, B01111111, B11111111, B10111100, B00000111, B10011111, B11001111, B11100000, B00001111, B11111000, B00000000, B00111000, B11111000, B00000111, B11110000, B00001111, B11110000, B01111000, B00001111, B10111100, B00000111, B10011110, B00000011, B11100000, B00001111, B11111000, B00000000, B00111001, B11110000, B00001111, B01111000, B00001111, B01110000, B01111000, B00000111, B10111100, B00000111, B10111110, B00000001, B11100000, B00001111, B11111111, B11111100, B00111011, B11100000, B00001111, B01111000, B00011110, B01111000, B01111000, B00011111, B10111111, B11111111, B10111100, B00000001, B11110000, B00001111, B01111111, B11111111, B00111111, B11000000, B00011110, B00111100, B00011110, B00111100, B01111111, B11111111, B00111111, B11111111, B10111100, B00000001, B11110000, B00001111, B00011111, B11111111, B10111011, B11100000, B00011110, B00111100, B00111110, B00111100, B01111111, B11111110, B00111111, B11111111, B10111100, B00000001, B11110000, B00001111, B00000000, B00001111, B10111001, B11110000, B00111111, B11111110, B00111111, B11111110, B01111000, B01111100, B00111100, B00000111, B10111110, B00000001, B11100000, B00001111, B00000000, B00001111, B10111000, B11111000, B00111111, B11111110, B01111111, B11111110, B01111000, B00111110, B00111100, B00000111, B10011110, B00000001, B11100000, B00011111, B01111111, B11111111, B10111000, B01111100, B01111000, B00001111, B01111000, B00001111, B01111000, B00011111, B00111100, B00000111, B10011111, B10000111, B11000000, B00111110, B01111111, B11111111, B00111000, B00111110, B01111000, B00001111, B11110000, B00001111, B01111000, B00001111, B10111100, B00000111, B10001111, B11111111, B10011111, B11111110, B01111111, B11111100, B00111000, B00011111, B11110000, B00000111, B11110000, B00000111, B11111000, B00000111, B10111100, B00000111, B10000001, B11111110, B00011111, B11110000,
};

#include <Streaming.h>


void setup()   {
  Serial.begin(115200);
  Wire.begin();

  //display.begin(0); // Demo display
  //display.begin(0, 0x3, 32, true); // BI16-1x6OLED
  //display.begin(1, 0x3, 32, true); // BI16-1x8OLED
  //display.begin(2, 0x3, 32); // PCB-SIL-1x6OLED
   display.begin(3, 0x1F, 32, true); // PCB-SIL-1x10OLED (addr: 2+3)
  //display.begin(3, 0x3, 32);    // PCB-1x6 
}

int8_t dy = 1, dx = 1;
int x = 0, y = 0;
uint8_t sizex = 128, sizey = 13;
void loop() {
  if (x + sizex + dx > 255 || x + dx < 0) {
    dx = -dx;
  }
  if (y + sizey + dy > 31 || y + dy < 0) {
    dy = -dy;
  }

  x += dx;
  y += dy;

  display.drawBitmap(x, y, SKAARHOJLogo, 128, 13, 1, false);

  /*for(uint8_t i = x; i<x+sizex; i++) {
    for(uint8_t j = y; j<y+sizey; j++) {
      display.drawPixel(i, j, 1);
    }
    }*/

  display.display(B11111);
  display.clearDisplay();
}