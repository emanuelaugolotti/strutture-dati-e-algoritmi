//Time: 7 min
#include <stdlib.h>
#include <stdio.h>

int GetTriangularNumber(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 3;
	}
	int n1 = GetTriangularNumber(n - 1);
	int n2 = GetTriangularNumber(n - 2);
	int n3 = GetTriangularNumber(n - 3);
	int ris = 3 * n1 - 3 * n2 + n3;
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
	int ris = GetTriangularNumber(n);
	printf("%i", ris);
	return 0;
}