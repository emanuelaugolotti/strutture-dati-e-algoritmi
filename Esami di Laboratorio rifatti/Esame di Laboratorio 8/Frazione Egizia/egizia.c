#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool IsMultiplo(int n, int d) {
	if (n % d == 0) {
		return true;
	}
	return false;
}

void StampaFraz(int d, bool* prima_fraz) {
	if (!*prima_fraz) {
		printf(" + ");
	}
	printf("1/%i", d);
	*prima_fraz = false;
}

void FrazioneEgiziaRec(int n, int d, bool* prima_fraz) {
	int d_frazunit = (int)ceil((double)d / (double)n);
	StampaFraz(d_frazunit, prima_fraz);
	if (IsMultiplo(d, n)) {
		return;
	}
	int d_new = d * d_frazunit;
	int n_new = n * d_frazunit - d;
	FrazioneEgiziaRec(n_new, d_new, prima_fraz);
}

void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia.");
		return;
	}
	bool prima_fraz = true;
	FrazioneEgiziaRec(n, d, &prima_fraz);
}