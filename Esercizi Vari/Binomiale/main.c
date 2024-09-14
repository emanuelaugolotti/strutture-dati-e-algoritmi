#include <stdio.h>

extern double Binomiale(unsigned int n, unsigned int k);

int main(void) {
	double ris;
	ris = Binomiale(0, 1);
	printf("%f\n", ris);
	ris = Binomiale(1, 1);
	printf("%f\n", ris);
	ris = Binomiale(5, 1);
	printf("%f\n", ris);
	ris = Binomiale(10, 4);
	printf("%f\n", ris);
	ris = Binomiale(10, 5);
	printf("%f\n", ris);
	ris = Binomiale(10, 6);
	printf("%f\n", ris);
	return 0;
}