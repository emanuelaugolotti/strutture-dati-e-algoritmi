double BinomialeRec(unsigned int n, unsigned int k) {
	if (k == 0 || k == n) {
		return 1.;
	}
	double val1 = BinomialeRec(n - 1, k - 1);
	double val2 = BinomialeRec(n - 1, k);
	double somma = val1 + val2;
	return somma;
}

double Binomiale(unsigned int n, unsigned int k) {
	if (n == 0 || k > n) {
		return -1;
	}
	double ris = BinomialeRec(n, k);
	return ris;
}