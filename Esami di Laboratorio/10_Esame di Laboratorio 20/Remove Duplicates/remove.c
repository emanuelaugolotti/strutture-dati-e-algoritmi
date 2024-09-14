//Time: 39min
#include "remove.h"

Item* RemoveDuplicates(Item* i) {
	if (ListIsEmpty(i)) {
		return NULL;
	}
	if (ListIsEmpty(ListGetTail(i))) {
		return i;
	}
	Item* out = i;
	Item* prev = out;
	Item* curr = ListGetTail(i);
	Item* succ = NULL;
	while (!ListIsEmpty(curr)) {
		const ElemType* elemcurr = ListGetHeadValue(curr);
		const ElemType* elemprev = ListGetHeadValue(prev);
		if (ElemCompare(elemcurr, elemprev) == 0) {
			if (!ListIsEmpty(ListGetTail(i))) {	//curr non è l'ultimo elemento della lista
				succ = ListGetTail(curr);
				prev->next = succ;
				curr->next = NULL;
				ListDelete(curr);
				curr = succ;
			} else {	//curr è l'ultimo elemento della lista
				prev->next = NULL;
				curr->next = NULL;
				ListDelete(curr);
				curr = prev;
			}
		} else {
			Item* tmp = curr;
			curr = ListGetTail(curr);
			prev = tmp;
		}
	}
	return out;
}