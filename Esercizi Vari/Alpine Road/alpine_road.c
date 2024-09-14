#include "alpine_road.h"

void PrintSolution(const Point* p, size_t curr_size, bool* curr) {
	for (size_t i = 0; i < curr_size; ++i) {
		if (curr[i]) {
			char c = 'A' + (char)i;
			printf("%c: (%3i, %3i)\n", c, p[i].s, p[i].h);
		}
	}
}

void GetPosPrimoUltimo(bool* curr, size_t curr_size, size_t* pos_primo, size_t* pos_ultimo) {
	bool done = false;
	for (size_t i = 0; i < curr_size; ++i) {
		if (curr[i]) {
			if (!done) {
				*pos_primo = i;
				done = true;
			}
			*pos_ultimo = i;
		}
	}
}

bool IsSolution(const Point* p, bool* curr, size_t curr_size, int dh) {
	size_t pos_max, pos_min;
	bool done = false;
	int h_max = INT_MIN;
	int h_min = INT_MAX;
	for (size_t i = 0; i < curr_size; ++i) {
		if (curr[i]) {
			int h_curr = p[i].h;
			int s_curr = p[i].s;
			if (h_max < h_curr) {
				h_max = h_curr;
				pos_max = i;
				done = true;
			}
			if (h_min > h_curr) {
				h_min = h_curr;
				pos_min = i;
			}
		}
	}
	if (!done) {
		return false;
	}
	size_t pos_primo, pos_ultimo;
	GetPosPrimoUltimo(curr, curr_size, &pos_primo, &pos_ultimo);
	for (size_t i = pos_primo; i <= pos_ultimo; ++i) {
		if (!curr[i]) {
			return false;
		}
	}
	int diff = h_max - h_min;
	if (diff <= dh && diff >= -dh) {
		return true;
	}
	return false;
}

int GetDistanza(const Point* p, bool* curr,size_t curr_size) {
	int d;
	size_t pos_primo, pos_ultimo;
	GetPosPrimoUltimo(curr, curr_size, &pos_primo, &pos_ultimo);
	d = p[pos_ultimo].s - p[pos_primo].s;
	return d;
}

void FindPathRec(const Point* p, size_t p_size, int dh, int len_curr, int* len_best, bool* curr, bool* best, 
				size_t i) {
	if (i == p_size) {
		if (IsSolution(p, curr, p_size, dh)) {
			int len_curr = GetDistanza(p, curr, p_size);
			if (len_curr > *len_best) {
				*len_best = len_curr;
				memcpy(best, curr, p_size * sizeof(bool));
			}
		}
		return;
	}
	curr[i] = false;
	FindPathRec(p, p_size, dh, len_curr, len_best, curr, best, i + 1);
	curr[i] = true;
	FindPathRec(p, p_size, dh, len_curr, len_best, curr, best, i + 1);
}

int FindPath(const Point* p, size_t p_size, int dh) {
	if (p == NULL || p_size ==0) {
		return -1;
	}
	int len_best = 0;
	bool* curr = calloc(p_size, sizeof(bool));
	bool* best = calloc(p_size, sizeof(bool));
	FindPathRec(p, p_size, dh, 0, &len_best, curr, best, 0);
	if (len_best == 0) {
		return -1;	//non ci sono soluzioni valide
	}
	PrintSolution(p, p_size, best);
	free(curr);
	free(best);
	return len_best;
}