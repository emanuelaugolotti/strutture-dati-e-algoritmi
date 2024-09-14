#include "minheap.h"
#include <stdlib.h>

int Pop(Heap* h) {
	int min = h->data[0];
	h->data[0] = h->data[h->size - 1];
	--(h->size);
	HeapMinMoveDown(h, 0);
	return min;
}

int KthLeast(const int* v, size_t n, int k) {
	Heap* h = HeapCreateEmpty();
	for (size_t i = 0; i < n; ++i) {
		HeapMinInsertNode(h, v + i);
	}
	int kth_min;
	for (int i = 0; i < k; ++i) {
		kth_min = Pop(h);
	}
	HeapDelete(h);
	return kth_min;
}