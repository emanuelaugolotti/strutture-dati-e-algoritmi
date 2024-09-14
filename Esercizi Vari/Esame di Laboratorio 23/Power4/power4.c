//Time: 15 min
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void IsPower4Rec(int n, int* x, bool* is_pow) {
	int ris = (int)pow((double)4, (double)*x);
	if (ris == n) {
		*is_pow = true;
		return;
	}
	if (ris > n) {
		return;
	}
	++(*x);
	IsPower4Rec(n, x, is_pow);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	bool is_pow = false;
	int x = 0;
	IsPower4Rec(n, &x, &is_pow);
	if (is_pow) {
		printf("4^%i = %i", x, n);
	} else {
		printf("!p4");
	}
	return 0;
}