#include "tree.h"

extern void SostituisciSomma(Node* t);

int main(void) {
	Node* t = TreeCreateEmpty();
	ElemType v[] = { 2, 1, 3, 7, 4, 2, 4 };
	t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, NULL),
			TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 2,
			TreeCreateRoot(v + 5, NULL, NULL),
			TreeCreateRoot(v + 6, NULL, NULL)));
	
	TreeWriteStdoutPostOrder(t);

	SostituisciSomma(t);
	TreeWriteStdoutPostOrder(t);
	
	TreeDelete(t);
	return 0;
}