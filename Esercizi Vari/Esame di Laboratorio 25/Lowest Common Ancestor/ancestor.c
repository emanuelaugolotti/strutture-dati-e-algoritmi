#include "tree.h"

//dato un albero e un nodo, ritorna true se il nodo appartiene all'albero, false altrimenti.
bool TreeContainsNode(const Node* tree, const Node* node) {
	if (TreeIsEmpty(tree)) {
		return false;
	}
	if (tree == node) {
		return true;
	} 
	bool ris1 = TreeContainsNode(TreeLeft(tree), node);
	bool ris2 = TreeContainsNode(TreeRight(tree), node);
	bool ris_tot = ris1 || ris2;
	return ris_tot;
}

void LowestCommonAncestorRec(const Node* t, const Node* n1, const Node* n2, const Node** ris) {
	if (TreeIsEmpty(t)) {
		return;
	}
	bool ris1 = TreeContainsNode(t, n1);
	bool ris2 = TreeContainsNode(t, n2);
	if (ris1 && ris2) {
		*ris = t;
	}
	LowestCommonAncestorRec(TreeLeft(t), n1, n2, ris);
	LowestCommonAncestorRec(TreeRight(t), n1, n2, ris);
}

const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2) {
	const Node* ris = TreeCreateEmpty();
	LowestCommonAncestorRec(t, n1, n2, &ris);
	return ris;
}