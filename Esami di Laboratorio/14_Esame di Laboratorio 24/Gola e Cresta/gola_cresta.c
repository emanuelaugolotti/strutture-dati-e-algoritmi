#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void StampaSol(int* curr, size_t n) {
	printf("(");
	for (size_t i = 0; i < n; ++i) {
		printf("%i", curr[i]);
		if (i != n - 1) {
			printf(", ");
		}
	}
	printf("), ");
}

bool Verifica(int* curr, size_t start) {
	if ((curr[start] < curr[start + 1] && curr[start + 1] > curr[start + 2]) ||
		(curr[start] > curr[start + 1] && curr[start + 1] < curr[start + 2])) {
		return true;
	}
	return false;
}

bool Prendo(int* curr, size_t n) {
	size_t start = 0;
	while (n >= 3) {
		bool ris = Verifica(curr, start);
		if (!ris) {
			return false;
		}
		++start;
		--n;
	}
	return true;
}

void GolaCrestaRec(size_t n, int* curr, size_t presi, size_t i) {
	if (i == n) {
		if (presi < n) {
			return;
		}
		if (Prendo(curr, n)) {
			StampaSol(curr, n);
		}
		return;
	}
	for (int e = 0; e < 3; ++e) {
		curr[i] = e;
		++presi;
		GolaCrestaRec(n, curr, presi, i + 1);
		--presi;
	}
}

void GolaCresta(size_t n) {
	if (n < 3) {
		return;
	}
	int* curr = malloc(n * sizeof(int));
	GolaCrestaRec(n, curr, 0, 0);
	free(curr);
}