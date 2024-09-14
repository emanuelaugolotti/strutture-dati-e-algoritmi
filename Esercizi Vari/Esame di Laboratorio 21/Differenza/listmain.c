#include "differenza.h"

int main(void) {
   
   //Lista 1
    ElemType v1[] = { '7', '1', '0', '1' };
    size_t v1_size = sizeof(v1) / sizeof(ElemType);
    Item* list1 = ListCreateEmpty();
    for (size_t i = 0; i < v1_size; ++i) {
        list1 = ListInsertBack(list1, &v1[i]);
    }
    //Lista 2
    ElemType v2[] = { '3', '2', '4' };
    size_t v2_size = sizeof(v2) / sizeof(ElemType);
    Item* list2 = ListCreateEmpty();
    for (size_t i = 0; i < v2_size; ++i) {
        list2 = ListInsertBack(list2, &v2[i]);
    }
    
    Item* ris = Differenza(list1, list2);
    ListWriteStdout(ris);

    ListDelete(list1);
    ListDelete(list2);
    
    return 0;
}                                     