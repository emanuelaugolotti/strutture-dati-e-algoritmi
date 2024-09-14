#include <stdlib.h>
#include <stdio.h>

double CalcolaLogisticMap(int n, double x0, double r) {
	if (n == 0) {
		return x0;
	}
	double x_prev = CalcolaLogisticMap(n - 1, x0, r);
	double xn = r * x_prev * (1 - x_prev);
	return xn;
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		return 1;
	}
	int n = strtol(argv[3], NULL, 10);
	double x0 = strtold(argv[1], NULL);
	double r = strtod(argv[2], NULL);
	if (x0 < 0 || x0 > 1 || r < 0 || n < 0) {
		return 1;
	}
	double ris = CalcolaLogisticMap(n, x0, r);
	printf("%f", ris);
	return 0;
}