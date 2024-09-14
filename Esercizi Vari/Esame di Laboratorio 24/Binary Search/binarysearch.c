#include <stdlib.h>

int BinarySearch(const int* v, size_t v_size, int value) {
	if (v == NULL || v_size == 0) {
		return -1;
	}
	int start = 0;
	int stop = (int)v_size - 1;
	while (start <= stop) {
		size_t mid = (start + stop) / 2;
		int middle = v[mid];
		if (middle == value) {
			return mid;
		}
		else if (value < middle) {
			stop = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return -1;
}