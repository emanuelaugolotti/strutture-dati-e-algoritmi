//Time: 36 min
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

void Invert(Item* curr, Item* stop, Item* prev) {
	while (curr != stop) {
		Item* succ = ListGetTail(curr);
		curr->next = prev;
		prev = curr;
		curr = succ;
	}
}

Item* Reverse(Item* list, int right) {
	if (right <= 1) {
		return list;
	}
	int len = Lenght(list);
	if (right >= len) {
		right = len;
	}
	Item* start_striscia2 = GetItem(list, right);
	Item* start_striscia1 = GetItem(list, right - 1);
	Item* stop_striscia1 = list;
	Invert(stop_striscia1, start_striscia2, start_striscia2);
	return start_striscia1;
}