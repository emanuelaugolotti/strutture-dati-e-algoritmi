#include "list.h"
#include <crtdbg.h>

extern Item* BucketSort(Item* l);

int main(void) {
    int v[] = { 7, 2, 5, 4 };
    size_t v_size = sizeof(v) / sizeof(int);
	
	Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    ListWriteStdout(list);

    Item* ris = BucketSort(list);
    ListWriteStdout(ris);
    
    ListDelete(ris);
    _CrtDumpMemoryLeaks();
    return 0;
}