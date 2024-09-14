#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool IsPalindromoRec(const char* str, int start, int stop) {
	if (start >= stop) {
		return true;
	}
	if (str[start] != str[stop]) {
		return false;
	}
	return IsPalindromoRec(str, start + 1, stop - 1);
}

bool IsPalindromo(const char* str) {
	if (str == NULL) {
		return false;
	}
	size_t len = strlen(str);
	if (len == 0) {
		return true;
	}
	bool ris = IsPalindromoRec(str, 0, (int)len - 1);
	return ris;
}