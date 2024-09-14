#include "list.h"

void ContaElementi(const Item* i, int* count) {
	while (!ListIsEmpty(i)) {
		++(*count);
		i = ListGetTail(i);
	}
}

const Item* GetItem(const Item* l, int pos) {
	const Item* prev = ListCreateEmpty();
	for (int i = 0; i <= pos; ++i) {
		prev = l;
		l = ListGetTail(l);
	}
	return prev;
}

Item* CopiaLista(const Item* l) {
	Item* out = ListCreateEmpty();
	while (!ListIsEmpty(l)) {
		const ElemType* e = ListGetHeadValue(l);
		out = ListInsertBack(out, e);
		l = ListGetTail(l);
	}
	return out;
}

Item* CopiaDaN(const Item* i, int n) {
	if (ListIsEmpty(i)) {
		return NULL;
	}
	int count = 0;
	ContaElementi(i, &count);
	if (count < n) {
		return NULL;
	}
	const Item* start = GetItem(i, n - 1);
	Item* out = CopiaLista(start);
	return out;
}