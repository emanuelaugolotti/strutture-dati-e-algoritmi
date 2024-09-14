#include <stdio.h>

extern int Parentesi(int n);

int main(void) {
	int ris = Parentesi(3);
	printf("s = %i", ris);
	return 0;
}