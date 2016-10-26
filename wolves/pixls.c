#include <stdlib.h>
#include "pixls.h"

void
update_pixl (dyn_pixl * pixl)
{
  switch (pixl->anim)
    {
    case WAIT:
      do_wait (pixl);
      break;
    case ON:
      do_on (pixl);
      break;
    case OFF:
      do_off (pixl);
      break;
    }

  pixl->frame++;
  return;
}

void
update_pixls (dyn_pixl pixls[], unsigned int number_of_pixls)
{
  unsigned char n;
  for (n = 0; n < number_of_pixls; n++)
    {
      update_pixl( &pixls[n] );
    }

  return;
}

void
do_wait (dyn_pixl * pixl)
{
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
