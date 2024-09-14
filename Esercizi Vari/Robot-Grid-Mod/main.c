#include "robot_mod.h"

void StampaGriglia(struct Grid* g) {
	for (size_t r = 0; r < g->rows; ++r) {
		for (size_t c = 0; c < g->cols; ++c) {
			printf(" %2i ", g->cells[r * g->cols + c]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	struct Grid g;
	g.rows = 3;
	g.cols = 5;
	g.cells = calloc(g.rows * g.cols, sizeof(int));
	g.cells[1] = g.cells[8] = -1;
	StampaGriglia(&g);
	int ris = FindPaths(&g, 9);
	printf("s = %i\n", ris);
	printf("-------------------------------------\n\n");

	struct Grid a;
	a.rows = 3;
	a.cols = 5;
	a.cells = calloc(a.rows * a.cols, sizeof(int));
	a.cells[6] = a.cells[13] = a.cells[1] = a.cells[8] = -1;
	StampaGriglia(&a);
	ris = FindPaths(&a, -1);
	printf("s = %i", ris);

	free(g.cells);
	free(a.cells);
	return 0;
}