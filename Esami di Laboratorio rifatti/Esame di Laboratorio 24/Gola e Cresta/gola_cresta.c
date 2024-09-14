//Time: 23 min
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

bool IsSol(int* curr, size_t n) {
	size_t start = 0, stop = 2;
	while (start < n - 2 && stop < n) {
		if ((curr[start]<curr[start + 1] && curr[start + 1]>curr[stop]) || (curr[start] > curr[start + 1] &&
			curr[start + 1] < curr[stop])) {
			++start;
			++stop;
			continue;
		} else {
			return false;
		}
	}
	return true;
}

void GolaCrestaRec(size_t n, int* curr, size_t i) {
	if (i == n) {
		if (IsSol(curr, n)) {
			StampaSol(curr, n);
		}
		return;
	}
	for (int j = 0; j < 3; ++j) {
		curr[i] = j;
		GolaCrestaRec(n, curr, i + 1);
	}
}

void GolaCresta(size_t n) {
	if (n < 3) {
		return;
	}
	int* curr = malloc(n * sizeof(int));
	GolaCrestaRec(n, curr, 0);
	free(curr);
}