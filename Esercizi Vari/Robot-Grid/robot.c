//Time: 1h 20min
#include "robot.h"

bool IsMossaProibita(const struct Grid* g, size_t next, bool verso_destra, size_t n_cols, size_t c_curr) {
	if (verso_destra && c_curr >= n_cols - 1) {
		return true;
	}
	if (next >= g->cols * g->rows) {
		return true;
	}
	int val = g->cells[next];
	if (val == -1) {
		return true;
	}
	return false;
}

void PrintLine(size_t n_cols) {
	printf("+");
	for (size_t i = 0; i < n_cols; ++i) {
		printf("---+");
	}
	printf("\n");
}

void PrintGrid(const struct Grid* g) {
	PrintLine(g->cols);
	for (size_t r = 0; r < g->rows; ++r) {
		printf("|");
		for (size_t c = 0; c < g->cols; ++c) {
			int val = g->cells[r * g->cols + c];
			if (val != -1 && val < 10) {
				printf("% i |", val);
			}
			else if (val != -1 && val > 9) {
				printf("%-3i|", val);
			} else {
				printf(" B |");
			}
		}
		printf("\n");
		PrintLine(g->cols);
	}
	printf("\n");
}

void FindPathsRec(const struct Grid* g, struct Grid* curr, int* nsol, size_t r_curr, size_t c_curr,
				int n) {
	size_t poscurr = r_curr * g->cols + c_curr;
	if (poscurr == (g->rows - 1) * g->cols + g->cols - 1) {
		if (memcmp(curr, g, g->cols * g->rows * sizeof(int)) != 0) {
			++(*nsol);
			printf("Sol %i:\n", *nsol);
			PrintGrid(curr);
		}
		return;
	}
	size_t next;
	//verso destra di una cella
	next = poscurr + 1;
	bool versodestra = true;
	if (!IsMossaProibita(g, next, versodestra, g->cols, c_curr)) {
		curr->cells[next] = n;
		++n;
		FindPathsRec(g, curr, nsol, r_curr, c_curr + 1, n);
		--n;
		curr->cells[next] = 0;
	}
	//verso il basso di una cella
	versodestra = false;
	next = poscurr + g->cols;
	if (!IsMossaProibita(g, next, versodestra, g->cols, c_curr)) {
		curr->cells[next] = n;
		++n;
		FindPathsRec(g, curr, nsol, r_curr + 1, c_curr, n);
	}
}

int FindPaths(const struct Grid* g) {
	int nsol = 0;
	if (g == NULL || (g->cols == 0 && g->rows == 0)) {
		return nsol;
	}
	struct Grid curr;
	curr.rows = g->rows;
	curr.cols = g->cols;
	curr.cells = malloc(curr.rows * curr.cols * sizeof(int));
	memcpy(curr.cells, g->cells, curr.rows * curr.cols * sizeof(int));
	curr.cells[0] = 1;
	FindPathsRec(g, &curr, &nsol, 0, 0, 2);
	free(curr.cells);
	return nsol;
}