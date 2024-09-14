#include "minheap.h"

extern size_t ConnectRopes(Heap* ropes);

int main(void) {
    // Min Heap
    ElemType v[] = { 1, 3, 4, 4, 6 };
    //ElemType v[] = { 23, 16, 17, 12, 8, 10, 15, 9, 3, 2 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Heap* h = HeapCreateEmpty();
    for (unsigned i = 0; i < v_size; ++i) {
        HeapMinInsertNode(h, &v[i]);
    }

    size_t ris = ConnectRopes(h);
	
	HeapDelete(h);
	return 0;
}