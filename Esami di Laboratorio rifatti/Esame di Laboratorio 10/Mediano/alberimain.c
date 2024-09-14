#include "tree.h"

extern double Mediano(const Node* t);

int main(void) {

//Albero 2
	ElemType v[] = { 7, 4, 8, 2, 5, 1 };
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
		 4      8
		/ \
	   2   5
	  /
	 1

   */
			

////Albero 3
//	ElemType v[] = { 4, 2, 6, 1, 3, 5, 7 };
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
//	TreeWriteStdoutInOrder(t);
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

	double mediano = Mediano(t);
	
	TreeDelete(t);
	return 0;
}



