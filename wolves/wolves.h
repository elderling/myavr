

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char brightness;
    unsigned int frame;
    unsigned int end_frame;
    unsigned char animation; // FIXME enum
} dyn_pixl;

void wait( dyn_pixl *pixl);
void dump_pixl( dyn_pixl *pixl);
