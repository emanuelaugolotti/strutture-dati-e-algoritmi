// 1h 39min
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void PrintSolution(size_t* v, size_t n, size_t* nsol) {
	if (*nsol != 0) {
		printf("\n");
	}
	for (size_t i = 0; i < n; ++i) {
		printf("%zi", v[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}
}

bool IsIn(size_t elemento, const char* r, bool* usati, size_t i, size_t* curr) {
	if (i == 0 || 
		(i > 0 && (r[i - 1] == 'i' || r[i - 1] == 'I') && !usati[elemento - 1] && elemento > curr[i - 1]) ||
		(i > 0 && (r[i - 1] == 'd' || r[i - 1] == 'D') && !usati[elemento - 1] && elemento < curr[i - 1])) {
		return true;
	} else {
		return false;
	}
}

void RegoleRec(const char* r, size_t n, bool* usati, size_t* curr, size_t* nsol, size_t* nusati, size_t i) {
	if (i == n) {
		if (*nusati == n) {
			PrintSolution(curr, n, nsol);
			++(*nsol);
		}
		return;
	}

	for (size_t elemento = 1; elemento <= n; ++elemento) {
		if (IsIn(elemento, r, usati, i, curr)) {
			curr[i] = elemento;
			usati[elemento - 1] = true;
			++(*nusati);
			RegoleRec(r, n, usati, curr, nsol, nusati, i + 1);

			//Rollback
			curr[i] = 0;
			usati[elemento - 1] = false;
			--(*nusati);
			RegoleRec(r, n, usati, curr, nsol, nusati, i + 1);
		}
	}

	RegoleRec(r, n, usati, curr, nsol, nusati, n);
}

void Regole(const char* r) {
	if (r == NULL) {
		return;
	}

	size_t len = strlen(r);
	
	bool* usati = calloc((len + 1), sizeof(bool));
	size_t* curr = calloc((len + 1), sizeof(size_t));
	size_t nsol = 0, nusati = 0;
	
	RegoleRec(r, len + 1, usati, curr, &nsol, &nusati,0);

	free(usati);
	free(curr);
}