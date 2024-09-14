//Time: 28 min
#include "cc.h"

bool IsInVector(const ElemType* val, const ElemType* v, size_t v_size) {
	for (size_t i = 0; i < v_size; ++i) {
		if (ElemCompare(val, v + i) == 0) {
			return true;
		}
	}
	return false;
}

const Item* GetNext(const Item* i, const ElemType* v, size_t v_size) {
	if (ListIsEmpty(i)) {
		return i;
	}
	while (!ListIsEmpty(i)) {
		const ElemType* val = ListGetHeadValue(i);
		if (!IsInVector(val, v, v_size)) {
			return i;
		}
		i = ListGetTail(i);
	}
	return i;
}

int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	if (ListIsEmpty(i) || v == NULL || v_size == 0) {
		return 0;
	}
	int n = 0;
	while (!ListIsEmpty(i)) {
		const ElemType* val = ListGetHeadValue(i);
		if (IsInVector(val, v, v_size)) {
			i = GetNext(ListGetTail(i), v, v_size);
			++n;
		} else {
			i = ListGetTail(i);
		}
	}
	return n;
}