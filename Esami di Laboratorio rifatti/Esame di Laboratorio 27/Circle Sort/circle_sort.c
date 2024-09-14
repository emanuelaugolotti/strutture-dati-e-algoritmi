//Time: 54 min
#include <stdlib.h>
#include <stdbool.h>

void Swap(int* v, int pos1, int pos2) {
	int tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void GetNewStartStop(int start, int stop, int size, int* startnew, int* stopnew) {
	if (size % 2 == 0) {
		*stopnew = start + (size / 2) - 1;
		*startnew = stop - size / 2 + 1;
	}
	else {
		*stopnew = start + (size / 2);
		*startnew = stop - (size / 2) + 1;
	}
}

void ConfrontoScambioCircolare(int* v, int start, int stop, bool* ordinato, int size) {
	while (start < stop) {
		if (v[start] > v[stop]) {
			Swap(v, start, stop);
			*ordinato = false;
		}
		++start;
		--stop;
	}
	if (size % 2 != 0) {
		if (v[size / 2] > v[size / 2 + 1]) {
			Swap(v, size / 2, size / 2 + 1);
		}
	}
}

void CircleSortRec(int* v, int start, int stop, bool* ordinato) {
	if (start == stop) {
		return;
	}
	int size = stop - start + 1;
	ConfrontoScambioCircolare(v, start, stop, ordinato, size);
	int stopnew, startnew;
	GetNewStartStop(start, stop, size, &startnew, &stopnew);
	CircleSortRec(v, start, stopnew, ordinato);
	CircleSortRec(v, startnew, stop, ordinato);
}

void CircleSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 2) {
		return;
	}
	bool ordinato = false;
	while (!ordinato) {
		ordinato = true;
		CircleSortRec(v, 0, (int)v_size - 1, &ordinato);
	}
}