#include "list.h"

Item* CreaDaMinori(const Item* i, int v) {
	if (ListIsEmpty(i)) {
		return NULL;
	}
	Item* out = ListCreateEmpty();
	while (!ListIsEmpty(i)) {
		const ElemType* val = ListGetHeadValue(i);
		if (ElemCompare(val, &v) <= 0) {
			out = ListInsertBack(out, val);
		}
		i = ListGetTail(i);
	}
	return out;
}