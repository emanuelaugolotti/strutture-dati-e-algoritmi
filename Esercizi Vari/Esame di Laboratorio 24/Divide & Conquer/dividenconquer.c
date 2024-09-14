//Time: 11 min
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int DividenConquerRec(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	int ris1 = DividenConquerRec((int)floor((double)n / 2));
	int ris2 = DividenConquerRec((int)ceil((double)n / 2));
	int ristot = ris1 + ris2 + n;
	return ristot;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	int ris = DividenConquerRec(n);
	printf("%i", ris);
	return 0;
}