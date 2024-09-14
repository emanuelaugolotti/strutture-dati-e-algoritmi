//Time: 15 min
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void PrintSolution(int* curr, int curr_size, int* nsol) {
	printf("%4i) ", *nsol);
	for (int i = 0; i < curr_size; ++i) {
		printf("%i", curr[i]);
	}
	printf("\n");
}

bool IsSolution(int* curr, int curr_size) {
	bool consec_uguali = false;
	for (int i = 0; i < curr_size - 1; ++i) {
		int n1 = curr[i];
		int n2 = curr[i + 1];
		if (n1 == n2) {
			consec_uguali = true;
		}
	}
	if (!consec_uguali) {
		return false;
	}
	return true;
}

void PasswordsRec(int n, int* nsol, int* curr, int i) {
	if (i == n) {
		if (IsSolution(curr, n)) {
			++(*nsol);
			PrintSolution(curr, n, nsol);
		}
		return;
	}
	int start = 0;
	if (i > 0) {
		start = curr[i - 1];
	}
	for (int j = start; j < 10; ++j) {
		curr[i] = j;
		PasswordsRec(n, nsol, curr, i + 1);
	}
}

void Passwords(int n) {
	if (n < 2) {
		return;
	}
	int* curr = malloc(n * sizeof(int));
	int nsol = 0;
	PasswordsRec(n, &nsol, curr, 0);
	free(curr);
}