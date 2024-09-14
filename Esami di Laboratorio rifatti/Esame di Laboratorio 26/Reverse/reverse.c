//Time: 53 min
#include "reverse.h"

int Lenght(Item* list) {
	int len = 0;
	while (!ListIsEmpty(list)) {
		++len;
		list = ListGetTail(list);
	}
	return len;
}

Item* GetItem(Item* l, int pos) {
	for (int i = 0; i < pos; ++i) {
		l = ListGetTail(l);
	}
	return l;
}

void GetFirstLastStriscia1(Item* list, int left, int len, Item** first, Item** last) {
	if (left == 0) {
		*first = GetItem(list, len - 1);
		*last = *first;
	} else {
		*first = list;
		*last = GetItem(list, left - 1);
	}
}

void GetFirstLastStriscia2(Item* list, int len, int left, Item** first, Item** last) {
	*first = GetItem(list, len - 1);
	if (left == 0) {
		*last = list;
	} else {
		*last = GetItem(list, left);
	}
}

void Inverti(Item* l) {
	Item* prev = ListCreateEmpty();
	while (!ListIsEmpty(l)) {
		Item* succ = ListGetTail(l);
		l->next = prev;
		prev = l;
		l = succ;
	}
}


Item* Reverse(Item* list, int left) {
	int len = Lenght(list);
	if (left >= len - 1 || len == 0) {
		return list;
	}
	Item* first_striscia1 = NULL;
	Item* last_striscia1 = NULL;
	GetFirstLastStriscia1(list, left, len, &first_striscia1, &last_striscia1);
	Item* first_striscia2 = NULL;
	Item* last_striscia2 = NULL;
	GetFirstLastStriscia2(list, len, left, &first_striscia2, &last_striscia2);
	Inverti(last_striscia2);
	if (left != 0) {
		last_striscia1->next = first_striscia2;
	}
	return first_striscia1;
}