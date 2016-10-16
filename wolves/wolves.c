
#include <stdio.h>
#include "wolves.h"

#define NUMBER_OF_PIXLS 3

dyn_pixl dyn_pixls[NUMBER_OF_PIXLS];

int main( int argc, char **argv)
{
    unsigned char n;
    for ( n = 0; n < NUMBER_OF_PIXLS; n++) {
        do_wait(&dyn_pixls[n]);
        dump_pixl(&dyn_pixls[n]);
    }

}

void do_wait( dyn_pixl *pixl) {
    pixl->red = 15;
    pixl->anim = wait;
    return;
}

void dump_pixl( dyn_pixl *pixl) {

    printf("Dumping dyn_pixl\n");
    printf("red: %u\n", pixl->red);
    printf("green: %u\n", pixl->green);
    printf("blue: %u\n", pixl->blue);
    printf("brightness: %u\n", pixl->brightness);
    printf("frame: %u\n", pixl->frame);
    printf("end_frame: %u\n", pixl->end_frame);
    printf("\n");

    return;
}
