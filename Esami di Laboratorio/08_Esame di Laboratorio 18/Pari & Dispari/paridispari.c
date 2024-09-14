//Time: 38 min
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

bool IsPari(Item* i) {
	ElemType value = ElemCopy(ListGetHeadValue(i));
	return !(value % 2);
}

Item* PariDispari(Item* i) {
	if (ListIsEmpty(i)) {
		return NULL;
	}
	Item* tmproot = i;
	Item* rootlistpari = ListCreateEmpty();
	Item* rootlistdispari = ListCreateEmpty();
	Item* prevpari = ListCreateEmpty();
	Item* prevdispari = ListCreateEmpty();
	bool isprimopari = true;
	bool isprimodispari = true;
	while (!ListIsEmpty(i)) {
		if (IsPari(i)) {
			if (isprimopari) {
				rootlistpari = i;
				isprimopari = false;
			} else {
				prevpari->next = i;
			}
			prevpari = i;
		} else {	//E' dispari
			if (isprimodispari) {
				rootlistdispari = i;
				isprimodispari = false;
			} else {
				prevdispari->next = i;
			}
			prevdispari = i;
		}
		i = ListGetTail(i);
	}
	if (isprimopari || isprimodispari) {
		return tmproot;
	}
	prevdispari->next = NULL;
	prevpari->next = rootlistdispari;
	ListWriteStdout(rootlistpari);
	return rootlistpari;
}