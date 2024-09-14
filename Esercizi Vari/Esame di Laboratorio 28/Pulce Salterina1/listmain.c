#include "pulce.h"

int main(void) {
    //Lista doppiamente concatenata
    /*ElemType v[] = { 2, -3, 4, 1, 0, 5, -12, 3 };*/
    ElemType v[] = { 2 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item* list = DListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = DListInsertBack(list, &v[i]);
    }
    DListWriteStdout(list);

    /*Item* start = list;
    for (size_t i = 0; i < 2; ++i) {
        start = DListGetTail(start);
    }
    DListWriteStdout(list);*/

    /*const Item* ris = CalcolaPercorso(start, 13);*/
    const Item* ris = CalcolaPercorso(list, 0);
    
    DListDelete(list);
    return 0;
}