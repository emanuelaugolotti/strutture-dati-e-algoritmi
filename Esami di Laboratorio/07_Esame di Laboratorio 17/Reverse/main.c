#include "list.h"
#include <stdlib.h>
#include <crtdbg.h>

extern Item* Reverse(Item* i);

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    int v[] = { 1, 3, 4, 7, 8 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item* list = ListCreateFromVector(v, v_size);

    Item* ris = Reverse(list);

    ListDelete(ris);
    _CrtDumpMemoryLeaks();
    return 0;
}