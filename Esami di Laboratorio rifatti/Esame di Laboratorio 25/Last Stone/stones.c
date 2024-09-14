//Time: 30 min
#include "maxheap.h"
#include <stdlib.h>

//ritorna (tramite il parametro di output popped) il nodo del valore massimo dopo averlo rimosso dall'heap.
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

void Scontro2Pietre(ElemType y, ElemType x, ElemType* peso_doposcontro, Heap* h) {
    if (x == y) {
        *peso_doposcontro = 0;
    } else {
        *peso_doposcontro = y - x;
        h->data = realloc(h->data, (h->size + 1) * sizeof(ElemType));
        ++(h->size);
        h->data[h->size - 1] = *peso_doposcontro;
        HeapMaxMoveUp(h, (int)h->size - 1);
    }
}

int LastStoneWeight(Heap* h) {
    ElemType peso_doposcontro = h->data[0];
    while (h->size > 1) {
        ElemType y, x;
        Pop(h, &y);
        Pop(h, &x);
        Scontro2Pietre(y, x, &peso_doposcontro, h);
    }
    return peso_doposcontro;
}