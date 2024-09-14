#include "reverse.h"

int Lenght(Item* list) {
	int len = 0;
	for (; !ListIsEmpty(list); list = ListGetTail(list)) {
		++len;
	}
	return len;
}

Item* GetItem(Item* list, int pos) {
	for (int i = 0; i < pos; ++i) {
		list = ListGetTail(list);
	}
	return list;
}

void Invert(Item* curr, Item* prev) {
	while (!ListIsEmpty(curr)) {
		Item* succ = ListGetTail(curr);
		curr->next = prev;
		prev = curr;
		curr = succ;
	}
}

Item* Reverse(Item* list, int left) {
	int len = Lenght(list);
	if (left >= len - 1) {
		return list;
	}
	Item* start_striscia1 = ListCreateEmpty();
	Item* stop_striscia1 = ListCreateEmpty();
	Item* start_striscia2 = ListCreateEmpty();
	Item* stop_striscia2 = ListCreateEmpty();
	if (left <= 0) {
		left = len - 1;
		start_striscia2 = GetItem(list, len - 1);
		stop_striscia2 = list;
	} else {
		start_striscia1 = list;
		stop_striscia1 = GetItem(list, left - 1);
		start_striscia2 = GetItem(list, len - 1);
		stop_striscia2 = GetItem(list, left);
	}
	Invert(stop_striscia2, NULL);
	if (!ListIsEmpty(stop_striscia1)) {
		stop_striscia1->next = start_striscia2;
		return start_striscia1;
	}
	return start_striscia2;
}