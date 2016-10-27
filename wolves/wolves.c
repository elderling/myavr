
#include <stdio.h>
#include "pixls.h"

#define TOTAL_FRAMES  100


void render_pixl (dyn_pixl * pixl);
void render_pixls (dyn_pixl pixls[], unsigned int number_of_pixls);
void test_compare_pixl ();
void test_wait ();

int
main (int argc, char **argv) {

  test_compare_pixl ();
  test_wait ();
}

void
test_wait ()
{
  dyn_pixl pixl = {
    255,                        // red
    255,                        // green
    255,                        // blue
    0,                          // brightness
    0,                          // frame
    2,                          // end_frame
    WAIT                        // anim
  };

  dyn_pixl end_pixl = {
    255,                        // red
    255,                        // green
    255,                        // blue
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
test_compare_pixl ()
{
  dyn_pixl pixla = {
    255,                        // red
    255,                        // green
    255,                        // blue
    0,                          // brightness
    0,                          // frame
    2,                          // end_frame
    WAIT                        // anim
  };

  dyn_pixl pixlb = {
    255,                        // red
    255,                        // green
    255,                        // blue
    0,                          // brightness
    0,                          // frame
    2,                          // end_frame
    WAIT                        // anim
  };

  dyn_pixl pixlc = {
    255,                        // red
    255,                        // green
    255,                        // blue
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
     pixl->red,
     pixl->green,
     pixl->blue, pixl->brightness, pixl->frame, pixl->end_frame, pixl->anim);
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
