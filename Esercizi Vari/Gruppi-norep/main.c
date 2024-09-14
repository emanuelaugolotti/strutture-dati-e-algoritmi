#include <stdio.h>

extern int Gruppi(const char* filename, int n);

int main(void) {
	
	int ris = Gruppi("nomi_02.txt", 3);
	printf("s = %i", ris);
	return 0;
}