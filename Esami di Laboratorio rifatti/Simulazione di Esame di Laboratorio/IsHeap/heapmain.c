#include "minheap.h"

extern bool IsHeap(const Heap* h);

int main(void) {
    /*ElemType v[] = { 1, 3, 4, 21, 2, 5, 18, 77, 8, -1 };*/
    /*ElemType v[] = { 23, 16, 17, 12, 8, 10, 15, 9, 3, 2 };*/
    ElemType v[] = { 0 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    
    Heap* h = HeapCreateEmpty();
    h->data = v;
    h->size = 1;
    /*for (unsigned i = 0; i < v_size; ++i) {
        HeapMinInsertNode(h, &v[i]);
    }*/
	
    bool ris = IsHeap(h);

	HeapDelete(h);
	return 0;
}