#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

bool IsNode(const Node* t, int val) {
	const ElemType* value = TreeGetRootValue(t);
	if (ElemCompare(value, &val) == 0) {
		return true;
	}
	return false;
}

void SearchNode(const Node* t, int val, const Node** p, const Node** p_curr, int* i_val, int i) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (IsNode(t, val)) {
		*i_val = i;
		*p = *p_curr;
	}
	p_curr = &t;
	SearchNode(TreeLeft(t), val, p, p_curr, i_val, i + 1);
	SearchNode(TreeRight(t), val, p, p_curr, i_val, i + 1);
}

bool Cugini(const Node* t, int a, int b) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	const Node* pa = TreeCreateEmpty();
	const Node* pb = TreeCreateEmpty();
	int a_level;
	int b_level;
	SearchNode(t, a, &pa, &t, &a_level, 0);
	SearchNode(t, b, &pb, &t, &b_level, 0);
	if (a_level == b_level && pa != pb) {
		return true;
	}
	return false;
}