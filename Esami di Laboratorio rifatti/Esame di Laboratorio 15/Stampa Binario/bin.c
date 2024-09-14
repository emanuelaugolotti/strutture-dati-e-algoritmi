#include <stdlib.h>
#include <stdio.h>

void StampaBinario(int n) {
	int q = n / 2;
	int r = n % 2;
	if (q == 0) {
		printf("%i", r);
		return;
	}
	StampaBinario(q);
	printf("%i", r);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	StampaBinario(n);
	return 0;
}