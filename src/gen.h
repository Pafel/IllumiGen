#ifndef GEN_H
#define GEN_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "base.h"

int text_gen (nbase * base, int a, int n, char *out);

int gram_rand (int index, nbase * base);

#endif
