//Time: 14 min
#include "minheap.h"
#include <stdlib.h>

bool Pop(Heap* h, ElemType* e) {
	if (h->size == 0) {
		return false;
	}
	*e = ElemCopy(h->data);
	h->data[0] = ElemCopy(h->data + (h-> size - 1));
	h->data = realloc(h->data, (h->size - 1) * sizeof(ElemType));
	--(h->size);
	HeapMinMoveDown(h, 0);
	return true;
}