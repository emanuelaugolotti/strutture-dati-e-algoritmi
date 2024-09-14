#include "differenza.h"

int main(void) {
    int v1[] = { '7', '1', '0','1' };
    size_t v1_size = sizeof(v1) / sizeof(int);
	
	Item *list1 = ListCreateEmpty();
    for (size_t i = 0; i < v1_size; ++i) {
        list1 = ListInsertBack(list1, &v1[i]);
    }

    int v2[] = { '3', '2', '4' };
    size_t v2_size = sizeof(v2) / sizeof(int);
    Item* list2 = ListCreateEmpty();
    for (size_t i = 0; i < v2_size; ++i) {
        list2 = ListInsertBack(list2, &v2[i]);
    }

    ListWriteStdout(list1);
    ListWriteStdout(list2);

    Item* ris = Differenza(list1, list2);
    ListWriteStdout(ris);
    
    ListDelete(list1);
    ListDelete(list2);
    ListDelete(ris);
    return 0;
}