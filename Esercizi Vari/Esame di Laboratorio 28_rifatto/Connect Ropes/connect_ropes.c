#include "minheap.h"
#include <stdlib.h>

ElemType Pop(Heap* h) {
	ElemType min = h->data[0];
	h->data[0] = h->data[h->size - 1];
	--(h->size);
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, 0);
	return min;
}

size_t ConnectRopes(Heap* ropes) {
	if (HeapIsEmpty(ropes)) {
		return 0;
	}
	size_t costo_out = 0;
	while (ropes->size > 1) {
		ElemType costo1 = Pop(ropes);
		ElemType costo2 = Pop(ropes);
		ElemType costotot = costo1 + costo2;
		costo_out += costotot;
		HeapMinInsertNode(ropes, &costotot);
	}
	return costo_out;
}