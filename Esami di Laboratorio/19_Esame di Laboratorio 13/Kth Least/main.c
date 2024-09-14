#include "minheap.h"
#include <crtdbg.h>

extern ElemType KthLeast(const Heap* h, int k);

int main(void) {
    ElemType v[] = { 0, 12, 4, 21, 2, 5, 18, 77, 8, -1 };
    size_t v_size = sizeof(v) / sizeof(ElemType);

    Heap* h = HeapCreateEmpty();
    for (unsigned i = 0; i < v_size; ++i) {
        HeapMinInsertNode(h, &v[i]);
    }
    HeapWriteStdout(h);

    Heap* ris = KthLeast(h, 5);

    HeapDelete(h);
    _CrtDumpMemoryLeaks();
	return 0;
}