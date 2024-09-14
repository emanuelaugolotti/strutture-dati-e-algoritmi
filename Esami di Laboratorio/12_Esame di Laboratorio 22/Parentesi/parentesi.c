#include <stdlib.h>
#include <stdio.h>

void PrintSol(int* curr, int size) {
	for (int i = 0; i < size; ++i) {
		if (curr[i] == 1) {
			printf("(");
		} else {
			printf(")");
		}
	}
	printf("\n");
}

void ParentesiRec(int n, int* curr, int* usati, int* nsol, int i) {
	if (i == 2 * n) {
		if ((usati[0] == n) && (usati[1] == n)) {
			PrintSol(curr, 2 * n);
			++(*nsol);
		}
		return;
	}
	if ((usati[0] < n && usati[1] == 0) || (usati[1] > 0 && usati[1] < n)) {
		curr[i] = 1;	//parentesi aperta
		usati[0] += 1;
		ParentesiRec(n, curr, usati, nsol, i + 1);
		usati[0] -= 1;
	}
	if (usati[0] > 0 && usati[1] < n && usati[0] != usati[1]) {
		curr[i] = -1;	//parentesi chiusa
		usati[1] += 1;
		ParentesiRec(n, curr, usati, nsol, i + 1);
		usati[1] -= 1;
	}
}

int Parentesi(int n) {
	if (n < 0) {
		return -1;
	}
	if (n == 0) {
		return 0;
	}
	int* curr = calloc(n * 2, sizeof(int));
	int* usati = calloc(2, sizeof(int));
	int nsol = 0;
	ParentesiRec(n, curr, usati, &nsol, 0);
	free(curr);
	free(usati);
	return nsol;
}