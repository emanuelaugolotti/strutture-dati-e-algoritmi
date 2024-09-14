//Time: 34 min
#include "minheap.h"
#include <string.h>
#include <stdlib.h>

int KthLeast(const int* v, size_t n, int k) {
	Heap* h = HeapCreateEmpty();
	for (size_t i = 0; i < n; ++i) {
		HeapMinInsertNode(h, v + i);
	}
	int min;
	for (int i = 0; i < k; ++i) {
		min = h->data[0];
		h->data[0] = h->data[h->size - 1];
		--h->size;
		HeapMinMoveDown(h, 0);
	}
	h->size = n;
	HeapDelete(h);
	return min;
}