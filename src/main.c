#include "base.h"
#include "analyse.h"
#include "gen.h"
#include "stat.h"

#include <stdout.h>
#include <getopt.h>

int main (int argc, char **argv)
{
	int opt;
	int mode = 0;			// 0 - czyta pliki, 1 - czyta dane przejściowe
	int n = 2;			// rząd n-gramów, domyślnie 2
	int a = 4;			// liczba akapitów do generacji, domyślnie 4
	int s = 25;			// liczba słów w akapicie, domyślnie 25
	char *out = stdline;		// ścieżka zapisu wygenerowanego tekstu, domyślnie stdline
	char *bfile = base;		// ścieżka do danych przejściowych
	char **in;			// pliki do odczytu

	FILE *input;
	FILE *output = fopen(out);
	FILE *base_output = fopen(bfile);
	FILE *statout = fopen(stat);
	nbase base = new_base(n);

	while ((opt = getopt (argc, argv, "n:a:s:z:d:b:")) != -1) {

	}

	if (mode == 0) {
		int i = 0;
		while (in[i] != NULL) {
			inp = fopen(input[i]);
			analyse(base, input);
		}
	}

	else
		base_load(base, base_output);

	text_gen(base, a, s, output);
	
	if (mode == 0)
		base_gen(base, base_output);

	stat_gen(base, statout);

	return 0;
}
