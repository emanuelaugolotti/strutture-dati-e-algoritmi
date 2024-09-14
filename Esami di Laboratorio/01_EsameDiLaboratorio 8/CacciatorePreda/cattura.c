#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int n;	//numero prede cacciate
	int* s;	//vettore
	bool* prede_usate;
} Cattura;

void Azzera(int* v, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		v[i] = -1;
	}
}

static void CacciatorePredaRec(const char* v, size_t v_size, int u, Cattura* best, Cattura* curr, 
	int n_cacciatori, int n_prede, int* v_prede, int* v_cacciatori, int i) {

	if (curr->n > best->n) {
		best->n = curr->n;
		memcpy(best->s, curr->s, v_size * sizeof(int));
		memcpy(best->prede_usate, curr->prede_usate, v_size * sizeof(bool));
	}
	
	//Caso base
	if (i  >= n_cacciatori) {
		return;
	}

	for (int p = 0; p < n_prede; ++p) {	// scorro le prede
		int pospreda = v_prede[p];
		int poscacciatore = v_cacciatori[i];
		int d = abs(poscacciatore - pospreda);

		if (!(curr->prede_usate)[p] && d <= u) {
			(curr->prede_usate)[p] = true;
			(curr->s)[pospreda] = -2;
			(curr->s)[poscacciatore] = pospreda;
			++(curr->n);
			CacciatorePredaRec(v, v_size, u, best, curr, n_cacciatori, n_prede, v_prede, v_cacciatori, i + 1);
			
			//Rollback
			(curr->prede_usate)[p] = false;
			(curr->s)[pospreda] = -1;
			(curr->s)[poscacciatore] = -1;
			--(curr->n);
		}
	}
	
	CacciatorePredaRec(v, v_size, u, best, curr, n_cacciatori, n_prede, v_prede, v_cacciatori, i + 1);
}

int* CacciatorePreda(const char* v, size_t v_size, int u) {
	if (v == NULL) {
		return NULL;
	}

	int n_cacciatori = 0;
	int n_prede = 0;
	int* v_prede = malloc(v_size * sizeof(int));
	int* v_cacciatori = malloc(v_size * sizeof(int));
	for (size_t i = 0; i < v_size; ++i) {
		if (v[i] == 'C' || v[i] == 'c') {
			v_cacciatori[n_cacciatori] = (int)i;
			++n_cacciatori;
		} else {
			v_prede[n_prede] = (int)i;
			++n_prede;
		}
	}

	int* vbest = malloc(v_size * sizeof(int));
	Azzera(vbest, v_size);
	bool* predeusate_best = calloc(v_size, sizeof(bool));
	Cattura best = { 0, vbest, predeusate_best };

	int* vcurr = malloc(v_size * sizeof(int));
	Azzera(vcurr, v_size);
	bool* predeusate_curr = calloc(v_size, sizeof(bool));
	Cattura curr = { 0, vcurr, predeusate_curr };

	CacciatorePredaRec(v, v_size, u, &best, &curr, n_cacciatori, n_prede, v_prede, v_cacciatori, 0);
	
	//Libero la memoria
	free(curr.s);
	free(curr.prede_usate);
	free(best.prede_usate);
	free(v_prede);
	free(v_cacciatori);

	return best.s;
}