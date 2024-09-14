//Time: 28min
#include "tree.h"

void InvertRec(Node* p) {
	if (TreeIsLeaf(p)) {
		return;
	}
	Node* l = TreeLeft(p);
	Node* r = TreeRight(p);
	InvertRec(l);
	InvertRec(r);
	Node* tmp = p->left;
	p->left = p->right;
	p->right = tmp;
}

Node* Invert(Node* t) {
	if (TreeIsEmpty(t)) {
		return TreeCreateEmpty();
	}
	InvertRec(t);
	return t;
}