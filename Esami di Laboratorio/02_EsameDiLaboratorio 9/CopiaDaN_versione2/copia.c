#include "elemtype.h"
#include "list.h"

#include <stdlib.h>

Item* CopiaDaN(const Item* i, int n) {
	Item* out = ListCreateEmpty();

	int count = 1;
	while (count < n && !ListIsEmpty(i)) {
		i = ListGetTail(i);
		++count;
	}

	if (count < n) {
		return out;
	}

	while (!ListIsEmpty(i)) {
		const ElemType* curr = ListGetHeadValue(i);
		out = ListInsertBack(out, curr);
		i = ListGetTail(i);
	}
	
	return out;
}