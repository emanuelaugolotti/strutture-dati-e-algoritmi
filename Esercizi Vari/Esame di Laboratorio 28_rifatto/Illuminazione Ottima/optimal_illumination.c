#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool IsSolution(int M, int R, const int* light, bool* curr, size_t curr_size) {
	int poscurr = 0;
	for (size_t i = 0; i < curr_size; ++i) {
		if (curr[i]) {
			size_t poslampione = light[i];
			int start = poslampione - R;
			if (start < 0) {
				start = 0;
			}
			int stop = poslampione + R;
			if (start > poscurr) {
				return false;
			}
			poscurr = stop;
		}
	}
	if (poscurr >= M) {
		return true;
	}
	return false;
}

void OptimalIlluminationRec(int M, int R, const int* light, size_t light_size, bool* curr, bool* best,
							size_t accesicurr, size_t* accesibest, size_t i) {
	if (i == light_size) {
		if (IsSolution(M, R, light, curr, light_size)) {
			if (accesicurr < *accesibest) {
				*accesibest = accesicurr;
				memcpy(best, curr, light_size * sizeof(bool));
			}
		}
		return;
	}
	curr[i] = true;
	++accesicurr;
	OptimalIlluminationRec(M, R, light, light_size, curr, best, accesicurr, accesibest, i + 1);
	curr[i] = false;
	--accesicurr;
	OptimalIlluminationRec(M, R, light, light_size, curr, best, accesicurr, accesibest, i + 1);
}

bool* OptimalIllumination(int M, int R, const int* light, size_t light_size) {
	if (light == NULL || light_size == 0 || R == 0 || M == 0) {
		return NULL;
	}
	bool* curr = calloc(light_size, sizeof(bool));
	bool* best = calloc(light_size, sizeof(bool));
	size_t accesibest = light_size + 1;
	OptimalIlluminationRec(M, R, light, light_size, curr, best, 0, &accesibest, 0);
	free(curr);
	if (accesibest == light_size + 1) {
		free(best);
		return NULL;
	}
	return best;
}