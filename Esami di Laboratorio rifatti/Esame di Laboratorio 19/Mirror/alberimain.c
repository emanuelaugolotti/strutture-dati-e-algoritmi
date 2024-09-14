#include "tree.h"

extern bool TreeIsMirror(Node* t);

int main(void) {
	ElemType v[] = { 0, 1, 1, 4, 2, 2, 2 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, NULL),
			TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 2,
			TreeCreateRoot(v + 5, NULL, NULL),
			TreeCreateRoot(v + 6, NULL, NULL)));

	/*
			 0
			/ \
		   /   \
		  1     1
		 / \   / \
		4   2 2   4

	*/

	bool ris = TreeIsMirror(t);

	TreeDelete(t);
	return 0;
}