#include "base.h"

nbase base_new (int n, int k)
{
	nbase base;

	base.r = n;
	base.length = 0;

	int i, j;
	base.grams = malloc(sizeof (ngram) * k);

	base.n = malloc(sizeof(int*) * k);
	for (i = 0 ; i < k ; i++)
		base.n[i] = malloc(sizeof(int) * k);

	return base;
}

void add_gram (nbase * base, char **gram)			// dodaje n-gram do bazy
{
	base->grams[base->length] = new_gram (gram, base->r);
	base->length++;
}

void add_n (int a, int b, nbase * base)
{
	if (base->n[a][b] == 0)
		base->n[a][b] = 1;
	else
		base->n[a][b]++;
}

int check_gram (char **gram, nbase * base)			// sprawdza, czy n-gram nie jest już w bazie
{								// jeśli jest zwraca index, jeśli nie ma -1
	int i, j;
	int n = 0;
	for (i = 0 ; i < base->length ; i++) {
		for (j = 0 ; j < base->r ; j++) {
			if (strcmp(base->grams[i]->words[j], gram[j]) == 0) {
				n++;
				if (n == base->r)
					return i;
			}
		}
		n = 0;
	}
	return -1;
}

ngram * new_gram (char **gram_words, int n)
{
	ngram * gram;
	int i;
	gram = malloc(sizeof(ngram*));
	gram->words = malloc(sizeof(char**));
	for (i = 0 ; i < n ; i++) {
		gram->words[i] = malloc(sizeof(char) * 32);
		strcpy(gram->words[i], gram_words[i]);
	}

	return gram;
}

void base_gen (nbase * base, char *out)				// generuje plik z danymi przejściowe
{
	FILE *ou = fopen (out, "w");
	int i, j;

	fprintf (ou, "%d %d\n", base->r, base->length);
	
	for (i = 0 ; i < base->length ; i++) {
		for (j = 0 ; j < base->r ; j++)
			fprintf(ou, "%s ", base->grams[i]->words[j]);
	fprintf(ou, "\n");
	}

	for (i = 0 ; i < base->length ; i++) {
		for (j = 0 ; j < base->length ; j++)
			fprintf (ou, "%d ", base->n[i][j]);
	fprintf(ou, "\n");
	}
}

nbase base_load (char *in)				// wczytuje bazę z pliku przejściowego
{
	FILE *inp = fopen (in, "r");
	int n, k, l;
	char *word = malloc (sizeof(char) * 32);

	fscanf (inp, "%d %d", &n, &k);

	nbase base = base_new (n, k);
	base.length = k;

	int i, j;
	for (i = 0 ; i < k ; i++) {
		base.grams[i] = malloc (sizeof(ngram*));
		base.grams[i]->words = malloc (sizeof(char**));
		for (j = 0 ; j < n ; j++) {
			fscanf (inp, "%s", word);
			base.grams[i]->words[j] = malloc (sizeof(char) * 32);
			strcpy(base.grams[i]->words[j], word);
		}
	}

	for (i = 0 ; i < k ; i++) {
		for (j = 0 ; j < k ; j++) {
			fscanf (inp, "%d", &l);
			base.n[i][j] = l;
		}
	}
	return base;
}
