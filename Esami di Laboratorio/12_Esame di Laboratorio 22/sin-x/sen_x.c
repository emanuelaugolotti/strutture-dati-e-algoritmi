#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double FattorialeRec(double n) {
	if (n == 1) {
		return 1;
	}
	double ris = n * FattorialeRec(n - 1);
	return ris;
}

double CalcolaSenoRec(double i, double x, double n) {
	if (n == i + 1) {
		return 0;
	}
	double fatt = FattorialeRec(2 * n + 1);
	double termine_i = pow(-1, n) * pow(x, 2 * n + 1) / fatt;
	double somma = termine_i + CalcolaSenoRec(i, x, n + 1);
	return somma;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		return 1;
	}
	double x = strtold(argv[1], NULL);
	double i = strtold(argv[2], NULL);
	if (i < 0) {
		return 1;
	}
	double ris = CalcolaSenoRec(i, x, 0);
	printf("%f", ris);
	return 0;
}