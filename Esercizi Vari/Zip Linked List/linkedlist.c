//https://github.com/lee-hen/Algoexpert/tree/master/very_hard/27_zip_linked_list
#include "list.h"

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

Item* ZipLinkedList(Item* l) {
	size_t len = Lenght(l);
	if (len == 1) {
		return l;
	}
	Item* curr = l;
	Item* succ = ListGetTail(l);
	Item* last = NULL;
	int last_pos = (int)len - 1;
	while (last_pos > 1) {
		last = GetItem(curr, last_pos);
		Item* prec_last = GetItem(curr, last_pos - 1);
		prec_last->next = NULL;
		curr->next = last;
		last->next = succ;
		curr = succ;
		succ = ListGetTail(succ);
		last_pos -= 2;
	}
	return l;
}