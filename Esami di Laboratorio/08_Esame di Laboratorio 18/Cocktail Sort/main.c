#include <stdlib.h>
extern void CocktailSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 5, 2, 6, 1, 3, 4, 0 };
	size_t v_size = sizeof(v) / sizeof(int);

	CocktailSort(v, v_size);
	
	return 0;
}