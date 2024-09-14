#include <stdio.h>
#include <stdlib.h>

void PrintString(char* str, int k) {
	printf("{");
	for (int i = 0; i <= k; ++i) {
		printf("%c", str[i]);
	}
	printf("}, ");
}

void BacktrackStrModRec(int n, int k, char* curr, int i) {
	if (i == k) {
		PrintString(curr, k);
		return;
	}

	for (char j = 'a'; j < 'a' + n; ++j) {
		curr[i] = j;
		BacktrackStrModRec(n, k, curr, i + 1);
	}
}

void BacktrackStrMod(int n, int k) {
	if (n <= 0 || n > 26 || k <= 0) {
		return;
	}

	char* curr = calloc(k + 1, sizeof(char));
	BacktrackStrModRec(n, k, curr, 0);
	free(curr);
	return;
}