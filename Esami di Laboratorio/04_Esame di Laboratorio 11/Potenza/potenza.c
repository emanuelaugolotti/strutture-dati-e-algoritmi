//Time: 7 min
static int PotenzaRec(int a, int b) {
	if (b == 0) {
		return 1;
	}
	
	return a * PotenzaRec(a, b - 1);
}

int Potenza(int a, int b) {
	if (a == 0 && b == 0) {
		return 1;
	}
	
	return PotenzaRec(a, b);
}