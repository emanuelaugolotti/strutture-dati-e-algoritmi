#include "pulce.h"

size_t GetLenghtPosCurrInizio(const Item* start, size_t* pos_curr, const Item** iniziolista) {
	const Item* prev = start;
	size_t count = 0;
	while (!DListIsEmpty(start)) {
		prev = start;
		++count;
		start = DListGetPrev(start);
	}
	*iniziolista = prev;
	*pos_curr = count - 1;
	size_t len = 0;
	while (!DListIsEmpty(prev)) {
		++len;
		prev = DListGetTail(prev);
	}
	return len;
}

const Item* GetItem(const Item* l, size_t pos) {
	for (size_t i = 0; i < pos; ++i) {
		l = DListGetTail(l);
	}
	return l;
}

size_t GetNextPos(size_t* rimasti, const ElemType* val_curr, size_t len, size_t pos_curr) {
	size_t dafare;
	bool avanti = true;
	if (*val_curr < 0) {
		avanti = false;
	}
	if (abs(*val_curr) < (int)*rimasti) {
		dafare = abs(*val_curr);
		*rimasti -= dafare;
	} else {
		dafare = *rimasti;
		*rimasti = 0;
	}
	while (dafare > 0) {
		if (avanti && pos_curr == len - 1) {
			avanti = false;
		}
		if (!avanti && pos_curr == 0) {
			avanti = true;
		}
		if (avanti) {
			++pos_curr;
		} else {
			--pos_curr;
		}
		--dafare;
	}

	return pos_curr;
}

const Item* CalcolaPercorso(const Item* start, size_t n) {
	if (start == NULL || n == 0) {
		return NULL;
	}
	if (DListIsEmpty(DListGetTail(start)) || DListIsEmpty(DListGetPrev(start))) {
		return start;
	}
	const Item* iniziolista = DListCreateEmpty();
	size_t pos_curr;
	size_t len = GetLenghtPosCurrInizio(start, &pos_curr, &iniziolista);
	size_t rimasti = n;
	while (rimasti > 0) {
		const ElemType* val_curr = DListGetHeadValue(start);
		pos_curr = GetNextPos(&rimasti, val_curr, len, pos_curr);
		start = GetItem(iniziolista, pos_curr);
	}
	return start;
}