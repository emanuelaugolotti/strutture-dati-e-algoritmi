#include "minheap.h"
#include <crtdbg.h>

extern int KthLeast(const int* v, size_t n, int k);

int main(void) {
 
    ElemType v[] = { 0, 12, 4, 21, 2, 5, 18, 77, 8, -1 };
	size_t v_size =sizeof(v) / sizeof(int);

	int ris = KthLeast(v, v_size, 3);
	
	_CrtDumpMemoryLeaks();
	return 0;
}