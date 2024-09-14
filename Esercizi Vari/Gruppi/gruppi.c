#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void LiberaMemoria(char* alunni[], int n_alunni, int* curr, int* usati) {
	for (int i = 0; i < n_alunni; ++i) {
		free(alunni[i]);
	}
	free(alunni);
	free(curr);
	free(usati);
}

void PrintSolution(char* alunni[], int* curr, int curr_size) {
	printf("{ ");
	for (int i = 0; i < curr_size; ++i) {
		int pos_alunno = curr[i];
		printf("%s", alunni[pos_alunno]);
		if (i != curr_size - 1) {
			printf(", ");
		}
	}
	printf(" }\n");
}

bool AltroNomeStessaIniziale(char* alunni[], int* curr, int curr_size, int pos_alunno1) {
	char* alunno1 = alunni[pos_alunno1];
	char iniziale1 = alunno1[0];
	for (int i = 0; i < curr_size; ++i) {
		int pos_alunno2 = curr[i];
		char* alunno2 = alunni[pos_alunno2];
		char iniziale2 = alunno2[0];
		if (pos_alunno2 != pos_alunno1 && iniziale1 == iniziale2) {
			return true;
		}
	}
	return false;
}

bool AltroNomeConsecutivo(char* alunni[], int* curr, int curr_size, int pos_alunno1) {
	char* alunno1 = alunni[pos_alunno1];
	char iniziale1 = alunno1[0];
	for (int i = 0; i < curr_size; ++i) {
		int pos_alunno2 = curr[i];
		char* alunno2 = alunni[pos_alunno2];
		char iniziale2 = alunno2[0];
		if (pos_alunno2 != pos_alunno1 && (iniziale2 == iniziale1 + 1 || iniziale1 == iniziale2 + 1)) {
			return true;
		}
	}
	return false;
}

bool IsSolution(char* alunni[], int* curr, int curr_size) {
	for (int i = 0; i < curr_size; ++i) {
		if (AltroNomeStessaIniziale(alunni, curr, curr_size, curr[i])) {
			return false;
		}
		if (AltroNomeConsecutivo(alunni, curr, curr_size, curr[i])) {
			return false;
		}
	}
	return true;
}

void GruppiRec(char* alunni[], int* curr, bool* usati, int n, int n_alunni, int* nsol, int i) {
	if (i == n) {
		if (IsSolution(alunni, curr, n)) {
			PrintSolution(alunni, curr, n);
			++(*nsol);
		}
		return;
	}
	for (int j = 0; j < n_alunni; ++j) {
		if (!usati[j]) {
			curr[i] = j;
			usati[j] = true;
			GruppiRec(alunni, curr, usati, n, n_alunni, nsol, i + 1);
			usati[j] = false;
		}
	}
}

int Gruppi(const char* filename, int n) {
	FILE* f = fopen(filename, "r");
	if (f == NULL || feof(f)) {
		return 0;
	}
	int nsol = 0, n_alunni = 0;
	char** alunni = NULL;
	while (1) {
		alunni = realloc(alunni, (n_alunni + 1) * sizeof(char*));
		alunni[n_alunni] = calloc(21, sizeof(char));
		int ris = fscanf(f, "%20s", alunni[n_alunni]);
		if (ris != 1) {
			break;
		}
		++n_alunni;
	}
	alunni = realloc(alunni, n_alunni * sizeof(char*));
	if (n > n_alunni || n < 1) {
		return 0;
	}
	int* curr = malloc(n_alunni * sizeof(int));
	bool* usati = calloc(n_alunni, sizeof(bool));
	GruppiRec(alunni, curr, usati, n, n_alunni, &nsol, 0);
	LiberaMemoria(alunni, n_alunni, curr, usati);
	return nsol;
}