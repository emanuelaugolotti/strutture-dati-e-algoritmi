//Time: 23 min
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
	if (ropes->size == 0) {
		return 0;
	}
	ElemType costototale_unione = 0;
	while (ropes->size > 1) {
		ElemType min1 = Pop(ropes);
		ElemType min2 = Pop(ropes);
		ElemType costo_unione = min1 + min2;
		costototale_unione += costo_unione;
		HeapMinInsertNode(ropes, &costo_unione);
	}
	return costototale_unione;
}