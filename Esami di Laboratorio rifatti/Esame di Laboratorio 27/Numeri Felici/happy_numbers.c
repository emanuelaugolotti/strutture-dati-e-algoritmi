//Time: 11 min
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int Sommacifre(int n) {
	int sum = 0;
	while (n > 0) {
		int r = n % 10;
		sum += r * r;
		n /= 10;
	}
	return sum;
}

bool IsFelice(int n) {
	if (n == 1) {
		return true;
	}
	if (n == 4 || n == 0) {
		return false;
	}
	int new_n = Sommacifre(n);
	return IsFelice(new_n);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	bool ris = IsFelice(n);
	if (ris) {
		printf("Felice");
	} else {
		printf("Infelice");
	}
	return 0;
}