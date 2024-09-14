#include "cc.h"

int main(void) {
	ElemType v[] = { 0, 1, 3, 4 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	Item* l = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		l = ListInsertBack(l, v + i);
	}
	ListWriteStdout(l);
	ElemType vettore[] = { 3 };
	size_t vettore_size = sizeof(vettore) / sizeof(ElemType);

	int ris = ComponentiConnesse(l, vettore, vettore_size);
	printf("Numero componenti connesse: %d", ris);

	ListDelete(l);
	return 0;
}