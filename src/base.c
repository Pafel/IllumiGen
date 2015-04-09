#include "base.h"

void base_new (nbase * base, int n)
{
	base->r = n;
	base->k = 1;
	base->lenght = 0;

	int i;
	base->grams = malloc(sizeof(ngram) * 25);
	for(i = 0 ; i<25 ; i++)
	base->grams[i] = malloc(sizeof(ngram));

	base->n = (int**)malloc(sizeof(int) * 25);
	for (i = 0 ; i < 25 ; i++)
		base->n[i] = malloc(sizeof(int) * 25); 
}

void add_gram (int k, nbase * base, char **gram)		// dodaje n-gram do bazy
{
	if (base->lenght == base->k * 25) {
		k++;
		ngram tmp;
		base->grams  = realloc(base->grams, sizeof(ngram) * k * 25);
	}
	base->grams[base->lenght]->words = gram;

	base->lenght++;
}

int check_gram (char **gram, nbase * base)			// sprawdza, czy n-gram nie jest już w bazie
{								// jeśli jest zwraca 1, jeśli nie ma 0
	int i, j;
	for (i = 0 ; i < base->lenght ; i++) {
		for (j = 0 ; j < base->r ; j++) {
			if (base->grams[i]->words[j] != gram[j])
				return 0;
		}
	}

	return 1;
}

void base_gen (nbase * base, char *out)				// generuje plik z danymi przejściowe
{

}

void base_load (nbase * base, char *in)				// wczytuje bazę z pliku przejściowego
{

}
