#include "minheap.h"
#include <stdlib.h>
#include <string.h>

ElemType KthLeast(const Heap* h, int k) {
    Heap* tmp = malloc(sizeof(Heap));
    tmp->size = h->size;
    tmp->data = malloc(tmp->size * sizeof(ElemType));
    memcpy(tmp->data, h->data, tmp->size * sizeof(ElemType));
    ElemType kthmin;
    for (int i = 0; i < k; ++i) {
        kthmin = tmp->data[0];
        tmp->data[0] = tmp->data[tmp->size - 1];
        --(tmp->size);
        tmp->data = realloc(tmp->data, tmp->size * sizeof(ElemType));
        HeapMinMoveDown(tmp, 0);
    }
    HeapDelete(tmp);
    return kthmin;
}