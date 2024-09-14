#include "sum_dlist.h"

const Item* GetLastItem(const Item* l) {
	const Item* prev = DListCreateEmpty();
	while (!DListIsEmpty(l)) {
		prev = l;
		l = DListGetTail(l);
	}
	return prev;
}

void CalcolaSommaRiporto(const Item* i1, const Item* i2, ElemType* sum, ElemType* riporto) {
	ElemType val1, val2;
	if (!DListIsEmpty(i1)) {
		val1 = ElemCopy(DListGetHeadValue(i1));
	} else {
		val1 = 0;
	}
	if (!DListIsEmpty(i2)) {
		val2 = ElemCopy(DListGetHeadValue(i2));
	} else {
		val2 = 0;
	}
	ElemType somma = val1 + val2 + *riporto;
	*riporto = somma / 10;
	*sum = somma % 10;
}

Item* DListSum(const Item* i1, const Item* i2) {
	if (DListIsEmpty(i1) && DListIsEmpty(i2)) {
		return DListCreateEmpty();
	}
	Item* out = DListCreateEmpty();
	const Item* tmp1 = GetLastItem(i1);
	const Item* tmp2 = GetLastItem(i2);
	ElemType riporto = 0;
	while (!DListIsEmpty(tmp1) || !DListIsEmpty(tmp2)) {
		ElemType sum;
		CalcolaSommaRiporto(tmp1, tmp2, &sum, &riporto);
		out = DListInsertHead(&sum, out);
		if (!DListIsEmpty(tmp1)) {
			tmp1 = DListGetPrev(tmp1);
		}
		if (!DListIsEmpty(tmp2)) {
			tmp2 = DListGetPrev(tmp2);
		}
	}
	if (riporto != 0) {
		out = DListInsertHead(&riporto, out);
	}
	return out;
}