
#include <stdio.h>
#include <math.h>
#include "pixls.h"

#define TOTAL_FRAMES  100


int compare_pixl (dyn_pixl * pixl_a, dyn_pixl * pixl_b);
void render_pixl (dyn_pixl * pixl);
void render_pixls (dyn_pixl pixls[], unsigned int number_of_pixls);
void test_compare_pixl ();
void test_wait ();
void test_fade_in ();
void test_fade_out ();
void test_transition ();

RGB white = { 255, 255, 255 };

int
main (int argc, char **argv)
{

  test_compare_pixl ();
  test_wait ();
  test_fade_in ();
  test_fade_out ();
  test_transition ();
}

void
test_transition ()
{
  dyn_pixl pixl = {
    &white,
    0,                          // brightness
    0                           // frame
  };

  pixl.inst = get_prg_instruction (0);

  int n;

  for (n = 0; n < 299; n++)
    {
      printf
        ("global frame: %u \t local frame %u \t anim: %u \t brightness: %f\n",
         n, pixl.frame, pixl.inst->anim, pixl.brightness);
      update_pixl (&pixl);
    }

  return;

}

void
test_wait ()
{
  instruction the_inst = { WAIT, 2 };
  dyn_pixl pixl = {
    &white,
    0,                          // brightness
    0,                          // frame
    &the_inst
  };

  dyn_pixl end_pixl = {
    &white,
    0,                          // brightness
    2,                          // frame
    &the_inst
  };

  int n;
  for (n = 0; n < TOTAL_FRAMES; n++)
    {
      update_pixl (&pixl);
    }

  if (compare_pixl (&pixl, &end_pixl))
    {
      printf ("WAIT PASS\n");
    }
  else
    {
      printf ("WAIT FAIL\n");
    }
}

void
test_fade_in ()
{
  instruction the_inst = { FADE_IN, 17 };
  dyn_pixl pixl = {
    &white,
    0,                          // brightness
    0,                          // frame
    &the_inst
  };

  dyn_pixl end_pixl = {
    &white,
    0.71,                       // brightness
    12,                         // frame
    &the_inst
  };

  int n;
  for (n = 0; n < 12; n++)
    {
      update_pixl (&pixl);
    }

  if (compare_pixl (&pixl, &end_pixl))
    {
      printf ("FADE_IN PASS\n");
    }
  else
    {
      printf ("FADE_IN FAIL: \n");
      render_pixl (&pixl);

    }
}

void
test_fade_out ()
{
  instruction the_inst = { FADE_OUT, 100 };
  dyn_pixl pixl = {
    &white,
    1,                          // brightness
    0,                          // frame
    &the_inst
  };

  dyn_pixl end_pixl = {
    &white,
    0.25,                       // brightness
    75,                         // frame
    &the_inst
  };

  int n;
  for (n = 0; n < 75; n++)
    {
      update_pixl (&pixl);
    }

  if (compare_pixl (&pixl, &end_pixl))
    {
      printf ("FADE_OUT PASS\n");
    }
  else
    {
      printf ("FADE_OUT FAIL: \n");
      render_pixl (&pixl);

    }
}

void
test_compare_pixl ()
{
  instruction the_inst = { WAIT, 2 };
  dyn_pixl pixla = {
    &white,
    0,                          // brightness
    0,                          // frame
    &the_inst
  };

  dyn_pixl pixlb = {
    &white,
    0,                          // brightness
    0,                          // frame
    &the_inst
  };

  dyn_pixl pixlc = {
    &white,
    1,                          // brightness
    0,                          // frame
    &the_inst
  };

  if (compare_pixl (&pixla, &pixlb))
    {
      printf ("compare_pixl() equals test PASS\n");
    }
  else
    {
      printf ("compare_pixl() equals test FAIL\n");
    }

  if (!compare_pixl (&pixla, &pixlc))
    {
      printf ("compare_pixl() NOT equals test PASS\n");
    }
  else
    {
      printf ("compare_pixl() NOT equals test FAIL\n");
    }
}


void
render_pixl (dyn_pixl * pixl)
{

  printf
    ("red-> %u\ngreen-> %u\nblue-> %u\nbrightness-> %f\nframe-> %u\nend_frame-> %u\nanim-> %u\nprg_counter-> %u\n",
     pixl->rgb->red,
     pixl->rgb->green,
     pixl->rgb->blue, pixl->brightness, pixl->frame, pixl->inst->end_frame,
     pixl->inst->anim, pixl->prg_counter);
  return;
}


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

int
compare_pixl (dyn_pixl * pixl_a, dyn_pixl * pixl_b)
{
  if (pixl_a->rgb->red == pixl_b->rgb->red
      && pixl_a->rgb->green == pixl_b->rgb->green
      && pixl_a->rgb->blue == pixl_b->rgb->blue
      && pixl_a->frame == pixl_b->frame
      && pixl_a->inst->end_frame == pixl_b->inst->end_frame)
    {
      if (fabs (pixl_a->brightness - pixl_b->brightness) < 0.5)
        {
          return 1;
        }
      else
        {
          return 0;
        }
    }
  else
    {
      return 0;
    }
}
