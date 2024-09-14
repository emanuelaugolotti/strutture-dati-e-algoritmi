#include <stdlib.h>

extern int BinarySearch(const int* v, size_t v_size, int value);

int main(void) {
	int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	size_t v_size = sizeof(v) / sizeof(int);

	int pos = BinarySearch(v, v_size, 0);

	return 0;
}