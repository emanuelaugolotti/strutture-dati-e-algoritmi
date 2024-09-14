#include "maxheap.h"
#include <stdlib.h>
#include <string.h>

extern int LastStoneWeight(Heap* h);

//Heap* Heapify(ElemType* v, size_t v_size) {
//	Heap* h = HeapCreateEmpty();
//	h->size = v_size;
//	h->data = malloc(h->size * sizeof(ElemType));
//	memcpy(h->data, v, h->size * sizeof(ElemType));
//	for (int i = (int)h->size / 2 - 1; i >= 0; --i) {
//		HeapMaxMoveDown(h, i);
//	}
//	return h;
//}

int main(void) {
	Heap* h = HeapCreateEmpty();
	h->size = 3;
	h->data = malloc(h->size * sizeof(ElemType));
	
	ElemType v[] = { 77, 21, 18 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	/*Heap* h = Heapify(v, v_size);*/

	memcpy(h->data, v, h->size * sizeof(ElemType));
	HeapWriteStdout(h);

	int ris = LastStoneWeight(h);

	HeapDelete(h);
	return 0;
}