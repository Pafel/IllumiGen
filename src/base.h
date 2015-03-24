

typedef struct gram{
	char **words;
}ngram;

typedef struct base{
	gram **grams;
	int lenght;
	int r;
	int n[lenght][lenght];
}nbase;

nbase new_base (int r);									//zwraca wskaźnik na nową, pustą bazę

void add_gram (nbase * base, char **words);		// dodaje n-gram do bazy

int check_gram (ngram gram, nbase base);			// sprawdza, czy n-gram nie jest już w bazie
														// jeśli jest zwraca 1, jeśli nie ma 0

void base_gen (nbase base, FILE *out);					// generuje plik z danymi przejściowe

void base_load (nbase base, FILE *in);					// wczytuje bazę z pliku przejściowego
