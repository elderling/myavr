#include <Adafruit_NeoPixel.h>

typedef enum
{ wait, on, off } animation;

typedef struct
{
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  float brightness;
  unsigned int frame;
  unsigned int end_frame;
  animation anim;
} dyn_pixl;

#define NUMBER_OF_PIXLS 3
#define TOTAL_FRAMES 50
#define PIN 6
dyn_pixl dyn_pixls[NUMBER_OF_PIXLS] = {
  {255,                         // red
   255,                         //green
   255,                         //blue
   1,                         // brightness
   0,                           // frame
   5,                           // end_frame
   wait                         // anim
   }
  ,
  {127,                         // red
   127,                         //green
   127,                         //blue
   1,                         // brightness
   0,                           // frame
   6,                           // end_frame
   wait                         // anim
   }
  ,
  {255,                         // red
   255,                         //green
   255,                         //blue
   1,                         // brightness
   0,                           // frame
   7,                           // end_frame
   wait                         // anim
   }
};

void
render_pixls (dyn_pixl pixls[]);

Adafruit_NeoPixel strip =
Adafruit_NeoPixel (NUMBER_OF_PIXLS, PIN, NEO_GRB + NEO_KHZ800);

void
setup ()
{
    strip.begin();
  render_pixls(dyn_pixls);

}

void
loop ()
{
  // put your main code here, to run repeatedly:

}

void
render_pixls (dyn_pixl pixls[])
{
  unsigned char red, green, blue;
  unsigned char n;
  for (n = 0; n < NUMBER_OF_PIXLS; n++)
    {
      red = pixls[n].red * pixls[n].brightness / 100;
      green = pixls[n].green * pixls[n].brightness / 100;
      blue = pixls[n].blue * pixls[n].brightness / 100;

      strip.setPixelColor (n, strip.Color (red, green, blue));

    }

strip.show();
  return;
}
