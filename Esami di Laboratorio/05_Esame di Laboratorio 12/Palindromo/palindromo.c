//Time: 21min
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool IsPalindromoRec(const char* str, size_t start1, size_t start2, size_t* stop) {
	if ((start1 == *stop && start2 == *stop) || start1 > start2) {
		return true;
	}
	if (str[start1] != str[start2]) {
		return false;
	}
	return IsPalindromoRec(str, start1 + 1, start2 - 1, stop);
}

bool IsPalindromo(const char* str) {
	if (str == NULL) {
		return false;
	}
	size_t stop = strlen(str) / 2;
	size_t len = strlen(str);
	if (len == 0) {
		return true;
	}
	return IsPalindromoRec(str, 0, len - 1, &stop);
}