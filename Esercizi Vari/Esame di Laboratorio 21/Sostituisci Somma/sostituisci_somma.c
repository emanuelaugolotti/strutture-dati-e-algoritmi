//Time: 25 min
#include "tree.h"

int CalcolaSommaNodi(Node* t) {
	const ElemType* val = TreeGetRootValue(t);
	ElemType val_sinistra, val_destra;
	Node* l = TreeLeft(t);
	if (!TreeIsEmpty(l)) {
		val_sinistra = ElemCopy(TreeGetRootValue(l));
	} else {
		val_sinistra = 0;
	}
	Node* r = TreeRight(t);
	if (!TreeIsEmpty(r)) {
		val_destra = ElemCopy(TreeGetRootValue(r));
	} else {
		val_destra=0;
	}
	int somma = val_destra + val_sinistra + *val;
	return somma;
}

void SostituisciSomma(Node* t) {
	if (TreeIsEmpty(t)) {
		return;
	}
	SostituisciSomma(TreeLeft(t));
	SostituisciSomma(TreeRight(t));
	int somma = CalcolaSommaNodi(t);
	t->value = ElemCopy(&somma);
}