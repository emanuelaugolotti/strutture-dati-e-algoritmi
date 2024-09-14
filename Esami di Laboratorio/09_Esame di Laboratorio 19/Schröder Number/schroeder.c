//Time: 10min
#include <stdlib.h>
#include <stdio.h>

int SchroderRec(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 2;
	}
	int somma = 0;
	int n1 = SchroderRec(n - 1);
	int n2 = SchroderRec(n - 2);
	somma = ((6 * n - 3) * n1) / (n + 1) - ((n - 2) * n2) / (n + 1);
	return somma;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	int schroder = SchroderRec(n);
	printf("%i", schroder);
	return 0;
}