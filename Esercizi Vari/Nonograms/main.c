#include "nonograms.h"

int main(void) {
	Constraints constr;
	constr.rows = 8;
	constr.cols = 11;
	constr.r_constr = malloc(constr.rows * sizeof(int*));
	constr.c_constr = malloc(constr.cols * sizeof(int*));
	int r1[] = { 1, 1, -1 };
	int r2[] = { 1, 1, -1 };
	int r3[] = { 7, -1 };
	int r4[] = { 2, 3, 2, -1 };
	int r5[] = { 11, -1 };
	int r6[] = { 1, 7, 1, -1 };
	int r7[] = { 1, 1, 1, 1, -1 };
	int r8[] = { 2, 2, -1 };
	constr.r_constr[0] = r1;
	constr.r_constr[1] = r2;
	constr.r_constr[2] = r3;
	constr.r_constr[3] = r4;
	constr.r_constr[4] = r5;
	constr.r_constr[5] = r6;
	constr.r_constr[6] = r7;
	constr.r_constr[7] = r8;
	
	int c1[] = { 3, -1 };
	int c2[] = { 2, -1 };
	int c3[] = { 1, 5, -1 };
	int c4[] = { 2, 2, 1, -1 };
	int c5[] = { 4, 1, -1 };
	int c6[] = { 4, -1 };
	int c7[] = { 4, 1, -1 };
	int c8[] = { 2, 2, 1, -1 };
	int c9[] = { 1, 5, -1 };
	int c10[] = { 2, -1 };
	int c11[] = { 3, -1 };
	constr.c_constr[0] = c1;
	constr.c_constr[1] = c2;
	constr.c_constr[2] = c3;
	constr.c_constr[3] = c4;
	constr.c_constr[4] = c5;
	constr.c_constr[5] = c6;
	constr.c_constr[6] = c7;
	constr.c_constr[7] = c8;
	constr.c_constr[8] = c9;
	constr.c_constr[9] = c10;
	constr.c_constr[10] = c11;

	Nonogram(&constr);

	free(constr.r_constr);
	free(constr.c_constr);
	return 0;
}