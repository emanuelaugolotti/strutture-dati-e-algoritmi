#include "minheap.h"
#include <stdlib.h>
#include <string.h>

Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	Heap* out = HeapCreateEmpty();
	out->size = h1->size + h2->size;
	out->data = malloc(out->size * sizeof(ElemType));
	memcpy(out->data, h1->data, h1->size * sizeof(ElemType));
	memcpy((out->data) + h1->size, h2->data, h2->size * sizeof(ElemType));

	for (int i = (int)out->size / 2 - 1; i >= 0; --i) {
		HeapMinMoveDown(out, i);
	}
	
	return out;
}