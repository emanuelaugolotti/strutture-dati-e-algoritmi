#include "tree.h"

extern const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2);

int main(void) {
	//Albero Char
	ElemType v[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	size_t v_size = sizeof(v) / sizeof(ElemType);

/*		  a
		/  \
	   /    \
	  b      c
	 / \      \
	d   e      f
	 \        /
	  g      h
*/


	Node* t1 = TreeCreateRoot(v + 4, NULL, NULL);
	Node* t2 = TreeCreateRoot(v + 6, NULL, NULL);
	
	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, t2),
			t1),
		TreeCreateRoot(v + 2, NULL,
			TreeCreateRoot(v + 5, TreeCreateRoot(v + 7, NULL, NULL), NULL)));

	const Node* ris = LowestCommonAncestor(t, t1, t2);

	TreeDelete(t);
	return 0;
}