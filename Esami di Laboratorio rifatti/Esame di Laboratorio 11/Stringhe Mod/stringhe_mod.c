#include <stdio.h>
#include <stdlib.h>

void PrintSolution(char* curr, int k) {
	printf("{");
	for (int i = 0; i < k; ++i) {
		printf("%c", curr[i]);
	}
	printf("}, ");
}

void BacktrackStrModRec(int n, int k, char* curr, int count, int i) {
	if (i == k) {
		if (count == k) {
			PrintSolution(curr, k);
		}
		return;
	}
	for (char c = 'a'; c < 'a' + n; ++c) {
		curr[i] = c;
		++count;
		BacktrackStrModRec(n, k, curr, count, i + 1);
		--count;
	}
}

void BacktrackStrMod(int n, int k) {
	if (n <= 0 || n > 26 || k <= 0) {
		return;
	}
	char* curr = malloc(k * sizeof(char));
	BacktrackStrModRec(n, k, curr, 0, 0);
	free(curr);
}