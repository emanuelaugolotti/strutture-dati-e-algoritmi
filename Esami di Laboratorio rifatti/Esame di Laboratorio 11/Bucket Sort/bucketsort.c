#include "list.h"
#include <stdlib.h>

int CalcolaIndice(int min, int max, int n, ElemType e) {
	int num = (n - 1) * (e - min);
	int den = max - min;
	return num / den;
}

void PopolaVettore(Item* v[], int size) {
	for (int i = 0; i < size; ++i) {
		v[i] = ListCreateEmpty();
	}
}

void PopolaBucket(Item* l, Item* v[]) {
	int min, max, n;
	GetMinMaxSize(l, &min, &max, &n);
	while (!ListIsEmpty(l)) {
		ElemType e = ElemCopy(ListGetHeadValue(l));
		int index = CalcolaIndice(min, max, n, e);
		v[index] = ListInsertBack(v[index], &e);
		Item* tmp = l;
		l = ListGetTail(l);
		free(tmp);
	}
}

Item* BucketSort(Item* l) {
	int min, max, n;
	GetMinMaxSize(l, &min, &max, &n);
	if (n == 0) {
		return ListCreateEmpty();
	}
	if (n == 1) {
		return l;
	}
	Item** v = malloc(n * sizeof(Item*));
	PopolaVettore(v, n);
	PopolaBucket(l, v);
	Item* out = ListCreateEmpty();
	for (int i = 0; i < n; ++i) {
		Item* ris = BucketSort(v[i]);
		out = ConcatList(out, ris);
	}
	free(v);
	return out;
}