#include <stdlib.h>
#include <stdio.h>

int CalcolaSchroderNumber(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 2;
	}
	int n1 = CalcolaSchroderNumber(n - 1);
	int n2 = CalcolaSchroderNumber(n - 2);
	return ((6 * n - 3) * n1 - (n - 2) * n2) / (n + 1);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	int ris = CalcolaSchroderNumber(n);
	printf("%i", ris);
	return 0;
}