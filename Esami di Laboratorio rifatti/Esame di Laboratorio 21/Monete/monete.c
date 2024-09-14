//Time: 21 min
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void PrintSolution(int* curr, size_t curr_size) {
	for (size_t i = 0; i < curr_size; ++i) {
		printf("%i ", curr[i]);
	}
	printf("\n");
}

bool IsSolution(int* curr, size_t curr_size, int b, const int* m) {
	int sum = 0;
	for (size_t i = 0; i < curr_size; ++i) {
		sum += (curr[i] * m[i]);
	}
	if (sum == b) {
		return true;
	}
	return false;
}

void CombinaMoneteRec(int b, const int* m, size_t m_size, int* curr, size_t i, int* nsol) {
	if (i == m_size) {
		if (IsSolution(curr, m_size, b, m)) {
			PrintSolution(curr, m_size);
			++(*nsol);
		}
		return;
	}
	int stop = b / m[i];
	for (int j = stop; j >= 0; --j) {
		curr[i] += j;
		CombinaMoneteRec(b, m, m_size, curr, i + 1, nsol);
		curr[i] -= j;
	}
}

int CombinaMonete(int b, const int* m, size_t m_size) {
	if (m_size == 0) {
		return 0;
	}
	int nsol = 0;
	int* curr = calloc(m_size, sizeof(int));
	CombinaMoneteRec(b, m, m_size, curr, 0, &nsol);
	free(curr);
	return nsol;
}