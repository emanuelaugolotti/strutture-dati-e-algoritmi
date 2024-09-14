#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

uint8_t Converti(uint8_t pos) {
	uint8_t ris;
	switch (pos) {
	case 0: ris = 1;
		break;
	case 1: ris = 2;
		break;
	case 2: ris = 4;
		break;
	case 3: ris = 8;
		break;
	case 4: ris = 16;
		break;
	case 5: ris = 1;
		break;
	case 6: ris = 2;
		break;
	case 7: ris = 4;
		break;
	case 8: ris = 8;
		break;
	case 9: ris = 16;
		break;
	default: ris = 32;
		break;
	}
	return ris;
}

void OreMinuti(bool* accesi, uint8_t* ore, uint8_t* minuti) {
	*ore = 0;
	*minuti = 0;
	for (uint8_t h = 0; h <= 4; ++h) {
		if (accesi[h]) {
			*ore += Converti(h);
		}
	}
	for (uint8_t m = 5; m <= 10; ++m) {
		if (accesi[m]) {
			*minuti += Converti(m);
		}
	}
}

bool IsValid(uint8_t ore, uint8_t minuti) {
	if (ore <= 23 && minuti <= 59) {
		return true;
	}
	return false;
}

void ValidTimesRec(uint8_t n, bool* accesi, uint8_t i, uint8_t* n_accesi, uint8_t start) {
	if (i == n) {
		if (*n_accesi != n) {
			return;
		}
		uint8_t ore, minuti;
		OreMinuti(accesi, &ore, &minuti);
		if (IsValid(ore, minuti)) {
			printf("%02i:%02i, ", ore, minuti);
		}
		return;
	}
	for (uint8_t j = start; j <= 10; ++j) {
		if (!accesi[j]) {
			accesi[j] = true;
			++(*n_accesi);
			ValidTimesRec(n, accesi, i + 1, n_accesi, j);
			accesi[j] = false;
			--(*n_accesi);
		}
	}
}

void ValidTimes(uint8_t n) {
	if (n > 11) {
		return;
	}
	bool* accesi = calloc(11, sizeof(bool));
	uint8_t n_accesi = 0;
	ValidTimesRec(n, accesi, 0, &n_accesi, 0);
	free(accesi);
}