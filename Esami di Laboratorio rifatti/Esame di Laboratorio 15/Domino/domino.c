#include "domino.h"
#include <stdbool.h>
#include <string.h>


void PopolaLeftRight(Placing* curr, const Tessera* t, uint8_t* left, uint8_t* right, size_t i) {
	uint32_t idx1 = curr[i].indice;
	uint32_t idx2 = curr[i + 1].indice;
	if (!curr[i].flipped) {
		*left = t[idx1].val2;
	} else {
		*left = t[idx1].val1;
	}
	if (!curr[i + 1].flipped) {
		*right = t[idx2].val1;
	} else {
		*right = t[idx2].val2;
	}
}

bool IsSolution(Placing* curr, size_t countcurr, const Tessera* t) {
	for (size_t i = 0; i < countcurr - 1; ++i) {
		uint8_t left, right;
		PopolaLeftRight(curr, t, &left, &right, i);
		if (left != right) {
			return false;
		}
	}
	return true;
}

void DominoRec(const Tessera* t, size_t t_size, size_t* ret_size, Placing* curr, size_t countcurr, Placing* best,
				size_t* countbest, bool* usati, size_t i) {
	if (i == t_size) {
		if (IsSolution(curr, countcurr, t)) {
			if (*countbest < countcurr) {
				*countbest = countcurr;
				memcpy(best, curr, t_size * sizeof(Placing));
			}
		}
		return;
	}
	for (size_t j = 0; j < t_size; ++j) {
		if (!usati[j]) {
			curr[countcurr].indice = (uint32_t)j;
			curr[countcurr].flipped = true;
			if (countcurr == 0 || (countcurr > 0 && IsSolution(curr, countcurr, t))) {
				usati[j] = true;
				++countcurr;
				DominoRec(t, t_size, ret_size, curr, countcurr, best, countbest, usati, i + 1);
				curr[countcurr - 1].flipped = false;
				DominoRec(t, t_size, ret_size, curr, countcurr, best, countbest, usati, i + 1);
				--countcurr;
				usati[j] = false;
			}
		}
	}
	DominoRec(t, t_size, ret_size, curr, countcurr, best, countbest, usati, t_size);
}


Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size) {
	if (ret_size != NULL) {
		*ret_size = 0;
	}
	if (t == NULL || t_size == 0 || ret_size == NULL) {
		return NULL;
	}
	Placing* curr = malloc(t_size * sizeof(Placing));
	Placing* best = malloc(t_size * sizeof(Placing));
	bool* usati = calloc(t_size, sizeof(bool));
	size_t countbest = 0;
	DominoRec(t, t_size, ret_size, curr, 0, best, &countbest, usati, 0);
	free(curr);
	free(usati);
	if (countbest == 0) {
		free(best);
		return NULL;
	}
	best = realloc(best, countbest * sizeof(Placing));
	*ret_size = countbest;
	return best;
}