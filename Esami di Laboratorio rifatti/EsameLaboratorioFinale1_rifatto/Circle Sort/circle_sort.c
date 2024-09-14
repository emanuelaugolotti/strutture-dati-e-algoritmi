#include <stdlib.h>
#include <stdbool.h>

void Swap(int* v, int pos1, int pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void CalcolaStartStop(int* start_sn, int* stop_sn, int* start_dx, int* stop_dx, size_t* dim_sn, size_t* dim_dx, 
						size_t dim_prev, int start_prev, int stop_prev) {
	*dim_sn = (int)dim_prev / 2;
	*start_sn = start_prev;
	*start_dx = (int)*dim_sn + start_prev;
	*stop_dx = stop_prev;
	*stop_sn = *start_dx - 1;
	if (dim_prev % 2 == 0) {
		*dim_dx = *dim_sn;
	} else {
		*dim_dx = *dim_sn + 1;
	}
}

void CircleSortRec(int* v, size_t dim, int start, int stop, bool* ordinato) {
	if (dim == 1) {
		return;
	}
	int start_prev = start;
	int stop_prev = stop;
	while (start < stop) {
		if (v[start] > v[stop]) {
			Swap(v, start, stop);
			*ordinato = false;
		}
		++start;
		--stop;
	}
	if (start == stop) {
		if (v[start - 1] > v[start]) {
			Swap(v, start - 1, start);
			*ordinato = false;
		}
	}
	int start_dx, stop_dx, start_sn, stop_sn;
	size_t dim_sn, dim_dx;
	CalcolaStartStop(&start_sn, &stop_sn, &start_dx, &stop_dx, &dim_sn, &dim_dx, dim, start_prev, stop_prev);
	CircleSortRec(v, dim_sn, start_sn, stop_sn, ordinato);
	CircleSortRec(v, dim_dx, start_dx, stop_dx, ordinato);
}

void CircleSort(int* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return;
	}
	bool ordinato = true;
	CircleSortRec(v, v_size, 0, (int)v_size - 1, &ordinato);
	if (ordinato) {
		return;
	} else {
		CircleSort(v, v_size);
	}
}