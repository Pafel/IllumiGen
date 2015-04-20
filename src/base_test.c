#include "base.h"

#include <stdio.h>

int main()
{
	int k = 0;
	int n = 2;
	int i;
	nbase base = base_new(n);

	char **text = malloc(sizeof(char**));
	text[0] = "Ala";
	text[1] = "ma";

	for(i = 0 ; i < 10 ; i++) {
		add_gram(k, &base, text);
		printf ("%d\n", check_gram(text, &base));
	}
	return 0;
}
