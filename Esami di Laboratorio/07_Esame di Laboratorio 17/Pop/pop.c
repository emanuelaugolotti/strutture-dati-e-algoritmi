//Time: 22min
#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>

bool Pop(Heap* h, ElemType* e) {
	if (HeapIsEmpty(h) || e == NULL) {
		return false;
	}
	*e = ElemCopy(HeapGetNodeValue(h, 0));
	ElemDelete(h->data + (h->size - 1));
	--(h->size);
	HeapMinMoveDown(h, 0);
	return true;
}