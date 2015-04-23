#include <stdio.h>
#include <getopt.h>
#include <string.h>

#include "base.h"
int main (int argc, char **argv)
{
	int w = 0;
	int opt;
	int mode = 0;					// 0 - czyta pliki, 1 - czyta dane przejściowe
	int n = 2;					// rząd n-gramów, domyślnie 2
	int a = 4;					// liczba akapitów do generacji, domyślnie 4
	int s = 25;					// liczba słów w akapicie, domyślnie 25
	char *out = "out";				// ścieżka zapisu wygenerowanego tekstu
	char *bfile = "base";				// ścieżka do danych przejściowych
	char **in = malloc(sizeof(char*) * 10);		// pliki do odczytu
	char *statout = "stat";

	char *help =	"IllumiGen: POMOC\n"
			"\n"
			"ARGUMENTY WYWOŁANIA PROGRAMU:\n"
			"-n - rząd n-gramow\n"
			"-a - liczba akapitow do generacji\n"
			"-s - liczba słów w akapicie\n"
			"-z - ścieżka zapisu wygenerowanego tekstu\n"
			"-d - ścieżka do zapisu/odczytu danych przejściowych\n"
			"-m - wybór trybu działania programu\n"
			"pliki do odczytu podaje sie bez dodatkowych argumentów, przykladowe pliki znajduja sie w folderze data\n"
			"\n"
			"TRYBY DZIALANIA PROGRAMU:\n"
			"0: tryb domylny - generacja n-gramow na podstawie danych tekstow zrodłowych\n"
			"1: odczyt n-gramow z pliku z danymi przejsciowymi\n"
			"\n"
			"PRZYKŁADOWE WYWOLANIE Z PODANYMI WARTOSCIAMI DOMYSLNYMI I PRZYKŁADOWYMI PLIKAMI:\n"
			"./illumigen data/lifeandadv -n 2 -a 4 -s 25 -z out -d base -m 0\n";

	if (argc == 1) {
		printf ("%s", help);
		return 0;
	}

	while ((opt = getopt (argc, argv, "n:a:s:z:d:m:")) != -1) {
		switch (opt) {
			case 'n':
				n = atoi(optarg);
				break;
			case 'a':
				a = atoi(optarg);
				break;
			case 's':
				s = atoi(optarg);
				break;
			case 'z':
				out = optarg;
				break;
			case 'd':
				bfile = optarg;
				break;
			case 'm':
				mode = atoi(optarg);
				break;
		}
	}

	int i;
	int z = 0;
	int j = 0;
	if (mode == 0) {
		for (i = 1 ; i < argc ; i++) {
			if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "-s") == 0 ||
			    strcmp(argv[i], "-z") == 0 || strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-m") == 0   )
				i++;
			else {
				if ((z = count_words(argv[i])) == -1) {
					printf ("Błąd przy wczytywaniu pliku %s.\n", argv[i]);
				}
				else {
					w += z;
					in[j] = argv[i];
					j++;
				}
			}
		}

		if (j == 0) {
			printf("Błąd, nie podano plików.\n");
			return -1;
		}
		else if (w == 0) {
			printf("Błąd, podane pliki puste.\n");
			return -1;
		}
	}

	i = 0;

	nbase base;
	if (mode == 0) {
		base = base_new(n, w);
		while (in[i] != NULL) {
			analyse(&base, in[i]);
			i++;
		}
	}
	else if (mode == 1)
		base = base_load(bfile);
	else {
		printf ("Error 404: mode not found\n");
		return 404;
	}

	text_gen(&base, a, s, out);
	
	if (mode == 0)
		base_gen(&base, bfile);

	stat_gen(base, statout, w);

	return 0;
}
