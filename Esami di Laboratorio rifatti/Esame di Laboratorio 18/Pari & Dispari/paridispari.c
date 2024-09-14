//Time: 1h
#include "list.h"

bool IsItemPari(Item* i) {
	const ElemType* val = ListGetHeadValue(i);
	if (*val % 2 == 0) {
		return true;
	}
	return false;
}

Item* GetLastPari(Item* i) {
	Item* out = ListCreateEmpty();
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		if (!IsItemPari(i)) {
			break;
		}
		out = i;
	}
	return out;
}

Item* GetLastDispari(Item* i) {
	Item* out = ListCreateEmpty();
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		if (IsItemPari(i)) {
			break;
		}
		out = i;
	}
	return out;
}

void CollegaPrimoUltimoStriscia(Item* i, Item** primo, Item** ultimo, Item** root, bool pari) {
	if (ListIsEmpty(*root)) {
		*root = i;
	}
	*primo = i;
	if (!ListIsEmpty(*ultimo)) {
		(*ultimo)->next = *primo;
	}
	if (pari) {
		*ultimo = GetLastPari(i);
	} else {
		*ultimo = GetLastDispari(i);
	}
}

Item* PariDispari(Item* i) {
	if (ListIsEmpty(i)) {
		return NULL;
	}
	Item* pariroot = ListCreateEmpty();
	Item* dispariroot = ListCreateEmpty();
	Item* primopari = ListCreateEmpty();
	Item* primodispari = ListCreateEmpty();
	Item* ultimopari = ListCreateEmpty();
	Item* ultimodispari = ListCreateEmpty();
	while (!ListIsEmpty(i)) {
		bool pari = IsItemPari(i);
		if (pari) {
			CollegaPrimoUltimoStriscia(i, &primopari, &ultimopari, &pariroot, pari);
			i = ListGetTail(ultimopari);
		} else {
			CollegaPrimoUltimoStriscia(i,&primodispari, &ultimodispari, &dispariroot, pari);
			i = ListGetTail(ultimodispari);
		}
	}
	if (!ListIsEmpty(ultimopari)) {
		ultimopari->next = dispariroot;
	}
	if (!ListIsEmpty(ultimodispari)) {
		ultimodispari->next = NULL;
	}
	if (ListIsEmpty(pariroot)) {
		return dispariroot;
	}
	return pariroot;
}