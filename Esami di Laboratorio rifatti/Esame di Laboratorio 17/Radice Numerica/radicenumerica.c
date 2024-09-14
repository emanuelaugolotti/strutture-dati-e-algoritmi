#include <stdlib.h>
#include <stdio.h>

int CalcolaSommaCifre(int n) {
	int somma = 0;
	while (n > 0) {
		int r = n % 10;
		somma += r;
		n /= 10;
	}
	return somma;
}

void CalcolaEStampaRadice(int n) {
	if (n < 10) {
		printf("%i", n);
		return;
	}
	int sommacifre = CalcolaSommaCifre(n);
	CalcolaEStampaRadice(sommacifre);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	CalcolaEStampaRadice(n);
	return 0;
}