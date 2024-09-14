#include "list.h"

const Item* EsistePuntatoreUguale(const Item* curr, const Item* i) {
	while (!ListIsEmpty(i)) {
		if (curr == i) {
			return i;
		}
		i = ListGetTail(i);
	}
	return NULL;
}

const Item* CommonTail(const Item* i1, const Item* i2) {
	if (ListIsEmpty(i1) || ListIsEmpty(i2)) {
		return NULL;
	}
	const Item* out = ListCreateEmpty();
	while (!ListIsEmpty(i1)) {
		const Item* curr = i1;
		const Item* ris = EsistePuntatoreUguale(curr, i2);
		if (!ListIsEmpty(ris)) {
			out = curr;
			break;
		}
		i1 = ListGetTail(i1);
	}
	return out;
}