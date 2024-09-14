//Time: 37 min
#include "doublelist.h"

Item* GetLast(Item* i) {
	Item* prev = DListCreateEmpty();
	while (!DListIsEmpty(i)) {
		prev = i;
		i = DListGetTail(i);
	}
	return prev;
}

void Collega(Item** prec, Item* succ) {
	if (!DListIsEmpty(*prec)) {
		(*prec)->next = succ;
	}
	Item* last = GetLast(succ);
	succ->prev = (*prec);
	*prec = last;
}

Item* ConcatenaN(Item** v, size_t v_size) {
	if (v_size == 0) {
		return DListCreateEmpty();
	}
	Item* out = DListCreateEmpty();
	Item* prec = DListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		if (!DListIsEmpty(v[i])) {
			if (DListIsEmpty(out)) {
				out = v[i];
			}
			Collega(&prec, v[i]);
		}
	}
	return out;
}