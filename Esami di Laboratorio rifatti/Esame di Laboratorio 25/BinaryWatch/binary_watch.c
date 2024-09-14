//Time: 58 min
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t ConvertiLed(uint8_t pos) {
	uint8_t ris;
	switch (pos) {
	case 0: {
			ris = 1;
			break;
	}
	case 1: {
		ris = 2;
		break;
	}
	case 2: {
		ris = 4;
		break;
	}
	case 3: {
		ris = 8;
		break;
	}
	case 4: {
		ris = 16;
		break;
	}
	case 5: {
		ris = 1;
		break;
	}
	case 6: {
		ris = 2;
		break;
	}
	case 7: {
		ris = 4;
		break;
	}
	case 8: {
		ris = 8;
		break;
	}
	case 9: {
		ris = 16;
		break;
	}
	default: {
		ris = 32;
		break;
	}
}
	return ris;
}

bool IsOrarioValido(uint8_t* curr, uint8_t n, uint8_t* ore, uint8_t* min) {
	*ore = 0;
	*min = 0;
	for (uint8_t i = 0; i < n; ++i) {
		uint8_t val = ConvertiLed(curr[i]);
		if (curr[i] <= 4) {
			*ore += val;
		} else {
			*min += val;
		}
	}
	if (*ore <= 23 && *min <= 59) {
		return true;
	}
	return false;
}

void StampaSol(uint8_t ore, uint8_t min) {
	printf("%02i:%02i, ", ore, min);
}

void ValidTimesRec(uint8_t n, uint8_t* curr, uint8_t i) {
	if (i == n) {
		uint8_t ore, min;
		if (IsOrarioValido(curr, n, &ore, &min)) {
			StampaSol(ore, min);
		}
		return;
	}
	uint8_t start = 0;
	if (i != 0) {
		start = curr[i - 1] + 1;
	}
	for (uint8_t j = start; j < 11; ++j) {
		curr[i] = j;
		ValidTimesRec(n, curr, i + 1);
	}
}

void ValidTimes(uint8_t n) {
	if (n > 11) {
		return;
	}
	uint8_t* curr = malloc(n * sizeof(uint8_t));
	ValidTimesRec(n, curr, 0);
	free(curr);
}