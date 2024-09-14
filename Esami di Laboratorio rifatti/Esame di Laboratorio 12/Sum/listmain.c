#include "list.h"

extern Item* Sum(const Item* i1, const Item* i2);

int main(void) {
    int v1[] = { 7 };
    size_t v1_size = sizeof(v1) / sizeof(int);
	
	Item *list1 = ListCreateEmpty();
    for (size_t i = 0; i < v1_size; ++i) {
        list1 = ListInsertBack(list1, &v1[i]);
    }

    int v2[] = { 3 };
    size_t v2_size = sizeof(v2) / sizeof(int);

    Item* list2 = ListCreateEmpty();
    for (size_t i = 0; i < v2_size; ++i) {
        list2 = ListInsertBack(list2, &v2[i]);
    }

    Item* ris = Sum(list1, list2);
    ListWriteStdout(ris);
    
    ListDelete(list1);
    ListDelete(list2);
    return 0;
}