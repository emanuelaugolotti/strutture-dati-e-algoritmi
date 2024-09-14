#include "tree.h"

bool TreeTwinsRec(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}
	bool ris1 = TreeTwinsRec(TreeLeft(t1), TreeLeft(t2));
	bool ris2 = TreeTwinsRec(TreeRight(t1), TreeRight(t2));
	return ris1 && ris2;
}

bool TreesAreTwins(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	bool are_twins = TreeTwinsRec(t1, t2);
	return are_twins;
}