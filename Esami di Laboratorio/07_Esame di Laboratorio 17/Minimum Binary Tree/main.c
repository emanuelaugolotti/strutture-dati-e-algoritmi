#include "tree.h"
#include <stdlib.h>

extern Node* CreateMinBinTree(const ElemType* v, size_t v_size);

int main(void) {
	ElemType v[] = { 3,2,1,6,8,5 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Node* t = CreateMinBinTree(v, v_size);
	TreeWriteStdoutPostOrder(t);

	TreeDelete(t);
	return 0;
}