#include "tree.h"
#include <stdbool.h>

void TreeContainsNode(const Node* tree, const Node* node, bool* isin) {
	if (TreeIsEmpty(tree)) {
		return;
	}
	if (tree == node) {
		*isin = true;
		return;
	}
	TreeContainsNode(TreeLeft(tree), node, isin);
	TreeContainsNode(TreeRight(tree), node, isin);
}

void LowestCommonAncestorRec(const Node* t, const Node* n1, const Node* n2, const Node** ancestor,
						size_t i_curr, size_t* i_ancestor) {
	if (TreeIsEmpty(t)) {
		return;
	}
	bool isin_n1 = false;
	TreeContainsNode(t, n1, &isin_n1);
	bool isin_n2 = false;
	TreeContainsNode(t, n2, &isin_n2);
	if (isin_n1 && isin_n2) {
		if (*i_ancestor <= i_curr) {
			*i_ancestor = i_curr;
			*ancestor = t;
		}
	}
	LowestCommonAncestorRec(TreeLeft(t), n1, n2, ancestor, i_curr + 1, i_ancestor);
	LowestCommonAncestorRec(TreeRight(t), n1, n2, ancestor, i_curr + 1, i_ancestor);
}

const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2) {
	if (n1 == n2) {
		return n1;
	}
	const Node* ancestor;
	size_t i_ancestor = 0;
	LowestCommonAncestorRec(t, n1, n2, &ancestor, 0, &i_ancestor);
	return ancestor;
}