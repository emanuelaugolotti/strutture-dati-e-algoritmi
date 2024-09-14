#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//int GetRaggioIll() {
//
//}

bool StradaIlluminata(int M, int R, const int* light, size_t light_size, bool* curr) {
	int poscurr = 0;
	for (size_t i = 0; i < light_size; ++i) {
		if (curr[i]) {
			/*int r = GetRaggioIll();
			poscurr += r;*/
		}
	}
	return true;
}

void OptimalIlluminationRec(int M, int R, const int* light, size_t light_size, bool* curr, bool* best, 
	size_t currcount, size_t  bestcount, size_t i) {
	if (i == light_size) {
		if (StradaIlluminata(M, R, light, light_size, curr)) {
			if (currcount < bestcount) {
				bestcount = currcount;
				memcpy(best, curr, light_size * sizeof(bool));
			}
		}
		return;
	}
	curr[i] = true;
	++currcount;
	OptimalIlluminationRec(M, R, light, light_size, curr, best, currcount, bestcount, i + 1);
	curr[i] = false;
	--currcount;
	OptimalIlluminationRec(M, R, light, light_size, curr, best, currcount, bestcount, i + 1);
}

bool* OptimalIllumination(int M, int R, const int* light, size_t light_size) {
	if (light == NULL || light_size == 0) {
		return NULL;
	}
	bool* curr = calloc(light_size, sizeof(bool));
	bool* best = calloc(light_size, sizeof(bool));
	size_t bestcount = light_size + 1;
	bool* done = false;
	OptimalIlluminationRec(M, R, light, light_size, curr, best, 0, bestcount, 0);
	free(curr);
	if (bestcount == light_size + 1) {
		free(best);
		return NULL;
	}
	return best;
}