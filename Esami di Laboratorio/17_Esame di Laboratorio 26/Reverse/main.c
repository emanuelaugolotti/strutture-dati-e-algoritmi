#include "reverse.h"

int main(void) {
	ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Item* l = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		l = ListInsertBack(l, v + i);
	}
	ListWriteStdout(l);

	/*Item* ris1 = Reverse(l, 3);
	ListWriteStdout(ris1);*/
	/*Item* ris2 = Reverse(l, 7);
	ListWriteStdout(ris2);*/
	/*Item* ris3 = Reverse(l, 12);
	ListWriteStdout(ris3);*/
	Item* ris4 = Reverse(l, 0);
	ListWriteStdout(ris4);

	ListDelete(l);
	return 0;
}