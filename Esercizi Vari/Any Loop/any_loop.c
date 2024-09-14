#include "list.h"

bool IsRipetuto(const Item* i, const Item* next, size_t count) {
	for (size_t j = 0; j < count; ++j) {
		if (i == next) {
			return true;
		}
		i = ListGetTail(i);
	}
	return false;
}

bool AnyLoop(const Item* i) {
	if (ListIsEmpty(i)) {
		return false;
	}
	const Item* curr = i;
	size_t count = 0;
	while (!ListIsEmpty(curr)) {
		const Item* next = ListGetTail(curr);
		if (IsRipetuto(i, next, count)) {
			return true;
		}
		curr = next;
		++count;
	}
	return false;
}