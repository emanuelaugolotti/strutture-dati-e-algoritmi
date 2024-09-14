//Time: 55 min
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void PrintSolution(int* v, size_t v_size, const int* buildings) {
	for (size_t i = 0; i < v_size; ++i) {
		size_t pos = v[i];
		printf("%i ", buildings[pos]);
	}
	printf("\n");
}

int GetAreaRectangle(int* curr, size_t curr_size, const int* buildings) {
	size_t pos_h = curr[0];
	int h = buildings[pos_h];
	for (size_t i = 0; i < curr_size; ++i) {
		pos_h = curr[i];
		if (buildings[pos_h] < h) {
			h = buildings[pos_h];
		}
	}
	return h * (int)curr_size;
}

void LargestRectangleRec(const int* buildings, size_t buildings_size, int* curr, size_t curr_size, int* best,
						size_t* best_size, int* areabest, size_t i) {
	if (i == buildings_size) {
		PrintSolution(curr, curr_size, buildings);
		int areacurr = GetAreaRectangle(curr, curr_size, buildings);
		if (*areabest < areacurr) {
			*areabest = areacurr;
			*best_size = curr_size;
			memcpy(best, curr, buildings_size * sizeof(int));
		}
		return;
	}
	for (size_t j = i; j < buildings_size; ++j) {
		if (i == 0 || (i > 0 && curr[curr_size - 1] == j - 1)) {
			curr[curr_size] = (int)j;
			++curr_size;
			LargestRectangleRec(buildings, buildings_size, curr, curr_size, best, best_size, areabest, i + 1);
			--curr_size;
			curr[curr_size] = 0;
		}
	}
	LargestRectangleRec(buildings, buildings_size, curr, curr_size, best, best_size, areabest, buildings_size);
}

int LargestRectangle(const int* buildings, size_t buildings_size) {
	if (buildings == NULL || buildings_size == 0) {
		return 0;
	}
	int* curr = calloc(buildings_size, sizeof(int));
	int* best = calloc(buildings_size, sizeof(int));
	size_t best_size = 0;
	int areabest;
	LargestRectangleRec(buildings, buildings_size, curr, 0, best, &best_size, &areabest, 0);
	printf("Best:\n");
	PrintSolution(best, best_size, buildings);
	printf("Area = %i", areabest);
	free(curr);
	free(best);
	return (int)best_size;
}