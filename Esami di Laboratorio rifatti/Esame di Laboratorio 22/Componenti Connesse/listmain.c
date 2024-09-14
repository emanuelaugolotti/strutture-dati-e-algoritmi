#include "cc.h"

int main(void) {
    int v[] = { 0, 1, 3, 4, 5, 6, 8, 7 };
    size_t v_size = sizeof(v) / sizeof(int);
	
	Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }

    ElemType vettore[] = { 7, 8, 0, 4, 6 };
    size_t vettore_size = sizeof(vettore) / sizeof(ElemType);

    int ris = ComponentiConnesse(list, vettore, vettore_size);
    
    ListDelete(list);
    return 0;
}