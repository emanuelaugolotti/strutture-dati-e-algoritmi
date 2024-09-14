#include "colora.h"

struct Soluzione {
	char* v;	//vettore colori delle aree
	size_t n; //numero aree colorate
};

void PrintSolution(char* v, size_t v_size, int* nsol) {
	if (*nsol) {
		printf("\n");
	}
	for (size_t i = 0; i < v_size; ++i) {
		if (i) {
			printf(" ");
		}
		printf("%zd -> %c;", i, v[i]);
	}
}

static void MappaColoriRec(const struct Matrix* m, const char* c, size_t c_size, int* nsol, size_t i, 
	struct Soluzione* curr) {

	if (i == m->size && (curr->n != m->size)) {
		return;
	}
	
	if (i == m->size) {
		PrintSolution(curr->v, m->size, nsol);
		++(*nsol);
		return;
	}

	for (size_t color_type = 0; color_type < c_size; ++color_type) {
		bool trovato = true;
		
		for (size_t col = 0; col < m->size; ++col) {

			bool adiacente = (m->data[i * m->size + col]);
			bool stesso_colore = (curr->v[col] == c[color_type]);
			bool non_se_stesso = i != col;

			if (adiacente && stesso_colore && non_se_stesso) {
				trovato = false;
			}
		}
		
		if (trovato == true) {
			curr->v[i] = c[color_type];
			++(curr->n);
			MappaColoriRec(m, c, c_size, nsol, i + 1, curr);
			
			// Rollback
			curr->v[i] = 0;
			--(curr->n);
		}
	}
	
	MappaColoriRec(m, c, c_size, nsol, m->size, curr);
}

int MappaColori(const struct Matrix* m, const char* c, size_t c_size) {
	if (m == NULL || c == NULL || c_size == 0) {
		return 0;
	}
	
	int nsol = 0;
	struct Soluzione curr;
	curr.n = 0;
	curr.v = calloc(m->size, sizeof(char));

	MappaColoriRec(m, c, c_size, &nsol, 0, &curr);
	
	free(curr.v);
	return nsol;
}