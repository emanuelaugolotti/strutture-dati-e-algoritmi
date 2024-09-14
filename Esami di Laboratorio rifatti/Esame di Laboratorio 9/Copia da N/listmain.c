#include "list.h"

extern Item* CopiaDaN(const Item* i, int n);

int main(void) {
    int v[] = { 12, 2, 37, 4 };
    size_t v_size = sizeof(v) / sizeof(int);
	
	Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    ListWriteStdout(list);
    
    Item* ris = CopiaDaN(list, 2);
    ListWriteStdout(ris);

    ListDelete(list);
    ListDelete(ris);
    return 0;
}