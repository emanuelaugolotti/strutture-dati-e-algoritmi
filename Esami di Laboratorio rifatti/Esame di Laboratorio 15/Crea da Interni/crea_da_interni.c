//Time: 19 min
#include "list.h"
#include <math.h>

bool IsIn(const ElemType* point, double r) {
	int xa = point->x;
	int ya = point->y;
	double d = sqrt(xa * xa + ya * ya);
	if (d < r) {
		return true;
	}
	return false;
}

Item* CreaDaInterni(const Item* i, double r) {
	Item* out = ListCreateEmpty();
	while (!ListIsEmpty(i)) {
		const ElemType* point = ListGetHeadValue(i);
		if (IsIn(point, r)) {
			out = ListInsertBack(out, point);
		}
		i = ListGetTail(i);
	}
	return out;
}