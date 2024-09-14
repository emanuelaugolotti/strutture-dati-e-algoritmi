//Time: 22min
#include "tree.h"
#include <stdbool.h>

bool TreeIsMirrorRec(Node* tl, Node* tr) {
	if (TreeIsEmpty(tl) && TreeIsEmpty(tr)) {
		return true;
	}
	if (TreeIsEmpty(tl) || TreeIsEmpty(tr)) {
		return false;
	}
	const ElemType* vl = TreeGetRootValue(tl);
	const ElemType* vr = TreeGetRootValue(tr);
	if (ElemCompare(vl, vr) != 0) {
		return false;
	}
	bool esterniismirror = TreeIsMirrorRec(TreeLeft(tl), TreeRight(tr));
	if (!esterniismirror) {
		return false;
	}
	bool interniismirror = TreeIsMirrorRec(TreeRight(tl), TreeLeft(tr));
	if (!interniismirror) {
		return false;
	}
	return true;
}

bool TreeIsMirror(Node* t) {
	if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
		return true;
	}
	return TreeIsMirrorRec(TreeLeft(t), TreeRight(t));
}