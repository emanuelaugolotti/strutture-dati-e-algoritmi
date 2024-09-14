#include "robot_mod.h"

void PrintLine(const struct Grid* g) {
	printf("+");
	for (size_t i = 0; i < g->cols; ++i) {
		printf("---+");
	}
	printf("\n");
}

void PrintGrid(const struct Grid* g) {
	PrintLine(g);
	for (size_t r = 0; r < g->rows; ++r) {
		printf("|");
		for (size_t c = 0; c < g->cols; ++c) {
			int val = g->cells[r * g->cols + c];
			if (val != -1 && val < 10) {
				printf(" %i |", val);
			}  else if(val !=- 1 && val > 9) {
				printf("%3i|", val);
			} else {
				printf(" B |");
			}
		}
		printf("\n");
		PrintLine(g);
	}
	printf("\n");
}

size_t GetNextPos(const struct Grid* g, int i, size_t pos_curr, size_t r_curr, size_t c_curr, size_t* r_new, 
	size_t* c_new) {
	size_t next;
	switch (i) {
	case 0: {
		if (c_curr < g->cols - 1) {
			next = pos_curr + 1;
			*r_new = r_curr;
			*c_new = c_curr + 1;
		} else {
			next = -1;
		}
		break;
	}
	case 1: {
		next = pos_curr + g->cols;
		*r_new = r_curr + 1;
		*c_new = c_curr;
		break;
	}
	default: {
		next = pos_curr - g->cols;
		*r_new = r_curr - 1;
		*c_new = c_curr;
		break;
	}
	}
	return next;
}

bool IsPosProibita(const struct Grid* g, size_t pos) {
	if (pos >= g->cols * g->rows || pos < 0) {
		return true;
	}
	int val = g->cells[pos];
	if (val == -1) {
		return true;
	}
	return false;
}

void FindPathsRec(const struct Grid* g, struct Grid* curr, int max_moves, int n_step, size_t r_curr,
				size_t c_curr, int* nsol, bool* usati) {
	size_t pos_curr = r_curr * g->cols + c_curr;
	if ((pos_curr == g->cols * g->rows - 1) && (max_moves >= 0 && n_step <= max_moves || max_moves < 0)) {
		++(*nsol);
		printf("Sol %i:\n", *nsol);
		PrintGrid(curr);
		return;
	}
	if (max_moves >= 0 && n_step > max_moves) {
		return;		//non è una soluzione valida
	}
	for (int i = 0; i < 3; ++i) {
		size_t r_new, c_new;
		size_t pos_next = GetNextPos(g, i, pos_curr, r_curr, c_curr, &r_new, &c_new);
		if (!usati[pos_next] && !IsPosProibita(g, pos_next)) {
			curr->cells[pos_next] = n_step + 1;
			++n_step;
			usati[pos_next] = true;
			FindPathsRec(g, curr, max_moves, n_step, r_new, c_new, nsol, usati);
			curr->cells[pos_next] = 0;
			--n_step;
			usati[pos_next] = false;
		}
	}
}

int FindPaths(const struct Grid* g, int max_moves) {
	if (g == NULL) {
		return 0;
	}
	int nsol = 0;
	struct Grid curr;
	curr.rows = g->rows;
	curr.cols = g->cols;
	curr.cells = malloc(curr.rows * curr.cols * sizeof(int));
	bool* usati = calloc(g->cols * g->rows, sizeof(bool));
	usati[0] = true;
	memcpy(curr.cells, g->cells, curr.rows * curr.cols * sizeof(int));
	curr.cells[0] = 1;
	FindPathsRec(g, &curr, max_moves, 1, 0, 0, &nsol, usati);
	free(usati);
	free(curr.cells);
	return nsol;
}