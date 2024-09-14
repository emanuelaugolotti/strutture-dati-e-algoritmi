#include <stdlib.h>

extern int OptimalSubarray(const int* v, size_t n);

int main(void) {
	int v[] = { 1, 2, 1, -100, 5, 6 };
	size_t v_size = sizeof(v) / sizeof(int);
	int ris = OptimalSubarray(v, v_size);
	return 0;
}