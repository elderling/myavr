typedef enum
{ WAIT, FADE_IN, FADE_OUT } animation;

typedef struct
{
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  double brightness;
  unsigned int frame;
  unsigned int end_frame;
  animation anim;
} dyn_pixl;

void do_wait (dyn_pixl * pixl);
void do_fade_in (dyn_pixl * pixl);
void do_fade_out (dyn_pixl * pixl);
void update_pixls (dyn_pixl pixls[], unsigned int number_of_pixls);
void random_anim (dyn_pixl * pixl);
long random_at_most (long max);
void update_pixl (dyn_pixl * pixl);
int compare_pixl (dyn_pixl * pixl_a, dyn_pixl * pixl_b);
