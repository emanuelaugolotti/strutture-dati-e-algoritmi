#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void PrintSol(int* curr, int count) {
	printf("{ ");
	for (int i = 0; i < count; ++i) {
		printf("%i ", curr[i]);
	}
	printf("}, ");
}

void SubsetEqualRec(int n, int s, int* curr, int count, int i, int sum, bool* usati) {
	if (sum == s) {
		PrintSol(curr, count);
		return;
	}
	if (i == n || sum > s) {
		return;
	}
	for (int j = 1; j <= n; ++j) {
		if (i == 0 || (!usati[j - 1] && curr[count - 1] < j)) {
			curr[count] = j;
			usati[j - 1] = true;
			++count;
			sum += j;
			SubsetEqualRec(n, s, curr, count, i + 1, sum, usati);
			--count;
			sum -= j;
			usati[j - 1] = false;
		}
	}
}

void SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0) {
		return;
	}
	int* curr = malloc(n * sizeof(int));
	bool* usati = calloc(n, sizeof(bool));
	SubsetEqualRec(n, s, curr, 0, 0, 0, usati);
	free(curr);
	free(usati);
}