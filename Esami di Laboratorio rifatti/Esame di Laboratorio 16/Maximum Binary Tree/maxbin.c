#include "tree.h"

int GetIndexMax(const ElemType* v, int start, int stop) {
	int posmax = start;
	ElemType max = v[posmax];
	for (int i = start; i <= stop; ++i) {
		if (ElemCompare(&max, v + i) < 0) {
			posmax = i;
			max = v[i];
		}
	}
	return posmax;
}

Node* CreateMaxBinTreeRec(const ElemType* v, int start, int stop) {
	if (start > stop) {
		return TreeCreateEmpty();
	}
	int posmax = GetIndexMax(v, start, stop);
	ElemType max = v[posmax];
	Node* l = CreateMaxBinTreeRec(v, start, posmax - 1);
	Node* r = CreateMaxBinTreeRec(v, posmax + 1, stop);
	Node* t = TreeCreateRoot(&max, l, r);
	return t;
}

Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return TreeCreateEmpty();
	}
	return CreateMaxBinTreeRec(v, 0, (int)v_size - 1);
}