#include "list.h"

extern Item* ZipLinkedList(Item* l);

int main(void) {
   
    ElemType v[] = { 1, 2, 3, 4, 5, 6 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    ListWriteStdout(list);

    Item* ris = ZipLinkedList(list);
    ListWriteStdout(ris);
    
    ListDelete(list);
    return 0;
}