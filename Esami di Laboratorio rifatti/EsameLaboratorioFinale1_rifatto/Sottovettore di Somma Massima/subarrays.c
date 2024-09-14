#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Soluzione {
	int* data;
	size_t count;
	int sum;
} Soluzione;

bool IsSoluzione(int* curr, const int* v, size_t n, size_t count) {
	const int* trovato = NULL;
	for (size_t i = 0; i < n; ++i) {
		if (v[i] == curr[0]) {
			trovato = v + i;
		}
	}
	int ris = memcmp(trovato, curr, count * sizeof(int));
	if (ris == 0) {
		return true;
	}
	return false;
}

void OptimalSubarrayRec(const int* v, size_t n, Soluzione* curr, Soluzione* best, size_t i) {
	if (i == n) {
		if (IsSoluzione(curr->data, v, n, curr->count)) {
			if (best->sum < curr->sum) {
				best->count = curr->count;
				best->sum = curr->sum;
				memcpy(best->data, curr->data, n * sizeof(int));
			}
		}
		return;
	}
	/*if (i == n) {
		if (best->sum < curr->sum) {
			best->count = curr->count;
			best->sum = curr->sum;
			memcpy(best->data, curr->data, n * sizeof(int));
		}
		return;
	}*/
	for (size_t index = i; index < n; ++index) {
		curr->data[curr->count] = v[index];
		curr->sum += v[index];
		++(curr->count);
		OptimalSubarrayRec(v, n, curr, best, i + 1);
		curr->sum -= v[index];
		--(curr->count);
		OptimalSubarrayRec(v, n, curr, best, i + 1);
	}
	/*for (size_t index = i; index < n; ++index) {
		if (curr->count > 1 && curr->data[curr->count - 1] != v[index - 1]) {
			OptimalSubarrayRec(v, n, curr, best, n);
		}
		if (curr->count == 0 || (curr->count > 0 && curr->data[curr->count - 1] == v[index - 1])) {
			curr->data[curr->count] = v[index];
			curr->sum += v[index];
			++(curr->count);
			OptimalSubarrayRec(v, n, curr, best, i + 1);
			curr->sum -= v[index];
			--(curr->count);
		}
	}*/
	OptimalSubarrayRec(v, n, curr, best, n);
}

int OptimalSubarray(const int* v, size_t n) {
	if (v == NULL || n == 0) {
		return 0;
	}
	Soluzione* curr = malloc(sizeof(Soluzione));
	curr->count = 0;
	curr->data = malloc(n * sizeof(int));
	curr->sum = 0;
	Soluzione* best = malloc(sizeof(Soluzione));
	best->count = 0;
	best->data = malloc(n * sizeof(int));
	best->sum = 0;
	OptimalSubarrayRec(v, n, curr, best, 0);
	int max_sum = best->sum;
	free(curr->data);
	free(best->data);
	free(curr);
	free(best);
	return max_sum;
}