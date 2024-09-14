#include <stdlib.h>
#include <string.h>

void ReverseStringRec(const char* str, size_t len, char* out, size_t i) {
	if (i == len) {
		return;
	}
	out[i] = str[len - i - 1];
	ReverseStringRec(str, len, out, i + 1);
}

char* ReverseString(const char* str) {
	if (str == NULL) {
		return NULL;
	}
	size_t len = strlen(str);
	char* out = calloc(len + 1, sizeof(char));
	ReverseStringRec(str, len, out, 0);
	return out;
}