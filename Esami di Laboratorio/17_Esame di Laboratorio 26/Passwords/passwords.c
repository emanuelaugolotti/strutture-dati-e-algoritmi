#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void PrintSol(int* curr, int* nsol, int n) {
	printf("%4i) ", *nsol);
	for (int i = 0; i < n; ++i) {
		printf("%i", curr[i]);
	}
	printf("\n");
}

bool ContiguiUguali(int* curr, int count) {
	for (int i = 0; i < count - 1; ++i) {
		if (curr[i] == curr[i + 1]) {
			return true;
		}
	}
	return false;
}

void PasswordsRec(int n, int* curr, int* nsol, int i, int count, int prec) {
	if (i == n) {
		if (count == n) {
			++(*nsol);
			PrintSol(curr, nsol, n);
		}
		return;
	}
	for (int j = prec; j < 10; ++j) {
		bool uguali = ContiguiUguali(curr, count);
		if (uguali || (!uguali && curr[count - 1] == j && i == n - 1) || i == 0 || 
			(!uguali && i != n - 1)) {
			curr[count] = j;
			++count;
			prec = j;
			PasswordsRec(n, curr, nsol, i + 1, count, prec);
			--count;
		}	
	}
}

void Passwords(int n) {
	if (n <= 1) {
		return;
	}
	int* curr = malloc(n * sizeof(int));
	int nsol = 0;
	PasswordsRec(n, curr, &nsol, 0, 0, 0);
	free(curr);
}