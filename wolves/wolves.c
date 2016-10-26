
#include "pixls.h"

#define NUMBER_OF_PIXLS 3
#define TOTAL_FRAMES  100


void render_pixl (dyn_pixl * pixl);
void render_pixls (dyn_pixl pixls[], unsigned int number_of_pixls);

int
main (int argc, char **argv)
{
  dyn_pixl pixl  = {
    255,                       // red
     255,                       // green
     255,                       // blue
     0,                         // brightness
     0,                         // frame
     2,                         // end_frame
     WAIT                       // anim
  };

  int n;
  for (n = 0; n < TOTAL_FRAMES; n++)
    {
    }
}


void
render_pixl (dyn_pixl * pixl)
{

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

