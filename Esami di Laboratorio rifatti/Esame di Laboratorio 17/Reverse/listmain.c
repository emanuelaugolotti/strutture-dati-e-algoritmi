#include "list.h"

extern Item* Reverse(Item* i);

int main(void) {
    /*int v[] = { 1, 3, 4, 7, 8 };*/
    int v[] = { 1, 2 };
    size_t v_size = sizeof(v) / sizeof(int);
	
	Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }

    Item* ris = Reverse(list);
    ListWriteStdout(ris);
    
    ListDelete(list);
    return 0;
}