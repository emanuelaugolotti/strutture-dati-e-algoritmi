#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char FindLettera(const char* ninput, int nparola) {
	char ninput_tmp[] = {0,0};
	ninput_tmp[0] = ninput[0];
	int numero = strtol(ninput_tmp, NULL, 10);
	char lettera;
	if ('2' <= ninput[0] && ninput[0]  <= '6') {
		lettera = 'A' + 3 * (numero - 2) + nparola;
	}
	if (ninput[0] == '9') {
		lettera = 'V' + 3 * (numero - 2) + nparola;
	}
	if (ninput[0] == '7') {
		lettera = '0' + 3 * (numero - 2) + nparola;
	}
	if (ninput[0] == '8') {
		lettera = 'S' + 3 * (numero - 2) + nparola;
	}
	return lettera;
}

void Print(const char* str, int* parola, int* nsol, size_t len) {
	if (*nsol != 0) {
		printf("\n");
	}
	for (size_t i = 0; i < len; ++i) {
		char lettera = FindLettera(str + i, parola[i]);
		printf("%c", lettera);
	}
}

void ParoleT9Rec(const char* str, int* parola, int* nsol, size_t len, size_t i) {
	if (i == len) {
		Print(str, parola, nsol, len);
		++(*nsol);
		return;
	}
	for (int lettera = 0; lettera < 3; ++lettera) {
		parola[i] = lettera;
		ParoleT9Rec(str, parola, nsol, len, i + 1);
	}
	if (str[i] == '7' || str[i] == '9') {
		parola[i] = 3;
		ParoleT9Rec(str, parola, nsol, len, len);
	}
	return;
}

int ParoleT9(const char* str) {
	if (str == NULL || str[0] == 0) {
		return 0;
	}
	size_t len = strlen(str);
	int nsol = 0;
	int* parola = malloc(len * sizeof(int));
	ParoleT9Rec(str, parola, &nsol, len, 0);
	free(parola);
	return nsol;
}