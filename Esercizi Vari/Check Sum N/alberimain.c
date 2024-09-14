#include "tree.h"

extern bool CheckSumN(const Node* t, int n);

int main(void) {

//Albero 2
	ElemType v[] = { 7, 6, 8, 2, 5, 1 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, TreeCreateRoot(v + 5, NULL, NULL), NULL),
			TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 2, NULL, NULL));
	/*
			7
		   / \
		  /   \
		 6      8
		/ \
	   2   5
	  /
	 1

   */

	bool ris = CheckSumN(t, 6);
			

////Albero 3
//	ElemType v[] = { 2, 1, 3, 7, 4, 2, 4 };
//	size_t v_size = sizeof(v) / sizeof(ElemType);
//
//	Node* t = TreeCreateRoot(v,
//		TreeCreateRoot(v + 1,
//			TreeCreateRoot(v + 3, NULL, NULL),
//			TreeCreateRoot(v + 4, NULL, NULL)),
//		TreeCreateRoot(v + 2,
//			TreeCreateRoot(v + 5, NULL, NULL),
//			TreeCreateRoot(v + 6, NULL, NULL)));
//
//	/*
//			 2
//			/ \
//		   /   \
//		  1     3
//		 / \   / \
//		7   4 2   4
//
//	*/

////Albero 4	
//	ElemType v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	size_t v_size = sizeof(v) / sizeof(ElemType);
//
//	Node* t = TreeCreateRoot(v,
//		TreeCreateRoot(v + 1,
//			TreeCreateRoot(v + 3, TreeCreateRoot(v + 7, NULL, NULL), TreeCreateRoot(v + 8, NULL, NULL)),
//			TreeCreateRoot(v + 4, NULL, NULL)),
//		TreeCreateRoot(v + 2,
//			TreeCreateRoot(v + 5, NULL, NULL),
//			TreeCreateRoot(v + 6, NULL, NULL)));
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

	
//	//Albero 5 (Albero di char)
//	ElemType v[] = { 'b', 'v', 'r', 'v', 'v', 'r', 'r' };
//	size_t v_size = sizeof(v) / sizeof(ElemType);
//
////		      b
////	 	    /  \
////		   /    \
////		  v      r
////		 / \      \
////		v   v      r
////				  /
////				 r
//	
//
//	Node* t = TreeCreateRoot(v,
//		TreeCreateRoot(v + 1,
//			TreeCreateRoot(v + 3, NULL, NULL),
//			TreeCreateRoot(v + 4, NULL, NULL)),
//		TreeCreateRoot(v + 2, NULL,
//			TreeCreateRoot(v + 5, TreeCreateRoot(v + 6, NULL, NULL), NULL)));


	TreeDelete(t);
	return 0;
}