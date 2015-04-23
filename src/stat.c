#include "base.h"

void stat_gen (nbase base, char *out, int w)
{
	FILE *ou = fopen (out, "w");
	int i, j, l;
	int n = 0;
	int max = 0;
	int k = 0;
	int *index_max_gram = malloc (sizeof(int) * 10);

	for (i = 0 ; i < base.length ; i++) {
		for (j = 0 ; j < base.length ; j++)
			n += base.n[i][j];
		if (n == max) {
			index_max_gram[k] = i;
			k++;
		}
		else if (n > max) {
			for (l = 0 ; l < k ; l++)
				index_max_gram[l] = 0;
			index_max_gram[k] = i;
			max = n;
			k = 1;
		}
		n = 0;
	}

	fprintf (ou, "Najczęściej występujące n-gramy:\n");
	for (i = 0 ; i < k ; i++) {
		for (j = 0 ; j < base.r ; j++)
			fprintf (ou, "%s ", base.grams[index_max_gram[i]]->words[j]);
		fprintf (ou, "\n");
	}
	fprintf (ou, "Ilość wystąpień: %d\n\n", max);
	fprintf (ou, "Ilość słów w tekstach źródłowych: %d\n\n", w);
	fprintf (ou, "Ilość wygenerowanych n-gramów: %d\n\n", base.length);
}
