#include "list.h"
#include <stdlib.h>
#include <crtdbg.h>

extern Item* Sum(const Item* i1, const Item* i2);

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    ElemType e1[] = { 7 }; //4527
    size_t e1_size = sizeof(e1) / sizeof(ElemType);
    Item* l1 = ListCreateFromVector(e1, e1_size);
    ListWriteStdout(l1);
   
    ElemType e2[] = { 3 };    //423
    size_t e2_size = sizeof(e2) / sizeof(ElemType);
    Item* l2 = ListCreateFromVector(e2, e2_size);
    ListWriteStdout(l2);

    Item* res = Sum(l1, l2);
    ListWriteStdout(res);

    ListDelete(l1);
    ListDelete(l2);
    ListDelete(res);

	_CrtDumpMemoryLeaks();
	return 0;
}