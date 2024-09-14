#include <stdlib.h>
#include <stdio.h>

extern void BrickSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 3, 1, 2 };
	size_t v_size = sizeof(v) / sizeof(int);
	
	BrickSort(v, v_size);
	
	return 0;
}