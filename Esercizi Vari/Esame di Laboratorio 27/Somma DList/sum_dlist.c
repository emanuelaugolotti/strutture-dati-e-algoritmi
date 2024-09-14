//Time: 26 min
#include "sum_dlist.h"

ElemType GetSum(ElemType val1, ElemType val2, ElemType* riporto) {
	ElemType sum = *riporto + val1 + val2;
	*riporto = sum / 10;
	sum %= 10;
	return sum;
}

const Item* GetLastItem(const Item* i) {
	const Item* prev = i;
	while (!DListIsEmpty(i)) {
		prev = i;
		i = DListGetTail(i);
	}
	return prev;
}

Item* DListSum(const Item* i1, const Item* i2) {
	Item* out = DListCreateEmpty();
	ElemType riporto = 0;
	i1 = GetLastItem(i1);
	i2 = GetLastItem(i2);
	while (!DListIsEmpty(i1) || !DListIsEmpty(i2)) {
		ElemType val1 = 0, val2 = 0;
		if (!DListIsEmpty(i1)) {
			val1 = ElemCopy(DListGetHeadValue(i1));
			i1 = DListGetPrev(i1);
		}
		if (!DListIsEmpty(i2)) {
			val2 = ElemCopy(DListGetHeadValue(i2));
			i2 = DListGetPrev(i2);
		}
		ElemType sum = GetSum(val1, val2, &riporto);
		out = DListInsertHead(&sum, out);
	}
	if (riporto != 0) {
		out = DListInsertHead(&riporto, out);
	}
	return out;
}