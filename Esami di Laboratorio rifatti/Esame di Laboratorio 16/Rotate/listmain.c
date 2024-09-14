#include "list.h"

extern Item* Rotate(Item* i, int n);

int main(void) {
    int v[] = { 1, 3, 4, 7, 8 };
    size_t v_size = sizeof(v) / sizeof(int);
	
	Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    ListWriteStdout(list);

    Item* ris = Rotate(list, 1);
    ListWriteStdout(ris);
    
    ListDelete(list);
    return 0;
}