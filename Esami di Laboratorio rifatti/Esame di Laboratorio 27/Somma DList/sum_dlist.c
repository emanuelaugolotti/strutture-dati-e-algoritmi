//Time: 32 min
#include "sum_dlist.h"

ElemType GetSommaRiporto(const Item* i1, const Item* i2, ElemType* riporto) {
	ElemType val1 = 0, val2 = 0, sum;
	if (!DListIsEmpty(i1)) {
		val1 = ElemCopy(DListGetHeadValue(i1));
	}
	if (!DListIsEmpty(i2)) {
		val2 = ElemCopy(DListGetHeadValue(i2));
	}
	sum = val1 + val2 + *riporto;
	*riporto = sum / 10;
	return sum % 10;
}

const Item* GetLast(const Item* i) {
	const Item* prev = i;
	while (!DListIsEmpty(i)) {
		prev = i;
		i = DListGetTail(i);
	}
	return prev;
}

const Item* GetProssimoItem(const Item** i) {
	if (!DListIsEmpty(*i)) {
		*i = DListGetPrev(*i);
	}
	return *i;
}

Item* DListSum(const Item* i1, const Item* i2) {
	if (DListIsEmpty(i1) && DListIsEmpty(i2)) {
		return DListCreateEmpty();
	}
	Item* out = DListCreateEmpty();
	i1 = GetLast(i1);
	i2 = GetLast(i2);
	ElemType riporto = 0;
	while (!DListIsEmpty(i1) || !DListIsEmpty(i2)) {
		ElemType sum = GetSommaRiporto(i1, i2, &riporto);
		out = DListInsertHead(&sum, out);
		i1 = GetProssimoItem(&i1);
		i2 = GetProssimoItem(&i2);
	}
	if (riporto != 0) {
		out = DListInsertHead(&riporto, out);
	}
	return out;
}