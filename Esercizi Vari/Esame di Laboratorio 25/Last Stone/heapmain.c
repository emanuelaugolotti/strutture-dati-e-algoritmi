#include "maxheap.h"

extern int LastStoneWeight(Heap* h);

int main(void) {
 
    //Max Heap
    ElemType v[] = { 21, 18, 77 };
    //ElemType v[] = { 23, 16, 17, 12, 8, 10, 15, 9, 3, 2 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Heap* h = HeapCreateEmpty();
    for (unsigned i = 0; i < v_size; ++i) {
        HeapMaxInsertNode(h, &v[i]);
    }

    int ris = LastStoneWeight(h);
	
	HeapDelete(h);
	return 0;
}