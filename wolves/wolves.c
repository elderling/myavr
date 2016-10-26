
#include <stdio.h>
#include "pixls.h"

#define NUMBER_OF_PIXLS 3
#define TOTAL_FRAMES  100


void render_pixl (dyn_pixl * pixl);
void render_pixls (dyn_pixl pixls[], unsigned int number_of_pixls);
void test_compare_pixl ();

int
main (int argc, char **argv)
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

  //render_pixl(&pixl);

  int n;
  for (n = 0; n < NUMBER_OF_PIXLS; n++)
    {
      update_pixl (&pixl);
    }

  //render_pixl(&pixl);

  test_compare_pixl ();
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
