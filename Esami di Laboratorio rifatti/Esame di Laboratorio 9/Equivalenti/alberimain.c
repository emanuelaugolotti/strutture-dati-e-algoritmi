#include "tree.h"

extern bool Equivalenti(const Node* t1, const Node* t2);

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

	ElemType v1[] = { -2, 5, 1, 8, 2, 1, -18, 11 };
	size_t v1_size = sizeof(v1) / sizeof(ElemType);

	/*		 -2
			/  \
		   /    \
		  5      1
		 / \      \
		8   2      1
		 \        /
		-18      11
	*/

	Node* t1 = TreeCreateRoot(v1,
		TreeCreateRoot(v1 + 1,
			TreeCreateRoot(v1 + 3, NULL, TreeCreateRoot(v1 + 6, NULL, NULL)),
			TreeCreateRoot(v1 + 4, NULL, NULL)),
		TreeCreateRoot(v1 + 2, NULL,
			TreeCreateRoot(v1 + 5, TreeCreateRoot(v1 + 7, NULL, NULL), NULL)));

	/*ElemType v[] = { 1, 3, 4 };
	Node* n1 = TreeCreateRoot(v, NULL, NULL);
	Node* n2 = TreeCreateRoot(v + 1, NULL, NULL);
	Node* n3 = TreeCreateRoot(v + 2 ,NULL, NULL);
	Node* t = TreeCreateRoot(n1, n2, n3);
	Node* t1 = TreeCreateRoot(n1, n3, n2);*/
	
	TreeWriteStdoutPostOrder(t);
	TreeWriteStdoutPostOrder(t1);

	bool ris = Equivalenti(t, t1);

	TreeDelete(t);
	TreeDelete(t1);
	return 0;
}