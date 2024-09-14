//Time: 28 min
#include "remove.h"

bool IsDuplicato(Item* prev, Item* i) {
	if (ListIsEmpty(prev)) {
		return false;
	}
	const ElemType* val1 = ListGetHeadValue(prev);
	const ElemType* val2 = ListGetHeadValue(i);
	if (ElemCompare(val1, val2) == 0) {
		return true;
	}
	return false;
}

Item* EliminaDuplicato(Item* i) {
	Item* tmp = i;
	i = ListGetTail(i);
	free(tmp);
	return i;
}

Item* RemoveDuplicates(Item* i) {
	if (ListIsEmpty(i)) {
		return i;
	}
	Item* root = i;
	Item* prev = ListCreateEmpty();
	while (!ListIsEmpty(i)) {
		bool ris = IsDuplicato(prev, i);
		if (ris) {
			Item* succ = EliminaDuplicato(i);
			prev->next = succ;
			i = succ;
		} else {
			prev = i;
			i = ListGetTail(i);
		}
	}
	return root;
}