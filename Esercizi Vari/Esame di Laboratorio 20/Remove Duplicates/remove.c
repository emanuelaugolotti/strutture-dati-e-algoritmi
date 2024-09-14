#include "remove.h"

bool IsDuplicato(Item* i, const ElemType* val_prec) {
	if (ListIsEmpty(i)) {
		return false;
	}
	const ElemType* val_succ = ListGetHeadValue(i);
	if (ElemCompare(val_prec, val_succ) == 0) {
		return true;
	}
	return false;
}

Item* GetNext(Item* prec, Item* curr, const ElemType* val) {
	while (!ListIsEmpty(curr)) {
		const ElemType* val_curr = ListGetHeadValue(curr);
		if (ElemCompare(val_curr, val) != 0) {
			break;
		}
		Item* tmp = curr;
		curr = ListGetTail(curr);
		free(tmp);
	}
	prec->next = curr;
	return curr;
}

Item* RemoveDuplicates(Item* i) {
	if (ListIsEmpty(i)) {
		return NULL;
	}
	Item* out = i;
	while (!ListIsEmpty(i)) {
		const ElemType* val = ListGetHeadValue(i);
		Item* succ = ListGetTail(i);
		bool is_duplicato = IsDuplicato(succ, val);
		if (!is_duplicato) {
			i = succ;
		} else {
			i = GetNext(i, succ, val);
		}
	}
	return out;
}