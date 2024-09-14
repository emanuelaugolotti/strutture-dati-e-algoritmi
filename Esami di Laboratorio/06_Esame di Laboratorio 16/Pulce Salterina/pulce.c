//Time: 1h 11min
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Soluzione {
	char* sequenza;
	size_t size;
	int num_mosse;
};
typedef struct Soluzione Soluzione;

bool IsProibita(const int* f, size_t f_size, int pos) {
	for (size_t i = 0; i < f_size; ++i) {
		if (pos == f[i]) {
			return true;
		}
	}
	return false;
}

void GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, Soluzione* best, Soluzione curr,
	int pos_corrente, int i) {
	if (pos_corrente == h) {	//Nido raggiunto
		if (curr.num_mosse < best->num_mosse) {
			best->size = curr.size;
			best->num_mosse = curr.num_mosse;
			memcpy(best->sequenza, curr.sequenza, n * sizeof(char));
		}
		return;
	}
	if (i == n) {	//Nido non raggiunto
		return;
	}

	//Mossa a
	int new_pos = pos_corrente + a;
	if (new_pos >= 0 && !IsProibita(f, f_size, new_pos)) {
		curr.sequenza[curr.num_mosse] = 'a';
		++(curr.num_mosse);
		++(curr.size);
		GuidaLaPulceRec(f, f_size, a, b, n, h, best, curr, new_pos, i + 1);
		--(curr.num_mosse);
		--(curr.size);
	}

	//Mossa b
	new_pos = pos_corrente - b;
	if (new_pos >= 0 && !IsProibita(f, f_size, new_pos) && 
		curr.num_mosse > 0 && curr.sequenza[curr.num_mosse - 1] != b) {
		curr.sequenza[curr.num_mosse] = 'b';
		++(curr.num_mosse);
		++(curr.size);
		GuidaLaPulceRec(f, f_size, a, b, n, h, best, curr, new_pos, i + 1);
	}
}

char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size) {
	*ret_size = 0;
	if (f == NULL || (a == 0 && b == 0) || n == 0) {
		return NULL;
	}
	Soluzione best;
	best.num_mosse = INT_MAX;
	best.size = 0;
	best.sequenza = calloc(n, sizeof(char));
	Soluzione curr;
	curr.num_mosse = 0;
	curr.size = 0;
	curr.sequenza = calloc(n, sizeof(char));
	GuidaLaPulceRec(f, f_size, a, b, n, h, &best, curr, 0, 0);
	free(curr.sequenza);
	*ret_size = best.size;
	return best.sequenza;
}