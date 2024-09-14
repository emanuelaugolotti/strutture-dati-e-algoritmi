#include <stdio.h>

extern int Parentesi(int n);

int main(void) {
	int ris = Parentesi(0);
	printf("Numero soluzioni: %i", ris);
	
	return 0;
}