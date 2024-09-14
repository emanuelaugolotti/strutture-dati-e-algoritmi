#include <stdlib.h>
#include <string.h>

struct Soluzione {
	int* data;
	int sum;
	size_t count;
};
typedef struct Soluzione Soluzione;

void OptimalSubarrayRec(const int* v, size_t n, Soluzione* best, Soluzione* curr, size_t i) {
	if (i == n) {
		if (best->sum < curr->sum) {
			best->count = curr->count;
			best->sum = curr->sum;
			memcpy(best->data, curr->data, n * sizeof(int));
		}
		return;
	}
	for (size_t j = i; j < n; ++j) {
		if (i == 0 || (i > 0 && curr->data[curr->count - 1] == v[i - 1])) {
			curr->data[curr->count] = v[j];
			++(curr->count);
			curr->sum += v[j];
			OptimalSubarrayRec(v, n, best, curr, i + 1);
			--(curr->count);
			curr->sum -= v[j];
		}
		OptimalSubarrayRec(v, n, best, curr, i + 1);
	}
}

int OptimalSubarray(const int* v, size_t n) {
	if (n == 0) {
		return 0;
	}
	Soluzione* curr = malloc(sizeof(Soluzione));
	curr->sum = 0;
	curr->count = 0;
	curr->data = malloc(n * sizeof(int));
	Soluzione* best = malloc(sizeof(Soluzione));
	best->sum = 0;
	best->count = 0;
	best->data = malloc(n * sizeof(int));
	OptimalSubarrayRec(v, n, best, curr, 0);
	int max_sum = best->sum;
	free(curr->data);
	free(curr);
	free(best->data);
	free(best);
	return max_sum;
}