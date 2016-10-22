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

void do_wait(dyn_pixl * pixl);
void do_on(dyn_pixl * pixl);
void do_off(dyn_pixl * pixl);
void render_pixl(dyn_pixl * pixl);
void update_pixls( dyn_pixl pixls[] );
void render_pixls( dyn_pixl pixls[] );
void random_anim(dyn_pixl * pixl);
long random_at_most(long max) ;

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

void do_wait(dyn_pixl * pixl);
void do_on(dyn_pixl * pixl);
void do_off(dyn_pixl * pixl);
void render_pixl(dyn_pixl * pixl);
void update_pixls( dyn_pixl pixls[] );
void render_pixls( dyn_pixl pixls[] );
void random_anim(dyn_pixl * pixl);
long random_at_most(long max) ;

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
      update_pixls (dyn_pixls);
      render_pixls (dyn_pixls);
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

void
update_pixls (dyn_pixl pixls[])
{
  unsigned char n;
  for (n = 0; n < NUMBER_OF_PIXLS; n++)
    {
// FIXME switch?
      if ((&dyn_pixls[n])->anim == wait)
        {
          do_wait (&dyn_pixls[n]);
        }

      if ((&dyn_pixls[n])->anim == on)
        {
          do_on (&dyn_pixls[n]);
        }

      if ((&dyn_pixls[n])->anim == off)
        {
          do_off (&dyn_pixls[n]);
        }

      if ((&dyn_pixls[n])->frame == (&dyn_pixls[n])->end_frame)
        {
          random_anim (&dyn_pixls[n]);
        }
    }

  return;
}

void
random_anim (dyn_pixl * pixl)
{
  pixl->frame = 0;
  pixl->anim = (animation) random_at_most (2);
  pixl->end_frame = (int) random_at_most (6);
  return;
}

void
do_wait (dyn_pixl * pixl)
{
  if (pixl->frame < pixl->end_frame)
    {
      pixl->frame++;
    }

  return;
}

void
do_on (dyn_pixl * pixl)
{
  pixl->brightness = 100;
  if (pixl->frame < pixl->end_frame)
    {
      pixl->frame++;
    }

  return;
}

void
do_off (dyn_pixl * pixl)
{
  pixl->brightness = 0;
  if (pixl->frame < pixl->end_frame)
    {
      pixl->frame++;
    }

  return;
}

// From http://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range#6852396
// Assumes 0 <= max <= RAND_MAX
// Returns in the closed interval [0, max]
long
random_at_most (long max)
{
  unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
   
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins, defect = num_rand % num_bins;

  long x;
  do
    {
      x = random ();
    }
  // This is carefully written not to overflow
  while (num_rand - defect <= (unsigned long) x);

  // Truncated division is intentional
  return x / bin_size;
}
