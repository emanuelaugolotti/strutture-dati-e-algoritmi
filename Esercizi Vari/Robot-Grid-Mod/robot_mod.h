#ifndef ROBOT_MOD_H_
#define ROBOT_MOD_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Grid {
	size_t rows, cols;
	int* cells;
};

extern int FindPaths(const struct Grid* g, int max_moves);
extern void PrintGrid(const struct Grid* g);

#endif	//ROBOT_MOD_H_
