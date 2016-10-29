#include <Adafruit_NeoPixel.h>
#include "pixls.h"

#define NUMBER_OF_PIXLS 1
#define PIN 1

Adafruit_NeoPixel strip =
Adafruit_NeoPixel (NUMBER_OF_PIXLS, PIN, NEO_GRB + NEO_KHZ800);

RGB white = { 255, 0, 0 };

dyn_pixl pixl; 

void
setup ()
{
  strip.begin ();
  pixl.rgb = &white;
  pixl.frame = 0;
  pixl.brightness = 0;
  pixl.inst = get_prg_instruction(0);

  return;
}

void
loop ()
{
  unsigned char red, green, blue;

  update_pixl(&pixl);

  red = pixl.brightness * pixl.rgb->red;
  green =  pixl.brightness * pixl.rgb->green;
  blue =  pixl.brightness * pixl.rgb->blue;

      strip.setPixelColor (0, strip.Color (red, green, blue));
  strip.show ();
  
  // put your main code here, to run repeatedly:
  delay(10);
}
/*
void
render_pixls (dyn_pixl pixls[])
{
  unsigned char red, green, blue;
  unsigned char n;
  for (n = 0; n < NUMBER_OF_PIXLS; n++)
    {
      red = pixls[n].red ;
      green = pixls[n].green;
      blue = pixls[n].blue;

      strip.setPixelColor (n, strip.Color (red, green, blue));

    }

  strip.show ();
  return;
}
*/

