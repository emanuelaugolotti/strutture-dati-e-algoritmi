#include "doublelist.h"

extern Item* ConcatenaN(Item** v, size_t v_size);

int main(void) {
   //Lista doppiamente concatenata
    ElemType v1[] = { 1, 2, 3 };
    size_t v1_size = sizeof(v1) / sizeof(ElemType);
    Item* list1 = DListCreateEmpty();
    for (size_t i = 0; i < v1_size; ++i) {
        list1 = DListInsertBack(list1, &v1[i]);
    }

    ElemType v2[] = { 4, 5 };
    size_t v2_size = sizeof(v2) / sizeof(ElemType);
    Item* list2 = DListCreateEmpty();
    for (size_t i = 0; i < v2_size; ++i) {
        list2 = DListInsertBack(list2, &v2[i]);
    }

    Item* list3 = NULL;

    ElemType v4[] = { 6 };
    size_t v4_size = sizeof(v4) / sizeof(ElemType);
    Item* list4 = DListCreateEmpty();
    for (size_t i = 0; i < v4_size; ++i) {
        list4 = DListInsertBack(list4, &v4[i]);
    }

    Item* vett[4] = { list1, list2, list3, list4 };
    Item* ris = ConcatenaN(vett, 4);
    DListWriteStdout(ris);

    DListDelete(ris);
    return 0;
}