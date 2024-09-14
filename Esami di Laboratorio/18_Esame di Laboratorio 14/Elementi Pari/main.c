#include "list.h"
#include <stdlib.h>

extern Item* ElementiPari(const Item* i);

int main(void) {
	ElemType v[] = { 7, 2, 5, 8, 6, 4 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	Item* l = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		l = ListInsertBack(l, v + i);
	}
	ListWriteStdout(l);

	Item* ris = ElementiPari(l);
	ListWriteStdout(ris);

	ListDelete(l);
	ListDelete(ris);
	return 0;
}