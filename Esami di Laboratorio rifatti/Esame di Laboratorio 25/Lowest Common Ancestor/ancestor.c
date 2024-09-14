//Time: 37 min
#include "tree.h"

bool TreeContainsNode(const Node* t, const Node* node) {
	if (TreeIsEmpty(t)) {
		return false;
	}
	bool ris1 = false;
	if (t == node) {
		ris1 = true;
	} 
	bool ris2 = TreeContainsNode(TreeLeft(t), node);
	bool ris3 = TreeContainsNode(TreeRight(t), node);
	return ris1 || ris2 || ris3;
}

void LowestCommonAncestorRec(const Node* t, const Node* n1, const Node* n2, int lcurr, int* lbest, 
					const Node** ancestor) {
	if (TreeIsEmpty(t)) {
		return;
	}
	bool ris1 = TreeContainsNode(t, n1);
	bool ris2 = TreeContainsNode(t, n2);
	if (ris1 && ris2 && *lbest < lcurr) {
		*lbest = lcurr;
		*ancestor = t;
	}
	LowestCommonAncestorRec(TreeLeft(t), n1, n2, lcurr + 1, lbest, ancestor);
	LowestCommonAncestorRec(TreeRight(t), n1, n2, lcurr + 1, lbest, ancestor);
}

const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2) {
	const Node* ancestor = t;
	int lbest = 0;
	LowestCommonAncestorRec(t, n1, n2, 0, &lbest, &ancestor);
	return ancestor;
}