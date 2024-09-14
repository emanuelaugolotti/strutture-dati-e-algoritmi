//Time: 52 min
#include "shift.h"

size_t Lenght(Item* l) {
	size_t len = 0;
	for (; !ListIsEmpty(l); l = ListGetTail(l)) {
		++len;
	}
	return len;
}

Item* GetItem(Item* list, size_t pos) {
	for (size_t i = 0; i < pos; ++i) {
		list = ListGetTail(list);
	}
	return list;
}

Item* ShiftN(Item* list, size_t n) {
	size_t len = Lenght(list);
	if (len <= 1 || n == 0) {
		return list;
	}
	while (n >= len) {
		n = (n - len) + 1;
	}
	Item* newroot = ListGetTail(list);
	Item* ultimostriscia = GetItem(list, n);
	Item* succ = GetItem(list, n + 1);
	ultimostriscia->next = list;
	list->next = succ;
	return newroot;
}