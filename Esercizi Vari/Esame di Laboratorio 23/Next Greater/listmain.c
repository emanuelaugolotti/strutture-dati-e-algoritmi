#include "next_greater.h"

int main(void) {
    //lista 0
    ElemType v[] = { 2, 3, 1, 4, 7, 2 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }

    size_t answer_size;
    ElemType* ris = NextGreater(list, &answer_size);
    
    free(ris);
    ListDelete(list);
    return 0;
}