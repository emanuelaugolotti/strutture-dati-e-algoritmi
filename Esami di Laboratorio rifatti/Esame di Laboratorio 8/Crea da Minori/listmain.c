#include "list.h"

extern Item* CreaDaMinori(const Item* i, int v);

int main(void) {
    int v[] = { 12, 2, 37, 4 };
    size_t v_size = sizeof(v) / sizeof(int);
	
	Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    ListWriteStdout(list);

    Item* ris = CreaDaMinori(list, 5);
    ListWriteStdout(ris);
    
    ListDelete(list);
    ListDelete(ris);

    
    ////Lista doppiamente concatenata
    //ElemType v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //size_t v_size = sizeof(v) / sizeof(ElemType);

    //Item* list = DListCreateEmpty();
    //for (size_t i = 0; i < v_size; ++i) {
    //    list = DListInsertBack(list, &v[i]);
    //}
    //
    //DListDelete(list);
    
    return 0;
}