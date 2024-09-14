//Time: 42min
#include <stdlib.h>

size_t FindPosMax(int* v, size_t stop) {
	size_t pos_max = 0;
	int max = v[0];
	for (size_t i = 0; i <= stop; ++i) {
		if (v[i] > max) {
			max = v[i];
			pos_max = i;
		}
	}
	return pos_max;
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
	size_t pos_max = FindPosMax(v, curr_size - 1);
	Flip(v, pos_max);
	Flip(v, curr_size - 1);
	PancakeSortRec(v, curr_size - 1);
}

void PancakeSort(int* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return;
	}
	PancakeSortRec(v, v_size);
}