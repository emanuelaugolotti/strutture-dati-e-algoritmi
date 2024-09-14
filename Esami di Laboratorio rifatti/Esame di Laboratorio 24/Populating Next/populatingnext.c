//Time: 36 min
#include "tree.h"

void PopulatingNextRec(Node* t, Node** prev) {
	if (TreeIsEmpty(t)) {
		return;
	}
	PopulatingNextRec(TreeLeft(t), prev);
	if (*prev != NULL) {
		(*prev)->next = t;
		*prev = t;
	}
	if (*prev == NULL) {
		*prev = t;
	}
	PopulatingNextRec(TreeRight(t), prev);
}

void PopulatingNext(Node* t) {
	if (TreeIsEmpty(t)) {
		return;
	}
	Node* prev = TreeCreateEmpty();
	PopulatingNextRec(t, &prev);
}