//Time: 19 min
//https://github.com/lee-hen/Algoexpert/tree/master/very_hard/26_linked_list_palindrome
#include "list.h"

size_t Lenght(const Item* l) {
	size_t len = 0;
	while (!ListIsEmpty(l)) {
		++len;
		l = ListGetTail(l);
	}
	return len;
}

const Item* GetItem(const Item* l, size_t pos) {
	for (size_t i = 0; i < pos; ++i) {
		l = ListGetTail(l);
	}
	return l;
}

bool Palindrome(const Item* l) {
	if (ListIsEmpty(l)) {
		return false;
	}
	size_t start_pos = 0;
	size_t stop_pos = Lenght(l) - 1;
	while (start_pos < stop_pos) {
		const Item* start = GetItem(l, start_pos);
		const Item* stop = GetItem(l, stop_pos);
		const ElemType* val1 = ListGetHeadValue(start);
		const ElemType* val2 = ListGetHeadValue(stop);
		if (ElemCompare(val1, val2) != 0) {
			return false;
		}
		++start_pos;
		--stop_pos;
	}
	return true;
}