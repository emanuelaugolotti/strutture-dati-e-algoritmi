#include "sum_dlist.h"

int main(void) {
    //Lista doppiamente concatenata
    ElemType v[] = { 9, 5, 4 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item* list1 = DListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list1 = DListInsertBack(list1, &v[i]);
    }

    ElemType v2[] = { 6, 9 };
    size_t v2_size = sizeof(v2) / sizeof(ElemType);
    Item* list2 = DListCreateEmpty();
    for (size_t i = 0; i < v2_size; ++i) {
        list2 = DListInsertBack(list2, &v2[i]);
    }

    Item* ris = DListSum(list1, list2);
    DListWriteStdout(ris);
    
    DListDelete(list1);
    DListDelete(list2);
    DListDelete(ris);
    return 0;
}