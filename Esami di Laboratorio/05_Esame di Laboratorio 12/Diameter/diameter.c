//Time: 1h 11min
#include "tree.h"

void CalcolaDMaxSottoalbero(const Node* t, int* dmax, int dcurr, int i) {
	if (TreeIsLeaf(t)) {
		++dcurr;
		if (*dmax < dcurr) {
			*dmax = dcurr;
		}
		return;
	}
	++dcurr;
	CalcolaDMaxSottoalbero(TreeLeft(t), dmax, dcurr, i + 1);
	CalcolaDMaxSottoalbero(TreeRight(t), dmax, dcurr, i + 1);
}

void DiameterRec(const Node* t, int* dmax, int dcurr, int i) {
	if (TreeIsLeaf(t)) {
		dcurr = 1;
		return;
	}

	int dlmax = 0, drmax = 0;
	Node* l = TreeLeft(t);
	Node* r = TreeRight(t);
	CalcolaDMaxSottoalbero(l, &dlmax, 0, 0);
	CalcolaDMaxSottoalbero(r, &drmax, 0, 0);
	dcurr = dlmax + drmax + 1;
	if (dcurr > *dmax) {
		*dmax = dcurr;
	}
	DiameterRec(TreeLeft(t), dmax, dcurr, i + 1);
	DiameterRec(TreeRight(t), dmax, dcurr, i + 1);
}

int Diameter(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	int dmax = 0;
	DiameterRec(t, &dmax, 0, 0);
	return dmax;
}