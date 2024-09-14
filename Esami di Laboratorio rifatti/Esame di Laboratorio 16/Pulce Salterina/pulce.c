#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Spostamenti {
	char* sequenza;
	size_t size;
} Spostamenti;

bool IsProibita(const int* f, size_t f_size, int pos) {
	for (size_t i = 0; i < f_size; ++i) {
		if (pos == f[i]) {
			return true;
		}
	}
	return false;
}

bool IsSolution(const int* f, size_t f_size, int a, int b, int h, Spostamenti curr) {
	int poscurr = 0;
	for (size_t i = 0; i < curr.size; ++i) {
		if (curr.sequenza[i] == 'a') {
			poscurr += a;
		} else {
			poscurr -= b;
		}
		if (poscurr < 0 || IsProibita(f, f_size, poscurr)) {
			return false;
		}
	}
	if (poscurr == h) {
		return true;
	}
	return false;
}

void GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, size_t i, Spostamenti curr, 
					Spostamenti* best) {
	if (i == (size_t)n) {
		if (IsSolution(f, f_size, a, b, h, curr)) {
			if (curr.size < best->size) {
				best->size = curr.size;
				memcpy(best->sequenza, curr.sequenza, n * sizeof(char));
			}
		}
		return;
	}
	for (char c = 'a'; c <= 'b'; ++c) {
		curr.sequenza[curr.size] = c;
		++curr.size;
		GuidaLaPulceRec(f, f_size, a, b, n, h, i + 1, curr, best);
		--curr.size;
	}
	GuidaLaPulceRec(f, f_size, a, b, n, h, n, curr, best);
}

char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size) {
	if (ret_size != NULL) {
		*ret_size = 0;
	}
	if (f == NULL || ret_size == NULL || n < 0) {
		return NULL;
	}
	Spostamenti curr;
	curr.size = 0;
	curr.sequenza = malloc(n * sizeof(char));
	Spostamenti* best = malloc(sizeof(Spostamenti));
	best->size = n + 1;
	best->sequenza = malloc(n * sizeof(char));
	GuidaLaPulceRec(f, f_size, a, b, n, h, 0, curr, best);
	char* out = NULL;
	if ((int)best->size != n + 1) {
		*ret_size = best->size;
		out = malloc(*ret_size * sizeof(char));
		memcpy(out, best->sequenza, best->size * sizeof(char));
	}
	free(curr.sequenza);
	free(best->sequenza);
	free(best);
	return out;
}