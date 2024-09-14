#include <stdlib.h>
#include <stdio.h>

extern char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size);

int main(void) {
	int f[] = { 1, 6, 2, 14, 5, 17, 4 };
	size_t f_size = sizeof(f) / sizeof(int);
	size_t ret_size;

	char* ris = GuidaLaPulce(f, f_size, 16, 9, 5, 7, &ret_size);

	free(ris);
	return 0;
}