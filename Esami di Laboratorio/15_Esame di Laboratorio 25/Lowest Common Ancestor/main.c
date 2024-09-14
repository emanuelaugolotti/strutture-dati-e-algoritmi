#include "tree.h"

extern const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2);

int main(void) {
	ElemType v[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	
	Node* n1 = TreeCreateRoot(v + 7, NULL, NULL);
	Node* n2 = TreeCreateRoot(v + 6, NULL, NULL);
	
	Node* tree = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, NULL),
			TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 2,
		TreeCreateRoot(v + 5, NULL, n1),
		n2));
	
	TreeWriteStdoutPostOrder(tree);

	const Node* ancestor = LowestCommonAncestor(tree, n1, n2);

	TreeDelete(tree);
		
	return 0;
}