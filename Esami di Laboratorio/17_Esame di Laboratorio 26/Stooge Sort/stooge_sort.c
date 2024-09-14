#include <stdlib.h>

void Swap(int* v, size_t pos1, size_t pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void StoogeRec(int* v, size_t dim, size_t start, size_t stop) {
	if (dim == 1) {
		return;
	}
	if (dim == 2) {
		if (v[start] > v[stop]) {
			Swap(v, start, stop);
		}
		return;
	}
	size_t n;
	if ((dim * 2) % 3 == 0) {
		n = (dim * 2) / 3;
	} else {
		n = ((dim * 2) / 3) + 1;
	}
	StoogeRec(v, n, start, start + n - 1);
	StoogeRec(v, n, stop - n + 1, stop);
	StoogeRec(v, n, start, start + n - 1);
}

void Stooge(int* vector, size_t vector_size) {
	if (vector == NULL || vector_size == 0) {
		return;
	}
	StoogeRec(vector, vector_size, 0, vector_size - 1);
	return;
}