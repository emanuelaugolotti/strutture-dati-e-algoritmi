#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Lampadine {
	bool* v;
	size_t count;
} Lampadine;

bool StradaIlluminata(int M, int R, const int* light, size_t light_size, bool* curr) {
	int start = 0;
	for (size_t i = 0; i < light_size; ++i) {
		if (curr[i]) {
			int r_sn = light[i] - R;
			int r_dx = light[i] + R;
			if (r_sn > start) {
				return false;
			}
			start = r_dx;
		}
	}
	if (start < M) {
		return false;
	}
	return true;
}

void OptimalIlluminationRec(int M, int R, const int* light, size_t light_size, Lampadine curr, Lampadine* best,
							size_t i) {
	if (i == light_size) {
		if (StradaIlluminata(M, R, light, light_size, curr.v)) {
			if (best->count > curr.count) {
				best->count = curr.count;
				memcpy(best->v, curr.v, light_size * sizeof(bool));
			}
		}
		return;
	}
	curr.v[i] = true;
	++(curr.count);
	OptimalIlluminationRec(M, R, light, light_size, curr, best, i + 1);
	curr.v[i] = false;
	--(curr.count);
	OptimalIlluminationRec(M, R, light, light_size, curr, best, i + 1);
}

bool* OptimalIllumination(int M, int R, const int* light, size_t light_size) {
	if (light == NULL || light_size == 0) {
		return NULL;
	}
	Lampadine curr;
	curr.v = calloc(light_size, sizeof(bool));
	curr.count = 0;
	Lampadine best;
	best.v = calloc(light_size, sizeof(bool));
	best.count = light_size + 1;
	OptimalIlluminationRec(M, R, light, light_size, curr, &best, 0);
	free(curr.v);
	if (best.count == light_size + 1) {
		free(best.v);
		return NULL;
	}
	return best.v;
}