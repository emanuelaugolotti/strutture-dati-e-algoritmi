#include "remove.h"

int main(void) {
    //lista 0
    ElemType v[] = { 1, 2, 2, 2, 3, 4, 4, 5, 5 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    ListWriteStdout(list);

    Item* ris = RemoveDuplicates(list);
    ListWriteStdout(ris);
    
    ListDelete(ris);
    return 0;
}