#include "differenza.h"

Item* ListCreateFromVector(ElemType* v, size_t v_size) {
	Item* l = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		l = ListInsertBack(l, v + i);
	}
	return l;
}

int main(void) {
	ElemType v1[] = { '7','1','0','1' };
	ElemType v2[] = { '3','2','4' };
	size_t v1_size = sizeof(v1) / sizeof(ElemType);
	size_t v2_size = sizeof(v2) / sizeof(ElemType);
	
	Item* l1 = ListCreateFromVector(v1, v1_size);
	Item* l2 = ListCreateFromVector(v2, v2_size);
	ListWriteStdout(l1);
	ListWriteStdout(l2);

	Item* diff = Differenza(l1, l2);
	ListWriteStdout(diff);

	ListDelete(l1);
	ListDelete(l2);
	
	return 0;
}