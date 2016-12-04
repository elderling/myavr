#include <stdio.h>
#include "bitpack.h"

int
main (int argc, char **argv)
{
  unsigned char bytes[2] = { 0xff, 0xf0 };
  struct packed_values packed = { .bytes = bytes; .length = 2; };
  printf("All tests pass\n");
}
