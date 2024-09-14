//Time: 9 min
#include <stdlib.h>
#include <stdio.h>

int GetNext(int n) {
	if (n % 2 == 0) {
		return n / 2;
	}
	return 3 * n + 1;
}

void HailstoneRec(int n, int* count) {
	if (n == 1) {
		printf("%i", n);
		++(*count);
		return;
	}
	printf("%i, ", n);
	++(*count);
	int next = GetNext(n);
	HailstoneRec(next, count);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return -1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n <= 0) {
		return 0;
	}
	int count = 0;
	HailstoneRec(n, &count);
	return count;
}