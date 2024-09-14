//Time: 47 min
#include "shift.h"

size_t Lenght(Item* list) {
	size_t len = 0;
	for (; !ListIsEmpty(list); list = ListGetTail(list)) {
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
	if (ListIsEmpty(list) || n == 0) {
		return list;
	}
	size_t len = Lenght(list);
	if (len < 2) {
		return list;
	}
	/*if (n >= len) {
		n %= (len - 1);
		if (n == 0) {
			n = len - 1;
		}
	}*/
	while (n >= len) {
		n -= (len - 1);
	}
	Item* root = ListGetTail(list);
	Item* first = GetItem(list, n);
	Item* last = GetItem(list, n + 1);
	first->next = list;
	list->next = last;
	return root;
}