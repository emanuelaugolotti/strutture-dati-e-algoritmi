#include <stdlib.h>

extern char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size);

int main(void) {
	size_t ret_size1, ret_size2;
	
	int f1[] = { 12, 4, 7, 1, 15 };
	size_t f1_size = sizeof(f1) / sizeof(int);
	char* ris1 = GuidaLaPulce(f1, f1_size, 3, 15, 5, 9, &ret_size1);

	int f2[] = { 12, 4, 7, 1, 15 };
	size_t f2_size = sizeof(f1) / sizeof(int);
	char* ris2 = GuidaLaPulce(f1, f1_size, 3, 15, 2, 9, &ret_size2);

	free(ris1);
	free(ris2);
	return 0;
}