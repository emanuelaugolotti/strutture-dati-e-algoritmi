#ifndef ALPINE_ROAD_H_
#define ALPINE_ROAD_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct {
	int s, h;
} Point;

extern int FindPath(const Point* p, size_t p_size, int dh);

#endif	//ALPINE_ROAD_H_