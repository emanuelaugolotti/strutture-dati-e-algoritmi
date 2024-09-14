#include <stdlib.h>
#include <stdio.h>

extern int* RisolviProdotto(int n, const int* s);

void StampaMatrice(int* v, int n) {
	for (int c = 0; c < n; ++c) {
		for (int r = 0; r < n; ++r) {
			printf("%i ", v[r * n + c]);
		}
		printf("\n");
	}
}

int main(void) {
	int v[] = { 1, 2, 5, 8, 9, 16, 18, 40, 45 };
	
	int* ris = RisolviProdotto(3, v);
	StampaMatrice(ris, 3);
	
	if (ris != NULL) {
		free(ris);
	}
	return 0;
}