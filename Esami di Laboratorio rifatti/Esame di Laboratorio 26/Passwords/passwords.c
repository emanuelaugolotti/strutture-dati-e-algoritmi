//Time: 10 min
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void StampaSol(int* curr, int curr_size, int nsol) {
	printf("%4i) ", nsol);
	for (int i = 0; i < curr_size; ++i) {
		printf("%i", curr[i]);
	}
	printf("\n");
}

bool EsistonoUgualiContigui(int* curr, int curr_size) {
	for (int i = 0; i < curr_size - 1; ++i) {
		if (curr[i] == curr[i + 1]) {
			return true;
		}
	}
	return false;
}

void PasswordsRec(int n, int* curr, int i, int* nsol) {
	if (i == n) {
		if (EsistonoUgualiContigui(curr, n)) {
			++(*nsol);
			StampaSol(curr, n, *nsol);
		}
		return;
	}
	int start = 0;
	if (i > 0) {
		start = curr[i - 1];
	}
	for (int j = start; j < 10; ++j) {
		curr[i] = j;
		PasswordsRec(n, curr, i + 1, nsol);
	}
}

void Passwords(int n) {
	if (n <= 1) {
		return;
	}
	int* curr = malloc(n * sizeof(int));
	int nsol = 0;
	PasswordsRec(n, curr, 0, &nsol);
	free(curr);
}