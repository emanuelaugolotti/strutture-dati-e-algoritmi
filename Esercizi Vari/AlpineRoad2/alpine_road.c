#include "alpine_road.h"

void PrintSolution(const Point* p, size_t countcurr, size_t* curr) {
	for (size_t i = 0; i < countcurr; ++i) {
		size_t pos = curr[i];
		char c = 'A' + (char)pos;
		printf("%c: (%3i, %3i)\n", c, p[pos].s, p[pos].h);
	}
}

int GetDistanza(const Point* p, size_t* curr,size_t countcurr) {
	if (countcurr == 0) {
		return 0;
	}
	int d;
	size_t pos_primo = curr[0];
	size_t pos_ultimo = curr[countcurr - 1];
	d = p[pos_ultimo].s - p[pos_primo].s;
	return d;
}

bool IsSolution(const Point* p, size_t* curr, size_t countcurr, int dh) {
	if (countcurr == 0) {
		return false;
	}
	size_t pos_max, pos_min;
	int h_max = INT_MIN;
	int h_min = INT_MAX;
	for (size_t i = 0; i < countcurr; ++i) {
		size_t pos = curr[i];
		int h_curr = p[pos].h;
		int s_curr = p[pos].s;
		if (h_max < h_curr) {
			h_max = h_curr;
			pos_max = pos;
		}
		if (h_min > h_curr) {
			h_min = h_curr;
			pos_min = pos;
		}
	}
	size_t pos_primo = curr[0];
	size_t pos_ultimo = curr[countcurr - 1];
	int diff = h_max - h_min;
	if (diff <= dh && diff >= -dh) {
		return true;
	}
	return false;
}

void FindPathRec(const Point* p, size_t p_size, int dh, int len_curr, int* len_best, size_t* curr, 
	size_t* best, size_t i, size_t countcurr, size_t* countbest, bool* usati) {
	if (i == p_size) {
		if (IsSolution(p, curr, countcurr, dh)) {
			int len_curr = GetDistanza(p, curr, countcurr);
			if (len_curr > *len_best) {
				*len_best = len_curr;
				*countbest = countcurr;
				memcpy(best, curr, p_size * sizeof(size_t));
			}
		}
		return;
	}
	for (size_t j = i; j < p_size; ++j) {
		if (!usati[j] && (i == 0 || (i > 0 && curr[countcurr - 1] == j - 1))) {
			curr[countcurr] = j;
			++countcurr;
			FindPathRec(p, p_size, dh, len_curr, len_best, curr, best, i + 1, countcurr, countbest, usati);
			--countcurr;
		}
	}
	FindPathRec(p, p_size, dh, len_curr, len_best, curr, best, p_size, countcurr, countbest, usati);
}

int FindPath(const Point* p, size_t p_size, int dh) {
	if (p == NULL || p_size ==0) {
		return -1;
	}
	int len_best = 0;
	size_t* curr = malloc(p_size * sizeof(size_t));
	size_t* best = malloc(p_size * sizeof(size_t));
	bool* usati = calloc(p_size, sizeof(bool));
	size_t countbest = 0;
	FindPathRec(p, p_size, dh, 0, &len_best, curr, best, 0, 0, &countbest, usati);
	if (len_best == 0) {
		return -1;	//non ci sono soluzioni valide
	}
	PrintSolution(p, countbest, best);
	free(curr);
	free(best);
	return len_best;
}