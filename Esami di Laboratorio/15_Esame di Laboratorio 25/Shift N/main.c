#include "shift.h"

int main(void) {
	ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	
	Item* l = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		l = ListInsertBack(l, v + i);
	}
	ListWriteStdout(l);

	/*Item* ris = ShiftN(l, 2);
	ListWriteStdout(ris);*/
	/*Item* ris = ShiftN(l, 3);
	ListWriteStdout(ris);*/
	Item* ris = ShiftN(l, 33);
	ListWriteStdout(ris);
	
	ListDelete(l);
	return 0;
}