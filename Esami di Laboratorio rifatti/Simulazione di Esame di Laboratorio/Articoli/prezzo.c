//Time: 31 min
#include "prezzo.h"

void StampaSol(const struct Articolo* a, size_t* curr, size_t currsize) {
	for (size_t i = 0; i < currsize; ++i) {
		size_t index = curr[i];
		printf("%s, ", a[index].nome);
	}
	printf("\n");
}

bool IsSol(const struct Articolo* a, size_t* curr, size_t currsize, int sum) {
	int sumcurr = 0;
	for (size_t i = 0; i < currsize; ++i) {
		size_t index = curr[i];
		int prezzocurr = a[index].prezzo;
		sumcurr += prezzocurr;
	}
	if (sumcurr == sum) {
		return true;
	}
	return false;
}

void TrovaArticoliRec(const struct Articolo* a, size_t a_size, int sum, size_t* curr, bool* usati,
						size_t currsize, size_t i) {
	if (i == a_size) {
		if (IsSol(a, curr, currsize, sum)) {
			StampaSol(a, curr, currsize);
		}
		return;
	}
	if (!usati[i]) {
		curr[currsize] = i;
		usati[i] = true;
		++currsize;
		TrovaArticoliRec(a, a_size, sum, curr, usati, currsize, i + 1);
	}
	usati[i] = false;
	--currsize;
	TrovaArticoliRec(a, a_size, sum, curr, usati, currsize, i + 1);
}

void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum) {
	if (a == NULL || a_size == 0 || sum == 0) {
		return;
	}
	size_t* curr = malloc(a_size * sizeof(size_t));
	bool* usati = calloc(a_size, sizeof(bool));
	TrovaArticoliRec(a, a_size, sum, curr, usati, 0, 0);
	free(usati);
	free(curr);
}