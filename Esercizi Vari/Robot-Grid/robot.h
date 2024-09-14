#ifndef ROBOT_H_
#define ROBOT_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Grid {
	size_t rows, cols;
	int* cells;
};

extern int FindPaths(const struct Grid* g);
extern void PrintGrid(const struct Grid* g);

#endif	//ROBOT_H_
