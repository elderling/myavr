
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

RGB white = { 255, 255, 255 };

int
main (int argc, char **argv)
{

  test_compare_pixl ();
  test_wait ();
  test_fade_in ();
  test_fade_out ();
}

void
test_wait ()
{
  dyn_pixl pixl = {
    &white,
    0,                          // brightness
    0,                          // frame
    2,                          // end_frame
    WAIT                        // anim
  };

  dyn_pixl end_pixl = {
    &white,
    0,                          // brightness
    2,                          // frame
    2,                          // end_frame
    WAIT                        // anim
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
  dyn_pixl pixl = {
    &white,
    0,                          // brightness
    0,                          // frame
    17,                         // end_frame
    FADE_IN                     // anim
  };

  dyn_pixl end_pixl = {
    &white,
    0.71,                       // brightness
    12,                         // frame
    17,                         // end_frame
    FADE_IN                     // anim
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
  dyn_pixl pixl = {
    &white,
    1,                          // brightness
    0,                          // frame
    100,                        // end_frame
    FADE_OUT                    // anim
  };

  dyn_pixl end_pixl = {
    &white,
    0.25,                       // brightness
    75,                         // frame
    100,                        // end_frame
    FADE_OUT                    // anim
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
  dyn_pixl pixla = {
    &white,
    0,                          // brightness
    0,                          // frame
    2,                          // end_frame
    WAIT                        // anim
  };

  dyn_pixl pixlb = {
    &white,
    0,                          // brightness
    0,                          // frame
    2,                          // end_frame
    WAIT                        // anim
  };

  dyn_pixl pixlc = {
    &white,
    1,                          // brightness
    0,                          // frame
    2,                          // end_frame
    WAIT                        // anim
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
    ("red-> %u\ngreen-> %u\nblue-> %u\nbrightness-> %f\nframe-> %u\nend_frame-> %u\nanim-> %u\n",
     pixl->rgb->red,
     pixl->rgb->green,
     pixl->rgb->blue, pixl->brightness, pixl->frame, pixl->end_frame,
     pixl->anim);
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
      && pixl_a->end_frame == pixl_b->end_frame)
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

