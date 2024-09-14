#include <stdlib.h>
#include <math.h>

void Swap(int* v, size_t pos1, size_t pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void StoogeRec(int* v, size_t start, size_t stop, size_t dim) {
	if (v[start] > v[stop]) {
		Swap(v, start, stop);
	}
	if (dim >= 3) {
		size_t dim_new = (size_t)ceil((double)dim * 2. / 3.);
		size_t stop_new = start + dim_new - 1;
		StoogeRec(v, start, stop_new, dim_new);
		size_t start_new = stop - dim_new + 1;
		StoogeRec(v, start_new, stop, dim_new);
		StoogeRec(v, start, stop_new, dim_new);
	}
}

void Stooge(int* vector, size_t vector_size) {
	if (vector == NULL || vector_size < 2) {
		return;
	}
	StoogeRec(vector, 0, vector_size - 1, vector_size);
}