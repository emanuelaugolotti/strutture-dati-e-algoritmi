//https://github.com/lee-hen/Algoexpert/tree/master/very_hard/34_longest_balanced_substring
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void PrintSolution(char* curr, size_t curr_size) {
	for (size_t i = 0; i < curr_size; ++i) {
		printf("%c", curr[i]);
	}
	printf("\n");
}

bool IsSolution(const char* str, char* curr, size_t curr_size, size_t len) {
	size_t aperte = 0, chiuse = 0;
	for (size_t i = 0; i < curr_size; ++i) {
		if (curr[i] == '(') {
			++aperte;
		} else {
			++chiuse;
		}
		if (chiuse > aperte) {
			return false;
		}
	}
	if (aperte != chiuse) {
		return false;
	}
	if (strstr(str, curr) != NULL) {
		return true;
	}
	return false;
}

bool Prendo(char c, size_t aperte, size_t chiuse, bool* is_aperta, size_t i, char prec_curr, char prec_str) {
	if (i > 0 && prec_curr != prec_str) {
		return false;
	}
	if (c == '(') {
		++aperte;
		*is_aperta = true;
	} else {
		++chiuse;
		*is_aperta = false;
	}
	if (aperte >= chiuse) {
		return true;
	}
	return false;
}

void LongestBalancedSubstringRec(const char* str, size_t len, char* curr, size_t curr_size, char* best, 
		 size_t* best_size, size_t i, size_t aperte, size_t chiuse) {
	if (i == len) {
		if (IsSolution(str, curr, curr_size, len)) {
			/*PrintSolution(curr, curr_size);*/
			if (*best_size < curr_size) {
				*best_size = curr_size;
				memcpy(best, curr, curr_size * sizeof(char));
			}
		}
		return;
	}
	for (size_t j = i; j < len; ++j) {
		bool is_aperta;
		if (Prendo(str[j], aperte, chiuse, &is_aperta, i, curr[curr_size - 1], str[j - 1])) {
			curr[curr_size] = str[j];
			++curr_size;
			if (is_aperta) {
				++aperte;
			} else {
				++chiuse;
			}
			LongestBalancedSubstringRec(str, len, curr, curr_size, best, best_size, i + 1, aperte, chiuse);
			--curr_size;
			curr[curr_size] = 0;
			if (is_aperta) {
				--aperte;
			} else {
				--chiuse;
			}
		}
		
	}
	LongestBalancedSubstringRec(str, len, curr, curr_size, best, best_size, len, aperte, chiuse);
}

int LongestBalancedSubstring(const char* str) {
	if (str == NULL) {
		return 0;
	}
	size_t len = strlen(str);
	char* curr = calloc((len + 1), sizeof(char));
	char* best = calloc((len + 1), sizeof(char));
	size_t best_size = 0;
	LongestBalancedSubstringRec(str, len, curr, 0, best, &best_size, 0, 0, 0);
	printf("Soluzione Best: ");
	PrintSolution(best, best_size);
	printf("best size: %zi", best_size);
	free(curr);
	free(best);
	return (int)best_size;
}