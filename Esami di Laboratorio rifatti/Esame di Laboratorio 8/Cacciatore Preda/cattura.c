#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Soluzione {
	int* s;
	int n;	//numero prede cacciate
} Soluzione;

void PopolaVett(int* v, size_t v_size) {
	for (size_t i = 0; i < v_size; ++i) {
		v[i] = -1;
	}
}

bool PuoCacciare(int pos_cacc, int pos_preda, int u, Soluzione* curr) {
	if ((pos_preda - pos_cacc <= u) && (curr->s[pos_preda] == -1)) {
		return true;
	}
	return false;
}

void CacciatorePredaRec(const char* v, int u, Soluzione* curr, Soluzione* best, int* cacciatori,int n_cacc, 
						int* prede, int n_prede, size_t i, size_t v_size) {
	if (i == (size_t)n_cacc) {
		if (best->n < curr->n) {
			best->n = curr->n;
			memcpy(best->s, curr->s, v_size * sizeof(int));
		}
		return;
	}
	for (int j = 0; j < n_prede; ++j) {
		int pos_cacc = cacciatori[i];
		int pos_preda = prede[j];
		if (PuoCacciare(pos_cacc, pos_preda, u, curr)) {
			curr->s[pos_cacc] = pos_preda;
			curr->s[pos_preda] = -2;
			++(curr->n);
			CacciatorePredaRec(v, u, curr, best, cacciatori, n_cacc, prede, n_prede, i + 1, v_size);
			curr->s[pos_cacc] = -1;
			curr->s[pos_preda] = -1;
			--(curr->n);
		}
	}
	CacciatorePredaRec(v, u, curr, best, cacciatori, n_cacc, prede, n_prede, i + 1, v_size);
}

int* CacciatorePreda(const char* v, size_t v_size, int u) {
	if (v == NULL || v_size == 0 || u == 0) {
		return NULL;
	}
	int n_cacc = 0, n_prede = 0;
	int* cacciatori = malloc(v_size * sizeof(int));
	int* prede = malloc(v_size * sizeof(int));
	for (size_t i = 0; i < v_size; ++i) {
		if (v[i] == 'P' || v[i] == 'p') {
			prede[n_prede] = i;
			++n_prede;
		} else {
			cacciatori[n_cacc] = i;
			++n_cacc;
		}
	}
	Soluzione curr, best;
	curr.n = 0;
	curr.s = malloc(v_size * sizeof(int));
	PopolaVett(curr.s, v_size);
	best.n = 0;
	best.s = malloc(v_size * sizeof(int));
	PopolaVett(best.s, v_size);
	CacciatorePredaRec(v, u, &curr, &best, cacciatori, n_cacc, prede, n_prede, 0, v_size);
	free(curr.s);
	free(cacciatori);
	free(prede);
	return best.s;
}