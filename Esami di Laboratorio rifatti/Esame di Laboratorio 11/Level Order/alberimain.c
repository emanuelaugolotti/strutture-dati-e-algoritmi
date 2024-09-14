#include "tree.h"

extern void LevelOrder(const Node* t);

int main(void) {

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
		 4     8
		/ \
	   2   5
	  /
	 1

   */
			
	LevelOrder(t);
	TreeDelete(t);
	return 0;
}