#include <Adafruit_NeoPixel.h>
#include "pixls.h"

#define NUMBER_OF_PIXLS 8
#define PIN 1

Adafruit_NeoPixel strip =
Adafruit_NeoPixel (NUMBER_OF_PIXLS, PIN, NEO_GRB + NEO_KHZ800);

RGB white = { 255, 0, 0 };

#define NUM_PIXLS 8
dyn_pixl pixls[NUM_PIXLS];

void
setup ()
{
  strip.begin ();
  int i;
  for (i = 0; i < NUM_PIXLS; i++)
    {
      pixls[i].rgb = &white;
      pixls[i].frame = 0;
      pixls[i].brightness = 0;
      pixls[i].inst = get_prg_instruction (0);
    }
  return;
}

void
loop ()
{
  unsigned char red, green, blue;

  int i;
  for (i = 0; i < NUM_PIXLS; i++)
    {
      update_pixl (&pixls[i]);

      red = pixls[i].brightness * pixls[i].rgb->red;
      green = pixls[i].brightness * pixls[i].rgb->green;
      blue = pixls[i].brightness * pixls[i].rgb->blue;

      strip.setPixelColor (i, strip.Color (red, green, blue));
    }
  strip.show ();

  // put your main code here, to run repeatedly:
  delay (10);
}
