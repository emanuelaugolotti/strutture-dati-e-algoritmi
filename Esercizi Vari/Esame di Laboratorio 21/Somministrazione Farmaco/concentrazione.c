//Time: 13 min
#include <stdio.h>
#include <stdlib.h>

double GetConcentrazioneFarmaco(int n) {
	if (n == 0) {
		return 0.;
	}
	if (n == 1) {
		return 0.2;
	}
	double c_prev = GetConcentrazioneFarmaco(n - 1);
	double c_succ = 0.3 * c_prev + 0.2;
	return c_succ;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 1) {
		return 1;
	}
	double ris = GetConcentrazioneFarmaco(n - 1);
	printf("%f", ris);
	return 0;
}