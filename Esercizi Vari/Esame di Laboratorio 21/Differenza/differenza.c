//Time: 32 min
#include "differenza.h"

ElemType GetRisSottrazione(ElemType s, ElemType m, int* p) {
	s -= '0';
	m -= '0';
	s -= *p;
	*p = 0;
	if (s < m) {
		*p = 1;
		s += 10;
	}
	int r = s - m;
	return r + '0';
}

Item* Differenza(const Item* i1, const Item* i2) {
	Item* out = ListCreateEmpty();
	int prestito = 0;
	while (!ListIsEmpty(i1) || !ListIsEmpty(i2)) {
		ElemType val1 = '0';
		if (!ListIsEmpty(i1)) {
			val1 = ElemCopy(ListGetHeadValue(i1));
			i1 = ListGetTail(i1);
		}
		ElemType val2 = '0';
		if (!ListIsEmpty(i2)) {
			val2 = ElemCopy(ListGetHeadValue(i2));
			i2 = ListGetTail(i2);
		}
		ElemType r = GetRisSottrazione(val1, val2, &prestito);
		out = ListInsertBack(out, &r);
	}
	return out;
}