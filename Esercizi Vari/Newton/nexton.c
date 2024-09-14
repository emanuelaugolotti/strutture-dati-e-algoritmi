#include "newton.h"

bool IsGood(double xn_succ,double xn, double t, int max_iter) {
	double val = fabs(xn_succ - xn);
	if (val <= t) {
		return true;
	}
	return false;
}

double GetValPolinomio(const Polinomio* p, double xn) {
	double val = 0;
	for (size_t i = 0; i < p->size; ++i) {
		double coeff = (double)p->coeffs[i];
		val += coeff * pow((double)xn, (double)i);
	}
	return val;
}

void NewtonRec(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter, int count, 
	double* xn_succ) {
	if (max_iter > 0 && count == max_iter) {
		return;
	}
	double val1 = GetValPolinomio(p, xn);
	double val2 = GetValPolinomio(d, xn);
	*xn_succ = xn - val1 / val2;
	++count;
	if (IsGood(*xn_succ, xn, t, max_iter)) {
		return;
	}
	NewtonRec(p, d, *xn_succ, t, max_iter, count, xn_succ);
}

double Newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter) {
	double ris;
	NewtonRec(p, d, xn, t, max_iter, 0, &ris);
	return ris;
}