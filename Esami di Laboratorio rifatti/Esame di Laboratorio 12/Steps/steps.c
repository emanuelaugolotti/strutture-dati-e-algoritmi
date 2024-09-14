#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void PrintSolution(int* curr, int count) {
	printf("[");
	for (int i = 0; i < count; ++i) {
		printf("%i", curr[i]);
		if (i != count - 1) {
			printf(", ");
		}
	}
	printf("], ");
}

bool IsSolution(int* curr, int count, int n) {
	int somma = 0;
	for (int i = 0; i < count; ++i) {
		somma += curr[i];
	}
	if (somma == n) {
		return true;
	}
	return false;
}

void StepsRec(int n, int* curr, int count, int* nsol, int i) {
	if (i == n) {
		if (IsSolution(curr, count, n)) {
			PrintSolution(curr, count);
			++(*nsol);

		}
		return;
	}
	for (int j = 1; j <= 3; ++j) {
		curr[count] = j;
		++count;
		StepsRec(n, curr, count, nsol, i + 1);
		--count;
	}
	StepsRec(n, curr, count, nsol, n);
}

int Steps(int n) {
	if (n <= 0) {
		return 0;
	}
	int nsol = 0;
	int* curr = malloc(n * sizeof(int));
	StepsRec(n, curr, 0, &nsol, 0);
	free(curr);
	return nsol;
}