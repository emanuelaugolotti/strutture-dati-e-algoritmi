//12 min
void Swap(int* m, int* n) {
	int tmp = *m;
	*m = *n;
	*n = tmp;
}

int MCD(int m, int n) {
	if (m < n) {
		Swap(&m, &n);
	}

	if (n == 0) {
		return m;
	}
	
	return MCD(n, m % n);
}