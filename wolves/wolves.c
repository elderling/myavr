
#include <stdio.h>
#include "wolves.h"


#define NUMBER_OF_PIXLS 3
#define TOTAL_FRAMES 50

dyn_pixl dyn_pixls[NUMBER_OF_PIXLS] = {
  {255,                         // red
   255,                         //green
   255,                         //blue
   255,                         // brightness
   0,                           // frame
   0,                           // end_frame
   wait                         // anim
   }
  ,
  {127,                         // red
   127,                         //green
   127,                         //blue
   255,                         // brightness
   0,                           // frame
   0,                           // end_frame
   wait                         // anim
   }
  ,
  {255,                         // red
   255,                         //green
   255,                         //blue
   255,                         // brightness
   0,                           // frame
   0,                           // end_frame
   wait                         // anim
   }
};

int
main (int argc, char **argv)
{
  update_pixls (dyn_pixls);
  render_pixls (dyn_pixls);
}

void
render_pixls (dyn_pixl pixls[])
{
  unsigned char n;
  for (n = 0; n < NUMBER_OF_PIXLS; n++)
    {
      printf ("Rendering dyn_pixl %u : ", n);
      render_pixl (&dyn_pixls[n]);

      printf ("\n");
    }


  return;
}

void
update_pixls (dyn_pixl pixls[])
{
  unsigned char n;
  for (n = 0; n < NUMBER_OF_PIXLS; n++)
    {
      do_wait (&dyn_pixls[n]);
    }

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
render_pixl (dyn_pixl * pixl)
{

  printf (" red: %u", pixl->red);
  printf (", green: %u", pixl->green);
  printf (", blue: %u", pixl->blue);
  printf (", brightness: %u", pixl->brightness);
  printf (", frame: %u", pixl->frame);
  printf (", end_frame: %u", pixl->end_frame);

  return;
}
