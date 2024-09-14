//Time: 43 min
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char ConvertiCifraInLettera(char c, int n) {
	char ris = 0;
	switch (c) {
	case '2': {
		if (n == 0) {
			ris = 'A';
		} else if (n == 1) {
			ris = 'B';
		} else if (n == 2) {
			ris = 'C';
		}
		break;
	}
	case '3': {
		if (n == 0) {
			ris = 'D';
		} else if (n == 1) {
			ris = 'E';
		} else if (n == 2) {
			ris = 'F';
		}
		break;
	}
	case '4': {
		if (n == 0) {
			ris = 'G';
		} else if (n == 1) {
			ris = 'H';
		} else if (n == 2) {
			ris = 'I';
		}
		break;
	}
	case '5': {
		if (n == 0) {
			ris = 'J';
		} else if (n == 1) {
			ris = 'K';
		} else if (n == 2) {
			ris = 'L';
		}
		break;
	}
	case '6': {
		if (n == 0) {
			ris = 'M';
		} else if (n == 1) {
			ris = 'N';
		} else if (n == 2) {
			ris = 'O';
		}
		break;
	}
	case '7': {
		if (n == 0) {
			ris = 'P';
		} else if (n == 1) {
			ris = 'Q';
		} else if (n == 2) {
			ris = 'R';
		} else if (n == 3) {
			ris = 'S';
		}
		break;
	}
	case '8': {
		if (n == 0) {
			ris = 'T';
		} else if (n == 1) {
			ris = 'U';
		} else if (n == 2) {
			ris = 'V';
		}
		break;
	}
	case '9': {
		if (n == 0) {
			ris = 'W';
		} else if (n == 1) {
			ris = 'X';
		} else if (n == 2) {
			ris = 'Y';
		} else if (n == 3) {
			ris = 'Z';
		}
		break;
	}
	default: ris = 0;
		break;
	}
	return ris;
}

void StampaSol(const char* str, char* curr, size_t len) {
	for (size_t i = 0; i < len; ++i) {
		char c = ConvertiCifraInLettera(str[i], curr[i]);
		printf("%c", c);
	}
	printf("\n");
}

void ParoleT9Rec(const char* str, char* curr, int* nsol, size_t len, size_t i) {
	if (i == len) {
		StampaSol(str, curr, len);
		++(*nsol);
		return;
	}
	for (int j = 0; j <= 3; ++j) {
		if (ConvertiCifraInLettera(str[i], j) != 0) {
			curr[i] = j;
			ParoleT9Rec(str, curr, nsol, len, i + 1);
		}
	}
}

int ParoleT9(const char* str) {
	if (str == NULL) {
		return 0;
	}
	size_t len = strlen(str);
	if (len == 0) {
		return 0;
	}
	int nsol = 0;
	char* curr = malloc(len * sizeof(char));
	ParoleT9Rec(str, curr, &nsol, len, 0);
	free(curr);
	return nsol;
}