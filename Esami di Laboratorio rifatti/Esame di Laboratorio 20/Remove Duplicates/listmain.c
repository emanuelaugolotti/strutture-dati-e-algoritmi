#include "remove.h"

int main(void) {
    int v[] = { 1, 2, 2, 3, 4, 5, 5, 5, 6, 7, 7 };
    size_t v_size = sizeof(v) / sizeof(int);
	
	Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    ListWriteStdout(list);

    Item* ris = RemoveDuplicates(list);
    ListWriteStdout(ris);
    
    ListDelete(list);
    return 0;
}