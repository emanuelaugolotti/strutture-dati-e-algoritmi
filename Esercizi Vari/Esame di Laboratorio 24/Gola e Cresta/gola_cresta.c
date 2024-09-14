//Tim: 15 min
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void PrintSolution(int* curr, size_t curr_size) {
	printf("(");
	for (size_t i = 0; i < curr_size; ++i) {
		printf("%i", curr[i]);
		if (i < curr_size - 1) {
			printf(", ");
		}
	}
	printf("), ");
}

bool IsSolution(int* curr, size_t curr_size) {
	size_t start = 0, stop = 2;
	while (stop < curr_size) {
		if ((curr[start]<curr[start + 1] && curr[start + 1]>curr[stop]) ||
			(curr[start] > curr[start + 1] && curr[start + 1] < curr[stop])) {
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
		if (IsSolution(curr, n)) {
			PrintSolution(curr, n);
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