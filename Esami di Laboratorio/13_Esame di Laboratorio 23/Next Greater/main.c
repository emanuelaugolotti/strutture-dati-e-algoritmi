#include "next_greater.h"

int main(void) {
	ElemType v[] = { 2, 3, 1, 4, 7, 2 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	Item* l = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		l = ListInsertBack(l, v + i);
	}
	ListWriteStdout(l);

	size_t answer_size;
	Item* ris = NextGreater(l, &answer_size);

	ListDelete(l);

	return 0;
}