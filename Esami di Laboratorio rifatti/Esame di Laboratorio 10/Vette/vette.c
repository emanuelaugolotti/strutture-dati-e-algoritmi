#include "list.h"

bool IsVetta(const ElemType* e, const Item* i) {
	if (ListIsEmpty(i)) {
		return true;
	}
	while (!ListIsEmpty(i)) {
		const ElemType* val = ListGetHeadValue(i);
		if (ElemCompare(e, val) <= 0) {
			return false;
		}
		i = ListGetTail(i);
	}
	return true;
}

int ContaVette(const Item* i) {
	if (ListIsEmpty(i)) {
		return 0;
	}
	int count = 0;
	while (!ListIsEmpty(i)) {
		const ElemType* e = ListGetHeadValue(i);
		i = ListGetTail(i);
		bool vetta = IsVetta(e, i);
		if (vetta) {
			++count;
		}
	}
	return count;
}