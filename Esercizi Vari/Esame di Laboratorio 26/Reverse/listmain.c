#include "reverse.h"

int main(void) {
    //lista 0
    ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }

    Item* ris = Reverse(list, 3);
    ListWriteStdout(ris);
    
    ListDelete(list);

    ////Lista 1
    //ElemType v1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    //size_t v1_size = sizeof(v1) / sizeof(ElemType);
    //Item* list1 = ListCreateEmpty();
    //for (size_t i = 0; i < v1_size; ++i) {
    //    list1 = ListInsertBack(list1, &v1[i]);
    //}
    //ris = Reverse(list, 7);
    //ListWriteStdout(ris);

    ////Lista 2
    //ElemType v2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    //size_t v2_size = sizeof(v2) / sizeof(ElemType);
    //Item* list2 = ListCreateEmpty();
    //for (size_t i = 0; i < v2_size; ++i) {
    //    list2 = ListInsertBack(list2, &v2[i]);
    //}
    //ris = Reverse(list, 0);
    //ListWriteStdout(ris);
    //
    //ListDelete(list1);
    //ListDelete(list2);
   
    return 0;
}