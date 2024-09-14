//Time: 58min
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int ProdottoRiga(int* curr, int n, int r) {
	int prodotto = 1;
	for (int c = 0; c < n; ++c) {
		int e = curr[r * n + c];
		prodotto *= e;
	}
	return prodotto;
}

int ProdottoColonna(int* curr, int n, int c) {
	int prodotto = 1;
	for (int r = 0; r < n; ++r) {
		int e = curr[r * n + c];
		prodotto *= e;
	}
	return prodotto;
}

bool IsSol(int* curr, int n) {
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			int prod_riga = ProdottoRiga(curr, n, r);
			int prod_col = ProdottoColonna(curr, n, c);
			if (prod_riga != prod_col) {
				return false;
			}
		}
	}
	return true;
}

void RisolviProdottoRec(int n, const int* s,int* curr, int* sol, bool* usati, bool* esistesol, int n_usati, 
						int i) {
	if (i == n * n) {
		if (IsSol(curr, n) && n_usati == (n * n)) {
			memcpy(sol, curr, n * n * sizeof(int));
			*esistesol = true;
		}
		return;
	}
	for (int j = 0; j < n * n; ++j) {
		if (!usati[j]) {
			curr[i] = s[j];
			usati[j] = true;
			++n_usati;
			RisolviProdottoRec(n, s, curr, sol, usati, esistesol,n_usati, i + 1);
			usati[j] = false;
			--n_usati;
		}
	}
}

int* RisolviProdotto(int n, const int* s) {
	int* curr = malloc(n * n * sizeof(int));
	int* sol = malloc(n * n * sizeof(int));
	bool* usati = calloc(n * n, sizeof(bool));
	bool esistesol = false;
	RisolviProdottoRec(n, s, curr, sol, usati, &esistesol, 0, 0);
	free(usati);
	free(curr);
	if (!esistesol) {
		free(sol);
		return NULL;
	}
	return sol;
}