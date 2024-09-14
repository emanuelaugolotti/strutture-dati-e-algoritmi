//Time: 30 min
#define _CRT_SECURE_NO_WARNINGS
#include "maxheap.h"
#include <stdlib.h>

//Ritorna (tramite il parametro di output popped) il nodo del valore massimo dopo averlo rimosso dall'heap. 
//La Pop preserva le proprietà max-heap
void Pop(Heap* h, ElemType* popped) {
    if (h->size == 0) {
        popped = NULL;
        return;
    }
    *popped = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    h->data = realloc(h->data, sizeof(ElemType) * h->size);
    HeapMaxMoveDown(h, 0);
    return;
}

int LastStoneWeight(Heap* h) {
    if (h->size == 1) {
        return h->data[0];
    }
    int laststone;
    while (h->size > 1) {
        ElemType popped;
        Pop(h, &popped);
        ElemType y = popped;
        Pop(h, &popped);
        ElemType x = popped;
        laststone = y - x;
        if (laststone != 0) {
            h->data = realloc(h->data, (h->size + 1) * sizeof(ElemType));
            h->data[h->size] = laststone;
            ++(h->size);
            HeapMaxMoveUp(h, (int)h->size - 1);
        }
    }
	return laststone;
}