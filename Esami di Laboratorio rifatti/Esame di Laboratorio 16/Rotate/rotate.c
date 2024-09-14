#include "list.h"

Item* GetItem(Item* i, int pos) {
	for (int j = 0; j < pos; ++j) {
		i = ListGetTail(i);
	}
	return i;
}

int Lenght(Item* i) {
	int len = 0;
	while (!ListIsEmpty(i)) {
		++len;
		i = ListGetTail(i);
	}
	return len;
}

Item* Rotate(Item* i, int n) {
	if (ListIsEmpty(i)) {
		return i;
	}
	int len = Lenght(i);
	Item* prev_root = i;
	Item* new_root = GetItem(i, n);
	int len_striscia1 = Lenght(new_root);
	Item* stop_striscia1 = GetItem(new_root, len_striscia1 - 1);
	stop_striscia1->next = prev_root;
	int len_striscia2 = len - len_striscia1;
	Item* stop_striscia2 = GetItem(prev_root, len_striscia2 - 1);
	stop_striscia2->next = NULL;
	return new_root;
}