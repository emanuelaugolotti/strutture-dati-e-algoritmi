#include <stdlib.h>

extern int TempoTrasporto(int n, const int* t, int p);

int main(void) {
	int n = 4;
	int	t[] = { 3, 2, 4 };
	int	p = 5;

	int tempo = TempoTrasporto(n, t, p);

	return 0;
}