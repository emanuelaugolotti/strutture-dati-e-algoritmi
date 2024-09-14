//Time: 37 min
#include "tree.h"

Node* InserisciInBst(Node* t, const ElemType* val) {
	Node* new = TreeCreateRoot(val, NULL, NULL);
	if (TreeIsEmpty(t)) {
		return new;
	}
	Node* tmp = t;
	while (!TreeIsEmpty(t)) {
		const ElemType* curr = TreeGetRootValue(t);
		if (ElemCompare(val, curr) <= 0) {
			if (TreeIsEmpty(TreeLeft(t))) {
				t->left = new;
				break;
			}
			t = TreeLeft(t);
		}
		else {
			if (TreeIsEmpty(TreeRight(t))) {
				t->right = new;
				break;
			}
			t = TreeRight(t);
		}
	}
	return tmp;
}

//Node* InserisciInBst(Node* t, const ElemType* val) {
//	if (TreeIsEmpty(t)) {
//		return TreeCreateRoot(val, NULL, NULL);
//	}
//	const ElemType* curr = TreeGetRootValue(t);
//	if (ElemCompare(val, curr) <= 0) {
//		Node* l = InserisciInBst(TreeLeft(t), val);
//		t->left = l;
//	} else {
//		Node* r = InserisciInBst(TreeRight(t), val);
//		t->right = r;
//	}
//	return t;
//}

void VisitInOrder(const Node* t, Node** out) {
	if (TreeIsEmpty(t)) {
		return;
	}
	VisitInOrder(TreeLeft(t), out);
	const ElemType* val = TreeGetRootValue(t);
	*out = InserisciInBst(*out, val);
	VisitInOrder(TreeRight(t), out);
}

Node* Tree2Bst(const Node* t) {
	Node* out = TreeCreateEmpty();
	VisitInOrder(t, &out);
	return out;
}