//Time: 30 min in totale (compreso il main)
#include "list.h"

bool IsRipetuto(const Item* i, const Item* curr,  size_t count, const Item** tofind) {
	for (size_t j = 0; j < count; ++j) {
		if (i == curr) {
			*tofind = i;
			return true;
		}
		i = ListGetTail(i);
	}
	return false;
}

const Item* FindLoop(const Item* i) {
	size_t count = 0;
	const Item* curr = i;
	const Item* tofind = ListCreateEmpty();
	while (1) {
		if (IsRipetuto(i, curr, count, &tofind)) {
			break;
		}
		curr = ListGetTail(curr);
		++count;
	}
	return tofind;
}