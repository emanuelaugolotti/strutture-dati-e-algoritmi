#include "minheap.h"

extern Heap* MergeHeap(const Heap* h1, const Heap* h2);

int main(void) {
    ElemType v1[] = { 0, 1, 2, 3 };
    size_t v1_size = sizeof(v1) / sizeof(ElemType);
    
    Heap* h1 = HeapCreateEmpty();
    for (unsigned i = 0; i < v1_size; ++i) {
        HeapMinInsertNode(h1, &v1[i]);
    }
    HeapWriteStdout(h1);

    ElemType v[] = { 4, 5, 6, 7, 8 };
    size_t v_size = sizeof(v) / sizeof(ElemType);

    Heap* h2 = HeapCreateEmpty();
    for (unsigned i = 0; i < v_size; ++i) {
        HeapMinInsertNode(h2, &v[i]);
    }
    HeapWriteStdout(h2);

    Heap* ris = MergeHeap(h1, h2);
    /*Heap* ris = MergeHeap(HeapCreateEmpty(), HeapCreateEmpty());*/
    HeapWriteStdout(ris);
	
	HeapDelete(h1);
	HeapDelete(h2);
	HeapDelete(ris);
	return 0;
}