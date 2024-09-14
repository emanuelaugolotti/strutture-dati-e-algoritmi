#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool IsPowerRec(int n, int* count, int ris) {
	if (ris == n) {
		return true;
	}
	if (ris > n) {
		return false;
	}
	if (n == 1) {
		return true;
	}
	if (n == 0) {
		return false;
	}
	ris *= 4;
	++(*count);
	return IsPowerRec(n, count, ris);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	int count = 0;
	bool is_power = IsPowerRec(n, &count, 1);
	if (is_power) {
		printf("4^%i = %i", count, n);
	} else {
		printf("!p4");
	}
	return 0;
}