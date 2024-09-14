#include "next_greater.h"

int main(void) {
    //lista 0
    int v[] = { 2, 3, 1, 4, 7, 2 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    ListWriteStdout(list);
    
    size_t answer_size;
    ElemType* ris = NextGreater(list, &answer_size);
    free(ris);
    ListDelete(list);

    ////Lista 1
    //int v1[] = { 7, 1, 0, 1 };
    //size_t v1_size = sizeof(v1) / sizeof(int);
    //Item* list1 = ListCreateEmpty();
    //for (size_t i = 0; i < v1_size; ++i) {
    //    list1 = ListInsertBack(list1, &v1[i]);
    //}
    ////Lista 2
    //int v2[] = { 3, 2, 4 };
    //size_t v2_size = sizeof(v2) / sizeof(int);
    //Item* list2 = ListCreateEmpty();
    //for (size_t i = 0; i < v2_size; ++i) {
    //    list2 = ListInsertBack(list2, &v2[i]);
    //}
    //
    //ListDelete(list1);
    //ListDelete(list2);
    
    return 0;
}