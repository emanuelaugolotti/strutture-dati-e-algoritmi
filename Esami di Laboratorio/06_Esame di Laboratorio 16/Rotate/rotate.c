//Time: 33min
#include "list.h"
#include <stdlib.h>

size_t Lenght(Item* i) {
	size_t len = 0;
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		++len;
	}
	return len;
}

Item* GetItem(Item* i, size_t pos) {	//Ritorna l'Item di posizione pos
	Item* tmp = ListCreateEmpty();
	for (size_t j = 0; j <= pos; ++j) {
		tmp = i;
		i = ListGetTail(i);
	}
	return tmp;
}

Item* Rotate(Item* i, int n) {
	if (n == 0 || ListIsEmpty(i)) {
		return i;
	}
	
	Item* newroot = GetItem(i, n);
	Item* newlast = GetItem(i, n - 1);
	size_t len = Lenght(i);
	Item* prevlast = GetItem(i, len - 1);
	
	prevlast->next = i;
	newlast->next = NULL;
	
	ListWriteStdout(newroot);
	return newroot;
}