//Time: 1h
#include "reverse.h"

size_t Lenght(Item* l) {
	size_t len = 0;
	while (!ListIsEmpty(l)) {
		++len;
		l = ListGetTail(l);
	}
	return len;
}

Item* GetItem(Item* l, size_t pos) {
	Item* prev = ListCreateEmpty();
	for (size_t i = 0; i <= pos; ++i) {
		prev = l;
		if (!ListIsEmpty(l)) {
			l = ListGetTail(l);
		}
	}
	return prev;
}

void InvertiItem(Item* l, size_t pos) {
	Item* prev = l;
	Item* curr = ListGetTail(l);
	for (size_t i = 0; i < pos; ++i) {
		Item* succ = ListGetTail(curr);
		curr->next = prev;
		prev = curr;
		curr = succ;
	}
}

Item* Reverse(Item* list, int right) {
	if (ListIsEmpty(list)) {
		return list;
	}
	if (right <= 1) {
		return list;
	}
	size_t len = Lenght(list);
	size_t right_new = right;
	if (right >= (int)len) {
		right_new = len;
	}
	Item* ultimo_striscia1 = list;
	Item* primo_striscia1 = GetItem(list, right_new - 1);
	Item* primo_striscia2 = GetItem(list, right_new);
	InvertiItem(list, right_new - 1);
	ultimo_striscia1->next = primo_striscia2;
	return primo_striscia1;
}