#include "sum_dlist.h"

size_t Lenght(const Item* l) {
	size_t len = 0;
	while (!DListIsEmpty(l)) {
		++len;
		l = DListGetTail(l);
	}
	return len;
}

const Item* GetLast(const Item* l) {
	const Item* prev = DListCreateEmpty();
	while (!DListIsEmpty(l)) {
		prev = l;
		l = DListGetTail(l);
	}
	return prev;
}

ElemType SommaRiporto(ElemType val1, ElemType val2, ElemType* rip_new, ElemType* rip_prev) {
	ElemType sum = val1 + val2 + (*rip_prev);
	if (sum < 10) {
		*rip_new = 0;
		return sum;
	}
	else {
		ElemType r = sum % 10;
		*rip_new = sum / 10;
		return r;
	}
}

Item* DListSum(const Item* i1, const Item* i2) {
	if (DListIsEmpty(i1) && DListIsEmpty(i2)) {
		return DListCreateEmpty();
	}
	size_t len1 = Lenght(i1);
	size_t len2 = Lenght(i2);
	Item* out = DListCreateEmpty();
	const Item* last1 = GetLast(i1);
	const Item* last2 = GetLast(i2);
	size_t stop;
	if (len1 > len2) {
		stop = len2;
	}
	else {
		stop = len1;
	}
	ElemType rip_new = 0;
	ElemType rip_prev = 0;
	for (size_t j = 0; j < stop; ++j) {
		ElemType val1 = ElemCopy(DListGetHeadValue(last1));
		ElemType val2 = ElemCopy(DListGetHeadValue(last2));
		ElemType sum = SommaRiporto(val1, val2, &rip_new, &rip_prev);
		out = DListInsertHead(&sum, out);
		i1 = DListGetPrev(last1);
		i2 = DListGetPrev(last2);
	}
	const Item* rimanente = DListCreateEmpty();
	if (len1 > len2) {
		rimanente = last1;
	}
	else {
		rimanente = last2;
	}
	rip_prev = rip_new;
	while (!DListIsEmpty(rimanente)) {
		ElemType val = ElemCopy(DListGetHeadValue(rimanente));
		ElemType sum = SommaRiporto(val, 0, &rip_new, &rip_prev);
		out = DListInsertHead(&sum, out);
		rimanente = DListGetPrev(rimanente);
	}
	return out;
}