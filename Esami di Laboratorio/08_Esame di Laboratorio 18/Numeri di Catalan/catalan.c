//Time: 26min
#include <stdio.h>
#include <stdlib.h>

long long CatalanRec(long long n) {
	if (n == 0) {
		return 1;
	}
	long long ris = 0;
	for (long long i = 0; i < n; ++i) {
		ris += CatalanRec(i) * CatalanRec(n - 1 - i);
	}
	return ris;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	long long n = strtoll(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	long long ris = CatalanRec(n);
	printf("%lli", ris);
	return 0;
}