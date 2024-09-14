//Time: 12min
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void IsPrimeRec(int n, int count) {
	if (count == 1) {
		printf("true");
		return;
	}
	if (count != n && n % count == 0) {
		printf("false");
		return;
	}
	IsPrimeRec(n, count - 1);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	if (n == 1) {
		printf("false");
		return 0;
	}
	IsPrimeRec(n, n);
	return 0;
}