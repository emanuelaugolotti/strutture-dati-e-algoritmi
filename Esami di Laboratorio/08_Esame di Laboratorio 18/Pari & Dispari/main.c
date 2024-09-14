#include "list.h"

extern Item* PariDispari(Item* i);

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    int v[] = { 1, 2, 3, 4, 5, 6 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item* list = ListCreateFromVector(v, v_size);
    ListWriteStdout(list);

    Item* ris = PariDispari(list);

    ListDelete(list);
    return 0;
}