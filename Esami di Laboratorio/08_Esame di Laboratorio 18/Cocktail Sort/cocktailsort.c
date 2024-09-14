//Time: 33 min
#include <stdlib.h>
#include <stdbool.h>

void Swap(int* v, int pos1, int pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void CocktailSort(int* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return;
	}
	int start = 0;
	int end = (int)(v_size - 1);
	bool ordinato1 = false;
	bool ordinato2 = false;
	while (start < end || !ordinato1 || !ordinato2) {
		ordinato1 = true;
		ordinato2 = true;
		for (int i = start; i < end; ++i) {
			if (v[i] > v[i + 1]) {
				Swap(v, i, i + 1);
				ordinato1 = false;
			}
		}
		--end;
		for (int i = end; i > 0; --i) {
			if (v[i] < v[i - 1]) {
				Swap(v, i - 1, i);
				ordinato2 = false;
			}
		}
		++start;
	}
	return;
}