//Time: 16 min
#include "tree.h"

int LevelSumRec(const Node* t, size_t level, size_t level_curr) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	int ris1 = 0;
	if (level_curr == level) {
		const ElemType* val = TreeGetRootValue(t);
		ris1 = *val;
	}
	int ris2 = LevelSumRec(TreeLeft(t), level, level_curr + 1);
	int ris3 = LevelSumRec(TreeRight(t), level, level_curr + 1);
	return ris1 + ris2 + ris3;
}

extern int LevelSum(const Node* t, size_t level) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	int sum = LevelSumRec(t, level, 0);
	return sum;
}