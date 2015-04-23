#include "gen.h"

int text_gen (nbase * base, int a, int n, char *out)
{
	srand(time(NULL));
	FILE *output = fopen(out, "w");
	int i, j, k;
	int index = 0;

	for (k = 0 ; k < base->r ; k++)
		fprintf (output, "%s ", base->grams[index]->words[k]);
	for (i = 0 ; i < a ; i++) {
		for (j = 0 ; j < n-base->r ; j++) {
			if ((index = gram_rand (index, base)) == -1)
				return 0;
			else
				fprintf (output, "%s ", base->grams[index]->words[base->r - 1]);
		}
	fprintf (output, "\n");
	}
}

int gram_rand (int index, nbase * base)
{
	int max = 0;
	int i;
	int j = 0;
	int n = 0;
	int **tab = malloc (sizeof(int*) * base->length);
	int tmp;
	
	for (i = 0 ; i < base->length ; i++) {
		if (base->n[index][i] != 0) {
			tab[n] = malloc (sizeof(int) * 2);
			tab[n][0] = i;
			tab[n][1] = base->n[index][i];
			max += base->n[index][i];
			n++;
			}
	}
	
	if (max == 0)
		return -1;

	else {
		int x = (rand() % max) + 1;
		while (j != base->length) {
			tmp = tab[j][1];
			while (tmp != 0) {
				tmp--;
				x--;
				if (x == 0)
					return tab[j][0];
			}
		j++;
		}
	}
	return -1;
}
