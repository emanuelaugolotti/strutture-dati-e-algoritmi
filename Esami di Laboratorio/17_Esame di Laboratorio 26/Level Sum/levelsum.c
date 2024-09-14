//Time: 24 min
#include "tree.h"

void LevelSumRec(const Node* t, size_t level, int* sum, size_t i) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (i == level) {
		ElemType value = ElemCopy(TreeGetRootValue(t));
		(*sum) += value;
	}
	LevelSumRec(TreeLeft(t), level, sum, i + 1);
	LevelSumRec(TreeRight(t), level, sum, i + 1);
}

int LevelSum(const Node* t, size_t level) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	int sum = 0;
	LevelSumRec(t, level, &sum, 0);
	return sum;
}