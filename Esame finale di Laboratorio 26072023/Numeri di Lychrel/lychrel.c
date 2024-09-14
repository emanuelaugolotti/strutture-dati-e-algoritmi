#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int ContaCifre(int n) {
	int countcifre = 0;
	while (n > 0) {
		n /= 10;
		++countcifre;
	}
	return countcifre;
}

int GetInvertito(int n) {
	int countcifre = ContaCifre(n);
	int invertito = 0;
	while (n > 0) {
		int r = n % 10;
		n /= 10;
		int exp = countcifre - 1;
		invertito += r * (int)pow(10., (double)exp);
		--countcifre;
	}
	return invertito;
}

bool IsPalindromo(int n) {
	int invertito = GetInvertito(n);
	if (n == invertito) {
		return true;
	}
	return false;
}

void IsLychrel(int n, int i, bool* is_lychrel, int num_iterazionifatte, bool* done) {
	if (num_iterazionifatte == i) {
		return;
	}
	int invertito = GetInvertito(n);
	int sum = n + invertito;
	bool is_palindromo = IsPalindromo(sum);
	if (is_palindromo && !(*done)) {
		*is_lychrel = false;
		*done = true;
	}
	IsLychrel(sum, i, is_lychrel, num_iterazionifatte + 1, done);
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	int i = strtol(argv[2], NULL, 10);
	if (n < 0 || i < 0) {
		return 1;
	}
	bool is_lychrel = true;
	bool done = false;
	IsLychrel(n, i, &is_lychrel, 0, &done);
	if (is_lychrel) {
		printf("Lychrel");
	} else {
		printf("Non di Lychrel");
	}
	return 0;
}