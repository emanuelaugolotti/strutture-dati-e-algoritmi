//Time: 14 min
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int GetNumConfronti(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	int ris1 = GetNumConfronti((int)floor(n / 2.0));
	int ris2 = GetNumConfronti((int)ceil(n / 2.0));
	return ris1 + ris2 + n;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	int ris = GetNumConfronti(n);
	printf("%i", ris);
	return 0;
}