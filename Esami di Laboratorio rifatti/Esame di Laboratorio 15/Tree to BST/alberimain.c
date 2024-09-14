#include "tree.h"

extern Node* Tree2Bst(const Node* t);

int main(void) {
	//Albero 1
	ElemType v[] = { 6, 2, 9, 3, 8, 3, -9, 11, 5 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

/*		  6
		/  \
	   /    \
	  2      9
	 / \      \
	3   8      3
	     \      
	      5          
*/
	Node* n = TreeCreateRoot(v + 8, NULL, NULL);
	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, NULL),
			TreeCreateRoot(v + 4, NULL, n)),
		TreeCreateRoot(v + 2, NULL,
				TreeCreateRoot(v + 5, NULL, NULL)));

	TreeWriteStdoutInOrder(t);
	Node* ris = Tree2Bst(t);
	TreeWriteStdoutInOrder(ris);
	
	TreeDelete(t);
	TreeDelete(ris);
	return 0;
}



