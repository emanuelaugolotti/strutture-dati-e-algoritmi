//Time: 13 min
#include "tree.h"

void InvertRec(Node* t) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (!TreeIsLeaf(t)) {
		Node* l = TreeLeft(t);
		Node* r = TreeRight(t);
		t->left = r;
		t->right = l;
	}
	InvertRec(TreeLeft(t));
	InvertRec(TreeRight(t));
}

Node* Invert(Node* t) {
	if (TreeIsEmpty(t)) {
		return t;
	}
	InvertRec(t);
	return t;
}