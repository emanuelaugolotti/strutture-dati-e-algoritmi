#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool ProdottoAllineati(int* curr, int n, int r, int c) {
	int priga = 1;
	int pcol = 1;
	for (int col = 0; col < n; ++col) {
		priga *= curr[r * n + col];
	}
	for (int rig = 0; rig < n; ++rig) {
		pcol *= curr[rig * n + c];
	}
	if (priga == pcol) {
		return true;
	}
	return false;
}

bool IsSol(int* curr, int n) {
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			if (!ProdottoAllineati(curr, n, r, c)) {
				return false;
			}
		}
	}
	return true;
}

void RisolviProdottoRec(int n, const int* s, int* curr, bool* usati, int i, int* sequenzasol, bool* esistesol) {
	if (*esistesol) {
		return;
	}
	if (i == n * n) {
		if (IsSol(curr, n)) {
			*esistesol = true;
			memcpy(sequenzasol, curr, n * n * sizeof(int));
		}
		return;
	}
	for (int j = 0; j < n * n; ++j) {
		if (!usati[j]) {
			curr[i] = s[j];
			usati[j] = true;
			RisolviProdottoRec(n, s, curr, usati, i + 1, sequenzasol, esistesol);
			usati[j] = false;
		}
	}
}

int* RisolviProdotto(int n, const int* s) {
	int* curr = malloc(n * n * sizeof(int));
	int* sequenzasol = malloc(n * n * sizeof(int));
	bool* usati = calloc(n * n, sizeof(bool));
	bool esiste_sol = false;
	RisolviProdottoRec(n, s, curr, usati, 0, sequenzasol, &esiste_sol);
	free(usati);
	free(curr);
	if (!esiste_sol) {
		free(sequenzasol);
		return NULL;
	}
	return sequenzasol;
}