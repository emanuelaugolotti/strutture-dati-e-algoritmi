#include "colora.h"

int main(void) {
	char c[] = { 'r', 'v' };
	size_t c_size = sizeof(c) / sizeof(char);
	struct Matrix m;
	m.size = 3;
	bool aree[] = { 1, 1, 1, 1, 1, 0, 1, 0, 1 };
	m.data = aree;
	int num_sol = MappaColori(&m, c, c_size);
	return 0;
}