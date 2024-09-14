#include <stdlib.h>

extern void Stooge(int* vector, size_t vector_size);

int main(void) {
	int v[] = { 3, 6, 2, 4, 3, 1, 3, -1, 4 };
	size_t v_size = sizeof(v) / sizeof(int);
	Stooge(v, v_size);
	return 0;
}