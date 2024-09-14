// 3min
#include "elemtype.h"
#include "list.h"

#include <stdlib.h>

Item* CreaDaMinori(const Item* i, int v) {
	Item* out = ListCreateEmpty();


	while (!ListIsEmpty(i)) {
		const ElemType* curr = ListGetHeadValue(i);
		if (ElemCompare(curr, &v) <= 0) {
			out = ListInsertBack(out, curr);
		}
		
		i = ListGetTail(i);	// vado avanti nella lista
	}
	
	return out;
}