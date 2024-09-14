#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void IsPower4Rec(int n, int ris, int* x, bool* is_power) {
	if (n == 0) {
		return;
	}
	if (n == 1) {
		*is_power = true;
		*x = 0;
		return;
	}
	ris *= 4;
	if (ris == n) {
		*is_power = true;
		return;
	}
	if (ris > n) {
		return;
	}
	++(*x);
	IsPower4Rec(n, ris, x, is_power);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	bool is_power = false;
	int x = 1, ris = 1;
	IsPower4Rec(n, ris, &x, &is_power);
	if (is_power) {
		printf("4^%i = %i", x, n);
	}
	else {
		printf("!p4");
	}
	return 0;
}