// Più di 1h
#include "tree.h"
#include <float.h>
#include <stdlib.h>
#include <stdbool.h>

size_t ContaNodi2(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}

	return 1 + ContaNodi2(TreeLeft(t)) + ContaNodi2(TreeRight(t));
}

void SearchValue(const Node* t, size_t pos, size_t* count, ElemType* value, bool* done) {
	if (TreeIsEmpty(t)) {
		return;
	}

	SearchValue(TreeLeft(t), pos, count, value, done);
	
	if (*count == pos && !*done) {
		*value = ElemCopy(TreeGetRootValue(t));
		*done = true;
		return;
	}
	++(*count);
	
	SearchValue(TreeRight(t), pos, count, value, done);
}

double Mediano(const Node* t) {
	if (TreeIsEmpty(t)) {
		return DBL_MAX;
	}
	
	double mediano = 0;
	
	size_t numero_nodi = ContaNodi2(t);

	size_t count = 0;
	bool done = false;
	if (numero_nodi % 2 != 0) {	// n è dispari
		size_t pos1 = numero_nodi / 2;
		ElemType value;
		SearchValue(t, pos1, &count, &value, &done);
		mediano = (double)value;
	} else {	// n è pari
		size_t pos1 = numero_nodi / 2 - 1;
		size_t pos2 = pos1 + 1;
		count = 0;
		ElemType value1;
		done = false;
		SearchValue(t, pos1, &count, &value1, &done);
		count = 0;
		ElemType value2;
		done = false;
		SearchValue(t, pos2, &count, &value2, &done);
		mediano = (double)(value1 + value2) / 2;
	}
	
	return mediano;
}