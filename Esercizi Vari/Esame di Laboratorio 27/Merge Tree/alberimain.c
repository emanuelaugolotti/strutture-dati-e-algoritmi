#include "tree.h"

extern Node* MergeTree(const Node* t1, const Node* t2);

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

//Albero 4	
	ElemType v1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	size_t v1_size = sizeof(v1) / sizeof(ElemType);

	Node* t1 = TreeCreateRoot(v1,
		TreeCreateRoot(v1 + 1,
			TreeCreateRoot(v1 + 3, TreeCreateRoot(v1 + 7, NULL, NULL), TreeCreateRoot(v1 + 8, NULL, NULL)),
			TreeCreateRoot(v1 + 4, NULL, NULL)),
		TreeCreateRoot(v1 + 2,
			TreeCreateRoot(v1 + 5, NULL, NULL),
			TreeCreateRoot(v1 + 6, NULL, NULL)));

	/*
			 1
			/ \
		   /   \
		  2     3
		 / \   / \
		4   5 6   7
	   / \
	  8   9

	*/

	Node* ris = MergeTree(t, t1);
	TreeWriteStdoutPostOrder(ris);

	TreeDelete(t);
	TreeDelete(t1);
	TreeDelete(ris);
	return 0;
}