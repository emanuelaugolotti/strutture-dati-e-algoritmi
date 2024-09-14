#include "tree.h"

extern bool LeafTraversal(const Node* t1, const Node* t2);

int main(void) {
//	ElemType v[] = { -2, 5, 1, 8, 2, 1, -9, 11 };
//	size_t v_size = sizeof(v) / sizeof(ElemType);
//
///*		 -2
//		/  \
//	   /    \
//	  5      1
//	 / \      \
//	8   2      1
//	 \        /
//	 -9     11
//*/
//
//	Node* t1 = TreeCreateRoot(v,
//		TreeCreateRoot(v + 1,
//			TreeCreateRoot(v + 3, NULL, TreeCreateRoot(v + 6, NULL, NULL)),
//			TreeCreateRoot(v + 4, NULL, NULL)),
//		TreeCreateRoot(v + 2, NULL,
//				TreeCreateRoot(v + 5, TreeCreateRoot(v + 7, NULL, NULL), NULL)));

			
////Albero 3
//	ElemType v2[] = { 2, 1, 3, -9, 2, 11, 4 };
//
//	Node* t2 = TreeCreateRoot(v2,
//		TreeCreateRoot(v2 + 1,
//			TreeCreateRoot(v2 + 3, NULL, NULL),
//			TreeCreateRoot(v2 + 4, NULL, NULL)),
//		TreeCreateRoot(v2 + 2,
//			TreeCreateRoot(v2 + 5, NULL, NULL), NULL));
//
//	/*
//			 2
//			/ \
//		   /   \
//		  1     3
//		 / \   / 
//	   -9   2 11 
//
//	*/

////Albero 4	
//	ElemType v2[] = { 1, 2, 3, 4, 11, 6, -9, 2 };
//
//	Node* t2 = TreeCreateRoot(v2,
//		TreeCreateRoot(v2 + 1,
//			TreeCreateRoot(v2 + 3, TreeCreateRoot(v2 + 6, NULL, NULL), TreeCreateRoot(v2 + 7, NULL, NULL)),
//			TreeCreateRoot(v2 + 4, NULL, NULL)),
//		TreeCreateRoot(v2 + 2,
//			TreeCreateRoot(v2 + 5, NULL, NULL), NULL));
//
//	/*
//			 1
//			/ \
//		   /   \
//		  2     3
//		 / \   / 
//		4  11 6   
//	   / \
//	  -9  2
//
//	*/

	ElemType v[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	Node* t1 = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, NULL),
			TreeCreateRoot(v + 4, TreeCreateRoot(v + 6, NULL, NULL), TreeCreateRoot(v + 7, NULL, NULL))),
		TreeCreateRoot(v + 2, NULL, TreeCreateRoot(v + 5, NULL, NULL)));

	ElemType e[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	Node* t2 = TreeCreateRoot(e,
		TreeCreateRoot(e + 1, TreeCreateRoot(e + 3, NULL, NULL), TreeCreateRoot(e + 6, NULL, NULL)),
		TreeCreateRoot(e + 2, NULL,
			TreeCreateRoot(e + 4, TreeCreateRoot(e + 7, NULL, NULL), TreeCreateRoot(e + 5, NULL, NULL))));

	TreeWriteStdoutPostOrder(t1);
	TreeWriteStdoutPostOrder(t2);
	bool ris = LeafTraversal(t1, t2);
	TreeDelete(t1);
	TreeDelete(t2);
	return 0;
}