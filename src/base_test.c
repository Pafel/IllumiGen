#include "base.h"

#include <stdio.h>

int main()
{
	int k = 0;
	int n = 2;
	nbase base;

	base_new(&base, n);

	char **text;
	text[0] = "Ala";
	text[1] = "ma";

	add_gram(&k, &base, text);
	printf ("%d\n", check_gram(text, &base));
	return 0;
}
