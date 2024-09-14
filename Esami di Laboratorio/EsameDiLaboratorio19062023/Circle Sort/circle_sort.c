#include <stdlib.h>

void Swap(int* v, size_t pos1, size_t pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void CalcolaStartStop(size_t start_last, size_t* start_new1, size_t* start_new2, size_t stop_last, 
					size_t* stop_new1, size_t* stop_new2) {
	size_t n = stop_last - start_last + 1;
	if (n % 2 == 0) {
		n = n / 2;
		*start_new1 = start_last;
		*stop_new1 = *start_new1 + n - 1;
		*stop_new2 = stop_last;
		*start_new2 = *stop_new2 - n  + 1;
	}
	else {
		n = n / 2;
		*start_new1 = start_last;
		*stop_new1 = *start_new1 + n - 1;
		*stop_new2 = stop_last;
		*start_new2 = *stop_new2 - n;
	}
}

void CircleSortRec(int* v, size_t start, size_t stop) {
	if (start >= stop) {
		return;
	}
	int primo = v[start];
	int ultimo = v[stop];
	if (primo > ultimo) {
		Swap(v, start, stop);
	}
	size_t start_new1, start_new2;
	size_t stop_new1, stop_new2;
	CalcolaStartStop(start, &start_new1, &start_new2, stop, &stop_new1, &stop_new2);
	CircleSortRec(v, start_new1, stop_new1);
	CircleSortRec(v, start_new2, stop_new2);
}
void CircleSort(int* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return;
	}
	CircleSortRec(v, 0, v_size - 1);
}