#include "reverse.h"

int main(void) {
    //lista 0
    ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    Item* ris1 = Reverse(list, 3);
    ListWriteStdout(ris1);
    ListDelete(list);

    return 0;
}