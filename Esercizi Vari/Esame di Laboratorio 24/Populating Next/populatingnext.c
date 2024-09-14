//Time: 19 min
#include "tree.h"

void PopulatingNextRec(Node* t, Node** prev, bool* start) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (TreeIsLeaf(t) && !*start) {
		*prev = t;
		*start = true;
	}
	PopulatingNextRec(TreeLeft(t), prev, start);
	if (start) {
		(*prev)->next = t;
		*prev = t;
	}
	PopulatingNextRec(TreeRight(t), prev, start);
}

void PopulatingNext(Node* t) {
	bool start = false;
	Node* prev = TreeCreateEmpty();
	PopulatingNextRec(t,&prev,  &start);
}