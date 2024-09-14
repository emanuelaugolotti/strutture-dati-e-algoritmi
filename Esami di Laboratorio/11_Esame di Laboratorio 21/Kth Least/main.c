#include "minheap.h"

extern int KthLeast(const int* v, size_t n, int k);

int main(void) {
	int v[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };
	size_t v_size = sizeof(v) / sizeof(int);

	int kthmin = KthLeast(v, v_size, 6);
	return 0;
}