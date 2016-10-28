typedef enum
{ WAIT, FADE_IN, FADE_OUT } animation;

typedef struct
{
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} RGB;

typedef struct
{
  animation anim;
  unsigned int end_frame;
} instruction;

typedef struct
{
  RGB *rgb;
  double brightness;
  unsigned int frame;
  instruction *inst;
  unsigned char prg_counter;
} dyn_pixl;

#ifdef __cplusplus
extern "C" {
#endif
void do_wait (dyn_pixl * pixl);
void do_fade_in (dyn_pixl * pixl);
void do_fade_out (dyn_pixl * pixl);
void update_pixls (dyn_pixl pixls[], unsigned int number_of_pixls);
void random_anim (dyn_pixl * pixl);
long random_at_most (long max);
void update_pixl (dyn_pixl * pixl);
void next_instruction (dyn_pixl * pixl);
instruction *get_prg_instruction (unsigned char i);
#ifdef __cplusplus
}
#endif
