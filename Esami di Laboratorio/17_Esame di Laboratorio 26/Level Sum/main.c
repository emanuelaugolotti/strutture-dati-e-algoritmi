#include "tree.h"

extern int LevelSum(const Node* t, size_t level);

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

	TreeWriteStdoutPostOrder(t);

	int sum1 = LevelSum(t, 0);
	int sum2 = LevelSum(t, 1);
	int sum3 = LevelSum(t, 2);
	int sum4 = LevelSum(t, 3);
	int sum5 = LevelSum(t, 4);

	TreeDelete(t);
	return 0;
}