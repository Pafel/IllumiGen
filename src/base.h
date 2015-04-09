#include <stdlib.h>

typedef struct gram{
	char **words;
}ngram;

typedef struct base{
	ngram **grams;
	int lenght;
	int r, k;
	int **n;
}nbase;

void base_new (nbase * base, int n);

void add_gram (int k, nbase * base, char **words);		// dodaje n-gram do bazy

int check_gram (char **gram, nbase * base);		// sprawdza, czy n-gram nie jest już w bazie
								// jeśli jest zwraca 1, jeśli nie ma 0

void base_gen (nbase * base, char *out);				// generuje plik z danymi przejściowe

void base_load (nbase * base, char *in);				// wczytuje bazę z pliku przejściowego
