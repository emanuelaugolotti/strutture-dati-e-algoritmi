#include "secanti.h"

bool IsApprossimazioneBuona(double xn, double x_prev, double t) {
	double diff = xn - x_prev;
	if (fabs(diff) <= t) {
		return true;
	}
	return false;
}

double GetValPolinomio(const Polinomio* p, double xn) {
	double val = 0;
	for (size_t i = 0; i < p->size; ++i) {
		double coefficiente = (double)p->coeffs[i];
		val += coefficiente * pow(xn, (double)i);
	}
	return val;
}

double SecantiRec(const Polinomio* p, double x0, double x1, double t, int max_iter, int count) {
	double val0 = GetValPolinomio(p, x0);
	double val1 = GetValPolinomio(p, x1);
	double xn = x1 - (x1 - x0) / (val1 - val0) * val1;
	++count;
	if (IsApprossimazioneBuona(xn, x1, t)) {
		return xn;
	}
	if (max_iter > 0 && count == max_iter) {
		return xn;
	}
	return SecantiRec(p, x1, xn, t, max_iter, count);
}

double Secanti(const Polinomio* p, double x0, double x1, double t, int max_iter) {
	if (p == NULL || p->size == 0) {
		return 0.;
	}
	double ris = SecantiRec(p, x0, x1, t, max_iter, 0);
	return ris;
}