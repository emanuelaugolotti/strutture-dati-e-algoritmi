#include "diff_dlist.h"

ElemType GetRisDiff(ElemType n1, ElemType n2, ElemType* prestito) {
	n1 -= *prestito;
	if (n1 >= n2) {
		*prestito = 0;
	} else {
		n1 += 10;
		*prestito = 1;
	}
	ElemType diff = n1 - n2;
	return diff;
}

const Item* GetLastItem(const Item* list) {
	const Item* prev = list;
	while (!DListIsEmpty(list)) {
		prev = list;
		list = DListGetTail(list);
	}
	return prev;
}

Item* DListDiff(const Item* i1, const Item* i2) {
	if (DListIsEmpty(i1) && DListIsEmpty(i2)) {
		return DListCreateEmpty();
	}
	Item* out = DListCreateEmpty();
	i1 = GetLastItem(i1);
	i2 = GetLastItem(i2);
	ElemType prestito = 0;
	while (!DListIsEmpty(i1) || !DListIsEmpty(i2)) {
		ElemType n1 = 0;
		if (!DListIsEmpty(i1)) {
			n1 = ElemCopy(DListGetHeadValue(i1));
		}
		ElemType n2 = 0;
		if (!DListIsEmpty(i2)) {
			n2 = ElemCopy(DListGetHeadValue(i2));
		}
		ElemType ris_diff = GetRisDiff(n1, n2, &prestito);
		out = DListInsertHead(&ris_diff, out);
		if (!DListIsEmpty(i1)) {
			i1 = DListGetPrev(i1);
		}
		if (!DListIsEmpty(i2)) {
			i2 = DListGetPrev(i2);
		}
	}
	return out;
}