#include "tree.h"

void CalcolaDiametro(const Node* t, int* d_max, int d_curr) {
	if (TreeIsLeaf(t)) {
		++d_curr;
		if (d_curr > *d_max) {
			*d_max = d_curr;
		}
		return;
	}
	++d_curr;
	CalcolaDiametro(TreeLeft(t), d_max, d_curr);
	CalcolaDiametro(TreeRight(t), d_max, d_curr);
}

void VisitPreOrder(const Node* t, int* d_max) {
	if (TreeIsEmpty(t)) {
		return;
	}
	//Considero il nodo corrente
	int d_left = 0, d_right = 0;
	CalcolaDiametro(TreeLeft(t), &d_left, 0);
	CalcolaDiametro(TreeRight(t), &d_right, 0);
	int d_curr = d_left + d_right + 1;
	if (d_curr > *d_max) {
		*d_max = d_curr;
	}
	VisitPreOrder(TreeLeft(t), d_max);
	VisitPreOrder(TreeRight(t), d_max);
}

int Diameter(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	int d = 0;
	VisitPreOrder(t, &d);
	return d;
}