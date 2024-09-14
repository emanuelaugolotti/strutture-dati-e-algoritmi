#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

bool IsPari(size_t n) {
	if (n % 2 == 0) {
		return true;
	}
	return false;
}


Item* ElementiPari(const Item* i) {
	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}
	Item* out = ListCreateEmpty();
	size_t pos = 0;
	while (!ListIsEmpty(i)) {
		if (IsPari(pos)) {
			const ElemType* val = ListGetHeadValue(i);
			out = ListInsertBack(out, val);
		}
		i = ListGetTail(i);
		++pos;
	}
	return out;
}