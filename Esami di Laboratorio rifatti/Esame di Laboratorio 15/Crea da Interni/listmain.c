#include "list.h"

extern Item* CreaDaInterni(const Item* i, double r);

int main(void) {
    //lista 0
    ElemType v[] = { { 2, 1 }, { 6, 8 }, { 1, 1 }, { 3, 1 }, { 6, 6 },{ 9, 2 } };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    ListWriteStdout(list);
    
    Item* ris = CreaDaInterni(list, 4);
    ListWriteStdout(ris);
    ListDelete(list);
    ListDelete(ris);

    return 0;
}