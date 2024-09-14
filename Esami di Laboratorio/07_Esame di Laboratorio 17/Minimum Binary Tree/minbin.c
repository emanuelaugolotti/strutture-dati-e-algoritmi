//Time: 26 min
#include "tree.h"
#include <stdlib.h>

 size_t GetMinPos(const ElemType* v, int start, int stop) {
	int minpos = start;
	for (int i = start; i <= stop; ++i) {
		if (ElemCompare(v + i, v + minpos) < 0) {
			minpos = i;
		}
	}
	return minpos;
}

Node* CreateMinBinTreeRec(const ElemType* v, int start, int stop) {
	if (start > stop) {
		return TreeCreateEmpty();
	}
	if (start == stop) {
		return TreeCreateRoot(v + start, NULL, NULL);
	}

	int minpos = GetMinPos(v, start, stop);
	Node* l = CreateMinBinTreeRec(v, start, minpos - 1);
	Node* r = CreateMinBinTreeRec(v, minpos + 1, stop);
	return TreeCreateRoot(v + minpos, l, r);
}

Node* CreateMinBinTree(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return TreeCreateEmpty();
	}
	return CreateMinBinTreeRec(v, 0, (int)v_size - 1);
}