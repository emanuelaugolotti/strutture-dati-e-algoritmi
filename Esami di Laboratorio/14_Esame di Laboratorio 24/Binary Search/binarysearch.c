#include <stdlib.h>

int BinarySearch(const int* v, size_t v_size, int value) {
	if (v == NULL || v_size == 0) {
		return -1;
	}
	int start = 0;
	int stop = (int)v_size;
	while (start <= stop) {
		int mediana = (start + stop) / 2;
		int middle = v[mediana];
		if (value == middle) {	//elemento trovato
			return mediana;
		}
		if (value < middle) {	//cerco a sinistra
			stop = mediana - 1;
		} else {
			start = mediana + 1;	//cerco a destra
		}
	}
	return -1;
}