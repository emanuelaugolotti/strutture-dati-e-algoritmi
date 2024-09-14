//https://github.com/lee-hen/Algoexpert/tree/master/very_hard/11_compare_leaf_traversal
#include "tree.h"

void GetNextLeafRec(const Node* t, const Node** leaf, size_t num_nodo, size_t* numnodo_curr) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (TreeIsLeaf(t)) {
		++(*numnodo_curr);
		if (*numnodo_curr == num_nodo) {
			*leaf = t;
		}
	}
	GetNextLeafRec(TreeLeft(t), leaf, num_nodo, numnodo_curr);
	GetNextLeafRec(TreeRight(t), leaf, num_nodo, numnodo_curr);
}

const Node* GetNextLeaf(const Node* t, size_t count) {
	const Node* nextleaf = TreeCreateEmpty();
	size_t numnodo_curr = 0;
	GetNextLeafRec(t, &nextleaf, count + 1, &numnodo_curr);
	return nextleaf;
}

bool LeafTraversal(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	size_t count1 = 0, count2 = 0;
	while (1) {
		const Node* nextleaf1 = GetNextLeaf(t1, count1);
		const Node* nextleaf2 = GetNextLeaf(t2, count2);
		if (nextleaf1 == NULL && nextleaf2 == NULL) {
			return true;
		}
		if (nextleaf1 == NULL || nextleaf2 == NULL) {
			return false;
		}
		++count1;
		++count2;
		const ElemType* val1 = TreeGetRootValue(nextleaf1);
		const ElemType* val2 = TreeGetRootValue(nextleaf2);
		if (ElemCompare(val1, val2) != 0) {
			return false;
		}
	}
}