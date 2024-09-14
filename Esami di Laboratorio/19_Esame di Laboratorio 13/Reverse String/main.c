#include <stdlib.h>

extern char* ReverseString(const char* str);

int main(void) {
	char* ris = ReverseString("stringa da invertire");
	free(ris);
	return 0;
}