//Time: 10 min
#include <stdlib.h>
#include <stdio.h>

int NumeroTriangolareRec(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 3;
	}
	int next = 3 * NumeroTriangolareRec(n - 1) - 3 * NumeroTriangolareRec(n - 2) + NumeroTriangolareRec(n - 3);
	return next;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	int ris = NumeroTriangolareRec(n);
	printf("%i", ris);
	return 0;
}