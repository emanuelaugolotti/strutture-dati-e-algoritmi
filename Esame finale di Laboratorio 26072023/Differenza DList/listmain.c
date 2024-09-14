#include "diff_dlist.h"

int main(void) {
     
    //Lista doppiamente concatenata
    ElemType v[] = { 9, 5, 4 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item* list = DListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = DListInsertBack(list, &v[i]);
    }

    ElemType v1[] = { 6, 9 };
    size_t v1_size = sizeof(v1) / sizeof(ElemType);
    Item* list1 = DListCreateEmpty();
    for (size_t i = 0; i < v1_size; ++i) {
        list1 = DListInsertBack(list1, &v1[i]);
    }

    Item* ris = DListDiff(list, list1);
    DListWriteStdout(ris);

    
    DListDelete(list);
    DListDelete(list1);
    DListDelete(ris);
    return 0;
}