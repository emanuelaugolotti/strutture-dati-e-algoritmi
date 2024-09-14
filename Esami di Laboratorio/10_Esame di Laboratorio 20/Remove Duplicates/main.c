#include "remove.h"

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    int v[] = { 1, 2, 2, 4, 5, 5, 5, 8, 8 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item* list = ListCreateFromVector(v, v_size);

    Item* ris = RemoveDuplicates(list);

    ListDelete(list);
    return 0;
}
