//Time: 40 min
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool IsSolution(const int* v, size_t n, int* curr, size_t currsize) {
	int dacercare = curr[0];
	size_t pos;
	bool trovato = false;
	for (size_t i = 0; i < n; ++i) {
		if (v[i] == dacercare) {
			trovato = true;
			pos = i;
			break;
		}
	}
	if (!trovato) {
		return false;
	}
	if (memcmp(curr, v + pos, currsize * sizeof(int)) == 0) {
		return true;
	}
	return false;
}

int GetSum(int* v, size_t v_size) {
	int sum = 0;
	for (size_t i = 0; i < v_size; ++i) {
		sum += v[i];
	}
	return sum;
}

void OptimalSubarrayRec(const int* v, size_t n, int* curr, int* best, int* sumbest, size_t i, size_t posprev,
							size_t* bestsize, size_t currsize) {
	if (i == n) {
		if (IsSolution(v, n, curr, currsize)) {
			int sumcurr = GetSum(curr, currsize);
			if (sumcurr > *sumbest) {
				*sumbest = sumcurr;
				*bestsize = currsize;
				memcpy(best, curr, currsize * sizeof(int));
			}
		}
		return;
	}
	size_t start = 0, j;
	if (i > 0) {
		start = posprev + 1;
	}
	for (j = start; j < n; ++j) {
		curr[currsize] = v[j];
		++currsize;
		OptimalSubarrayRec(v, n, curr, best, sumbest, i + 1, j, bestsize, currsize);
		--currsize;
	}
	OptimalSubarrayRec(v, n, curr, best, sumbest, n, j, bestsize, currsize);
}

int OptimalSubarray(const int* v, size_t n) {
	if (v == NULL || n == 0) {
		return 0;
	}
	int* curr = malloc(n * sizeof(int));
	int* best = malloc(n * sizeof(int));
	size_t bestsize = 0;
	int sumbest = 0;
	OptimalSubarrayRec(v, n, curr, best, &sumbest, 0, 0, &bestsize, 0);
	free(curr);
	free(best);
	return sumbest;
}