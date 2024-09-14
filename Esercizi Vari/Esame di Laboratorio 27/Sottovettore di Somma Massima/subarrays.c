//Time: 29 min
#include <stdlib.h>
#include <stdbool.h>

bool IsSolution(size_t* curr, size_t curr_size) {
	for (size_t i = 0; i < curr_size - 1; ++i) {
		if (curr[i + 1] == curr[i] + 1) {
			continue;
		} else {
			return false;
		}
	}
	return true;
}

int GetSum(const int* v, size_t* curr, size_t curr_size) {
	int sum = 0;
	for (size_t i = 0; i < curr_size; ++i) {
		size_t pos = curr[i];
		int val = v[pos];
		sum += val;
	}
	return sum;
}

void OptimalSubarrayRec(const int* v, size_t n, size_t* curr, bool* usati, int* sum_best, size_t i, 
						size_t curr_size) {
	if (i == n) {
		if (IsSolution(curr, curr_size)) {
			int sum_curr = GetSum(v, curr, curr_size);
			if (sum_curr > *sum_best) {
				*sum_best = sum_curr;
			}
		}
		return;
	}
	size_t start = 0;
	if (i > 0) {
		start = curr[i - 1] + 1;
	}
	for (size_t j = start; j < n; ++j) {
		if (!usati[j]) {
			curr[curr_size] = j;
			usati[j] = true;
			++curr_size;
			OptimalSubarrayRec(v, n, curr, usati, sum_best, i + 1, curr_size);
			--curr_size;
			usati[j] = false;
		}
	}
	OptimalSubarrayRec(v, n, curr, usati, sum_best, n, curr_size);
}

int OptimalSubarray(const int* v, size_t n) {
	if (v == NULL || n == 0) {
		return 0;
	}
	int sum_best = 0;
	size_t* curr = malloc(n * sizeof(size_t));
	bool* usati = calloc(n, sizeof(bool));
	OptimalSubarrayRec(v, n, curr, usati, &sum_best, 0, 0);
	free(usati);
	free(curr);
	return sum_best;
}