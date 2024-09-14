//Time: 1h 06min
#include "tree.h"
#include <stdlib.h>

ElemType GetMax(const ElemType* v, int start, int stop, int* max_pos) {
	ElemType max = v[start];
	*max_pos = start;
	for (int i = start; i <= stop; ++i) {
		if (ElemCompare(v + i, v + *max_pos) > 0) {
			max = v[i];
			*max_pos = i;
		}
	}
	return max;
}

Node* CreateMaxBinTreeRec(const ElemType* v, int start, int stop) {
	if (start == stop) {
		return TreeCreateRoot(&v[start], NULL, NULL);
	}
	if (start > stop) {
		return TreeCreateEmpty();
	}
	
	int max_pos, new_start, new_stop;
	ElemType root = GetMax(v, start, stop, &max_pos);
	
	new_start = start;
	new_stop = max_pos - 1;
	Node* l = CreateMaxBinTreeRec(v, new_start, new_stop);
	
	new_start = max_pos + 1;
	new_stop = stop;
	Node* r = CreateMaxBinTreeRec(v,new_start, new_stop);
	
	Node* out = TreeCreateRoot(&root, l, r);
	return out;
}

Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return TreeCreateEmpty();
	}
	Node* out = CreateMaxBinTreeRec(v, 0, (int)v_size - 1);
	return out;
}