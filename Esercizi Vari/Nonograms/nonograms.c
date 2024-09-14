#include "nonograms.h"

void PrintSolution(const Constraints* constr, bool* curr) {
	for (size_t r = 0; r < constr->rows; ++r) {
		for (size_t c = 0; c < constr->cols; ++c) {
			size_t pos = r * constr->cols + c;
			if (curr[pos]) {
				printf("**");
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

bool CiSonoNCelleColorate(const Constraints* constr, int n_cellecolorate, bool* curr, size_t* start, 
						size_t* stop, bool riga) {
	size_t incremento = 1;
	if (!riga) {
		incremento = constr->cols;
	}
	bool done = false;
	for (size_t i = *start; i <= *stop; i+=incremento) {
		if (curr[i]) {
			*start = i;
			done = true;
			break;
		}
	}
	if (!done) {
		return false;
	}
	done = false;
	int count = 0;
	for (size_t i = *start; i <= *stop; i+=incremento) {
		if (curr[i]) {
			++count;
		}
		if (!curr[i]) {
			*start = i;
			break;
		}
		*start = i + 1;
	}
	if (count == n_cellecolorate) {
		return true;
	}
	return false;
}

bool VincoliColonnaRispettati(const Constraints* constr, bool* curr, int* vincoli, size_t start, size_t stop) {
	size_t i = 0;
	while (vincoli[i] != -1) {
		int n_cellecolorate = vincoli[i];
		if (!CiSonoNCelleColorate(constr, n_cellecolorate, curr, &start, &stop, false)) {
			return false;
		}
		++i;
	}
	return true;
}

bool VincoliRigaRispettati(const Constraints* constr, bool* curr, int* vincoli, size_t start, size_t stop) {
	size_t i = 0;
	while (vincoli[i] != -1) {
		int n_cellecolorate = vincoli[i];
		if (!CiSonoNCelleColorate(constr, n_cellecolorate, curr, &start, &stop, true)) {
			return false;
		}
		++i;
	}
	return true;
}

size_t GetFirsLastRow(const Constraints* constr, size_t pos, size_t* first_row, size_t* last_row) {
	size_t r = pos % constr->cols;
	size_t c = pos / constr->cols;
	*first_row = pos - (c - 1);
	*last_row = pos;
	return c;
}

size_t GetFirstLastCol(const Constraints* constr, size_t pos, size_t* first_col, size_t* last_col) {
	size_t r = pos % constr->cols;
	*first_col = pos - (constr->cols * r);
	*last_col = pos;
	return r;
}

bool Get(const Constraints* constr, size_t first_row, size_t last_row, size_t first_col, size_t last_col, 
			size_t r, size_t c, bool* curr) {
	int r_neri = 0, n_neririga = 0;
	size_t i = 0;
	int* vincoliriga = constr->r_constr[r];
	while (vincoliriga[i] != -1) {
		r_neri += vincoliriga[i];
		++i;
	}
	for (size_t i = first_row; i <= last_row; ++i) {
		if (curr[i]) {
			++n_neririga;
		}
	}
	if (n_neririga >= r_neri) {
		return false;
	}
	int c_neri = 0, n_nericolonna = 0;
	i = 0;
	int* vincolicolonna = constr->c_constr[c];
	while (vincolicolonna[i] != -1) {
		c_neri += vincolicolonna[i];
		++i;
	}
	for (size_t i = first_col; i <= last_col; i = constr->cols) {
		if (curr[i]) {
			++n_nericolonna;
		}
	}
	if (n_nericolonna >= c_neri) {
		return false;
	}
	return true;
}

void NonogramRec(const Constraints* constr, bool* curr, size_t i) {
	if (i > 0 && i % constr->cols == 0) {
		size_t start = i - constr->cols;
		size_t stop = i - 1;
		size_t n = i / constr->cols - 1;
		int* vincoli = constr->r_constr[n];
		if (!VincoliRigaRispettati(constr, curr, vincoli, start, stop)) {
			return;
		}
	}
	if (i >= (constr->rows - 1) * constr->cols) {
		size_t pos = ((constr->rows - 1) * constr->cols) / i;
		int* vincoli = constr->c_constr[pos];
		size_t start = pos;
		size_t stop = start + (constr->rows - 1) * constr->cols;
		if (!VincoliColonnaRispettati(constr, curr, vincoli, start, stop)) {
			return;
		}
	}
	if (i == constr->rows * constr->cols - 1) {
		PrintSolution(constr, curr);
		return;
	}
	size_t first_row, last_row, first_col, last_col;
	size_t r = GetFirsLastRow(constr, i, &first_row, &last_row);
	size_t c = GetFirstLastCol(constr, i, &first_col, &last_col);
	if (Get(constr, first_row, last_row, first_col, last_col, r, c, curr)) {
		curr[i] = true;
		NonogramRec(constr, curr, i + 1);
		curr[i] = false;
		NonogramRec(constr, curr, i + 1);
	}
}

void Nonogram(const Constraints* constr) {
	if (constr == NULL) {
		return;
	}
	bool* curr = calloc(constr->rows * constr->cols, sizeof(bool));
	NonogramRec(constr, curr, 0);
	free(curr);
}