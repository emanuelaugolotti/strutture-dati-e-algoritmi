#include <stdio.h>
#include <stdbool.h>

static void StampaFrazioneEgizia(int d, bool* prima_frazione) {
	if (!(*prima_frazione)) {
		printf(" + ");
	}
	printf("1/%i", d);
	*prima_frazione = false;
}

static void FrazioneEgiziaRec(int n, int d, bool* prima_frazione) {	
	
	//Caso Base
	if (d % n == 0) {
		StampaFrazioneEgizia(d / n, prima_frazione);
		return;
	}
	
	int d_tmp = 1 + d / n;
	StampaFrazioneEgizia(d_tmp, prima_frazione);
	
	int d_new = d_tmp * d;
	int n_new = (d_new / d) * n - d_new / d_tmp;
	FrazioneEgiziaRec(n_new, d_new, prima_frazione);
}

void FrazioneEgizia(int n, int d) {
	bool prima_frazione = true;

	//Caso particolare
	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia.");
		return;
	}

	FrazioneEgiziaRec(n, d, &prima_frazione);
}