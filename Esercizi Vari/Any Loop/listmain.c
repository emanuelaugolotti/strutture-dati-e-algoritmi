#include "list.h"

extern bool AnyLoop(const Item* i);

int main(void) {
   /* ElemType v[] = { 12, 99, 37, 12 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }*/

    Item* i1 = ListCreateEmpty();
    ElemType e1 = 12;
    i1 = ListInsertBack(i1, &e1);
    Item* i2 = ListCreateEmpty();
    ElemType e2 = 99;
    i2 = ListInsertBack(i2, &e2);
    Item* i3 = ListCreateEmpty();
    ElemType e3 = 37;
    i3 = ListInsertBack(i3, &e3);
   
     i1->next = i2;
    i2->next = i3;
    i3->next = i1;

    //i1->next = i2;
    //i2->next = i3;
    //i3->next = i3;
   
   /* i1->next = i2;
    i2->next = i3;
    i3->next = i2;*/
    
    /*ListWriteStdout(i1);*/
    bool ris = AnyLoop(i1);

   /* ListWriteStdout(list);
    bool ris = AnyLoop(list);*/
    
   /* ListDelete(list);*/
    
    free(i1);
    free(i2);
    free(i3);
    return 0;
}