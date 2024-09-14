#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int ProdottoRiga(int r, int n, int* curr) {
	int p = 1;
	for (int c = 0; c < n; ++c) {
		int val = curr[r * n + c];
		p *= val;
	}
	return p;
}

int ProdottoColonna(int c, int n, int* curr) {
	int p = 1;
	for (int r = 0; r < n; ++r) {
		int val = curr[r * n + c];
		p *= val;
	}
	return p;
}

bool IsSolution(int* curr, int n) {
	int p;
	bool done = false;
	for (int r = 0; r < n; ++r) {
		int p_curr = ProdottoRiga(r, n, curr);
		if (!done) {
			p = p_curr;
			done = true;
		}
		if (p != p_curr) {
			return false;
		}
	}
	for (int c = 0; c < n; ++c) {
		int p_curr = ProdottoColonna(c, n, curr);
		if (p != p_curr) {
			return false;
		}
	}
	return true;
}

void RisolviProdottoRec(int n, const int* s, int* curr, int* best, bool* usati, bool* done, int i) {
	if (i == n * n) {
		if (!*done && IsSolution(curr, n)) {
			memcpy(best, curr, n * n * sizeof(int));
			*done = true;
		}
		return;
	}
	for (int j = 0; j < n * n; ++j) {
		if (!usati[j]) {
			curr[i] = s[j];
			usati[j] = true;
			RisolviProdottoRec(n, s, curr, best, usati, done, i + 1);
			usati[j] = false;
		}
	}
}

int* RisolviProdotto(int n, const int* s) {
	int* curr = malloc(n * n * sizeof(int));
	int* best = malloc(n * n * sizeof(int));
	bool* usati = calloc(n * n, sizeof(bool));
	bool done = false;
	RisolviProdottoRec(n, s, curr, best, usati, &done, 0);
	free(curr);
	free(usati);
	if (!done) {
		free(best);
		return NULL;
	}
	return best;
}