#include "minheap.h"

extern bool Pop(Heap* h, ElemType* e);

int main(void) {
    ElemType v[] = { 0, 12, 4, 21, 2, -1, 5, 18, 77, 8 };
    /*ElemType v[] = { 23, 16, 17, 12, 8, 10, 15, 9, 3, 2 };*/
    size_t v_size = sizeof(v) / sizeof(ElemType);
    
    Heap* h = HeapCreateEmpty();
    for (unsigned i = 0; i < v_size; ++i) {
        HeapMinInsertNode(h, &v[i]);
    }
    HeapWriteStdout(h);

    ElemType e;
    bool ris = Pop(h, &e);
    HeapWriteStdout(h);
	
	HeapDelete(h);
	return 0;
}