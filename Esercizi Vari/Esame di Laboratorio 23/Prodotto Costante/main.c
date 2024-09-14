#include <stdlib.h>
#include <stdio.h>
#include <crtdbg.h>

extern int* RisolviProdotto(int n, const int* s);

void PrintMatrix(int* m, int n) {
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			printf("%-4i", m[r * n + c]);
		}
		printf("\n");
	}
}

int main(void) {
	int s[] = {1, 2, 5, 8, 9, 16, 18, 40, 45};

	int* ris = RisolviProdotto(3, s);
	PrintMatrix(ris, 3);

	free(ris);
	_CrtDumpMemoryLeaks();
	return 0;
}