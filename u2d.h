
#include <stdio.h>
#include <stdlib.h>

#define file_in args[2]
#define file_out args[3]
#define param args[1]

void help (int i);

int exist( char *file);

void convert(int par, char *in, char *out);
