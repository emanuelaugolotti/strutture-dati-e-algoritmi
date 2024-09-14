#include <stdlib.h>

extern void BrickSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 5, 9, -1, 3, 8, 2, 4, 7 };
	size_t v_size = sizeof(v) / sizeof(int);
	BrickSort(v, v_size);
	return 0;
}