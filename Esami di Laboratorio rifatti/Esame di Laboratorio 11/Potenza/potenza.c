int PotenzaRec(int a, int b, int count) {
	if (count == b) {
		return 1;
	}
	int pow = a * PotenzaRec(a, b, count + 1);
	return pow;
}

int Potenza(int a, int b) {
	if (a == 0 && b == 0) {
		return 1;
	}
	return PotenzaRec(a, b, 0);
}