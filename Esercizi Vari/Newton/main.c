#include "newton.h"
#include <crtdbg.h>

void LiberoMemoria(Polinomio* p) {
	free(p->coeffs);
}

void CalcolaDerivata(Polinomio* p, Polinomio* d) {
	for (size_t i = 0; i < d->size; ++i) {
		if (p->coeffs[i + 1] != 0) {
			d->coeffs[i] = (i + 1) * p->coeffs[i + 1];
		} else {
			d->coeffs[i] = 0;
		}
	}
}

int main(void) {
	Polinomio p;
	//p.size = 4;
	p.size = 7;
	p.coeffs = malloc(p.size * sizeof(int));
	
	/*p.coeffs[0] = 0;
	p.coeffs[1] = -2;
	p.coeffs[2] = 0;
	p.coeffs[3] = 1;*/

	/*p.coeffs[0] = 0;
	p.coeffs[1] = 0;
	p.coeffs[2] = 0;
	p.coeffs[3] = 1;*/

	p.coeffs[0] = 3;
	p.coeffs[1] = -2;
	p.coeffs[2] = 0;
	p.coeffs[3] = 12; 
	p.coeffs[4] = 0;
	p.coeffs[5] = 0;
	p.coeffs[6] = 7;

	Polinomio d;
	d.size = p.size - 1;
	d.coeffs = malloc(d.size * sizeof(int));
	CalcolaDerivata(&p, &d);

	double n;
	/*n = Newton(&p, &d,   1, 0.00001, -1);
	n = Newton(&p, &d,   1, 0.00001,  4);
	n = Newton(&p, &d, 0.5, 0.00001, -1);
	n = Newton(&p, &d,  -1, 0.00001, -1);*/

	/*n = Newton(&p, &d, 1, 0.00001, -1);
	n = Newton(&p, &d, 1, 0.0000001, -1);*/

	n = Newton(&p, &d, -2,   0.0000001, -1);
	n = Newton(&p, &d, -0.8, 0.0000001, -1);
	
	LiberoMemoria(&p);
	LiberoMemoria(&d);
	_CrtDumpMemoryLeaks();
	return 0;
}