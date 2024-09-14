#include <stdlib.h>
#include <stdio.h>

int NumeriLeonardo(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return NumeriLeonardo(n - 1) + NumeriLeonardo(n - 2) + 1;
}
	
int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 1;
	}
	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		return 1;
	}
	for (int i = 0; i <= n; ++i) {
		int ris = NumeriLeonardo(i);
		printf("%i, ", ris);
	}
	return 0;
}