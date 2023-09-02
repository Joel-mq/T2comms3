#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    2

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 10

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

int ledArr[10];

bool ledTogg = true;
  

void setup() {
  strip.begin();
//  strip.show(); // Initialize all pixels to 'off'
  

  for(int i = 0; i < 10; i++) {
  	ledArr[i] = i;
 
  }

  Serial.begin(9600);

}

void loop() {
    if(millis() % 1000 < 500 && ledTogg) {
       for(int i = 0; i < sizeof(ledArr); i++) {
          strip.setPixelColor(i, 255, 0, 255);
          strip.show(); 
       }
      ledTogg = false;
    } else if(millis() % 1000 >= 500 && !ledTogg){
      for(int i = 0; i < sizeof(ledArr); i++) {  
      strip.setPixelColor(i, 0, 255, 255);
        strip.show();
      }
      	ledTogg = true;
    }
  
  delay(50); 
}
