#include "tree.h"

Node* InsertElement(Node* t, const ElemType* e) {
	Node* out = t;
	Node* tmp = TreeCreateRoot(e, NULL, NULL);
	if (TreeIsEmpty(t)) {
		t = tmp;
		return t;
	}
	while (!TreeIsEmpty(t)) {
		const ElemType* val = TreeGetRootValue(t);
		if (ElemCompare(e, val) <= 0) {
			//vado a sinistra
			if (TreeIsEmpty(TreeLeft(t))) {
				t->left = tmp;
				break;
			}
			t = TreeLeft(t);
		}
		else {
			//vado a destra
			if (TreeIsEmpty(TreeRight(t))) {
				t->right = tmp;
				break;
			}
			t = TreeRight(t);
		}
	}
	return out;
}

void VisitaInOrdine(const Node* t, Node** bst) {
	if (TreeIsEmpty(t)) {
		return;
	}
	VisitaInOrdine(TreeLeft(t), bst);
	ElemType e = ElemCopy(TreeGetRootValue(t));
	*bst = InsertElement(*bst, &e);
	VisitaInOrdine(TreeRight(t), bst);
}

Node* Tree2Bst(const Node* t) {
	Node* bst = TreeCreateEmpty();
	if (TreeIsEmpty(t)) {
		return bst;
	}
	VisitaInOrdine(t, &bst);
	return bst;
}