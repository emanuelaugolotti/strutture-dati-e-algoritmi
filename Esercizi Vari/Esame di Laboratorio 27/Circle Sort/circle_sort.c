#include <stdlib.h>
#include <stdbool.h>

void Swap(int* v, size_t pos1, size_t pos2) {
	int tmp = v[pos2];
	v[pos2] = v[pos1];
	v[pos1] = tmp;
}

bool IsPari(int n) {
	if (n % 2 == 0) {
		return true;
	}
	return false;
}

void ScambiCircolari(int* v, size_t start, size_t stop, size_t dim, bool* ordinato) {
	while (start < stop) {
		if (v[start] > v[stop]) {
			Swap(v, start, stop);
			*ordinato = false;
		}
		++start;
		--stop;
	}
	if (!IsPari(dim)) {
		if (v[dim / 2] > v[dim / 2 + 1]) {
			Swap(v, dim / 2, dim / 2 + 1);
		}
	}
}

void CircleSortRec(int* v, size_t start, size_t stop, size_t dim, bool* ordinato) {
	if (dim < 2) {
		return;
	}
	ScambiCircolari(v, start, stop, dim, ordinato);
	size_t startnew, stopnew, dimnew;
	dimnew = dim / 2;
	if (IsPari(dim)) {
		stopnew = start + dimnew - 1;
		startnew = stop - dimnew + 1;
		CircleSortRec(v, start, stopnew, dimnew, ordinato);
		CircleSortRec(v, startnew, stop, dimnew, ordinato);
	} else {
		stopnew = start + dimnew;
		startnew = stop - dimnew + 1;
		CircleSortRec(v, start, stopnew, dimnew + 1, ordinato);
		CircleSortRec(v, startnew, stop, dimnew, ordinato);
	}
}

void CircleSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 2) {
		return;
	}
	bool ordinato = false;
	while (!ordinato) {
		ordinato = true;
		CircleSortRec(v, 0, v_size - 1, v_size, &ordinato);
	}
}