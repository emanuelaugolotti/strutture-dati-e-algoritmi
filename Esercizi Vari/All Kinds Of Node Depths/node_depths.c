//Time: 30 min
//https://github.com/lee-hen/Algoexpert/tree/master/very_hard/10_all_kinds_of_node_depths
#include "tree.h"

int ProfonditaSottoalberoRec(const Node* t, int livello) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	int sum = livello;
	int ris1 = ProfonditaSottoalberoRec(TreeLeft(t), livello + 1);
	int ris2 = ProfonditaSottoalberoRec(TreeRight(t), livello + 1);
	sum += (ris1 + ris2);
	return sum;
}

int NodeDepths(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	if (TreeIsLeaf(t)) {
		return 0;
	}
	int sum = ProfonditaSottoalberoRec(t, 0);
	int sum_left = NodeDepths(TreeLeft(t));
	int sum_right = NodeDepths(TreeRight(t));
	return sum + sum_left + sum_right;
}