#include "sum_dlist.h"
#include <crtdbg.h>

int main(void) {
  
    //Lista doppiamente concatenata
    ElemType v[] = { 9, 5, 4 };
    size_t v_size = sizeof(v) / sizeof(ElemType);

    Item* list1 = DListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list1 = DListInsertBack(list1, &v[i]);
    }
    DListWriteStdout(list1);
    
    
    ElemType e[] = { 6, 9 };
    size_t e_size = sizeof(e) / sizeof(ElemType);
    Item* list2 = DListCreateEmpty();
    for (size_t i = 0; i < e_size; ++i) {
        list2 = DListInsertBack(list2, &e[i]);
    }
    DListWriteStdout(list2);


    Item* ris = DListSum(list1, list2);
    DListWriteStdout(ris);

    DListDelete(list1);
    DListDelete(list2);
    DListDelete(ris);
    _CrtDumpMemoryLeaks();
    return 0;
}