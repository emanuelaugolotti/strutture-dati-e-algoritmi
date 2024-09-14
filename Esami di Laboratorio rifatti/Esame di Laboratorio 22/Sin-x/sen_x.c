//Time: 16 min
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double CalcolaFattoriale(double n) {
	if (n == 1) {
		return 1;
	}
	double fatt = n * CalcolaFattoriale(n - 1);
	return fatt;
}

double CalcolaSen(int i, double n, double x) {
	if ((int)n == i + 1) {
		return 0;
	}
	double addendo = pow(-1., n) / CalcolaFattoriale(2 * n + 1) * pow(x, 2 * n + 1);
	double somma = addendo + CalcolaSen(i, n + 1, x);
	return somma;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		return 1;
	}
	double x = strtod(argv[1], NULL);
	int i = strtol(argv[2], NULL, 10);
	if (i < 0) {
		return 1;
	}
	double ris = CalcolaSen(i, 0., x);
	printf("%f", ris);
	return 0;
}