#include <stdlib.h>

void TrasportaPersone(const int* t, int* rimaste, int start) {
	int capienza_treno = t[start];
	int persone_disponibili_perpartire = rimaste[start];
	if (persone_disponibili_perpartire == 0) {
		return;
	}
	if (capienza_treno >= persone_disponibili_perpartire) {
		rimaste[start] = 0;
		rimaste[start + 1] += persone_disponibili_perpartire;
	} else {
		int rimanenza = persone_disponibili_perpartire - capienza_treno;
		rimaste[start + 1] += capienza_treno;
		rimaste[start] = rimanenza;
	}
}

int TempoTrasporto(int n, const int* t, int p) {
	int* rimaste = calloc(n, sizeof(int));
	rimaste[0] = p;
	int minuto = 0;
	int stop = 0;
	while (rimaste[n - 1] < p) {
		for (int i = stop; i >= 0; --i) {
			TrasportaPersone(t, rimaste, i);
		}
		++minuto;
		if (rimaste[n - 2] > 0) {
			stop = n - 2;
		} else {
			++stop;
		}
	}
	free(rimaste);
	return minuto;
}