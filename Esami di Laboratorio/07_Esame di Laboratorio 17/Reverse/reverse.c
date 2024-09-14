//Time: 34 min
#include "list.h"
#include <stdlib.h>

size_t Lenght(Item* i) {
	size_t len = 0;
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		++len;
	}
	return len;
}

Item* GetItem(Item* i, size_t pos) {
	size_t count = 0;
	Item* tmp = NULL;
	while (count <= pos) {
		tmp = i;
		i = ListGetTail(i);
		++count;
	}
	return tmp;
}

extern Item* Reverse(Item* i) {
	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}
	size_t len = Lenght(i);
	size_t pos = len - 1;
	Item* newroot = ListCreateEmpty();
	for (size_t j = 1; j < len; ++j) {
		Item* curr = GetItem(i, pos);
		if (j == 1) {
			newroot = curr;
		}
		--pos;
		Item* prev = GetItem(i, pos);
		curr->next = prev;
	}
	i->next = NULL;
	return newroot;
}
