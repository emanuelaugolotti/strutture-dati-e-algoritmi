//https://github.com/rdtsc/codeeval-problem-statements/tree/master/hard/171-dna-alignment#dna-alignment
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int GetScore(char* seq1, char* seq2, size_t len1, size_t len2, int* curr) {
	int score = 0;
	bool indelstart = true;
	for (int i = 0; i < (int)len1; ++i) {
		int pos = curr[i];
		if (pos < len2) {
			if (seq2[pos] == seq1[i]) {
				score += 3;
			} else {
				score -= 3;
			}
		} else {
			if (indelstart) {
				score -= 8;
				indelstart = false;
			} else {
				score -= 1;
			}
		}
	}
	return score;
}

bool IsSolution(char* seq2, size_t len1, size_t len2, int* curr) {
	char next = seq2[0];
	for (size_t i = 0; i < len1; ++i) {
		size_t pos = curr[i];
		if (i < len2 - 1) {
			if (seq2[pos] == next) {
				next = seq2[pos + 1];
			} else {
				return false;
			}
		}
	}
	return true;
}

void DnaAlignmenRec(char* seq1, char* seq2, size_t len1, size_t len2, int* curr, int* best, bool* usati, 
	int* scorebest, size_t i) {
	if (i == len1) {
		if (IsSolution(seq2, len1, len2, curr)) {
			int scorecurr = GetScore(seq1, seq2, len1, len2, curr);
			if (scorecurr > *scorebest) {
				*scorebest = scorecurr;
				memcpy(best, curr, len1 * sizeof(int));
			}
		}
		return;
	}
	for (int j = 0; j < (int)len1; ++j) {
		if (!usati[j]) {
			curr[i] = j;
			usati[j] = true;
			DnaAlignmenRec(seq1, seq2, len1, len2, curr, best, usati, scorebest, i + 1);
			usati[j] = false;
		}
	}
}

void DnaAlignment(const char* filename) {
	if (filename == NULL) {
		return;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL || feof(f)) {
		return;
	}
	char seq1[401] = { 0 };
	char seq2[401] = { 0 };
	while (1) {
		int ris = fscanf(f, "%s %*[|]%s", seq1, seq2);
		if (ris != 2) {
			break;
		}
		size_t len1 = strlen(seq1);
		size_t len2 = strlen(seq2);
		int* curr = malloc(len1 * sizeof(int));
		int* best = malloc(len1 * sizeof(int));
		bool* usati = calloc(len1, sizeof(bool));
		int scorebest = INT_MIN;
		DnaAlignmenRec(seq1, seq2, len1, len2, curr, best, usati, &scorebest, 0);
		printf("%i\n", scorebest);
		free(curr);
		free(best);
		free(usati);
	}
}