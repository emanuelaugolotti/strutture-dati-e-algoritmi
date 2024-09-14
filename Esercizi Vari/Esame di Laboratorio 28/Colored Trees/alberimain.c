#include "tree.h"

extern const Node* BiggestColoredTree(const Node* t);

int main(void) {
	//Albero 1
	ElemType v[] = { 'b', 'v', 'r', 'v', 'v', 'r', 'r' };
	size_t v_size = sizeof(v) / sizeof(ElemType);

/*		  b
		/  \
	   /    \
	  v      r
	 / \      \
	v   v      r
	          /
	         r
*/

	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, NULL),
			TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 2, NULL,
				TreeCreateRoot(v + 5, TreeCreateRoot(v + 6, NULL, NULL), NULL)));

	TreeWriteStdoutPostOrder(t);


////Albero 2
//	ElemType v[] = { 'r', 'b', 'v', 'b', 'b', 'v', 'v' };
//	size_t v_size = sizeof(v) / sizeof(ElemType);
//
//	Node* t = TreeCreateRoot(v,
//		TreeCreateRoot(v + 1,
//			TreeCreateRoot(v + 3, NULL, NULL),
//			TreeCreateRoot(v + 4, NULL, TreeCreateRoot(v + 2, NULL, NULL))),
//		TreeCreateRoot(v + 2, NULL, TreeCreateRoot(v + 5, NULL, NULL)));
			

	//ElemType v[] = { 'b', 'v', 'r', 'v', 'r', 'v', 'r' };
	//Node* t = TreeCreateRoot(v,
	//	TreeCreateRoot(v + 1,
	//		TreeCreateRoot(v + 3, NULL, TreeCreateRoot(v + 5, NULL, NULL)), NULL),
	//	TreeCreateRoot(v + 2, NULL, TreeCreateRoot(v + 4, TreeCreateRoot(v + 6, NULL, NULL), NULL)));

	//TreeWriteStdoutPostOrder(t);
	//const Node* ris = BiggestColoredTree(t);
	//TreeWriteStdoutPostOrder(ris);

	TreeDelete(t);
	return 0;
}