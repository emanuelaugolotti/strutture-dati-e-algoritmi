#include "tree.h"
#include <stdlib.h>
//https://github.com/lee-hen/Algoexpert/tree/master/very_hard/09_right_sibling_tree

void GetBrotherRight(Node* t, Node* tofind, int livello, int livellocurr, Node** b, bool* done1, bool* done2) {
	if (*done1 && !(*done2) && livellocurr == livello) {
		*b = t;
		*done2 = true;
	}
	if (TreeIsEmpty(t)) {
		return;
	}
	if (t == tofind) {
		*done1 = true;
	}
	GetBrotherRight(TreeLeft(t), tofind, livello, livellocurr + 1, b, done1, done2);
	GetBrotherRight(TreeRight(t), tofind, livello, livellocurr + 1, b, done1, done2);
}

void PopolaVect(Node* t, int livello, Node* v[], size_t* pos, Node* root) {
	if (TreeIsEmpty(t)) {
		return;
	}
	PopolaVect(TreeLeft(t), livello + 1, v, pos, root);
	PopolaVect(TreeRight(t), livello + 1, v, pos, root);
	Node* b = TreeCreateEmpty();
	bool done1 = false, done2 = false;
	GetBrotherRight(root, t, livello, 0, &b, &done1, &done2);
	v[*pos] = b;
	*pos += 1;
}

size_t CountNodi(Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	size_t count = 1;
	count += CountNodi(TreeLeft(t));
	count += CountNodi(TreeRight(t));
	return count;
}

void ModificaTree(Node* t, Node* v[], size_t* pos) {
	if (TreeIsEmpty(t)) {
		return;
	}
	ModificaTree(TreeLeft(t), v, pos);
	ModificaTree(TreeRight(t), v, pos);
	t->right = v[*pos];
	++(*pos);
}

Node* SiblingTree(Node* t) {
	size_t n = CountNodi(t);
	Node** v = malloc(n * sizeof(Node*));
	size_t pos = 0;
	PopolaVect(t, 0, v, &pos, t);
	pos = 0;
	ModificaTree(t, v, &pos);
	free(v);
	return t;
}