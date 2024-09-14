#include "tree.h"

extern Node* MergeTree(const Node* t1, const Node* t2);

int main(void) {
	//Albero 1
	ElemType v[] = { -2, 5, 1, 8, 2, 1, -9, 11 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

/*		 -2
		/  \
	   /    \
	  5      1
	 / \      \
	8   2      1
	 \        /
	 -9     11
*/

	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, TreeCreateRoot(v + 6, NULL, NULL)),
			TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 2, NULL,
				TreeCreateRoot(v + 5, TreeCreateRoot(v + 7, NULL, NULL), NULL)));
			

//Albero 3
	ElemType v1[] = { 2, 1, 3, 7, 4, 2, 4 };
	size_t v1_size = sizeof(v1) / sizeof(ElemType);

	Node* t1 = TreeCreateRoot(v1,
		TreeCreateRoot(v1 + 1,
			TreeCreateRoot(v1 + 3, NULL, NULL),
			TreeCreateRoot(v1 + 4, NULL, NULL)),
		TreeCreateRoot(v1 + 2,
			TreeCreateRoot(v1 + 5, NULL, NULL),
			TreeCreateRoot(v1 + 6, NULL, NULL)));

	/*
			 2
			/ \
		   /   \
		  1     3
		 / \   / \
		7   4 2   4

	*/

	Node* ris = MergeTree(t, t1);
	TreeWriteStdoutPostOrder(ris);

	TreeDelete(t);
	TreeDelete(t1);
	return 0;
}



