#include <stdlib.h>
#include <stdbool.h>

bool IsDivisore(int n, int a) {
	if (a % n == 0) {
		return true;
	}
	return false;
}


int RecamanRec(int n) {
	if (n == 1) {
		return 1;
	}
	int prec = RecamanRec(n - 1);
	int a_n;
	if (IsDivisore(n - 1, prec)) {
		a_n = prec / (n - 1);
	}
	else {
		a_n = (n - 1) * prec;
	}
	return a_n;
}

int Recaman(int n) {
	if (n < 1) {
		return -1;
	}
	return RecamanRec(n);
}