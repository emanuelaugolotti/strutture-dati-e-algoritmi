#include <stdlib.h>

extern void PancakeSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 5, 2, 9, 1, 7, 3, 8, 6, 4 };
	size_t v_size = sizeof(v) / sizeof(int);
	PancakeSort(v, v_size);
	return 0;
}