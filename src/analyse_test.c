#include "analyse.h"
#include "base.h"

int main(int argc, char **argv)
{
	int k = 0;
	int n = 2;
	int i, j;

	nbase base = base_new(n);

	analyse(&base, argv[1]);

	for (i = 0 ; i < base.length ; i++) {
		for (j = 0 ; j < base.r ; j++)
			printf("%s ", base.grams[i]->words[j]);
		printf("\n");
	}
	

	return 0;
}
