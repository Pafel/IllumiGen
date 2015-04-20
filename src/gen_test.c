#include "analyse.h"
#include "gen.h"

int main (int argc, char **argv)
{
	int n = 2;
	nbase base = base_new(n);

	analyse (&base, argv[1]);
	text_gen (&base, 1, 20, argv[2]);

	return 0;
}
