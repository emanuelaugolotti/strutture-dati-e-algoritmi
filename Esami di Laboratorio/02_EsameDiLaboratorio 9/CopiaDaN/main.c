#include "elemtype.h"
#include "list.h"

#include <stdlib.h>

extern Item* CopiaDaN(const Item* i, int n);

int main(void) {

	ElemType v[] = { 12, 2, 37, 4 };
	size_t size = sizeof(v) / sizeof(ElemType);

	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < size; ++i) {
		list = ListInsertBack(list, v + i);
	}
	
	Item* ris = CopiaDaN(list, 2);

	ListDelete(ris);

	return 0;
}