#include <stdlib.h>

typedef struct gram{
	char **words;
}ngram;

typedef struct base{
	ngram **grams;
	int length;
	int r;
	int **n;
}nbase;

nbase base_new (int n);

void add_gram (nbase * base, char **words);			// dodaje n-gram do bazy

void add_n (int a, int b, nbase * base);

int check_gram (char **gram, nbase * base);				// sprawdza, czy n-gram nie jest już w bazie
									// jeśli jest zwraca index, jeśli nie ma -1

ngram * new_gram (char **gram_words, int n);

void base_gen (nbase * base, char *out);				// generuje plik z danymi przejściowe

void base_load (nbase * base, char *in);				// wczytuje bazę z pliku przejściowego
