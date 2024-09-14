//Time: 1 h
#include "shift.h"

size_t Lenght(Item* l) {
	size_t len = 0;
	while (!ListIsEmpty(l)) {
		++len;
		l = ListGetTail(l);
	}
	return len;
}

Item* GetItem(Item* l, size_t pos) {
	for (size_t i = 0; i < pos; ++i) {
		l = ListGetTail(l);
	}
	return l;
}

size_t GetNewN(size_t n, size_t len) {
	while (n >= len) {
		n -= (len - 1);
	}
	return n;
}

Item* ShiftN(Item* list, size_t n) {
	size_t len = Lenght(list);
	if (len == 0 || len == 1 || n == 0) {
		return list;
	}
	if (n >= len) {
		n = GetNewN(n, len);
	}
	Item* first_striscia1 = ListGetTail(list);
	Item* last_striscia1 = GetItem(list, n);
	Item* first_striscia2 = GetItem(list, n + 1);
	list->next = first_striscia2;
	last_striscia1->next = list;
 	return first_striscia1;
}