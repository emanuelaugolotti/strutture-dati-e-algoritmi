// 51 min
#include "tree.h"
#include <stdbool.h>

void EquivalentiRec(const Node* t1, const Node* t2, bool* ris) {
	const ElemType* curr1 = TreeGetRootValue(t1);
	const ElemType* curr2 = TreeGetRootValue(t2);

	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		if (ElemCompare(curr1, curr2) >= 0) {
			if ((*curr1 % *curr2) == 0) {
				return;
			} else {
				*ris = false;
				return;
			}
		} else {
			if ((*curr2 % *curr1) == 0) {
				return;
			} else {
				*ris = false;
				return;
			}
		}
	}

	if ((TreeIsLeaf(t1) && !TreeIsLeaf(t2)) || (!TreeIsLeaf(t1) && TreeIsLeaf(t2)) || 
		(ElemCompare(curr1, curr2) != 0)) {
		*ris = false;
		return;
	}
	
	if (!TreeIsEmpty(TreeLeft(t1)) && !TreeIsEmpty(TreeLeft(t2))) {
		EquivalentiRec(TreeLeft(t1), TreeLeft(t2), ris);
	}
	if (!TreeIsEmpty(TreeRight(t1)) && !TreeIsEmpty(TreeRight(t2))) {
		EquivalentiRec(TreeRight(t1), TreeRight(t2), ris);
	}
}

bool Equivalenti(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}

	bool ris = true;
	EquivalentiRec(t1, t2, &ris);
	return ris;
}