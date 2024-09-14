//Time: 31min
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

uint8_t Converti(uint8_t led) {
	uint8_t ris;
	switch (led) {
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

void StampaOrario(uint8_t ora, uint8_t minuti) {
	printf("%02i:%02i, ", ora, minuti);
}

bool GetOraMinuti(uint8_t* curr, uint8_t curr_size, uint8_t* ora, uint8_t* minuti) {
	*ora = 0;
	*minuti = 0;
	for (uint8_t i = 0; i < curr_size; ++i) {
		uint8_t led = curr[i];
		uint8_t convertito = Converti(led);
		if (led < 5) {
			*ora += convertito;
		} else {
			*minuti += convertito;
		}
	}
	if (*ora <= 23 && *minuti <= 59) {
		return true;
	}
	return false;
}

void ValidTimesRec(uint8_t n, uint8_t* curr, bool* usati, uint8_t i) {
	if (i == n) {
		uint8_t ora, minuti;
		if (GetOraMinuti(curr, n, &ora, &minuti)) {
			StampaOrario(ora, minuti);
		}
		return;
	}
	uint8_t start = 0;
	if (i > 0) {
		start = curr[i - 1] + 1;
	}
	for (uint8_t j = start; j < 11; ++j) {
		if (!usati[j]) {
			curr[i] = j;
			usati[j] = true;
			ValidTimesRec(n, curr,usati, i + 1);
			usati[j] = false;
		}
	}
}

void ValidTimes(uint8_t n) {
	if (n > 11) {
		return;
	}
	uint8_t* curr = malloc(n * sizeof(uint8_t));
	bool* usati = calloc(11, sizeof(bool));
	ValidTimesRec(n, curr, usati, 0);
	free(curr);
	free(usati);
}