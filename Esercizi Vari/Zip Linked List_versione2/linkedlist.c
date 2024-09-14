//https://github.com/lee-hen/Algoexpert/tree/master/very_hard/27_zip_linked_list
#include "list.h"

size_t Lenght(Item* l) {
	size_t len = 0;
	while (!ListIsEmpty(l)) {
		++len;
		l = ListGetTail(l);
	}
	return len;
}

Item* GetItem(Item* l, size_t pos) {
	for (size_t i = 0; i < pos; ++i) {
		l = ListGetTail(l);
	}
	return l;
}

Item* InvertiLista(Item* l) {
	Item* prev = ListCreateEmpty();
	while (!ListIsEmpty(l)) {
		Item* succ = ListGetTail(l);
		l->next = prev;
		prev = l;
		l = succ;
	}
	return prev;
}

Item* ZipLinkedList(Item* l) {
	size_t len = Lenght(l);
	Item* curr_lista1 = l;
	size_t pos_start2 = len / 2;
	Item* curr_lista2 = GetItem(l, pos_start2);
	curr_lista2 = InvertiLista(curr_lista2);
	while (!ListIsEmpty(ListGetTail(curr_lista2))) {
		Item* succ_lista2 = ListGetTail(curr_lista2);
		Item* succ_lista1 = ListGetTail(curr_lista1);
		curr_lista1->next = curr_lista2;
		curr_lista2->next = succ_lista1;
		curr_lista1 = succ_lista1;
		curr_lista2 = succ_lista2;
	}
	return l;
}