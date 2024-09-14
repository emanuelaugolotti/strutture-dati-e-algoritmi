//Time: 15 min
#include <stdlib.h>

void Swap(int* v, size_t pos1, size_t pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void GnomeSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 2) {
		return;
	}
	size_t gnomo_pos = 0;
	while (gnomo_pos < v_size) {
		if (gnomo_pos == 0) {
			++gnomo_pos;
		}
		if (v[gnomo_pos] < v[gnomo_pos - 1]) {
			Swap(v, gnomo_pos, gnomo_pos - 1);
			--gnomo_pos;
		} else {
			++gnomo_pos;
		}
	}
	return;
}