#include <stdlib.h>

size_t TrovaPosMax(int* v, size_t curr_size) {
	size_t posmax = 0;
	int max = v[posmax];
	for (size_t i = 0; i < curr_size; ++i) {
		if (v[i] > max) {
			posmax = i;
			max = v[i];
		}
	}
	return posmax;
}

void Swap(int* v, size_t pos1, size_t pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void Flip(int* v, size_t stop) {
	size_t start = 0;
	while (start < stop) {
		Swap(v, start, stop);
		++start;
		--stop;
	}
}

void PancakeSortRec(int* v, size_t curr_size) {
	if (curr_size == 1) {
		return;
	}
	size_t posmax = TrovaPosMax(v, curr_size);
	Flip(v, posmax);
	Flip(v, curr_size - 1);
	PancakeSortRec(v, curr_size - 1);
}

void PancakeSort(int* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return;
	}
	PancakeSortRec(v, v_size);
}