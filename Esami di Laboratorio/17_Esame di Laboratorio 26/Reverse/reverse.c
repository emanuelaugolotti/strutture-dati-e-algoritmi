#include "reverse.h"

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

Item* Reverse(Item* list, int left) {
	if (ListIsEmpty(list)) {
		return NULL;
	}
	size_t len = Lenght(list);
	if (left >= (int)len - 1) {
		return list;
	}
	Item* new_root = ListCreateEmpty();
	Item* new_last = ListCreateEmpty();
	Item* ultimo_primastriscia = ListCreateEmpty();
	if (left > 0) {
		new_root = list;
		new_last = GetItem(list, left);
		ultimo_primastriscia = GetItem(list, left - 1);
	} else {
		new_root = GetItem(list, len - 1);
		new_last = list;
	}
	Item* prev = new_last;
	Item* curr = ListGetTail(prev);
	while (!ListIsEmpty(ListGetTail(curr))) {
		Item* succ = ListGetTail(curr);
		curr->next = prev;
		if (ListIsEmpty(succ)) {
			break;
		}
		prev = curr;
		curr = succ;
	}
	curr->next = prev;
	new_last->next = NULL;
	if (ultimo_primastriscia != NULL) {
		ultimo_primastriscia->next = curr;
	}
	return new_root;
}