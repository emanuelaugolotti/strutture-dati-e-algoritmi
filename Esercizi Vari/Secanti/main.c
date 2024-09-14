#include "secanti.h"

int main(void) {
	Polinomio p;
	p.size = 4;
	p.coeffs = malloc(p.size * sizeof(int));
	p.coeffs[0] = 1;
	p.coeffs[1] = -12;
	p.coeffs[2] = -3;
	p.coeffs[3] = 2;
	
	double n;
	n = Secanti(&p, -2, 4,   0.00001, -1);
	n = Secanti(&p, -2, 4,   0.00001,  4);
	n = Secanti(&p, -2, 4, 0.0000001, -1);
	n = Secanti(&p, -2, 0,   0.00001, -1);
	free(p.coeffs);

	p.size = 5;
	p.coeffs = malloc(p.size * sizeof(int));
	p.coeffs[0] = 0;
	p.coeffs[1] = -3;
	p.coeffs[2] = 5;
	p.coeffs[3] = 0;
	p.coeffs[4] = 1;

	n = Secanti(&p,  0.4, 0.8, 0.0000001, -1);
	n = Secanti(&p,  0.4, 0.8, 0.0000001, 5);
	n = Secanti(&p, -0.2, 0.1, 0.0000001, -1);
	free(p.coeffs);

	return 0;
}