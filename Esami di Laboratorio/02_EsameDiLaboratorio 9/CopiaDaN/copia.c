// 34 min
#include "elemtype.h"
#include "list.h"

#include <stdlib.h>

int Lenght(const Item* i) {
	int count = 0;
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		++count;
	}
	return count;
}

static Item* CopiaDaNRec(const Item* i, int n, int count) {
	//caso base
	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}

	const ElemType* curr = ListGetHeadValue(i);
	i = ListGetTail(i);
	Item* out = CopiaDaNRec(i, n, count + 1);
	if (count >= n) {
		out = ListInsertHead(curr, out);
	}
	return out;
}

Item* CopiaDaN(const Item* i, int n) {
	if (ListIsEmpty(i)) {
		return NULL;
	}
	
	int len = Lenght(i);
	if (len < n) {
		return NULL;
	}

	Item* out = CopiaDaNRec(i, n, 1);
	return out;
}