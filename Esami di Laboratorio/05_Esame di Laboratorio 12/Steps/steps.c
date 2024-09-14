#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void PrintSolution(int* v, int n, int v_size) {
	int count = 0;
	printf("[");
	for (int i = 0; i < n; ++i) {
		if (v[i] != 0) {
			printf("%d", v[i]);
			++count;
			if (count < v_size) {
				printf(", ");
			}
		}
	}
	printf("], ");
}

static void StepsRec(int n, int* nsol, int gradinirimasti, int i, int* curr, int curr_size) {
	if (i == n && gradinirimasti > 0) {
		return;
	}
	
	if (i == n && gradinirimasti == 0) {
		PrintSolution(curr, n, curr_size);
		++(*nsol);
		return;
	}

	for (int j = 1; j <= 3; ++j) {
		if (gradinirimasti < j) {
			StepsRec(n, nsol, gradinirimasti, n, curr, curr_size);
		}
		if (gradinirimasti >= j) {
			curr[i] = j;
			gradinirimasti -= j;
			++curr_size;
			if (gradinirimasti == 0) {
				StepsRec(n, nsol, gradinirimasti, n, curr, curr_size);
			} else {
				StepsRec(n, nsol, gradinirimasti, i + 1, curr, curr_size);
			}
			//Rollback
			curr[i] = 0;
			gradinirimasti += j;
			--curr_size;
		}
	}
}

int Steps(int n) {
	int nsol = 0;
	
	if (n <= 0) {
		return nsol;
	}

	int* curr = calloc(n, sizeof(int));
	StepsRec(n, &nsol, n, 0, curr, 0);
	free(curr);
	return nsol;
}