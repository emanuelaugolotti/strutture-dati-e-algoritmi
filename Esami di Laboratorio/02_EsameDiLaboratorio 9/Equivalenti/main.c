#include "tree.h"
#include <stdbool.h>

extern bool Equivalenti(const Node* t1, const Node* t2);

int main(void) {
	ElemType v[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	Node* t1 = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, TreeCreateRoot(v + 6, NULL, NULL), TreeCreateRoot(v + 7, NULL, NULL)),
			TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 2, TreeCreateRoot(v + 5, NULL, NULL), NULL));

	
	ElemType e[] = { 1, 2, 3, 4, 5, 12, 21, 2 };
	Node* t2 = TreeCreateRoot(v,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 3, TreeCreateRoot(e + 6, NULL, NULL), TreeCreateRoot(e + 7, NULL, NULL)),
			TreeCreateRoot(e + 4, NULL, NULL)),
		TreeCreateRoot(e + 2, TreeCreateRoot(e + 5, NULL, NULL), NULL));

	/*ElemType v[] = { 1, 3, 4 };
	Node* t1 = TreeCreateRoot(v,
		TreeCreateRoot(v + 1, NULL, NULL),
		TreeCreateRoot(v + 2, NULL, NULL));


	ElemType e[] = { 1, 4, 3 };
	Node* t2 = TreeCreateRoot(e,
		TreeCreateRoot(e + 1, NULL, NULL),
		TreeCreateRoot(e + 2, NULL, NULL));*/
	
	TreeWriteStdoutPreOrder(t1);
	TreeWriteStdoutPreOrder(t2);
	
	bool ris = Equivalenti(t1, t2);

	
	TreeDelete(t1);
	TreeDelete(t2);
	return 0;
}