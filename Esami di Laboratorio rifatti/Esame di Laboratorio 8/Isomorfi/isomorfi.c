#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

bool IsomorfiRec(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}
	const ElemType* val1 = TreeGetRootValue(t1);
	const ElemType* val2 = TreeGetRootValue(t2);
	bool ris1 = false;
	if (ElemCompare(val1, val2) == 0) {
		ris1 = true;
	}
	bool ris2 = IsomorfiRec(TreeLeft(t1), TreeLeft(t2));
	bool ris3 = IsomorfiRec(TreeLeft(t1), TreeRight(t2));
	bool ris4 = IsomorfiRec(TreeRight(t1), TreeRight(t2));
	bool ris5 = IsomorfiRec(TreeRight(t1), TreeLeft(t2));
	if (ris1 && (ris2 || ris3) && (ris4 || ris5)) {
		return true;
	}
	return false;
}

bool Isomorfi(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	return IsomorfiRec(t1, t2);
}