//Time: 18 min
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void StampaSol(char* curr, int curr_size) {
	for (int i = 0; i < curr_size; ++i) {
		printf("%c", curr[i]);
	}
	printf("\n");
}

bool IsSoluzione(char* curr, int curr_size) {
	int aperte = 0;
	int chiuse = 0;
	for (int i = 0; i < curr_size; ++i) {
		if (i == 0 && curr[i] == ')') {
			return false;
		}
		if (curr[i] == '(') {
			++aperte;
		} else {
			++chiuse;
		}
		if (chiuse > aperte) {
			return false;
		}
	}
	if (aperte == chiuse) {
		return true;
	}
	return false;
}

void ParentesiRec(int n, char* curr, int* nsol, int i) {
	if(i == 2 * n) {
		if (IsSoluzione(curr, 2 * n)) {
			StampaSol(curr, 2 * n);
			++(*nsol);
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
	char* curr = calloc(2 * n, sizeof(char));
	ParentesiRec(n, curr, &nsol, 0);
	free(curr);
	return nsol;
}