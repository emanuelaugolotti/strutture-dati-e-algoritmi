#include "colora.h"

int main(void) {

	struct Matrix m;
	m.size = 3;
	bool v[] = { true, true, true, true, true, false, true, false, true };
	m.data = v;

	char c[] = { 'r', 'v' };
	size_t c_size = sizeof(c) / sizeof(char);

	int numero_soluzionitrovate = MappaColori(&m, c, c_size);
	
	return 0;
}