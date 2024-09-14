#include "tree.h"

bool IsMultiplo(int a, int b) {
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (a % b == 0) {
		return true;
	}
	return false;
}

bool Equivalenti(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}
	ElemType val1 = ElemCopy(TreeGetRootValue(t1));
	ElemType val2 = ElemCopy(TreeGetRootValue(t2));
	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		if (IsMultiplo(val1, val2)) {
			return true;
		}
		return false;
	}
	if (TreeIsLeaf(t1) || TreeIsLeaf(t2)) {
		return false;	//non hanno la stessa struttura
	}
	bool ris1 = false;
	if (ElemCompare(&val1, &val2) == 0) {
		ris1 = true;
	}
	bool ris2 = Equivalenti(TreeLeft(t1), TreeLeft(t2));
	bool ris3 = Equivalenti(TreeRight(t1), TreeRight(t2));
	if (ris1 && ris2 && ris3) {
		return true;
	}
	return false;
}