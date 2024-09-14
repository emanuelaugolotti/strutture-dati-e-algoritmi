//Time: 14 min
#include "tree.h"

int LevelSumRec(const Node* t, size_t lcerco, size_t lcurr) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	int sum = 0;
	if (lcerco == lcurr) {
		const ElemType* val = TreeGetRootValue(t);
		sum += *val;
	}
	sum += LevelSumRec(TreeLeft(t), lcerco, lcurr + 1);
	sum += LevelSumRec(TreeRight(t), lcerco, lcurr + 1);
	return sum;
}

int LevelSum(const Node* t, size_t level) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	return LevelSumRec(t, level, 0);
}