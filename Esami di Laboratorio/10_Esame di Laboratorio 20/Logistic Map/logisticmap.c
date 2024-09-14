#include <stdlib.h>
#include <stdio.h>

double LogisticRec(double x0, double r, int n) {
	if (n == 0) {
		return x0;
	} 
	double xprev = LogisticRec(x0, r, n - 1);
	double xn = r * xprev * (1.0 - xprev);
	return xn;
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		return 1;
	}
	double x0 = strtod(argv[1], NULL);
	double r = strtod(argv[2], NULL);
	int n = strtol(argv[3], NULL, 10);
	if (x0 < 0 || x0 > 1 || r < 0 || n < 0) {
		return 1;
	}
	double ris = LogisticRec(x0, r, n);
	printf("%f", ris);
	return 0;
}