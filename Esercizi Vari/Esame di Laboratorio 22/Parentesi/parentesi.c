//Time: 26 min
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void PrintSolution(char* curr, int curr_size) {
	for (int i = 0; i < curr_size; ++i) {
		printf("%c", curr[i]);
	}
	printf("\n");
}

bool IsSolution(char* curr, int curr_size) {
	int aperte = 0, chiuse = 0;
	for (int i = 0; i < curr_size; ++i) {
		if (curr[i] == '(') {
			++aperte;
		} else {
			++chiuse;
		}
		if (chiuse > aperte) {
			return false;
		}
	}
	if (aperte != chiuse) {
		return false;
	}
	return true;
}

void ParentesiRec(int n, char* curr, int* nsol, int i) {
	if (i == 2 * n) {
		if (IsSolution(curr, n, 2 * n)) {
			++(*nsol);
			PrintSolution(curr, 2 * n);
		}
		return;
	}
	curr[i] = '(';
	ParentesiRec(n, curr, nsol, i + 1);
	curr[i] = ')';
	ParentesiRec(n, curr, nsol, i + 1);
}

int Parentesi(int n) {
	if (n < 0) {
		return -1;
	}
	int nsol = 0;
	char* curr = malloc(2 * n * sizeof(char));
	ParentesiRec(n, curr, &nsol, 0);
	free(curr);
	return nsol;
}