#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double GetPi(double n) {
	if (n == 0.) {
		return 4.;
	}
	double prev = GetPi(n - 1);
	double ris = prev + (4. * pow(-1., n)) / (2. * n + 1.);
	return ris;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	double ris = GetPi((double)n);
	printf("%f", ris);
	return 0;
}