//Time: 21 min
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void PrintSol(char* curr) {
	printf("%s\n", curr);
}

void PasswordRec(const char* str, int* nsol, char* curr, int n, int len, int i) {
	if (i == n) {
		PrintSol(curr);
		++(*nsol);
		return;
	}
	for (int j = 0; j < len; ++j) {
		char c = str[j];
		curr[i] = c;
		PasswordRec(str, nsol, curr, n, len, i + 1);
	}
}

int Password(const char* str, int n) {
	if (str == NULL) {
		return 0;
	}
	int len = (int)strlen(str);
	if (len == 0) {
		return 0;
	}
	int nsol = 0;
	char* curr = calloc((n + 1), sizeof(char));
	PasswordRec(str, &nsol, curr, n, len, 0);
	free(curr);
	return nsol;
}