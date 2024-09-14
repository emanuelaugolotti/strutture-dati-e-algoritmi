#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

extern bool CheckSumN(const Node* t, int n);

int main(void) {
	ElemType v[] = { 7, 6, 8, 2, 5, 1 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, TreeCreateRoot(v + 5, NULL, NULL), NULL),
			TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 2, NULL, NULL));
	TreeWriteStdoutPreOrder(t);
	
	bool ris;
	ris = CheckSumN(t, 4);
	ris = CheckSumN(t, 6);
	ris = CheckSumN(t, 7);

	TreeDelete(t);
	return 0;
}