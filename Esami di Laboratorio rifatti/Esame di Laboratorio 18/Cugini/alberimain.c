#include "tree.h"

extern bool Cugini(const Node* t, int a, int b);

int main(void) {
	//Albero 1
	ElemType v[] = { -2, 5, 10, 8, 2, 1, -9, 11 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

/*		 -2
		/  \
	   /    \
	  5      10
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

	bool ris1 = Cugini(t, 8, 2);
	bool ris2 = Cugini(t, 8, 1);

////Albero 2
//	ElemType v[] = { 7, 6, 8, 2, 5, 1 };
//	size_t v_size = sizeof(v) / sizeof(ElemType);
//
//	Node* t = TreeCreateRoot(v,
//		TreeCreateRoot(v + 1,
//			TreeCreateRoot(v + 3, TreeCreateRoot(v + 5, NULL, NULL), NULL),
//			TreeCreateRoot(v + 4, NULL, NULL)),
//		TreeCreateRoot(v + 2, NULL, NULL));
//	/*
//			7
//		   / \
//		  /   \
//		 6      8
//		/ \
//	   2   5
//	  /
//	 1
//
//   */
			

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

	TreeDelete(t);
	return 0;
}