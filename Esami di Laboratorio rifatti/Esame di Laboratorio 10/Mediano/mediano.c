#include "tree.h"
#include <float.h>

void ContaNodi(const Node* t, int* count) {
	if (TreeIsEmpty(t)) {
		return;
	}
	ContaNodi(TreeLeft(t), count);
	++(*count);
	ContaNodi(TreeRight(t), count);
}

void GetNodeVal(const Node* t, int pos, ElemType* val, int* count) {
	if (TreeIsEmpty(t)) {
		return;
	}
	GetNodeVal(TreeLeft(t), pos, val, count);
	if (*count == pos) {
		*val = ElemCopy(TreeGetRootValue(t));
	}
	++(*count);
	GetNodeVal(TreeRight(t), pos, val, count);
}

double Mediano(const Node* t) {
	if (TreeIsEmpty(t)) {
		return DBL_MAX;
	}
	double mediano;
	int n = 0;
	ContaNodi(t, &n);
	int count = 0;
	if (n % 2 == 0) {	//pari
		int pos1 = n / 2;
		int pos2 = pos1 - 1;
		ElemType val1, val2;
		GetNodeVal(t, pos1, &val1, &count);
		count = 0;
		GetNodeVal(t, pos2, &val2, &count);
		mediano = (val1 + val2) / 2.0;

	} else {	//dispari
		int pos = n / 2;
		ElemType val;
		count = 0;
		GetNodeVal(t, pos, &val, &count);
		mediano = val;
	}
	return mediano;
}