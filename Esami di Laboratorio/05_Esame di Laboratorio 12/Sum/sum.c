#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

int Lenght(const Item* i) {
	int len = 0;
	while (!ListIsEmpty(i)) {
		++len;
		i = ListGetTail(i);
	}
	return len;
}

ElemType CalcolaSumERiporto(ElemType a, ElemType b, ElemType* riporto_prev, ElemType* riporto_new) {
	if (a + b + *riporto_prev > 9) {
		*riporto_new = (a + b + *riporto_prev) / 10;
	} else {
		*riporto_new = 0;
	}
	ElemType sum;
	if (riporto_new) {
		sum = (a + b + *riporto_prev) % 10;
	}
	else {
		sum = (a + b + *riporto_prev);
	}
	*riporto_prev = *riporto_new;
	return sum;
}

Item* AddSfasati(Item* out, const Item* i, ElemType* riporto_prev, ElemType* riporto_new) {
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		ElemType value =ElemCopy(ListGetHeadValue(i));
		ElemType sum = CalcolaSumERiporto(value, 0, riporto_prev, riporto_new);
		out = ListInsertBack(out, &sum);
	}
	return out;
}

Item* Sum(const Item* i1, const Item* i2) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return ListCreateEmpty();
	}
	int len1 = Lenght(i1);
	int len2 = Lenght(i2);
	int stop = len1 - 1;
	Item* out = ListCreateEmpty();
	if (len1 > len2) {
		stop = len2 - 1;
	}
	if (len2 > len1) {
		stop = len1 - 1;
	}
	ElemType riporto_prev = 0, riporto_new;
	for (int j = 0; j <= stop; ++j) {
		ElemType value1 = ElemCopy(ListGetHeadValue(i1));
		ElemType value2 = ElemCopy(ListGetHeadValue(i2));
		riporto_new = 0;
		ElemType sum = CalcolaSumERiporto(value1, value2, &riporto_prev, &riporto_new);
		out = ListInsertBack(out, &sum);
		i1 = ListGetTail(i1);
		i2 = ListGetTail(i2);
	}
	if (len1 != len2) {
		riporto_new = 0;
		if (len1 > len2) {
			out = AddSfasati(out, i1, &riporto_prev, &riporto_new);
		} else {
			out = AddSfasati(out, i2, &riporto_prev, &riporto_new);
		}
	}
	if (riporto_new) {
		out = ListInsertBack(out, &riporto_new);
	}
	return out;
}