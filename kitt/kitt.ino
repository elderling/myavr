//#include <Adafruit_NeoPixel.h>
#include <light_ws2812.h>
#ifdef __AVR__
  #include <avr/pgmspace.h>
  #include <avr/power.h>
#endif

#define PIN 1

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

struct cRGB leds[8];

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

const uint16_t some_pixels[8][8][3] PROGMEM = {
// frame 0
 {
    {0xff, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
 },
// frame 1
 {
    {0x00, 0x00, 0x00},
    {0xff, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
 },
// frame 2
 {
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0xff, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
 },
// frame 3
{
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0xff, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
},
// frame 4
 {
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0xff, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
 },
// frame 5
{
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0xff, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
},
// frame 6
{
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0xff, 0x00, 0x00},
    {0x00, 0x00, 0x00},
},
// frame 7
{
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00},
    {0xff, 0x00, 0x00},
}
};

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code


  //strip.begin();
  //strip.show(); // Initialize all pixels to 'off'
}

void loop() {
    frame_player();
}

void frame_player() {

    for (int frame = 0; frame < 8; frame++ ) {
        //for( int i = 0; i < strip.numPixels(); i++ ) {
        for( int i = 0; i < 8; i++ ) {

            uint8_t red = (uint8_t) pgm_read_word_near(&(some_pixels[frame][i][0]));
            uint8_t green = (uint8_t) pgm_read_word_near(&(some_pixels[frame][i][1]));
            uint8_t blue = (uint8_t) pgm_read_word_near(&(some_pixels[frame][i][2]));

            //strip.setPixelColor(i, strip.Color( red,green,blue ));
            leds[i].r = red;
            leds[i].g = green;
            leds[i].b = blue;
            ws2812_sendarray((uint8_t *)leds, 8*3);
        }

        //strip.show();
        
        delay(50);
    }

    for (int frame = 7; frame >= 0; frame-- ) {
        //for( int i = 0; i < strip.numPixels(); i++ ) {
        for( int i = 0; i < 8; i++ ) {

            uint8_t red =   (uint8_t) pgm_read_word_near(&(some_pixels[frame][i][0]));
            uint8_t green = (uint8_t) pgm_read_word_near(&(some_pixels[frame][i][1]));
            uint8_t blue =  (uint8_t)  pgm_read_word_near(&(some_pixels[frame][i][2]));

            //strip.setPixelColor(i, strip.Color( red,green,blue ));
            leds[i].r = red;
            leds[i].g = green;
            leds[i].b = blue;
            ws2812_sendarray((uint8_t *)leds, 8*3);
        }

        //strip.show();
        
        delay(50);
    }
}


