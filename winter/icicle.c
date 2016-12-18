#include <avr/pgmspace.h>
#include <util/delay.h>
#include "light_ws2812.h"

void frameless_player();

int
main (int argc, char **argv)
{
  while(1) frameless_player ();
}

void frameless_player() {
   struct cRGB blue[] = {{ .r = 0x00, .g = 0x00, .b = 0xff }};
   struct cRGB faded_blue[] = {{ .r = 0x00, .g = 0x00, .b = 0x88 }};
   struct cRGB dark_blue[] = {{ .r = 0x00, .g = 0x00, .b = 0x44 }};
   struct cRGB black[] = {{ .r = 0x00, .g = 0x00, .b = 0x00} };

   for (int position = 0; position < 11; position++) {
      for (int frame = 0; frame <8; frame++) {
         if( position == frame ) {
           ws2812_sendarray((uint8_t *) blue, 3);
         }
         else if ( frame == position -1 ) {
           ws2812_sendarray((uint8_t *) faded_blue, 3);
         }
         else if ( frame == position -2 ) {
           ws2812_sendarray((uint8_t *) dark_blue, 3);
         }
         else {
           ws2812_sendarray((uint8_t *) black, 3);
         }
      }
      _delay_us(60); // latch
      _delay_ms(100); //pause between frames
   }

   _delay_ms(700);
}
