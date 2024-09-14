#include "tree.h"

extern bool PercorsoSomma(Node* t, const ElemType* target);

int main(void) {
	
//Albero 3
	ElemType v[] = { 2, 1, 3, 7, 4, 2, 4 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, NULL),
			TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 2,
			TreeCreateRoot(v + 5, NULL, NULL),
			TreeCreateRoot(v + 6, NULL, NULL)));

	/*
			 2
			/ \
		   /   \
		  1     3
		 / \   / \
		7   4 2   4

	*/

	ElemType e1 = 7;
	ElemType e2 = 9;
	ElemType e3 = 11;
	bool ris;
	ris = PercorsoSomma(t, &e1);
	ris = PercorsoSomma(t, &e2);
	ris = PercorsoSomma(t, &e3);

	TreeDelete(t);
	return 0;
}