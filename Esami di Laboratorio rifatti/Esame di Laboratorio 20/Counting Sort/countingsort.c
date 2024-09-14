#include <stdlib.h>

void GetMaxMin(int* v, size_t v_size, int* max, int* min) {
	*max = v[0];
	*min = v[v_size - 1];
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
	int f = 0;
	for (size_t i = 0; i < v_size; ++i) {
		if (v[i] == val) {
			++f;
		}
	}
	return f;
}

void PopolaTmp(int* v, int tmp_size, size_t v_size, int* tmp, int min) {
	for (int i = 0; i < tmp_size; ++i) {
		int val = i + min;
		int f = GetFrequenza(v, v_size, val);
		tmp[i] = f;
	}
}

void PopolaVec(int* v, int tmp_size, int* tmp, int min) {
	int start = 0;
	for (int i = 0; i < tmp_size; ++i) {
		int val = i + min;
		int stop = start + tmp[i];
		for (int j = start; j < stop; ++j) {
			v[j] = val;
		}
		start = stop;
	}
}

void CountingSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 2) {
		return;
	}
	int max, min;
	GetMaxMin(v, v_size, &max, &min);
	int tmp_size = max - min + 1;
	int* tmp = malloc(tmp_size * sizeof(int));
	PopolaTmp(v, tmp_size, v_size, tmp, min);
	PopolaVec(v, tmp_size, tmp, min);
	free(tmp);
}