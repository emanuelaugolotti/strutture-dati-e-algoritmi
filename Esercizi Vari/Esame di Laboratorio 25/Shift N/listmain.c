#include "shift.h"

int main(void) {
   
   /* ElemType v[] = { 0, 1, 2, 3 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    Item* ris = ShiftN(list, 2);
    ListWriteStdout(ris);
    ListDelete(ris);*/

    ElemType v[] = { 0, 1, 2, 3, 4 , 5, 6, 7, 8 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    Item* ris = ShiftN(list, 24);
    ListWriteStdout(ris);
    ListDelete(ris);


    /*ElemType v1[] = {0, 1, 2, 3};
    size_t v1_size = sizeof(v1) / sizeof(ElemType);
    list = ListCreateEmpty();
    for (size_t i = 0; i < v1_size; ++i) {
        list = ListInsertBack(list, &v1[i]);
    }
    Item* ris1 = ShiftN(list, 3);
    ListWriteStdout(ris1);
    ListDelete(ris1);
    
    ElemType v2[] = { 0, 1, 2, 3 };
    size_t v2_size = sizeof(v2) / sizeof(ElemType);
    list = ListCreateEmpty();
    for (size_t i = 0; i < v2_size; ++i) {
        list = ListInsertBack(list, &v2[i]);
    }
    Item* ris2 = ShiftN(list, 4);
    ListWriteStdout(ris2);
    ListDelete(ris2);*/

    return 0;
}