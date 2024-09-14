//Time: 20 min
#include "tree.h"

size_t TrovaPosMin(const ElemType* v, int start, int stop, ElemType* min) {
	int posmin = start;
	*min = ElemCopy(v + posmin);
	for (int i = start; i <= stop; ++i) {
		if (ElemCompare(v + i, min) < 0) {
			posmin = i;
			*min = ElemCopy(v + i);
		}
	}
	return posmin;
}

Node* CreateMinBinTreeRec(const ElemType* v, int start, int stop) {
	if (start > stop) {
		return TreeCreateEmpty();
	}
	ElemType min;
	int posmin = TrovaPosMin(v, start, stop, &min);
	Node* l = CreateMinBinTreeRec(v, start, posmin - 1);
	Node* r = CreateMinBinTreeRec(v, posmin + 1, stop);
	Node* t = TreeCreateRoot(&min, l, r);
	return t;
}

Node* CreateMinBinTree(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return TreeCreateEmpty();
	}
	return CreateMinBinTreeRec(v, 0, (int)v_size - 1);
}