#include <Adafruit_NeoPixel.h>
#include "pixls.h"

#define PIN 1
#define NUM_PIXLS 20

Adafruit_NeoPixel strip =
Adafruit_NeoPixel (NUM_PIXLS, PIN, NEO_RGB + NEO_KHZ800);

RGB red = { 255, 0, 0 };
RGB black = { 0, 0, 0 };

unsigned char location = 0;

#define TOTAL_INSTRUCTIONS 16
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
  unsigned char i;
  for (i = 0; i < NUM_PIXLS; i++) {
      pixls[i].rgb = &black;
      pixls[i].frame = 0;
      pixls[i].brightness = 0;
      pixls[i].inst = get_prg_instruction (0);
      pixls[i].prg_counter = 0;
  }
   unsigned char randm ; 
    do { 
  randm = (random() % (NUM_PIXLS - 1)) ;
    }
    while ( randm ==  location);
    location = randm;
  for (i = randm; i <= randm + 1; i++)
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
  int n;
  unsigned char i;
  for (n = 0; n < 550; n++)
    {
      for (i = 0; i < NUM_PIXLS; i++)
        {
          update_pixl (&pixls[i]);
          strip.setPixelColor (i, strip.Color (
          (pixls[i].brightness * pixls[i].rgb->red),
          (pixls[i].brightness * pixls[i].rgb->green),
          (pixls[i].brightness * pixls[i].rgb->blue)
          ));
        }
      strip.show ();

      // put your main code here, to run repeatedly:
      delay (50);
    }

  init_pixls ();
}
