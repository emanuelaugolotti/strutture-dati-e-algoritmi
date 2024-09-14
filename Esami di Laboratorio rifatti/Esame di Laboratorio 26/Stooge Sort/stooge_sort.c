//Time: 27 min
#include <stdlib.h>
#include <math.h>

void Swap(int* v, int pos1, int pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void StoogeSortRec(int* v, int start, int stop, int dim) {
	if (dim < 2) {
		return;
	}
	if (v[start] > v[stop]) {
		Swap(v, start, stop);
	}
	if (dim >= 3) {
		int newdim = (int)ceil((double)dim * 2.0 / 3.0);
		StoogeSortRec(v, start, start + newdim - 1, newdim);
		StoogeSortRec(v, stop - newdim + 1, stop, newdim);
		StoogeSortRec(v, start, start + newdim - 1, newdim);
	}
}

void Stooge(int* vector, size_t vector_size) {
	if (vector == NULL || vector_size < 2) {
		return;
	}
	StoogeSortRec(vector, 0, (int)vector_size - 1, (int)vector_size);
}