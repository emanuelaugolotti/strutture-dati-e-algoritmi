//Time: 59min
#include "reverse.h"

int Lenght(Item* l) {
	int len = 0;
	while (!ListIsEmpty(l)) {
		++len;
		l = ListGetTail(l);
	}
	return len;
}

Item* GetItem(Item* l, int pos, int len) {
	Item* out = ListCreateEmpty();
	if (pos >= len) {
		return out;
	}
	for (int i = 0; i <= pos; ++i) {
		out = l;
		l = ListGetTail(l);
	}
	return out;
}

Item* Reverse(Item* list, int right) {
	int len = Lenght(list);
	if (right <= 1 || ListIsEmpty(list) || len <= 2) {
		return list;
	}
	Item* curr = list;
	Item* last = GetItem(list, right, len);
	int count = 0;
	while (count < right - 1 && !ListIsEmpty(ListGetTail(curr))) {
		Item* succ = ListGetTail(curr);
		curr->next = last;
		last = curr;
		curr = succ;
		++count;
	}
	curr->next = last;
	return curr;
}