#include <stdlib.h>
#include <stdio.h>

extern int CombinaMonete(int b, const int* m, size_t m_size);

int main(void) {
	int b = 4;
	int	m[] = { 1, 2, 50, 10, 5, 20 };
	size_t m_size = sizeof(m) / sizeof(int);

	int ris = CombinaMonete(b, m, m_size);
	printf("numero soluzioni = %i", ris);
	
	return 0;
}