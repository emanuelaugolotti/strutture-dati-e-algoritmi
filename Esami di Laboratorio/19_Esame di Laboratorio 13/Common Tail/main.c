#include "list.h"

extern const Item* CommonTail(const Item* i1, const Item* i2);

int main(void) {
	int v[] = { 5, 6, 7, 8, 9 };
	size_t v_size1 = sizeof(v) / sizeof(int);

	Item* list1 = ListCreateEmpty();
	for (size_t i = 0; i < v_size1; ++i) {
		list1 = ListInsertBack(list1, &v[i]);
	}

	int e[] = { 5, 6, 7, 8, 9 };
	size_t v_size2 = sizeof(e) / sizeof(int);

	Item* list2 = ListCreateEmpty();
	for (size_t i = 0; i < v_size2; ++i) {
		list2 = ListInsertBack(list2, &e[i]);
	}

	const Item* ris = CommonTail(list1, list2);
	ListWriteStdout(ris);

	ListDelete(list1);
	ListDelete(list2);
	return 0;
}