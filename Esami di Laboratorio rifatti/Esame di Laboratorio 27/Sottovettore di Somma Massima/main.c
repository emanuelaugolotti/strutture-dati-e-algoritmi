#include <stdlib.h>

extern int OptimalSubarray(const int* v, size_t n);

int main(void) {
	int v[] = { 1, 1, 1, -5, 1, 1, 1, -5, 1, 1, 1 };
	size_t v_size = sizeof(v) / sizeof(int);
	int ris = OptimalSubarray(v, v_size);
	return 0;
}