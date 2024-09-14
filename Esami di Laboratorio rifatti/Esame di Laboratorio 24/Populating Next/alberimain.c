#include "tree.h"

extern void PopulatingNext(Node* t);

int main(void) {
	ElemType v[] = { 2, 1, 3, 7, 4, 5, 0 };
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
		7   4 5   0

	*/

	PopulatingNext(t);
	TreeDelete(t);
	return 0;
}