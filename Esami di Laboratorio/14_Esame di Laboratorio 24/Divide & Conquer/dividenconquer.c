//Time: 12min
#include <stdlib.h>
#include <stdio.h>

int DivideConquerRec(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	int sup, inf;
	if (n % 2 == 0) {
		sup = n / 2;
		inf = sup;
	} else {
		sup = n / 2 + 1;
		inf = n / 2;
	}
	int c = DivideConquerRec(inf) + DivideConquerRec(sup) + n;
	return c;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	int ris = DivideConquerRec(n);
	printf("%i", ris);
	return 0;
}