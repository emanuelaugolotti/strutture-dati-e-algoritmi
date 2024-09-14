//Time: 26 min
#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdio.h>

Node* TreeReadRec(FILE* f) {
	ElemType c;
	int ris = fscanf(f, " %c", &c);
	if (ris != 1) {
		return TreeCreateEmpty();	//fine del file
	}
	if (c == '.') {	//foglia
		fscanf(f, " %c", &c);
		return TreeCreateRoot(&c, NULL, NULL);
	}
	Node* l = TreeReadRec(f);
	Node* r = TreeReadRec(f);
	return TreeCreateRoot(&c, l, r);
}

Node* TreeRead(const char* filename) {
	if (filename == NULL) {
		return TreeCreateEmpty();
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return TreeCreateEmpty();
	}
	Node* t = TreeReadRec(f);
	fclose(f);
	return t;
}