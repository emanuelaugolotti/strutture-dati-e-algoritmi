//Time: 27 min
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
	int end = (int)v_size - 1;
	while (start < end) {
		bool ordinato = true;
		for (int i = start; i < end; ++i) {
			if (v[i] > v[i + 1]) {
				Swap(v, i, i + 1);
				ordinato = false;
			}
		}
		--end;
		for (int i = end; i > start; --i) {
			if (v[i] < v[i - 1]) {
				Swap(v, i, i - 1);
				ordinato = false;
			}
		}
		++start;
		if (ordinato) {
			break;
		}
	}
}