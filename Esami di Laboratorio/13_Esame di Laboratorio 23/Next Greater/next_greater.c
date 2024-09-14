//Time: 38 min
#include "next_greater.h"

size_t Lenght(const Item* l) {
	size_t len = 0;
	while (!ListIsEmpty(l)) {
		++len;
		l = ListGetTail(l);
	}
	return len;
}

const Item* FindNext(const Item* l, const ElemType* val) {
	while (!ListIsEmpty(l)) {
		const ElemType* v = ListGetHeadValue(l);
		if (ElemCompare(v, val) > 0) {
			return l;
		}
		l = ListGetTail(l);
	}
	return NULL;
}

ElemType* NextGreater(const Item* list, size_t* answer_size) {
	*answer_size = 0;
	if (ListIsEmpty(list) || answer_size == NULL) {
		return NULL;
	}
	size_t len = Lenght(list);
	*answer_size = len;
	int* answer = malloc(len * sizeof(int));
	for (size_t i = 0; i < len; ++i) {
		const ElemType* val = ListGetHeadValue(list);
		const Item* next = FindNext(list, val);
		if (next != NULL) {
			answer[i] = ElemCopy(ListGetHeadValue(next));
		} else {
			answer[i] = INT_MIN;
		}
		list = ListGetTail(list);
	}
	return answer;
}