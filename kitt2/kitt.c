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
   struct cRGB red[] = {{ .r = 0xFF, .g = 0x00, .b = 0x00 }};
   struct cRGB faded_red[] = {{ .r = 0x88, .g = 0x00, .b = 0x00 }};
   struct cRGB dark_red[] = {{ .r = 0x44, .g = 0x00, .b = 0x00 }};
   struct cRGB black[] = {{ .r = 0x10, .g = 0x00, .b = 0x00} };

   for (int position = 0; position < 8; position++) {
      for (int frame = 0; frame <8; frame++) {
         if( position == frame ) {
           ws2812_sendarray((uint8_t *) red, 3);
         }
         else if ( frame == position -1 ) {
           ws2812_sendarray((uint8_t *) faded_red, 3);
         }
         else if ( frame == position -2 ) {
           ws2812_sendarray((uint8_t *) dark_red, 3);
         }
         else {
           ws2812_sendarray((uint8_t *) black, 3);
         }
      }
      _delay_us(50);
   }

   _delay_us(40);

   for (int position = 7; position >= 0; position--) {
      for (int frame = 0; frame <8; frame++) {
         if( position == frame ) {
           ws2812_sendarray((uint8_t *) red, 3);
         }
         else if ( frame == position +1 ) {
           ws2812_sendarray((uint8_t *) faded_red, 3);
         }
         else if ( frame == position +2 ) {
           ws2812_sendarray((uint8_t *) dark_red, 3);
         }
         else {
           ws2812_sendarray((uint8_t *) black, 3);
         }
      }
      _delay_us(50);
   }

   _delay_us(40);

}
