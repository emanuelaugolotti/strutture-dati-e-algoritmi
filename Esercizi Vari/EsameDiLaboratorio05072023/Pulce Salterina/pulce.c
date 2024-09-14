#include "pulce.h"

const Item* GetItem(const Item* l, size_t pos, bool* avanti) {
	for (size_t i = 0; i < pos; ++i) {
		if (avanti) {
			l = DListGetTail(l);
		} else {
			l = DListGetPrev(l);
		}
	}
	return l;
}

size_t GetNextPos(size_t len, const ElemType* val, bool* avanti, int currpos, size_t n, int* nsaltifatti) {
	if (*val >= 0) {
		*avanti = true;
	} else {
		*avanti = false;
	}
	int nrimasti = (int)n - *nsaltifatti;
	int dafare, nextpos;
	if (abs(*val) <= nrimasti) {
		dafare = abs(*val);
	} else {
		dafare = nrimasti;
	}
	*nsaltifatti += dafare;
	nextpos = currpos + dafare;
	int r;
	if (nextpos >= len) {
		r = (int)len - nextpos;
	}
	if (nextpos < 0) {
		r = abs(nextpos);
	}
	while (nextpos >= len) {
		nextpos -= (int)len;
	}
	return nextpos;
}

size_t Lenght(const Item* l) {
	size_t len = 0;
	while (!DListIsEmpty(l)) {
		++len;
		l = DListGetTail(l);
	}
	return len;
}

const Item* CalcolaPercorso(const Item* start, size_t n) {
	if (DListIsEmpty(start)) {
		return NULL;
	}
	size_t len = Lenght(start);
	const Item* arrivo = NULL;
	bool done = false;
	int nsaltifatti = 0, currpos = 0;
	while (!done) {
		const ElemType* valcurr = DListGetHeadValue(start);
		if (*valcurr == 0) {
			done = true;
		} else {
			bool avanti;
			int nextpos = GetNextPos(len, valcurr, &avanti, currpos, n, &nsaltifatti);
			start = GetItem(start, nextpos, &avanti);
			currpos = nextpos;
		}
		if (nsaltifatti == n) {
			done = true;
		}
	}
	arrivo = start;
	return arrivo;
}