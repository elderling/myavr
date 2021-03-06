#include <stdlib.h>
#include "pixls.h"

#define TOTAL_INSTRUCTIONS  16
instruction program[TOTAL_INSTRUCTIONS] = {
  FADE_IN, 100,
  WAIT, 50,
  FADE_OUT, 7,
  WAIT, 1,
  FADE_IN, 7,
  WAIT, 100,
  FADE_OUT, 5,
  WAIT, 1,
  FADE_IN, 5,
  WAIT, 100,
  FADE_OUT, 3,
  WAIT, 1,
  FADE_IN, 3,
  WAIT, 50,
  FADE_OUT, 30,
  WAIT, 50 
};

instruction *
get_prg_instruction (unsigned char i)
{
  return &program[i];
}

void
update_pixl (dyn_pixl * pixl)
{
  if (pixl->frame < pixl->inst->end_frame)
    {
      pixl->frame++;
    }
  else
    {
      pixl->frame = 0;
      if (++pixl->prg_counter >= TOTAL_INSTRUCTIONS)
        {
          return;
          // pixl->prg_counter = 0;
        }
      pixl->inst = &program[pixl->prg_counter];
    }

  switch (pixl->inst->anim)
    {
    case WAIT:
      do_wait (pixl);
      break;
    case FADE_IN:
      do_fade_in (pixl);
      break;
    case FADE_OUT:
      do_fade_out (pixl);
      break;
    }

  return;
}

void
update_pixls (dyn_pixl pixls[], unsigned char number_of_pixls)
{
  unsigned char n;
  for (n = 0; n < number_of_pixls; n++)
    {
      update_pixl (&pixls[n]);
    }

  return;
}

void
do_wait (dyn_pixl * pixl)
{
  return;
}

void
do_fade_in (dyn_pixl * pixl)
{
  pixl->brightness = (double) pixl->frame / pixl->inst->end_frame;

  return;
}

void
do_fade_out (dyn_pixl * pixl)
{
  pixl->brightness =
    (double) (pixl->inst->end_frame - pixl->frame) / pixl->inst->end_frame;

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
