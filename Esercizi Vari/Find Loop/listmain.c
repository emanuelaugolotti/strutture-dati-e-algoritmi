#include "list.h"
#include <crtdbg.h>
#include <stdlib.h>

const Item* FindLoop(const Item* i);

int main(void) {
    ElemType v[] = { 0, 1, 2, 3 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    
    Item* i1 = ListCreateEmpty();
    ElemType e1 = 4;
    i1 = ListInsertBack(i1, &e1);

    Item* root = list;
    for (int i = 0; i < 3; ++i) {
        root = ListGetTail(root);
    }
    root->next = i1;

    ElemType v1[] = { 5, 6, 7, 8, 9 };
    size_t v1_size = sizeof(v1) / sizeof(ElemType);
    Item* list1 = ListCreateEmpty();
    for (size_t i = 0; i < v1_size; ++i) {
        list1 = ListInsertBack(list1, &v1[i]);
    }

    Item* root1 = list1;
    for (int i = 0; i < 4; ++i) {
        root1 = ListGetTail(root1);
    }
    i1->next = list1;
    root1->next = i1;
    
    //ListWriteStdout(list);
    
    const Item* ris = FindLoop(i1);
    
    //Memoria da liberare
    for (int i = 0; i < 10; ++i) {
        Item* tmp = list;
        list = ListGetTail(list);
        free(tmp);
    }

    _CrtDumpMemoryLeaks();
    return 0;
}