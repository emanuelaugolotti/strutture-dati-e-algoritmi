#include "list.h"
#include <stdlib.h>

Item* CreateBucketVector(int n) {
	Item* v = malloc(n * sizeof(Item));
	for (int i = 0; i < n; ++i) {
		v[i].next = ListCreateEmpty();
	}
	return v;
}

int SearchIndex(int n, int max, int min, const ElemType* e) {
	return (n - 1) * (*e - min) / (max - min);
}

void InserisciElementiNelBucketVector(Item* l, Item* bucket_vector, int min, int max, int n) {
	Item* tmp = l;
	for (; !ListIsEmpty(l); l = ListGetTail(l)) {
		const ElemType* value = ListGetHeadValue(l);
		int index = SearchIndex(n, max, min, value);
		bucket_vector[index].next = ListInsertBack(bucket_vector[index].next, value);
	}
	ListDelete(tmp);
}

void DeleteBucketVector(Item* v, int n) {
	for (int i = 0; i < n; ++i) {
		ElemDelete(&v[i].value);
	}
	free(v);
}

Item* BucketSort(Item* l) {
	if (ListIsEmpty(l)) {
		return ListCreateEmpty();
	}
	
	if (ListIsEmpty(ListGetTail(l))) {	//Lista formata da un solo elemento
		return l;
	}
	
	int min, max, n;
	GetMinMaxSize(l, &min, &max, &n);
	Item* bucket_vector = CreateBucketVector(n);
	InserisciElementiNelBucketVector(l, bucket_vector, min, max, n);
	Item* root = ListCreateEmpty();
	Item* list = ListCreateEmpty();
	for (int i = 0; i < n; ++i) {	//Scorro il vettore di n bucket
		if (!ListIsEmpty(bucket_vector + i) && !ListIsEmpty(ListGetTail(bucket_vector + i))) {
			list = BucketSort(ListGetTail(bucket_vector + i));
			root = ConcatList(root, list);
		}
	}
	DeleteBucketVector(bucket_vector, n);
	return root;
}