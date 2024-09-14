#include "minheap.h"
#include <stdlib.h>
#include <string.h>

Heap* Heapify(const int* v, size_t n) {
	Heap* h = HeapCreateEmpty();
	h->size = n;
	h->data = malloc(h->size * sizeof(ElemType));
	memcpy(h->data, v, h->size * sizeof(ElemType));
	for (int i = (int)h->size / 2 - 1; i >= 0; --i) {
		HeapMinMoveDown(h, i);
	}
	return h;
}

int KthLeast(const int* v, size_t n, int k) {
	Heap* h = Heapify(v, n);
	int min;
	for (int i = 0; i < k; ++i) {
		min = h->data[0];
		h->data[0] = ElemCopy(h->data + (h->size - 1));
		--(h->size);
		HeapMinMoveDown(h, 0);
	}
	HeapDelete(h);
	return min;
}