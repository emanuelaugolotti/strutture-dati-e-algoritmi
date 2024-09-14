//Time: 27 min
#include "cc.h"

bool IsIn(const ElemType* v, const ElemType* val, size_t v_size) {
	for (size_t i = 0; i < v_size; ++i) {
		if (ElemCompare(v + i, val) == 0) {
			return true;
		}
	}
	return false;
}

const Item* GetLastItemStriscia(const Item* i, const ElemType* v, size_t v_size) {
	const Item* prev = i;
	bool done = false;
	while (!done && !ListIsEmpty(i)) {
		const ElemType* val = ListGetHeadValue(i);
		if (!IsIn(v, val, v_size)) {
			done = true;
		}
		prev = i;
		i = ListGetTail(i);
	}
	return prev;
}

int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	if (ListIsEmpty(i) || v_size == 0) {
		return 0;
	}
	int n = 0;
	while (!ListIsEmpty(i)) {
		const ElemType* val = ListGetHeadValue(i);
		if (IsIn(v, val, v_size)) {
			const Item* last = GetLastItemStriscia(i, v, v_size);
			i = last;
			++n;
		}
		i = ListGetTail(i);
	}
	return n;
}