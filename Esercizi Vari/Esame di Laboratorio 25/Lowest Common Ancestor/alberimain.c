//Time: 24 min
#include "tree.h"

extern const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2);

int main(void) {
	
//Albero 3
	ElemType v[] = { 'a','b', 'c', 'd', 'e', 'f', 'g' };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	ElemType e1 = 'h';
	ElemType e2 = 'i';
	Node* n1 = TreeCreateRoot(&e1, NULL, NULL);
	Node* n2 = TreeCreateRoot(&e2, NULL, NULL);


	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, n1, n2),
			TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 2,
			TreeCreateRoot(v + 5, NULL, NULL),
			TreeCreateRoot(v + 6, NULL, NULL)));

	const Node* ris = LowestCommonAncestor(t, n1, n2);	//'d'

	/*
			 2
			/ \
		   /   \
		  1     3
		 / \   / \
		7   4 2   4

	*/

////Albero 4	
//	ElemType v[] = { 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };
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


	TreeDelete(t);
	return 0;
}