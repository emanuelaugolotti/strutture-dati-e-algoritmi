#include <stdlib.h>

extern void InsertionSort(int* v, size_t v_size);

int main(void) {

	int v[] = { 5, 3, 7, 9, 8, 1 };
	size_t v_size = sizeof(v) / sizeof(int);

	InsertionSort(v, v_size);

	return 0;
}