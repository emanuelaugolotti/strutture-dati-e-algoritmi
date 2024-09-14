//Time: 14 min
#include "maxheap.h"
#include <stdlib.h>

//ritorna (tramite il parametro di output popped) il nodo del valore massimo dopo averlo rimosso dall'heap
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

ElemType ScontroPietre(ElemType peso1, ElemType peso2) {
    ElemType ris;
    if (ElemCompare(&peso1,&peso2) == 0) {
        ris = 0;
    } else {
        ris = peso1 - peso2;
    }
    return ris;
}

int LastStoneWeight(Heap* h) {
    while (h->size > 1) {
        ElemType peso1, peso2;
        Pop(h, &peso1);
        Pop(h, &peso2);
        ElemType ris_scontro = ScontroPietre(peso1, peso2);
        if (ris_scontro != 0) {
            HeapMaxInsertNode(h, &ris_scontro);
        }
    }
    ElemType ris = 0;
    if (h->size == 1) {
        ris = h->data[0];
    }
    return ris;
}