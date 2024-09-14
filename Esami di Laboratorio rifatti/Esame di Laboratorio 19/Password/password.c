//Time: 13 min
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void StampaSol(char* curr, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%c", curr[i]);
	}
	printf("\n");
}

void PasswordRec(const char* str, size_t len, int n, char* curr, int* nsol, int i) {
	if (i == n) {
		StampaSol(curr, n);
		++(*nsol);
		return;
	}
	for (size_t j = 0; j < len; ++j) {
		curr[i] = str[j];
		PasswordRec(str, len, n, curr, nsol, i + 1);
	}
}

int Password(const char* str, int n) {
	if (str == NULL) {
		return 0;
	}
	size_t len = strlen(str);
	if (len == 0) {
		return 0;
	}
	int nsol = 0;
	char* curr = malloc(n * sizeof(char));
	PasswordRec(str, len, n, curr, &nsol, 0);
	free(curr);
	return nsol;
}