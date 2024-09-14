#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef char* nome;

void LiberaMemoria(char* alunni[], int n_alunni) {
	for (int i = 0; i < n_alunni; ++i) {
		free(alunni[i]);
	}
	free(alunni);
}

void PrintSolution() {

}

bool IsSolution() {
	return true;
}

void GruppiRec() {

}

void LeggiDaFile(FILE* f, nome** alunni, int* n_alunni) {

	*n_alunni = 0;

	while (1) {
		*alunni = realloc(*alunni, (*n_alunni + 1) * sizeof(nome));
		(*alunni)[*n_alunni] = calloc(21, sizeof(char));
		int ris = fscanf(f, "%20s", (*alunni)[*n_alunni]);
		if (ris != 1) {
			break;
		}
		++(*n_alunni);
	}

	*alunni = realloc(*alunni, *n_alunni * sizeof(nome));

}

int Gruppi(const char* filename, int n) {
	FILE* f = fopen(filename, "r");
	if (f == NULL || feof(f)) {
		return 0;
	}
	int n_sol = 0, n_alunni;
	nome* alunni = NULL;
	LeggiDaFile(f, &alunni, &n_alunni);
	if (n > n_alunni || n < 1) {
		return 0;
	}
	int* curr = malloc(n_alunni * sizeof(int));
	bool* usati = calloc(n_alunni, sizeof(bool));
	
	free(curr);
	free(usati);
	LiberaMemoria(alunni, n_alunni);
	return n_sol;
}