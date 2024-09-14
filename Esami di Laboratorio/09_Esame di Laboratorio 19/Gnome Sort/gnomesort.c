//Time: 19min
#include <stdlib.h>

void Swap(int* v, size_t pos1, size_t pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void GnomeSort(int* v, size_t v_size) {
	for (size_t i = 1; i < v_size;) {
		if (v[i] < v[i - 1]) {
			Swap(v, i - 1, i);
			--i;
		} else {
			++i;
		}
	}
}