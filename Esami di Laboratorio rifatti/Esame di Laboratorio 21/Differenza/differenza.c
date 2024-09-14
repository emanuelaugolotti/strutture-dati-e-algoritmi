#include "differenza.h"

ElemType CalcolaPrestitoDifferenza(const Item* i1, const Item* i2, int* p) {
	const ElemType* ss = ListGetHeadValue(i1);
	int s = *ss - '0';
	int m, ris;
	if (!ListIsEmpty(i2)) {
		const ElemType* mm = ListGetHeadValue(i2);
		m = *mm - '0';
	} else {
		m = 0;
	}
	s -= *p;
	*p = 0;
	if (s < m) {
		*p = 1;
		s += 10;
	}
	ris = s - m;
	return ris + '0';
}

Item* Differenza(const Item* i1, const Item* i2) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return ListCreateEmpty();
	}
	Item* out = ListCreateEmpty();
	int p = 0;
	while (!ListIsEmpty(i1) || !ListIsEmpty(i2)) {
		ElemType d = CalcolaPrestitoDifferenza(i1, i2, &p);
		out = ListInsertBack(out, &d);
		i1 = ListGetTail(i1);
		if (!ListIsEmpty(i2)) {
			i2 = ListGetTail(i2);
		}
	}
	return out;
}