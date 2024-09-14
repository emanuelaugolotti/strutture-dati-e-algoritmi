#include "tree.h"

ElemType SostituisciSommaRec(Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	ElemType root = ElemCopy(TreeGetRootValue(t));
	Node* l = TreeLeft(t);
	ElemType sommaleft = SostituisciSommaRec(l);
	Node* r = TreeRight(t);
	ElemType sommaright = SostituisciSommaRec(r);
	ElemType sommatot = root + sommaright + sommaleft;
	t->value = ElemCopy(&sommatot);
	return sommatot;
}

void SostituisciSomma(Node* t) {
	if (TreeIsEmpty(t)) {
		return;
	}
	SostituisciSommaRec(t);
	return;
}