#include "tree.h"

bool UnicoColore(const Node* t, size_t* countnodi, size_t* h, size_t livellocurr, const char* c) {
	if (TreeIsEmpty(t)) {
		return true;
	}
	const ElemType* colore = TreeGetRootValue(t);
	++(*countnodi);
	if (livellocurr > *h) {
		*h = livellocurr;
	}
	bool ris1 = false;
	if (ElemCompare(colore, c) == 0) {
		ris1 = true;
	} 
	if (TreeIsLeaf(t)) {
		if (livellocurr > *h) {
			*h = livellocurr;
		}
	}
	bool ris2 = UnicoColore(TreeLeft(t), countnodi, h, livellocurr + 1, c);
	bool ris3 = UnicoColore(TreeRight(t), countnodi, h, livellocurr + 1, c);
	return ris1 && ris2 && ris3;
}

void BiggestColoredTreeRec(const Node* t, const Node** best, size_t* hbest, size_t* dimbest) {
	if (TreeIsEmpty(t)) {
		return;
	}
	const ElemType* colore = TreeGetRootValue(t);
	size_t countnodi = 0, h = 0;
	bool is_unicocolore = UnicoColore(t, &countnodi, &h, 0, colore);
	if (is_unicocolore) {
		if (countnodi > *dimbest) {
			*dimbest = countnodi;
			*best = t;
		}
		if (countnodi == *dimbest && h > *hbest) {
			*hbest = h;
			*best = t;
		}
	}
	BiggestColoredTreeRec(TreeLeft(t), best, hbest, dimbest);
	BiggestColoredTreeRec(TreeRight(t), best, hbest, dimbest);
}

const Node* BiggestColoredTree(const Node* t) {
	const Node* best = TreeCreateEmpty();
	if (TreeIsEmpty(t)) {
		return best;
	}
	size_t hbest = 0, dimbest = 0;
	BiggestColoredTreeRec(t, &best, &hbest, &dimbest);
	return best;
}