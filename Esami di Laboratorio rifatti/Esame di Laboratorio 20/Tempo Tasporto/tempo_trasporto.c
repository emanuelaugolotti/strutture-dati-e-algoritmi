#include <stdlib.h>

void Trasporta(const int* t, int pos, int* r) {
	if (r[pos] > 0) {
		if (r[pos] <= t[pos]) {
			int datrasportare = r[pos];
			r[pos] = 0;
			r[pos + 1] += datrasportare;
		} else {
			r[pos + 1] += t[pos];
			int rimanenti = r[pos] - t[pos];
			r[pos] = rimanenti;
		}
	}
}

void PopolaRimanenti(const int* t, int poscurr, int* r) {
	Trasporta(t, poscurr, r);
	for (int i = poscurr -1 ; i >= 0; --i) {
		Trasporta(t, i, r);
	}
}

int TempoTrasporto(int n, const int* t, int p) {
	int minuti = 0;
	int* r = calloc(n, sizeof(int));
	r[0] = p;
	int poscurr = 0;
	while (r[n - 1] != p) {
		PopolaRimanenti(t, poscurr, r);
		++minuti;
		if (poscurr < n - 2) {
			++poscurr;
		}
	}
	free(r);
	return minuti;
}