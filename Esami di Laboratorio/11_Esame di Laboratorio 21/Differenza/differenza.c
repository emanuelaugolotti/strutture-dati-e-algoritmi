#include "differenza.h"

bool Prestito(int n1, int n2, int* p_prev, int* p_new) {
	int d;
	if (*p_prev != 0) {
		n1 -= *p_prev;
	}
	d = n1 - n2;
	if (d > 0 || d == 0) {
		*p_new = 0;
		return false;
	}
	*p_new = 1;
	return true;
}

Item* Differenza(const Item* i1, const Item* i2) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return ListCreateEmpty();
	}
	Item* out = ListCreateEmpty();
	int p_prev = 0;
	bool i2_vuota = false;
	if (ListIsEmpty(i2)) {
		i2_vuota = true;
	}
	while (!ListIsEmpty(i1)) {
		ElemType nn1 = ElemCopy(ListGetHeadValue(i1));
		int n1 = nn1 - '0';
		ElemType nn2;
		int n2;
		if (!i2_vuota) {
			nn2 = ElemCopy(ListGetHeadValue(i2));
			n2 = nn2 - '0';
		} else {
			n2 = 0;
		}
		int d, p_new;
		if (!Prestito(n1, n2, &p_prev, &p_new)) {
			d = n1 - n2 - p_prev;
			p_prev = 0;
		} else {
			n1 = 10 + n1 - p_prev;
			d = n1 - n2;
			p_prev = p_new;
		}
		ElemType dd = d + '0';
		out = ListInsertBack(out, &dd);
		i1 = ListGetTail(i1);
		if (!i2_vuota && !ListIsEmpty(ListGetTail(i2))) {
			i2 = ListGetTail(i2);
		} else {
			i2_vuota = true;
		}
	}
	return out;
}