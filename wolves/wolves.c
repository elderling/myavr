
#define DEBUG 1
#ifdef DEBUG
 #include <stdio.h>
#endif

#include <stdlib.h>
#include "wolves.h"


#define NUMBER_OF_PIXLS 3
#define TOTAL_FRAMES 50

dyn_pixl dyn_pixls[NUMBER_OF_PIXLS] = {
  {255,                         // red
   255,                         //green
   255,                         //blue
   0,                           // brightness
   0,                           // frame
   5,                           // end_frame
   wait                         // anim
   }
  ,
  {127,                         // red
   127,                         //green
   127,                         //blue
   0,                           // brightness
   0,                           // frame
   6,                           // end_frame
   wait                         // anim
   }
  ,
  {255,                         // red
   255,                         //green
   255,                         //blue
   0,                           // brightness
   0,                           // frame
   7,                           // end_frame
   wait                         // anim
   }
};


int
main (int argc, char **argv)
{

  int n;
  for (n = 0; n < TOTAL_FRAMES; n++)
    {
#ifdef DEBUG
      printf ("main frame: %u\n", n);
#endif
      update_pixls (dyn_pixls);
      render_pixls (dyn_pixls);
    }
}

void
render_pixls (dyn_pixl pixls[])
{
  unsigned char n;
  for (n = 0; n < NUMBER_OF_PIXLS; n++)
    {
#ifdef DEBUG
      printf ("Rendering dyn_pixl %u : ", n);
#endif
      render_pixl (&dyn_pixls[n]);

#ifdef DEBUG
      printf ("\n");
#endif
    }

#ifdef DEBUG
  printf ("\n");
#endif

  return;
}

void
update_pixls (dyn_pixl pixls[])
{
  unsigned char n;
  for (n = 0; n < NUMBER_OF_PIXLS; n++)
    {
      switch (dyn_pixls[n].anim)
        {
        case wait:
          do_wait (&dyn_pixls[n]);
          break;
        case on:
          do_on (&dyn_pixls[n]);
          break;
        case off:
          do_off (&dyn_pixls[n]);
          break;
        }

      return;
    }
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

void
render_pixl (dyn_pixl * pixl)
{

#ifdef DEBUG
  //printf (" red: %u", pixl->red);
  //printf (", green: %u", pixl->green);
  //printf (", blue: %u", pixl->blue);
  printf (", brightness: %u", pixl->brightness);
  printf (", frame: %u", pixl->frame);
  printf (", end_frame: %u", pixl->end_frame);
  printf (", anim: %u", pixl->anim);
#endif

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
