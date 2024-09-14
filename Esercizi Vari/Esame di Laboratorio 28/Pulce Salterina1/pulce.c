#include "pulce.h"

size_t  GetDaFareERimasti(const ElemType* curr_val, size_t* rimasti, bool* avanti) {
	size_t dafare = (abs(*curr_val));
	*avanti = true;
	if (*curr_val < 0) {
		*avanti = false;
	}
	if (*curr_val == 0) {
		*rimasti = 0;
		dafare = 0;
	}
	if (dafare < *rimasti) {
		*rimasti -= dafare;
	}
	if (dafare >= *rimasti) {
		dafare = *rimasti;
		*rimasti = 0;
	}
	return dafare;
}

const Item* GetNextPos(const Item* start, size_t dafare, bool avanti) {
	while (dafare > 0) {
		if ((avanti && DListIsEmpty(DListGetTail(start))) || 
			(!avanti && DListIsEmpty(DListGetPrev(start)))) {
			if (avanti) {
				avanti = false;
			} else {
				avanti = true;
			}
		}
		if (avanti) {
			start = DListGetTail(start);
		} else {
			start = DListGetPrev(start);
		}
		--dafare;
	}
	return start;
}

const Item* CalcolaPercorso(const Item* start, size_t n) {
	if (DListIsEmpty(start)) {
		return NULL;
	}
	if ((DListIsEmpty(DListGetTail(start)) && DListIsEmpty(DListGetPrev(start))) || n == 0) {
		return start;	//Lista composta da un solo elemento
	}
	size_t rimasti = n;
	while (rimasti > 0) {
		const ElemType* curr_val = DListGetHeadValue(start);
		bool avanti;
		size_t dafare = GetDaFareERimasti(curr_val, &rimasti, &avanti);
		start = GetNextPos(start, dafare, avanti);
	}
	return start;
}