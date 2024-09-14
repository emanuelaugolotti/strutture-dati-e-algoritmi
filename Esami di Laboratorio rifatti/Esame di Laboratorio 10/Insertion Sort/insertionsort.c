#include <stdlib.h>

void InsertionSort(int* v, size_t v_size) {
	for (size_t i = 1; i < v_size; ++i) {
		int tmp = v[i];
		int j = (int)i;
		while (v[j - 1] > tmp && j > 0) {
			v[j] = v[j - 1];
			--j;
		}
		v[j] = tmp;
	}
}