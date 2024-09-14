#include <stdlib.h>

extern void CircleSort(int* v, size_t v_size);

int main(void) {
	int v[] = {3, 4, 1, 11, -1, 5, 2};
	size_t v_size = sizeof(v) / sizeof(int);
	CircleSort(v, v_size);
	return 0;
}