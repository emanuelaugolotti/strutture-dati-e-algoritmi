#include <stdlib.h>

extern void CocktailSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 5,2,8,3,1,9,7,4,6 };
	size_t v_size = sizeof(v) / sizeof(int);
	CocktailSort(v, v_size);
	return 0;
}