// 22 min
#include "list.h"
#include <stdbool.h>

bool Vetta(const Item* list, const ElemType* value) {
	if (ListIsEmpty(list)) {	// E' l'ultimo elemento della lista
		return true;
	}
	for (; !ListIsEmpty(list); list = ListGetTail(list)) {
		const ElemType* curr = ListGetHeadValue(list);
		if (ElemCompare(value, curr) <= 0) {
			return false;
		}
	}
	return true;
}

int ContaVette(const Item* i) {
	if (ListIsEmpty(i)) {
		return 0;
	}

	int count = 0;
	while (!ListIsEmpty(i)) {
		const ElemType* value_curr = ListGetHeadValue(i);
		if (Vetta(ListGetTail(i), value_curr)) {
			++count;
		}
		i = ListGetTail(i);
	}

	return count;
}