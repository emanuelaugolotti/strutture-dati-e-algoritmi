#include "list.h"
#include <stdbool.h>
#include <math.h>

bool IsInterno(const ElemType* val, double r) {
	double s = val->x * val->x + val->y * val->y;
	double d = sqrt(s);
	if (d < r) {
		return true;
	}
	return false;
}

Item* CreaDaInterni(const Item* i, double r) {
	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}
	Item* out = ListCreateEmpty();
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		const ElemType* val = ListGetHeadValue(i);
		if (IsInterno(val, r)) {
			out = ListInsertBack(out, val);
		}
	}
	return out;
}