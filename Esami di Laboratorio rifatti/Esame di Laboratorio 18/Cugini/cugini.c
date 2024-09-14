//Time: 17 min
#include "tree.h"

void GetLevelParent(const Node* t, int val, int* level, int i, const Node** p, const Node* p_curr) {
	if (TreeIsEmpty(t)) {
		return;
	}
	const ElemType* e = TreeGetRootValue(t);
	if (ElemCompare(e, &val) == 0) {
		*level = i;
		*p = p_curr;
	}
	p_curr = t;
	GetLevelParent(TreeLeft(t), val, level, i + 1, p, p_curr);
	GetLevelParent(TreeRight(t), val, level, i + 1, p, p_curr);
}

bool Cugini(const Node* t, int a, int b) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	int a_level, b_level;
	const Node* a_parent = TreeCreateEmpty();
	const Node* b_parent = TreeCreateEmpty();
	GetLevelParent(t, a, &a_level, 0, &a_parent, TreeCreateEmpty());
	GetLevelParent(t, b, &b_level, 0, &b_parent, TreeCreateEmpty());
	if (a_level == b_level && a_parent != b_parent) {
		return true;
	}
	return false;
}