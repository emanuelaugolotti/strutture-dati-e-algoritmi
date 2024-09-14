#include "list.h"

void GetValue(const Item* i1, const Item* i2, ElemType* val1, ElemType* val2) {
	if (!ListIsEmpty(i1)) {
		*val1 = ElemCopy(ListGetHeadValue(i1));
	} else {
		*val1 = 0;
	}
	if (!ListIsEmpty(i2)) {
		*val2 = ElemCopy(ListGetHeadValue(i2));
	} else {
		*val2 = 0;
	}
}

ElemType CalcolaSommaRiporto(ElemType val1, ElemType val2, ElemType* riporto) {
	ElemType somma = val1 + val2 + *riporto;
	*riporto = somma / 10;
	return somma % 10;
}

const Item* GetNext(const Item* i) {
	if (!ListIsEmpty(i)) {
		return ListGetTail(i);
	}
	return i;
}

Item* Sum(const Item* i1, const Item* i2) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return ListCreateEmpty();
	}
	Item* out = ListCreateEmpty();
	ElemType riporto = 0;
	while (!ListIsEmpty(i1) || !ListIsEmpty(i2)) {
		ElemType val1, val2;
		GetValue(i1, i2, &val1, &val2);
		ElemType somma = CalcolaSommaRiporto(val1, val2, &riporto);
		out = ListInsertBack(out, &somma);
		i1 = GetNext(i1);
		i2 = GetNext(i2);
	}
	if (riporto != 0) {
		out = ListInsertBack(out, &riporto);
	}
	return out;
}