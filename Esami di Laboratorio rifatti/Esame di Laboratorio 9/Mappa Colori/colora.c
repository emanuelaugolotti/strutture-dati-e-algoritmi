#include "colora.h"

bool SonoAdiacenti(const struct Matrix* m, size_t area1, size_t area2) {
	bool ris = false;
	for (size_t r = 0; r < m->size; ++r) {
		for (size_t c = 0; c < m->size; ++c) {
			if (r == area1 && c == area2) {
				ris = m->data[r * m->size + c];
			}
		}
	}
	return ris;
}

bool IsSolution(char* curr, const struct Matrix* m, size_t count, size_t curr_size) {
	if (count != curr_size) {
		return false;
	}
	for (size_t i = 0; i < curr_size - 1; ++i) {
		size_t area1 = i;
		for (size_t area2 = 0; area2 < curr_size; ++area2) {
			if (area1 != area2 && SonoAdiacenti(m, area1, area2) && curr[area1] == curr[area2]) {
				return false;
			}
		}	
	}
	return true;
}

void StampaSol(char* curr, size_t curr_size) {
	for (size_t i = 0; i < curr_size; ++i) {
		printf("%zi -> %c; ", i, curr[i]);
	}
	printf("\n");
}

void MappaColoriRec(const struct Matrix* m, const char* c, size_t c_size, char* curr, int* nsol, size_t i, 
					size_t aree_colorate) {
	if (i == m->size) {
		if (IsSolution(curr, m, aree_colorate, m->size)) {
			StampaSol(curr, m->size);
			++(*nsol);
		}
		return;
	}
	for (size_t pos_colore = 0; pos_colore < c_size; ++pos_colore) {
		curr[i] = c[pos_colore];
		++aree_colorate;
		MappaColoriRec(m, c, c_size, curr, nsol, i + 1, aree_colorate);
		--aree_colorate;
	}
}

int MappaColori(const struct Matrix* m, const char* c, size_t c_size) {
	if (m == NULL || c == NULL || c_size == 0) {
		return 0;
	}
	int nsol = 0;
	char* curr = malloc(m->size * sizeof(char));
	MappaColoriRec(m, c, c_size, curr, &nsol, 0, 0);
	free(curr);
	return nsol;
}