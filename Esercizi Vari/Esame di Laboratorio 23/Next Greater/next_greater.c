#include "next_greater.h"

size_t Lenght(const Item* list) {
	size_t len = 0;
	while (!ListIsEmpty(list)) {
		++len;
		list = ListGetTail(list);
	}
	return len;
}

ElemType GetNextGreater(const Item* list, const ElemType* val) {
	if (ListIsEmpty(list)) {
		return INT_MIN;
	}
	while (!ListIsEmpty(list)) {
		const ElemType* valcurr = ListGetHeadValue(list);
		if (ElemCompare(valcurr, val) > 0) {
			return *valcurr;
		}
		list = ListGetTail(list);
	}
	return INT_MIN;
}

ElemType* NextGreater(const Item* list, size_t* answer_size) {
	if (answer_size == NULL) {
		return NULL;
	}
	*answer_size = 0;
	if (ListIsEmpty(list)) {
		return NULL;
	}
	*answer_size = Lenght(list);
	ElemType* answer = malloc(*answer_size * sizeof(ElemType));
	size_t pos = 0;
	while (!ListIsEmpty(list)) {
		const ElemType* val = ListGetHeadValue(list);
		ElemType next_greater = GetNextGreater(ListGetTail(list), val);
		answer[pos] = next_greater;
		list = ListGetTail(list);
		++pos;
	}
	return answer;
}