//Time: 22 min
#include "tree.h"

ElemType SostituisciSommaRec(Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	const ElemType* root = TreeGetRootValue(t);
	ElemType l = SostituisciSommaRec(TreeLeft(t));
	ElemType r = SostituisciSommaRec(TreeRight(t));
	ElemType sum = *root + l + r;
	t->value = sum;
	return sum;
}

void SostituisciSomma(Node* t) {
	if (TreeIsEmpty(t)) {
		return;
	}
	SostituisciSommaRec(t);
}