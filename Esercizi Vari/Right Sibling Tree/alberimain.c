#include "tree.h"

extern Node* SiblingTree(Node* t);

int main(void) {
	
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


////Albero 2	
//	ElemType v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//	size_t v_size = sizeof(v) / sizeof(ElemType);
//
//	Node* t = TreeCreateRoot(v,
//		TreeCreateRoot(v + 1,
//			TreeCreateRoot(v + 3, TreeCreateRoot(v + 7, NULL, NULL), TreeCreateRoot(v + 8, NULL, NULL)),
//			TreeCreateRoot(v + 4, NULL, TreeCreateRoot(v + 9, NULL, NULL))),
//		TreeCreateRoot(v + 2,
//			TreeCreateRoot(v + 5, TreeCreateRoot(v + 10, TreeCreateRoot(v + 13, NULL, NULL), NULL), NULL),
//			TreeCreateRoot(v + 6, TreeCreateRoot(v + 11, NULL, NULL), TreeCreateRoot(v + 12, NULL, NULL))));
//
//	/*
//			 1
//			/ \
//		   /   \
//		  2     3
//		 / \   / \
//		4   5 6   7
//	   / \
//	  8   9
//
//	*/
//	
	TreeWriteStdoutPostOrder(t);
	Node* ris = SiblingTree(t);

	/*TreeDelete(t);*/
	return 0;
}