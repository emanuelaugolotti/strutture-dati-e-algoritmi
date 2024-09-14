#include "elemtype.h"
#include "list.h"

#include <stdlib.h>
#include <crtdbg.h>

extern Item* CreaDaMinori(const Item* i, int v);

int main(void) {

	ElemType v[] = { 12, 2, 37, 4 };
	
	Item* list = ListCreateEmpty();
	size_t size = sizeof(v) / sizeof(ElemType);
	for (size_t i = 0; i < size; ++i) {
		list = ListInsertBack(list, v + i);
	}

	Item* ris = CreaDaMinori(list, 5);

	//Libero la memoria
	ListDelete(list);
	ListDelete(ris);

	_CrtDumpMemoryLeaks();
	
	return 0;
}