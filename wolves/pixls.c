#include <stdlib.h>
#include "pixls.h"

void
render_pixls (dyn_pixl pixls[], unsigned int number_of_pixls)
{
  unsigned char n;
  for (n = 0; n < number_of_pixls; n++)
    {
      render_pixl (&pixls[n]);

    }

  return;
}

void
update_pixls (dyn_pixl pixls[], unsigned int number_of_pixls)
{
  unsigned char n;
  for (n = 0; n < number_of_pixls; n++)
    {
      switch (pixls[n].anim)
        {
        case WAIT:
          do_wait (&pixls[n]);
          if (pixls[n].frame >= pixls[n].end_frame)
            {
              random_anim (&pixls[n]);
            }
          break;
        case ON:
          do_on (&pixls[n]);
          random_anim (&pixls[n]);
          break;
        case OFF:
          do_off (&pixls[n]);
          random_anim (&pixls[n]);
          break;
        }
    }

  return;
}

void
random_anim (dyn_pixl * pixl)
{
  pixl->frame = 0;
  switch (random_at_most (2))
    {
    case 0:
      pixl->anim = WAIT;
      break;
    case 1:
      pixl->anim = ON;
      break;
    case 2:
      pixl->anim = OFF;
      break;
    }
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
  pixl->brightness = 1;

  return;
}

void
do_off (dyn_pixl * pixl)
{
  pixl->brightness = 0;

  return;
}

void
render_pixl (dyn_pixl * pixl)
{

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
