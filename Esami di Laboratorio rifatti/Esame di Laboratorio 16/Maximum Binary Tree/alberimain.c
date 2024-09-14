#include "tree.h"

extern Node* CreateMaxBinTree(const ElemType* v, size_t v_size);

int main(void) {
	ElemType v[] = { 3, 2, 1, 6, 0, 5 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	Node* t = CreateMaxBinTree(v, v_size);
	TreeWriteStdoutPostOrder(t);
	TreeDelete(t);
	return 0;
}