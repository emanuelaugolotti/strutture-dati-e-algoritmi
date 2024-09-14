#include "tree.h"
#include <float.h>
#include <stdlib.h>

extern double Mediano(const Node* t);

int main(void) {
	ElemType v[] = { 4, 2, 6, 1, 3, 5, 7 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	
	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, NULL), TreeCreateRoot(v + 4, NULL, NULL)),
		TreeCreateRoot(v + 2,
		TreeCreateRoot(v + 5, NULL, NULL), TreeCreateRoot(v + 6, NULL, NULL)));

	/*ElemType v[] = { 4, 2, 5, 1 };
	size_t v_size = sizeof(v) / sizeof(ElemType);

	Node* t = TreeCreateRoot(v,
		TreeCreateRoot(v + 1,
			TreeCreateRoot(v + 3, NULL, NULL), NULL),
		TreeCreateRoot(v + 2, NULL, NULL));*/

	TreeWriteStdoutInOrder(t);
	
	double mediano = Mediano(t);

	TreeDelete(t);	// Libero la memoria
	return 0;
}