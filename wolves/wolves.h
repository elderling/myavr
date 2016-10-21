

typedef enum { wait, on, off } animation;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char brightness;
    unsigned int frame;
    unsigned int end_frame;
    animation anim;
} dyn_pixl;

void do_wait(dyn_pixl * pixl);
void render_pixl(dyn_pixl * pixl);
void update_pixls( dyn_pixl pixls[] );
void render_pixls( dyn_pixl pixls[] );
