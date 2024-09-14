#include <stdlib.h>
#include <math.h>
#include <string.h>

int AToIRec(const char* str, int pos, int exp) {
	if (pos < 0) {
		return 0;
	}
	int new_cifra = (str[pos] - '0') * (int)pow(10, exp);
	int n = new_cifra + AToIRec(str, pos - 1, exp + 1);
	return n;
}

int AToI(const char* str) {
	if (str == NULL) {
		return 0;
	}
	size_t len = strlen(str);
	int n = AToIRec(str, (int)len - 1, 0);
	return n;
}