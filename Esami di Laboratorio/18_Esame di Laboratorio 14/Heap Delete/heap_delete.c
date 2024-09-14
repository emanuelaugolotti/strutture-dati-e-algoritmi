#include "minheap.h"
#include <stdlib.h>

void Swap(ElemType* v, size_t pos1, size_t pos2) {
	ElemType tmp = v[pos1];
	v[pos1] = v[pos2];
	v[pos2] = tmp;
}

void HeapDeleteNode(Heap* h, int k) {
	if (HeapIsEmpty(h)) {
		return;
	}
	if (k < 0 || k >= (int)h->size) {
		return;
	}
	size_t pos1 = k;
	size_t pos2 = h->size - 1;
	Swap(h->data, pos1, pos2);
	--(h->size);
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, (int)pos1);
}