#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool IsPrime(int n, int i) {
	if (i == 1 && n != 1) {
		return true;
	}
	if (i == 1 && n == 1) {
		return false;
	}
	if (i != n && n % i == 0) {
		return false;
	}
	return IsPrime(n, i - 1);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	bool ris = IsPrime(n, n);
	if (ris) {
		printf("true");
	} else {
		printf("false");
	}
	return 0;
}