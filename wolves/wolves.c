
#include "pixls.h"

#define NUMBER_OF_PIXLS 3
#define TOTAL_FRAMES  100

int
main (int argc, char **argv)
{
  dyn_pixl dyn_pixls[NUMBER_OF_PIXLS] = {
    {255,                       // red
     255,                       // green
     255,                       // blue
     0,                         // brightness
     0,                         // frame
     2,                         // end_frame
     WAIT                       // anim
     }
    ,
    {127,                       // red
     127,                       // green
     127,                       // blue
     0,                         // brightness
     0,                         // frame
     2,                         // end_frame
     WAIT                       // anim
     }
    ,
    {255,                       // red
     255,                       // green
     255,                       // blue
     0,                         // brightness
     0,                         // frame
     2,                         // end_frame
     WAIT                       // anim
     }
  };

  int n;
  for (n = 0; n < TOTAL_FRAMES; n++)
    {
#ifdef DEBUG
      printf ("main frame: %u\n", n);
#endif
      update_pixls (dyn_pixls, NUMBER_OF_PIXLS);
      render_pixls (dyn_pixls, NUMBER_OF_PIXLS);
    }
}

