//https://github.com/lee-hen/Algoexpert/tree/master/very_hard/11_compare_leaf_traversal
#include "tree.h"

const Node* Left(const Node* t, bool done) {
	if (TreeIsEmpty(t) || done) {
		return t;
	}
	return TreeLeft(t);
}

const Node* Right(const Node* t, bool done) {
	if (TreeIsEmpty(t) || done) {
		return t;
	}
	return TreeRight(t);
}

void GetLastLeaf(const Node* t, const Node** lastleaf, bool* done) {
	if (!TreeIsEmpty(t) && TreeIsLeaf(t) && !*done && *lastleaf != t) {
		*lastleaf = t;
		*done = true;
	}
}

bool LeafTraversalRec(const Node* t1, const Node* t2, const Node** lastleaf1, const Node** lastleaf2,
						bool* done1, bool* done2) {
	bool ris1 = true;
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	GetLastLeaf(t1, lastleaf1, done1);
	GetLastLeaf(t2, lastleaf2, done2);
	if (*done1 && *done2) {
		*done1 = false;
		*done2 = false;
		const ElemType* val1 = TreeGetRootValue(*lastleaf1);
		const ElemType* val2 = TreeGetRootValue(*lastleaf2);
		if (ElemCompare(val1, val2) != 0) {
			ris1 = false;
		}
	}
	/*GetLastLeaf(t1, lastleaf1, done1);
	GetLastLeaf(t2, lastleaf2, done2);*/
	bool ris2 = LeafTraversalRec(Left(t1, *done1), Left(t2, *done1), lastleaf1, lastleaf2, done1, done2);
	bool ris3 = LeafTraversalRec(Right(t1, *done2), Right(t2, *done2), lastleaf1, lastleaf2, done1, done2);
	return ris1 && ris2 && ris3;
}

bool LeafTraversal(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}
	const Node* lastleaf1 = NULL;
	const Node* lastleaf2 = NULL;
	bool done1 = false, done2 = false;
	bool ris = LeafTraversalRec(t1, t2, &lastleaf1, &lastleaf2, &done1, &done2);
	if (done1 != done2) {	//t1 e t2 hanno un numero di foglie diverso
		ris = false;
	}
	return ris;
}