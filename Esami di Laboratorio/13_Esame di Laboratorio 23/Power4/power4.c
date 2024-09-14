//Time: 20min
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void PowerRec(int n, int* exp, bool* ispower) {
	int ris = (int)pow(4, *exp);
	if (ris == n) {
		*ispower = true;
		return;
	}
	if (ris > n) {
		return;
	} 
	++(*exp);
	PowerRec(n, exp, ispower);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	int exp = 0;
	bool ispower = false;
	PowerRec(n, &exp, &ispower);
	if (ispower) {
		printf("4^%i = %i", exp, n);
	} else {
		printf("!p4");
	}
	return 0;
}