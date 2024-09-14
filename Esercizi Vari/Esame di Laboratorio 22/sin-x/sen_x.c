//Time: 15 min
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double GetFattoriale(double n) {
	if (n == 1) {
		return 1;
	}
	double ris1 = GetFattoriale(n - 1);
	double ris2 = ris1 * n;
	return ris2;
}

double GetSin(double x, double i) {
	if (i == 0) {
		return x;
	}
	double fatt = GetFattoriale(2 * i + 1);
	double ris1 = pow(-1.0, i) / fatt * pow(x, 2 * i + 1);
	double ris2 = GetSin(x, i - 1);
	double somma = ris1 + ris2;
	return somma;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		return 1;
	}
	double x = strtod(argv[1], NULL);
	double i = strtod(argv[2], NULL);
	if (i < 0) {
		return 1;
	}
	double ris = GetSin(x, i);
	printf("%f", ris);
	return 0;
}