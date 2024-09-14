#include "list.h"

extern Item* PariDispari(Item* i);

int main(void) {
    int v[] = { 3, 4, 8, 7, 2, 13, 14, 1, 12 };
    size_t v_size = sizeof(v) / sizeof(int);
	
	Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    ListWriteStdout(list);

    Item* ris = PariDispari(list);
    ListWriteStdout(ris);
    
    ListDelete(list);
    return 0;
}