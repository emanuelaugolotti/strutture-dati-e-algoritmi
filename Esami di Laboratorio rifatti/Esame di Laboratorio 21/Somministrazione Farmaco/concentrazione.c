#include <stdio.h>
#include <stdlib.h>

double CalcolaConcentrazione(int n) {
	if (n == 1) {
		return 0.;
	}
	double c_prev = CalcolaConcentrazione(n - 1);
	double c = 0.3 * c_prev + 0.2;
	return c;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 1) {
		return 1;
	}
	double ris = CalcolaConcentrazione(n);
	printf("%f", ris);
	return 0;
}