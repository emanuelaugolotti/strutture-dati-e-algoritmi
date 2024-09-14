#include "list.h"
#include <stdlib.h>
#include <crtdbg.h>

extern Item* BucketSort(Item* l);

int main(void) {

	ElemType v[] = { 7, 2, 5, 4 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		list = ListInsertBack(list, v + i);
	}
	ListWriteStdout(list);

	Item* list_res = BucketSort(list);

	ListWriteStdout(list_res);
	ListDelete(list_res);

	_CrtDumpMemoryLeaks();
	return 0;
}