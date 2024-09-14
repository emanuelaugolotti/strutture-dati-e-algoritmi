//Time: 22 min
#include "tree.h"

void PercorsoSommaRec(Node* t, const ElemType* target, bool* ris, ElemType sum) {
	if (TreeIsEmpty(t)) {
		return;
	}
	const ElemType* val = TreeGetRootValue(t);
	ElemType sum_curr = sum + *val;
	if (TreeIsLeaf(t) && sum_curr == *target) {
		*ris = true;
	}
	PercorsoSommaRec(TreeLeft(t), target, ris, sum + *val);
	PercorsoSommaRec(TreeRight(t), target, ris, sum + *val);
}

bool PercorsoSomma(Node* t, const ElemType* target) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	bool ris = false;
	PercorsoSommaRec(t, target, &ris, 0);
	return ris;
}