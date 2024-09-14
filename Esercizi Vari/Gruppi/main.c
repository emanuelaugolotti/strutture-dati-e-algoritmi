#include <stdio.h>

extern int Gruppi(const char* filename, int n);

int main(void) {
	
	int ris = Gruppi("nomi_03.txt", 2);
	printf("s = %i", ris);
	return 0;
}