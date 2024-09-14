#include <stdlib.h>
#include <stdio.h>

double ConcentrazioneRec(int n) {
	if (n == 0) {
		return 0.;
	}
	double cprev = ConcentrazioneRec(n - 1);
	double c = 0.3 * cprev + 0.2;
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
	double c = ConcentrazioneRec(n - 1);
	printf("%f", c);
	return 0;
}