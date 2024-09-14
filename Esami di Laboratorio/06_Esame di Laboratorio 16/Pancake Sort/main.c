#include <stdlib.h>

extern void PancakeSort(int* v, size_t v_size);

int main(void) {
	/*int v[] = { 3, 6, 1, 5 };*/
	int v[] = { 3 };
	size_t v_size = sizeof(v) / sizeof(int);

	PancakeSort(v, v_size);

	return 0;
}