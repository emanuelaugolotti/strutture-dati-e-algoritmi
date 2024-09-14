#include "tree.h"

extern Node* Tree2Bst(const Node* t);

int main(void) {
	ElemType v[] = { 6, 2, 9, 3, 8, 3, 5 };
	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, NULL),
			TreeCreateRoot(v + 4, NULL, TreeCreateRoot(v + 6, NULL, NULL))),
		TreeCreateRoot(v + 2, NULL, TreeCreateRoot(v + 5, NULL, NULL)));

	TreeWriteStdoutInOrder(t);
	
	Node* bst = Tree2Bst(t);
	
	TreeWriteStdoutInOrder(bst);

	TreeDelete(t);
	TreeDelete(bst);
	return 0;
}