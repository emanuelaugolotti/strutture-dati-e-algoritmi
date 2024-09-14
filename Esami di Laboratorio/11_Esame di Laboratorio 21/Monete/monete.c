#include <stdlib.h>
#include <stdio.h>

void PrintSol(int* v, size_t v_size) {
	for (size_t i = 0; i < v_size; ++i) {
		printf("%i", v[i]);
		if (i != v_size - 1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
}

void CombinaMoneteRec(int b, const int* m, size_t m_size, int* curr, int* b_curr, int* nsol, size_t start) {
	if (*b_curr == b) {
		PrintSol(curr, m_size);
		++(*nsol);
		return;
	}
	for (size_t tipotaglio = start; tipotaglio < m_size; ++tipotaglio) {
		int taglio = m[tipotaglio];
		if (*b_curr + taglio <= b) {
			curr[tipotaglio] += 1;
			*b_curr += m[tipotaglio];
			start = tipotaglio;
			CombinaMoneteRec(b, m, m_size, curr, b_curr, nsol, start);
			curr[tipotaglio] -= 1;
			*b_curr -= m[tipotaglio];
		}
	}
}

int CombinaMonete(int b, const int* m, size_t m_size) {
	if (b == 0 || m_size == 0) {
		return 0;
	}
	int nsol = 0;
	int b_curr = 0;
	int* curr = calloc(m_size, sizeof(int));
	CombinaMoneteRec(b, m, m_size, curr, &b_curr, &nsol, 0);
	free(curr);
	return nsol;
}