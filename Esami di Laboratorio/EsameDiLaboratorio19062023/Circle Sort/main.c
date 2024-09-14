#include <stdlib.h>
#include <stdbool.h>

extern void CircleSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 3, 1, -1, 5 };
	size_t v_size = sizeof(v) / sizeof(int);
	CircleSort(v, v_size);
	return 0;
}