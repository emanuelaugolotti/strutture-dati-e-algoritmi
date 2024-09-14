//Time: 12 min
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int GetSommaCifre(int n) {
	int sum = 0;
	while (n > 0) {
		int r = n % 10;
		sum += (r * r);
		n /= 10;
	}
	return sum;
}

bool IsfeliceRec(int n) {
	if (n == 1) {
		return true;
	}
	if (n == 4 || n == 0) {
		return false;
	}
	int sum = GetSommaCifre(n);
	bool ris = IsfeliceRec(sum);
	return ris;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	bool is_felice = IsfeliceRec(n);
	if (is_felice) {
		printf("Felice");
	} else {
		printf("Infelice");
	}
	return 0;
}