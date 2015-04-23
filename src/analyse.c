#include "analyse.h"

void analyse (nbase * base, char *inp)
{
	int r = base->r;
	int i, j;
	int index, index_prev;
	int n = 0;
	int k = 0;

	FILE *input;

	input = fopen(inp, "r");

	char *word = malloc(sizeof (char) * 32);
	char **string = malloc(sizeof (char*) * r);
	for (i = 0 ; i < r ; i++)
		string[i] = malloc(sizeof (char) * 32);
 
	while (fscanf(input, "%s", word) == 1) {
		if (n == r) {
			if ((index = check_gram(string, base)) == -1) {
				add_gram(base, string);
				index = base->length - 1;
			}
				
			if (base->length > 1)
				add_n (index_prev, index, base);
			index_prev = index;	

			for(j = 1 ; j < r ; j++)
				strcpy(string[j-1], string[j]);
			strcpy(string[j-1], word);
		}
		else {
			strcpy(string[n], word);
			n++;
		}
	}

	if ((index = check_gram(string, base)) == -1) {
		add_gram(base, string);
		index = base->length -1;
	}

	if (base->length > 1) {
		if (base->n[index_prev][index] = 0)
			base->n[index_prev][index] = 1;
		else
			base->n[index_prev][index]++;
	}
}

int count_words(char *in)
{
	int n = 0;
	char *str = malloc (sizeof(char) * 32);
	FILE *inp = fopen(in, "r");
	if (inp == NULL)
		return -1;
	while (fscanf(inp, "%s", str) == 1)
		n++;

	return n;

























}
