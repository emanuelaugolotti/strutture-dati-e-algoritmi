#include <stdlib.h>

extern void GnomeSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 3, 6, 2, 4 };
	size_t v_size = sizeof(v) / sizeof(int);

	GnomeSort(v, v_size);

	return 0;
}