//Time: 6 min
#include <stdlib.h>

int BinarySearch(const int* v, size_t v_size, int value) {
	if (v == NULL || v_size == 0) {
		return -1;
	}
	int start = 0;
	int stop = v_size - 1;
	while (start <= stop) {
		size_t mid = (start + stop) / 2;
		int middle = v[mid];
		if (value == middle) {
			return mid;		//elemento trovato
		}
		if (value < middle) {
			stop = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return -1;	//elemento non trovato
}