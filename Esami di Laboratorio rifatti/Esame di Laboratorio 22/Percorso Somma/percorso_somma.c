//Time: 22 min
#include "tree.h"

bool PercorsoSommaRec(Node* t, const ElemType* target, ElemType sum) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	const ElemType* val = TreeGetRootValue(t);
	sum += *val;
	if (TreeIsLeaf(t)) {
		if (sum == *target) {
			return true;
		}
		return false;
	}
	bool ris1 = PercorsoSommaRec(TreeLeft(t), target, sum);
	bool ris2 = PercorsoSommaRec(TreeRight(t), target, sum);
	return ris1 || ris2;
}

bool PercorsoSomma(Node* t, const ElemType* target) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	return PercorsoSommaRec(t, target, 0);
}