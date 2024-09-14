//Time: 18min
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int SommaCifre(int n) {
	int somma = 0;
	while (n > 0) {
		somma += n % 10;
		n /= 10;
	}
	return somma;
}

void RadiceNumericaRec(int n) {
	if (n >= 0 && n < 10) {
		printf("%i", n);
		return;
	}
	int somma = SommaCifre(n);
	RadiceNumericaRec(somma);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	RadiceNumericaRec(n);
	return 0;
}