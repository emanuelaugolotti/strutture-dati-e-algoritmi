#include "reverse.h"

int main(void) {
	ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	size_t e_size = sizeof(e) / sizeof(ElemType);
	Item* l = ListCreateEmpty();
	for (size_t i = 0; i < e_size; ++i) {
		l = ListInsertBack(l, e + i);
	}
	ListWriteStdout(l);
	printf("\n");

	Item* ris = Reverse(l, 12);
	ListWriteStdout(ris);

	ListDelete(l);
	return 0;
}