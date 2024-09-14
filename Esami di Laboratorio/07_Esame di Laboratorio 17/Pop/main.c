#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>
#include <crtdbg.h>

extern bool Pop(Heap* h, ElemType* e);

int main(void) {
    ElemType v[] = { 0, 12, 4, 21, 2, 5, 18, 77, 8, -1 };
    size_t v_size = sizeof(v) / sizeof(ElemType);

    Heap* h = HeapCreateEmpty();
    for (unsigned i = 0; i < v_size; ++i) {
        HeapMinInsertNode(h, &v[i]);
    }
    HeapWriteStdout(h);

    int e;
    bool ris = Pop(h, &e);
    HeapWriteStdout(h);
     
    HeapDelete(h);
    _CrtDumpMemoryLeaks();
    return 0;
}