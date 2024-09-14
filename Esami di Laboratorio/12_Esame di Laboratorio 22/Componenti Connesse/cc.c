#include "cc.h"

bool IsIn(const ElemType* v, size_t v_size, const ElemType* val) {
	for (size_t i = 0; i < v_size; ++i) {
		if (ElemCompare(v + i, val) == 0) {
			return true;
		}
	}
	return false;
}

const Item* CercaPrimo(const Item* i, const ElemType* v, size_t v_size) {
	while (!ListIsEmpty(i)) {
		const ElemType* value = ListGetHeadValue(i);
		if (IsIn(v, v_size, value)) {
			return i;
		}
		i = ListGetTail(i);
	}
	return NULL;
}

const Item* CercaUltimo(const Item* first, const ElemType* v, size_t v_size) {
	if (ListIsEmpty(first) || ListIsEmpty(ListGetTail(first))) {
		return first;
	}
	const Item* last = NULL;
	const ElemType* value = ListGetHeadValue(first);
	while (IsIn(v,v_size,value) && !ListIsEmpty(first)) {
		last = first;
		first = ListGetTail(first);
		if (ListIsEmpty(first)) {
			break;
		}
		value = ListGetHeadValue(first);
	}
	return last;
}

int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	if (ListIsEmpty(i) || v == NULL || v_size == 0) {
		return 0;
	}
	int n = 0;
	while (!ListIsEmpty(i)) {
		const Item* first = CercaPrimo(i, v, v_size);
		const Item* last = CercaUltimo(first, v, v_size);
		if (first == NULL && last == NULL) {
			break;
		}
		++n;
		if (ListIsEmpty(last)) {
			break;
		}
		i = ListGetTail(last);
	}
	return n;
}