//Time: 40min
#include <stdlib.h>

void FindMinMax(int* v, int v_size, int* min, int* max) {
	*min = v[0];
	*max = v[0];
	for (int i = 0; i < v_size; ++i) {
		if (v[i] > *max) {
			*max = v[i];
		}
		if (v[i] < *min) {
			*min = v[i];
		}
	}
}

int FindFrequenza(int* v, int v_size, int e) {
	int freq = 0;
	for (int i = 0; i < v_size; ++i) {
		if (v[i] == e) {
			++freq;
		}
	}
	return freq;
}

void PopolaV(int* v, int start, int stop, int e) {
	for (int i = start; i < stop; ++i) {
		v[i] = e;
	}
}

void CountingSort(int* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return;
	}
	int min;
	int max;
	FindMinMax(v, (int)v_size, &min, &max);
	int tmp_size = max - min + 1;
	int* tmp = malloc(tmp_size * sizeof(int));
	for (int i = 0; i < tmp_size; ++i) {
		int e = i + min;
		int freq_e = FindFrequenza(v, (int)v_size, e);
		tmp[i] = freq_e;
	}
	//si itera su tmp scrivendo in v, tmp[i] volte, il valore i + min(v)
	int start = 0;
	for (int i = 0; i < tmp_size; ++i) {
		int num_volte = tmp[i];
		int val = i + min;
		PopolaV(v, start, start + num_volte, val);
		start += num_volte;
	}
	free(tmp);
}