//Time: 16 min
#include <stdlib.h>
#include <stdio.h>

long long CatalanRec(long long n, long long i) {
	if (n == 0) {
		return 1;
	}
	if (i == n) {
		return 0;
	}
	long long a = CatalanRec(i, 0);
	long long b = CatalanRec(n - 1 - i, 0);
	long long ris = a * b + CatalanRec(n, i + 1);
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
	long long ris = CatalanRec(n, 0);
	printf("%lli", ris);
	return 0;
}