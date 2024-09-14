//29 min
#include <stdlib.h>
#include <math.h>
#include <string.h>

static int AToIRec(const char* str, size_t i, size_t exp) {
	if (str[i] == 0) {	//terminatore
		return 0;
	}

	int ris = (str[i] - 48) * (int)pow(10, exp);
	return ris + AToIRec(str, i + 1, exp - 1);
}

int AToI(const char* str) {
	if (str == NULL) {
		return 0;
	}
	
	return AToIRec(str, 0, strlen(str) - 1);
}