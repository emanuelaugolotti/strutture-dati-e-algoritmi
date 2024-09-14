#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

extern void LevelOrder(const Node* t);

int main(void) {
	/*ElemType v[] = { 7, 4, 8, 2, 5, 1, 5 };
	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, TreeCreateRoot(v + 5, NULL, NULL), NULL),
			TreeCreateRoot(v + 4, TreeCreateRoot(v + 6, NULL, NULL), NULL)),
		TreeCreateRoot(v + 2, NULL, NULL));*/
	
	
	ElemType v[] = { 11, 5, 12, 3, 9, 13, -1, 4, 8, 7 };
	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, TreeCreateRoot(v + 6, NULL, NULL), TreeCreateRoot(v + 7, NULL, NULL)),
			TreeCreateRoot(v + 4,
				TreeCreateRoot(v + 8,
					TreeCreateRoot(v + 9, NULL, NULL), NULL), NULL)),
		TreeCreateRoot(v + 2, NULL, TreeCreateRoot(v + 5, NULL, NULL)));
	
	
	TreeWriteStdoutPreOrder(t);
	
	LevelOrder(t);
	
	TreeDelete(t);
	return 0;
}