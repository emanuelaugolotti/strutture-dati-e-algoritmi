#include "tree.h"

extern Node* Invert(Node* t);

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

	TreeWriteStdoutPostOrder(t);
	Node* ris = Invert(t);
	TreeWriteStdoutPostOrder(t);

	TreeDelete(t);
	return 0;
}



