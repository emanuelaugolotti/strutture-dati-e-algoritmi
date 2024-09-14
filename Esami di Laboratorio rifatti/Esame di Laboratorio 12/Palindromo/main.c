#include <stdbool.h>
#include <stdlib.h>

extern bool IsPalindromo(const char* str);

int main(void) {
	bool ris = IsPalindromo("anna");
	ris = IsPalindromo("ossesso");
	ris = IsPalindromo("osso");
	ris = IsPalindromo("scott");
	return 0;
}