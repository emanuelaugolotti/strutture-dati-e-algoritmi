#include "cc.h"

int main(void) {

    //Lista 1
    ElemType v1[] = { 0, 1, 3, 4, 5, 6, 8, 7 };
    size_t v1_size = sizeof(v1) / sizeof(ElemType);
    Item* list1 = ListCreateEmpty();
    for (size_t i = 0; i < v1_size; ++i) {
        list1 = ListInsertBack(list1, &v1[i]);
    }

    ElemType v[] = { 7, 8, 0, 4, 6 };
    size_t v_size = sizeof(v) / sizeof(ElemType);

    int ris1 = ComponentiConnesse(list1, v, v_size);

    //Lista 2
    ElemType v2[] = { 0, 1, 2, 3, 4 };
    size_t v2_size = sizeof(v2) / sizeof(ElemType);
    Item* list2 = ListCreateEmpty();
    for (size_t i = 0; i < v2_size; ++i) {
        list2 = ListInsertBack(list2, &v2[i]);
    }

    ElemType  vett[] = { 1, 2, 4 };
    size_t vett_size = sizeof(vett) / sizeof(ElemType);

    int ris2 = ComponentiConnesse(list2, vett, vett_size);
    
    ListDelete(list1);
    ListDelete(list2);
   
    return 0;
}