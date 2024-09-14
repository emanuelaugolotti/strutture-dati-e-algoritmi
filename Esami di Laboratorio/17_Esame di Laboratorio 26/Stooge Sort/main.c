#include <stdlib.h>

extern void Stooge(int* vector, size_t vector_size);

int main(void) {
	int v[] = { 3,8,1,5,7,2,4,6 };
	size_t v_size = sizeof(v) / sizeof(int);
	Stooge(v, v_size);
	return 0;
}