#include "prezzo.h"

int main(void) {
	struct Articolo a[] = { { "articolo 1", 5 }, { "articolo 2", 3}, { "articolo 3", 1},
		{ "articolo 4", 10}, { "articolo 5", 1} };
	size_t a_size = sizeof(a) / sizeof(struct Articolo);
	TrovaArticoli(a, a_size, 4);
	return 0;
}