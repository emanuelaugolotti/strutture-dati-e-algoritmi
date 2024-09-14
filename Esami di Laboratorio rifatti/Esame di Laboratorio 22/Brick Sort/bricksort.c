//Time: 18 min
#include <stdlib.h>
#include <stdbool.h>

void Swap(int* v, size_t pos1, size_t pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void BrickSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 2) {
		return;
	}
	bool ordinato = false;
	while (!ordinato || v_size > 1) {
		ordinato = true;
		for (size_t i = 1; i < v_size - 1; i += 2) {
			if (v[i] > v[i + 1]) {
				Swap(v, i, i + 1);
				ordinato = false;
			}
		}
		for (size_t i = 0; i < v_size - 1; i += 2) {
			if (v[i] > v[i + 1]) {
				Swap(v, i, i + 1);
				ordinato = false;
			}
		}
		--v_size;
	}
}