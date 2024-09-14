//Time:
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int GetArea(const int* buildings, bool* curr, size_t curr_size,size_t start) {
	int h = buildings[start];
	for (size_t i = start; i < curr_size + start; ++i) {
		if (buildings[i] < h) {
			h = buildings[i];
		}
	}
	return curr_size * h;
}

bool IsSolution(bool* curr, size_t curr_size, size_t buildings_size, size_t* start) {
	*start = buildings_size;
	for (size_t i = 0; i < buildings_size; ++i) {
		if (curr[i] == 1) {
			*start = i;
			break;
		}
	}
	if (*start == buildings_size) {
		return false;
	}
	for (size_t i = *start; i < *start + curr_size; ++i) {
		if (curr[i] == 0) {
			return false;
		}
	}
	return true;
}

void LargestRectangleRec(const int* buildings, size_t buildings_size, bool* curr, size_t curr_size, bool* best, 
					int* area_best, size_t i) {
	if (i == buildings_size) {
		size_t start;
		if (IsSolution(curr, curr_size, buildings_size, &start)) {
			int area_curr = GetArea(buildings, curr, curr_size, start);
			if (area_curr > *area_best) {
				*area_best = area_curr;
				memcpy(best, curr, buildings_size * sizeof(bool));
			}
		}
		return;
	}
	curr[i] = true;
	++curr_size;
	LargestRectangleRec(buildings, buildings_size, curr, curr_size, best, area_best, i + 1);
	curr[i] = false;
	--curr_size;
	LargestRectangleRec(buildings, buildings_size, curr, curr_size, best, area_best, i + 1);
}

int LargestRectangle(const int* buildings, size_t buildings_size) {
	if (buildings == NULL || buildings_size == 0) {
		return 0;
	}
	bool* curr = calloc(buildings_size, sizeof(bool));
	bool* best = calloc(buildings_size, sizeof(bool));
	int area_best = 0;
	LargestRectangleRec(buildings, buildings_size, curr, 0, best, &area_best, 0);
	free(curr);
	free(best);
	return area_best;
}