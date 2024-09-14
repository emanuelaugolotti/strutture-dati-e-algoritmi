#include <stdbool.h>
#include <stdlib.h>

extern bool IsPalindromo(const char* str);

int main(void) {

	bool ris;
	ris = IsPalindromo("ossesso");
	ris = IsPalindromo("anna");
	ris = IsPalindromo("osso");
	ris = IsPalindromo("scott");
	ris = IsPalindromo("");
	
	return 0;
}