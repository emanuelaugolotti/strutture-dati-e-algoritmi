#include "minheap.h"
#include <stdlib.h>

void Push(Heap* h, const ElemType* e) {
	h->data = realloc(h->data, (h->size + 1) * sizeof(ElemType));
	++(h->size);
	h->data[h->size - 1] = ElemCopy(e);
	HeapMinMoveUp(h, (int)h->size - 1);
}