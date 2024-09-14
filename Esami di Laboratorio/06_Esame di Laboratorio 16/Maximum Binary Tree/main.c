#include "tree.h"
#include <stdlib.h>
#include <crtdbg.h>

extern Node* CreateMaxBinTree(const ElemType* v, size_t v_size);

int main(void) {
	ElemType v1[] = { 3,2,1,6,0,5 };
	size_t v1_size = sizeof(v1) / sizeof(ElemType);

	Node* t1 = CreateMaxBinTree(v1, v1_size);
	TreeWriteStdoutPostOrder(t1);
	
	ElemType v2[] = { 3,2,1 };
	size_t v2_size = sizeof(v2) / sizeof(ElemType);

	Node* t2 = CreateMaxBinTree(v2, v2_size);
	TreeWriteStdoutPostOrder(t2);

	TreeDelete(t1);
	TreeDelete(t2);
	_CrtDumpMemoryLeaks();
	return 0;
}