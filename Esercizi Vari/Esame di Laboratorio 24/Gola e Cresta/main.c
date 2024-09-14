#include <stdlib.h>
#include <stdio.h>

extern void GolaCresta(size_t n);

int main(void) {
	GolaCresta(3);
	printf("\n----------------------------\n");
	GolaCresta(4);
	return 0;
}