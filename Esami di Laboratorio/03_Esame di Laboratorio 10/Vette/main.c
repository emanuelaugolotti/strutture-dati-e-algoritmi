#include "list.h"
#include <stdlib.h>

extern int ContaVette(const Item* i);

int main(void) {
	Item* list = ListCreateEmpty();
	ElemType v[] = { 7, 2, 5, 4 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	for (size_t i = 0; i < v_size; ++i) {
		list = ListInsertBack(list, v + i);
	}

	int count = ContaVette(list);

	ListDelete(list);	// Libero la memoria
	
	return 0;
}