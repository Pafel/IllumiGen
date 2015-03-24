#include "base.h"

nbase new_base (int r);

void add_gram (nbase * base, char **words);	

int check_gram (ngram gram, nbase base);

void base_gen (nbase base, FILE *out);

void base_load (nbase base, FILE *in);