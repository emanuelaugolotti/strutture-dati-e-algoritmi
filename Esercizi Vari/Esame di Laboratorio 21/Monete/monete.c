//Time: 52 min
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void PrintSolution(int* curr, size_t curr_size) {
	for (size_t i = 0; i < curr_size; ++i) {
		printf("%i ", curr[i]);
	}
	printf("\n");
}

bool IsSolution(int b, const int* m, size_t m_size, int* curr, int* b_ris, int pos, int j) {
	*b_ris = 0;
	for (size_t i = 0; i < m_size; ++i) {
		if ((int)i == pos) {
			*b_ris += j * m[i];
		}
		*b_ris += curr[i] * m[i];
	}
	if (*b_ris <= b) {
		return true;
	}
	return false;
}

void CombinaMoneteRec(int b, const int* m, size_t m_size, int* curr, size_t i, int* nsol, int b_curr) {
	if (i == m_size) {
		if (b_curr == b) {
			PrintSolution(curr, m_size);
			++(*nsol);
		}
		return;
	}
	for (int j = b; j >= 0; --j) {
		int b_tmp = b_curr;
		int curr_tmp = curr[i];
		int b_ris;
		if (IsSolution(b, m, m_size, curr, &b_ris, i, j)) {
			curr[i] = j;
			b_curr = b_ris;
			CombinaMoneteRec(b, m, m_size, curr, i + 1, nsol, b_curr);
			curr[i] = curr_tmp;
			b_curr = b_tmp;
		}
	}
}

int CombinaMonete(int b, const int* m, size_t m_size) {
	int nsol = 0;
	int* curr = calloc(m_size, sizeof(int));
	CombinaMoneteRec(b, m, m_size, curr, 0, &nsol, 0);
	free(curr);
	return nsol;
}