#include "base.h"

#include <string.h>

nbase base_new (int n)
{
	nbase base;

	base.r = n;
	base.length = 0;

	int i, j;
	base.grams = malloc(sizeof (ngram) * 25);

	base.n = malloc(sizeof(int*) * 25);
	for (i = 0 ; i < 25 ; i++)
		base.n[i] = malloc(sizeof(int) * 25);

	return base;
}

void add_gram (nbase * base, char **gram)			// dodaje n-gram do bazy
{
	int k;
	if ((k = base->length % 25) == 0) {
		int n = base->length / 25;
		int i;
		ngram **tmp;

		tmp = realloc (base->grams, sizeof(ngram) * 25 * (n+1));
		base->grams = tmp;
		}

	base->grams[base->length] = new_gram (gram, base->r);
	base->length++;
}

void add_n (int a, int b, nbase * base)
{
	int k;
	if ((k = base->length % 25) == 0) {
		int n = base->length / 25;
		int i;
		int **tmp;

		tmp = malloc(sizeof(int*) * 25 * (n+1)); 
		
		for (i = 0 ; i < 25 * n ; i++)
			tmp[i] = realloc(base->n[i], sizeof(int) * 25 * (n+1));

		for (i = 25 * n ; i < 25 * (n+1) ; i++)
			tmp[i] = malloc(sizeof(int) * 25 * (n+1));

		base->n = tmp;
	}


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

}

void base_load (nbase * base, char *in)				// wczytuje bazę z pliku przejściowego
{

}
