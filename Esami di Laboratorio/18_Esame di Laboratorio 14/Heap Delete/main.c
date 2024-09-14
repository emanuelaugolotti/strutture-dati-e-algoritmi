#include "minheap.h"

extern void HeapDeleteNode(Heap* h, int k);

int main(void) {
	ElemType v[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	Heap* h = HeapCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		HeapMinInsertNode(h, v + i);
	}
	HeapWriteStdout(h);

	HeapDeleteNode(h, 4);	//elimino nodo 5
	HeapWriteStdout(h);

	HeapDelete(h);
	return 0;
}