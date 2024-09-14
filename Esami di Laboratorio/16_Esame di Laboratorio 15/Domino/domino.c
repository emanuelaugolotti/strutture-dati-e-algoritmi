#include "domino.h"

bool Prendo(const Tessera* t, uint8_t coda, uint8_t* new_coda, bool* flip, size_t pos) {
	if (coda == t[pos].val1) {
		*flip = false;
		*new_coda = t[pos].val2;
		return true;
	}
	if (coda == t[pos].val2) {
		*flip = true;
		*new_coda = t[pos].val1;
		return true;
	}
	return false;
}

void DominoRec(const Tessera* t, size_t t_size, size_t* ret_size, Placing* best, Placing* curr, bool* usati, 
	size_t count, uint8_t coda, size_t i) {
	if (i == t_size) {
		if (*ret_size < count) {
			memcpy(best, curr, t_size * sizeof(Placing));
			*ret_size = count;
		}
		return;
	}
	for (size_t j = 0; j < t_size; ++j) {
		if (count == 0) {
			curr[0].indice = (uint32_t)j;
			usati[j] = true;
			curr[0].flipped = false;
			coda = t[j].val2;
			count = 1;
			DominoRec(t, t_size, ret_size, best, curr, usati, count, coda, i + 1);
			curr[0].flipped = true;
			coda = t[j].val1;
			DominoRec(t, t_size, ret_size, best, curr, usati, count, coda, i + 1);
		}
		else {
			bool flip;
			uint8_t new_coda;
			uint8_t vecchia_coda = coda;
			bool prendo = Prendo(t, coda, &new_coda, &flip, j);
			if (!usati[j] && prendo) {
				coda = new_coda;
				curr[count].indice = (uint32_t)j;
				curr[count].flipped = flip;
				usati[j] = true;
				++count;
				DominoRec(t, t_size, ret_size, best, curr, usati, count, coda, i + 1);
				usati[j] = false;
				coda = vecchia_coda;
				--count;
			}
		}
	}
	DominoRec(t, t_size, ret_size, best, curr, usati, count, coda, t_size);
}

Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size) {
	if (ret_size == NULL) {
		return NULL;
	}
	*ret_size = 0;
	if (t == NULL || t_size == 0) {
		return NULL;
	}
	Placing* best = malloc(t_size * sizeof(Placing));
	Placing* curr = malloc(t_size * sizeof(Placing));
	bool* usati = calloc(t_size, sizeof(bool));
	DominoRec(t, t_size, ret_size, best, curr, usati, 0, 0, 0);
	best = realloc(best, *ret_size * sizeof(Placing));
	free(curr);
	free(usati);
	return best;
}