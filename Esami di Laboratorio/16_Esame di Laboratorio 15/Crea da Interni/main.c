#include "list.h"
#include <crtdbg.h>

extern Item* CreaDaInterni(const Item* i, double r);

int main(void) {
	ElemType punti[] = { { 1,1}, { 2, 1}, { 6,10}, { 2,2}, {12, -4}, { 9, 1}, { 0, 3} };
	size_t size = sizeof(punti) / sizeof(ElemType);
	Item* l = ListCreateEmpty();
	for (size_t i = 0; i < size; ++i) {
		l = ListInsertBack(l, punti + i);
	}
	ListWriteStdout(l);

	Item* ris = CreaDaInterni(l, 3);
	ListWriteStdout(ris);
	
	ListDelete(ris);
	ListDelete(l);
	_CrtDumpMemoryLeaks();
	return 0;
}