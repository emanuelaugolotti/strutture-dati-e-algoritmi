#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int CalcolaSomma(int n) {
	int somma = 0;
	while (n != 0) {
		int r = n % 10;
		somma += (r * r);
		n /= 10;
	}
	return somma;
}

void IsFelice(int n, bool* ris) {
	if (n == 1) {
		*ris = true;
		return;
	}
	if (n == 0) {
		*ris = false;
		return;
	}
	if (n == 4) {
		*ris = false;
		return;
	}
	int somma = CalcolaSomma(n);
	IsFelice(somma, ris);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	bool ris = false;
	IsFelice(n, &ris);
	if (ris) {
		printf("Felice");
	}
	else {
		printf("Infelice");
	}
	return 0;
}