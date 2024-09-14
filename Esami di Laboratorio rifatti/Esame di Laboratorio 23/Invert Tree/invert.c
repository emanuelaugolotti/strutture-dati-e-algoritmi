//Time: 9 min
#include "tree.h"

Node* Invert(Node* t) {
	if (TreeIsEmpty(t)) {
		return t;
	}
	if (TreeIsLeaf(t)) {
		return t;
	}
	Node* l = Invert(TreeLeft(t));
	Node* r = Invert(TreeRight(t));
	t->right = l;
	t->left = r;
	return t;
}