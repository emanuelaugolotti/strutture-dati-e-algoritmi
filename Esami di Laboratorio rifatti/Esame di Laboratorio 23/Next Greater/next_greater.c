//Time: 30 min
#include "next_greater.h"

size_t Lenght(const Item* l) {
	size_t len = 0;
	while (!ListIsEmpty(l)) {
		++len;
		l = ListGetTail(l);
	}
	return len;
}

const Item* GetNextItem(const Item* l, const ElemType* val, const ElemType** greater_next) {
	while (!ListIsEmpty(l) && ElemCompare(ListGetHeadValue(l), val) <= 0) {
		l = ListGetTail(l);
	}
	if (ListIsEmpty(l)) {
		return NULL;
	}
	*greater_next = ListGetHeadValue(l);
	return l;
}

ElemType* NextGreater(const Item* list, size_t* answer_size) {
	if (answer_size == NULL) {
		return NULL;
	}
	*answer_size = 0;
	if (ListIsEmpty(list)) {
		return NULL;
	}
	size_t len = Lenght(list);
	*answer_size = len;
	ElemType* out = malloc(len * sizeof(ElemType));
	size_t count = 0;
	for (; !ListIsEmpty(list); list = ListGetTail(list)) {
		const ElemType* val = ListGetHeadValue(list);
		const ElemType* greater_next;
		const Item* next = GetNextItem(list, val, &greater_next);
		if (next != NULL) {
			out[count] = ElemCopy(greater_next);
		} else {
			out[count] = INT_MIN;
		}
		++count;
	}
	return out;
}