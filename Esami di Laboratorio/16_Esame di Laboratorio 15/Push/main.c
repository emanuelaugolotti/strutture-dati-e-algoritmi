#include "minheap.h"
#include <string.h>
#include <stdlib.h>

extern void Push(Heap* h, const ElemType* e);

Heap* HeapCreateFromVector(ElemType* v, size_t v_size) {
	Heap* h = HeapCreateEmpty();
	h->size = v_size;
	h->data = malloc(h->size * sizeof(ElemType));
	memcpy(h->data, v, h->size * sizeof(ElemType));
	for (int i = (int)(h->size / 2) - 1; i >= 0; --i) {
		HeapMinMoveDown(h, i);
	}
	return h;
}
int main(void) {
	ElemType v[] = { 1, 2, 4, 6, 12, 23 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	Heap* h = HeapCreateFromVector(v, v_size);
	HeapWriteStdout(h);

	ElemType e = 3;
	Push(h, &e);
	HeapWriteStdout(h);

	HeapDelete(h);
	return 0;
}