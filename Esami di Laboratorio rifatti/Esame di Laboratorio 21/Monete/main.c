#include <stdlib.h>

extern int CombinaMonete(int b, const int* m, size_t m_size);

int main(void) {
	int b = 90;
	int	m[] = { 2, 50, 10, 5, 20 };
	size_t m_size = sizeof(m) / sizeof(int);
	int ris = CombinaMonete(b, m, m_size);
	return 0;
}