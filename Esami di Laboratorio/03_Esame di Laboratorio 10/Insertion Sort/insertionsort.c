//38 min
#include <stdlib.h>

void InsertionSort(int* v, size_t v_size) {
	for (size_t i = 1; i < v_size; ++i) {
		int tmp = v[i];

		int j = i - 1;
		while (j >= 0 && v[j] > tmp) {
			v[j + 1] = v[j];
			--j;
		}

		v[j + 1] = tmp;
	}
}