#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void StampaSol(int* curr, int curr_size) {
	for (int i = 0; i < curr_size; ++i) {
		printf("%i ", curr[i]);
	}
	printf("\n");
}

bool IsSolution(int* curr, const char* r, int count, int n) {
	if (count != (n + 1)) {
		return false;
	}
	for (int i = 0; i < n; ++i) {
		if (r[i] == 'd' || r[i] == 'D') {
			if (curr[i + 1] >= curr[i]) {
				return false;
			}
		} else {
			if (curr[i + 1] <= curr[i]) {
				return false;
			}
		}
	}
	return true;
}

void RegoleRec(const char* r, int n, int i, int* curr, bool* usati, int count) {
	if (i == n + 1) {
		if (IsSolution(curr, r, count, n)) {
			StampaSol(curr, n + 1);
		}
		return;
	}
	for (int j = 1; j <= n + 1; ++j) {
		if (!usati[j - 1]) {
			curr[i] = j;
			usati[j - 1] = true;
			++count;
			RegoleRec(r, n, i + 1, curr, usati, count);
			usati[j - 1] = false;
			--count;
		}
	}
}

void Regole(const char* r) {
	if (r == NULL) {
		return;
	}
	int n = (int)strlen(r);
	int* curr = malloc((n + 1) * sizeof(int));
	bool* usati = calloc(n + 1, sizeof(bool));
	RegoleRec(r, n, 0, curr, usati, 0);
	free(curr);
	free(usati);
}