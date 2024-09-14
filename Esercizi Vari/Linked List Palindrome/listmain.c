#include "list.h"

extern bool Palindrome(const Item* l);

int main(void) {
    
   /* ElemType v[] = { 0, 1, 2, 2, 1, 0 };*/
    /*ElemType v[] = { 6, 5, 9, 3, 4, 5, 6 };*/
    ElemType v[] = { 6 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    
    bool ris1 = Palindrome(list);
    
    ElemType v1[] = { 0, 1, 2, 3, 2, 1, 0 };
    size_t v1_size = sizeof(v1) / sizeof(ElemType);
    Item* list1 = ListCreateEmpty();
    for (size_t i = 0; i < v1_size; ++i) {
        list1 = ListInsertBack(list1, &v1[i]);
    }

    bool ris2 = Palindrome(list1);
   
    ElemType v2[] = { 0, 1, 2, 3, 1, 0 };
    size_t v2_size = sizeof(v2) / sizeof(ElemType);
    Item* list2 = ListCreateEmpty();
    for (size_t i = 0; i < v2_size; ++i) {
        list2 = ListInsertBack(list2, &v2[i]);
    }

    bool ris3 = Palindrome(list2);
    
    ListDelete(list);
    ListDelete(list1);
    ListDelete(list2);
    return 0;
}