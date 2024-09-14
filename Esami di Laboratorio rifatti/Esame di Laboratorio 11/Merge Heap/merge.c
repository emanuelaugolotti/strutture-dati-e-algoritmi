#include "minheap.h"
#include <stdlib.h>
#include <string.h>

Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	Heap* out = HeapCreateEmpty();
	out->size = h1->size;
	out->data = malloc(out->size * sizeof(ElemType));
	memcpy(out->data, h1->data, out->size * sizeof(ElemType));
	for (size_t i = 0; i < h2->size; ++i) {
		HeapMinInsertNode(out, h2->data + i);
	}
	return out;
}