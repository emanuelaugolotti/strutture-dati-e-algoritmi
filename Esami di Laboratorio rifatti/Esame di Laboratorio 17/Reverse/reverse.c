#include "list.h"

Item* Reverse(Item* i) {
	if (ListIsEmpty(i)) {
		return i;
	}
	Item* prev = ListCreateEmpty();
	Item* curr = i;
	while (!ListIsEmpty(curr)) {
		Item* succ = ListGetTail(curr);
		curr->next = prev;
		prev = curr;
		curr = succ;
	}
	return prev;
}