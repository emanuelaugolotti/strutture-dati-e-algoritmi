#include "tree.h"
#include <stdbool.h>

void IsomorfiRec(const Node* t1, const Node* t2, bool* inverti, bool* ris) {
	if(TreeIsLeaf(t1) && TreeIsLeaf(t2)) {	
		if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
			*ris = false;
		}
		return;
	}
	
	if (TreeIsLeaf(t1) || TreeIsLeaf(t2)) {
		*ris = false;
		return;
	}

	if (t1->left == NULL && t2->left == NULL) {
		if (ElemCompare(TreeGetRootValue(TreeRight(t1)), TreeGetRootValue(TreeRight(t2))) != 0) {
			*ris=false;
		}
		return;
	}
	if (t1->right == NULL && t2->right == NULL) {
		if (ElemCompare(TreeGetRootValue(TreeLeft(t1)), TreeGetRootValue(TreeLeft(t2))) != 0) {
			*ris = false;
		}
		return;
	}

	if (t1->left == NULL && t2->right == NULL) {
		if (ElemCompare(TreeGetRootValue(TreeRight(t1)), TreeGetRootValue(TreeLeft(t2))) == 0) {
			IsomorfiRec(TreeRight(t1), TreeLeft(t2), inverti, ris);
			return;
		} else {
			*ris=false;
			return;
		}
	}

	if (t1->right == NULL && t2->left == NULL) {
		if (ElemCompare(TreeGetRootValue(TreeLeft(t1)), TreeGetRootValue(TreeRight(t2))) == 0) {
			IsomorfiRec(TreeLeft(t1), TreeRight(t2), inverti, ris);
			return;
		}
		else {
			*ris = false;
			return;
		}
	}
	
	const ElemType* leftson1 = TreeGetRootValue(TreeLeft(t1));
	const ElemType* rightson1 = TreeGetRootValue(TreeRight(t1));
	const ElemType* leftson2 = TreeGetRootValue(TreeLeft(t2));
	const ElemType* rightson2 = TreeGetRootValue(TreeRight(t2));
	
	if (ElemCompare(leftson1, leftson2) != 0 || ElemCompare(rightson1, rightson2) != 0) {
		if (ElemCompare(leftson1, rightson2)!= 0 || ElemCompare(rightson1, leftson2) != 0) {
			*ris = false;
			return;
		}
		*inverti = true;
	} else {
		*inverti = false;
	}
	
	if (*inverti == false) {
		IsomorfiRec(TreeLeft(t1), TreeLeft(t2), inverti, ris);
		IsomorfiRec(TreeRight(t1), TreeRight(t2), inverti, ris);

	} else {
		IsomorfiRec(TreeLeft(t1), TreeRight(t2), inverti, ris);
		IsomorfiRec(TreeRight(t1), TreeLeft(t2), inverti, ris);
	}
}

bool Isomorfi(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}

	if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
		return false;
	}
	
	bool ris = true;
	bool inverti = false;
	IsomorfiRec(t1, t2, &inverti, &ris);
	return ris;
}