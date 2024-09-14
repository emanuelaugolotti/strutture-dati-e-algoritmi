#include "list.h"
#include <crtdbg.h>

extern Item* Rotate(Item* i, int n);

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
    ListWriteStdout(list);

    Item* ris = Rotate(list, 2);
    ListWriteStdout(ris);

    ListDelete(ris);
    _CrtDumpMemoryLeaks();
    return 0;
}