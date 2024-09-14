//Time: 23 min
#include "tree.h"

bool TreeIsMirrorRec(Node* t1, Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}
	const ElemType* val1 = TreeGetRootValue(t1);
	const ElemType* val2 = TreeGetRootValue(t2);
	bool ris1;
	if (ElemCompare(val1, val2) == 0) {
		ris1 = true;
	} else {
		ris1 = false;
	}
	bool ris2 = TreeIsMirrorRec(TreeLeft(t1), TreeRight(t2));
	bool ris3 = TreeIsMirrorRec(TreeRight(t1), TreeLeft(t2));
	return (ris1 && ris2 && ris3);
}

bool TreeIsMirror(Node* t) {
	if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
		return true;
	}
	bool is_mirror = TreeIsMirrorRec(TreeLeft(t), TreeRight(t));
	return is_mirror;
}