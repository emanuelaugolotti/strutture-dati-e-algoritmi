#include <stdlib.h>
#include <stdbool.h>

void Swap(int* v, size_t pos1, size_t pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void BrickSort(int* v, size_t v_size) {
	if (v_size == 1 || v_size == 0 || v == NULL) {
		return;
	}
	/*size_t stop_pari, stop_disp;
	if ((v_size - 1) % 2 == 0) {
		stop_pari = v_size - 2;
		stop_disp = v_size - 1;
	} else {
		stop_disp = v_size - 2;
		stop_pari = v_size - 1;
	}*/
	bool ordinato = false;
	while (!ordinato) {
		ordinato = true;
		for (size_t i = 1; i < v_size - 1/*stop_disp*/; i += 2) {
			if (v[i] > v[i + 1]) {
				Swap(v, i, i + 1);
				ordinato = false;
			}
		}
		for (size_t i = 0; i < v_size - 1/*stop_pari*/; i += 2) {
			if (v[i] > v[i + 1]) {
				Swap(v, i, i + 1);
				ordinato = false;
			}
		}
	}
}