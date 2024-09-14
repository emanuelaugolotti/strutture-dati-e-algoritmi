//Time: 9 min
#include <stdlib.h>
#include <stdio.h>

int TriangularRec(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 3;
	}
	int s = 3 * TriangularRec(n - 1) - 3 * TriangularRec(n - 2) + TriangularRec(n - 3);
	return s;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	int s = TriangularRec(n);
	printf("%i", s);
	return 0;
}