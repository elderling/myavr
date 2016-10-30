#include <Adafruit_NeoPixel.h>
#include "pixls.h"

#define NUMBER_OF_PIXLS 8
#define PIN 1

Adafruit_NeoPixel strip =
Adafruit_NeoPixel (NUMBER_OF_PIXLS, PIN, NEO_GRB + NEO_KHZ800);

RGB red = { 64, 0, 0 };
RGB green = { 0, 64, 0 };
RGB black = { 0, 0, 0 };

int location = 0;

#define TOTAL_INSTRUCTIONS 4
#define NUM_PIXLS 8
dyn_pixl pixls[NUM_PIXLS];

void init_pixls ();
void
setup ()
{
  strip.begin ();
  init_pixls ();
  return;
}

void
init_pixls ()
{
  int i;
  for (i = 0; i < NUM_PIXLS; i++) {
      pixls[i].rgb = &black;
      pixls[i].frame = 0;
      pixls[i].brightness = 0;
      pixls[i].inst = get_prg_instruction (0);
      pixls[i].prg_counter = 0;
  }
   int randm ; 
    do { 
  randm = random() % NUM_PIXLS;
    }
    while ( randm ==  location);
    location = randm;
  //int randm = 4;
  for (i = randm; i == randm; i++)
    {
      pixls[i].rgb = &red;
      pixls[i].frame = 0;
      pixls[i].brightness = 0;
      pixls[i].inst = get_prg_instruction (0);
      pixls[i].prg_counter = 0;
    }
  return;
}

void
loop ()
{
  unsigned char red, green, blue;

  int n, i;
  for (n = 0; n < 400; n++)
    {
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

  init_pixls ();
}
