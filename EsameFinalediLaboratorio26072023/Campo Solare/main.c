#include <stdlib.h>

extern int* SolarCut(int A, size_t* sol_size);

int main(void) {
	size_t sol_size;
	int* ris = SolarCut(12, &sol_size);
	free(ris);
	return 0;
}