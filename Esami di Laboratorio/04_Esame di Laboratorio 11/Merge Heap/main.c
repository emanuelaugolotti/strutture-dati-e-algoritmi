#include "minheap.h"
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

extern Heap* MergeHeap(const Heap* h1, const Heap* h2);

Heap* HeapMinInsertHeapify(const ElemType* v, size_t v_size) {
	Heap* h = HeapCreateEmpty();
	h->size = v_size;
	h->data = malloc(h->size * sizeof(ElemType));
	memcpy(h->data, v, h->size * sizeof(ElemType));

	for (int i = (int)h->size / 2 - 1; i >= 0; --i) {
		HeapMinMoveDown(h, i);
	}
	return h;
}

int main(void) {

	ElemType h1[] = { 23, 16, 17, 12, 8, 10, 15, 9, 3, 2 };
	size_t h1_size = sizeof(h1) / sizeof(ElemType);
	Heap* heap1 = HeapMinInsertHeapify(h1, h1_size);
	HeapWriteStdout(heap1);
	
	ElemType h2[] = { 3, 5, 4, 7, 8, 20, 16, -1 };
	size_t h2_size = sizeof(h2) / sizeof(ElemType);
	Heap* heap2 = HeapMinInsertHeapify(h2, h2_size);
	HeapWriteStdout(heap2);

	Heap* res = MergeHeap(heap1, heap2);
	HeapWriteStdout(res);

	HeapDelete(heap1);
	HeapDelete(heap2);
	HeapDelete(res);

	_CrtDumpMemoryLeaks();
	return 0;
}