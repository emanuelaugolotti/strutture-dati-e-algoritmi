#include <stdlib.h>

void GetMinMax(int* v, size_t v_size, int* min, int* max) {
	*min = v[0];
	*max = v[0];
	for (size_t i = 0; i < v_size; ++i) {
		if (v[i] > *max) {
			*max = v[i];
		}
		if (v[i] < *min) {
			*min = v[i];
		}
	}
}

int GetFrequenza(int* v, size_t v_size, int val) {
	int count = 0;
	for (size_t i = 0; i < v_size; ++i) {
		if (v[i] == val) {
			++count;
		}
	}
	return count;
}

void AggiornaFrequenza(int* v, size_t v_size, int* tmp, int tmp_size, int min) {
	for (int i = 0; i < tmp_size; ++i) {
		int val = i + min;
		int f = GetFrequenza(v, v_size, val);
		tmp[i] = f;
	}
}

void PopolaVec(int* v, int* tmp, int tmp_size, int min) {
	int poscurr = 0;
	for (int i = 0; i < tmp_size; ++i) {
		int val = i + min;
		int f = tmp[i];
		for (int j = 0; j < f; ++j) {
			v[poscurr] = val;
			++poscurr;
		}
	}
}

void CountingSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 2) {
		return;
	}
	int min, max;
	GetMinMax(v, v_size, &min, &max);
	int tmp_size = max - min + 1;
	int* tmp = malloc(tmp_size * sizeof(int));
	AggiornaFrequenza(v, v_size, tmp, tmp_size, min);
	PopolaVec(v, tmp, tmp_size, min);
	free(tmp);
}